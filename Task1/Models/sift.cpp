#include "sift.h"

SIFTX::SIFTX() {}

// SIFTX::baseLineImage(Mat image) {
//     // Implementation
// }

/**
 * @brief Computes the number of octaves in the scale space representation of an image for SIFTX.
 *
 * @param width Width of the image.
 * @param height Height of the image.
 *
 * @return Number of octaves (integer number).
 *
 * This function calculates the number of octaves needed for the scale space representation of an image
 * for the Scale-Invariant Feature Transform (SIFTX) algorithm. Octaves are defined as a series of
 * geometrically increasing image sizes created by repeatedly applying Gaussian blurring and downsampling
 * the original image. The number of octaves is determined based on the minimum dimension (width or height)
 * of the input image. The function computes the logarithm base 2 of the minimum dimension, rounds it to
 * the nearest integer, and subtracts 1 from the result to determine the number of octaves.
 */
int SIFTX::numberOfOctaves(int width, int height) {

    // Calculate the number of octaves needed for the scale space representation of the image
    int minDim = min(width, height);
    int numOctaves = cvRound(log((double)minDim) / log(2.0)) - 1;

    // Return the number of octaves
    return  numOctaves;
}

/**
 * @brief Generates sigma values for Gaussian blurring.
 *
 * @param sigma The initial sigma value for blurring.
 * @param intervals The number of intervals for generating sigma values.
 *
 * @return A vector of double values representing the sigma values.
 *
 * This function generates a series of sigma values for Gaussian blurring, which are used
 * to create a scale space representation of an image for feature extraction algorithms
 * like SIFTX (Scale-Invariant Feature Transform). The function takes an initial sigma value
 * and the number of intervals as input parameters. It computes the number of images per octave
 * based on the number of intervals and adds 3 to it. It then calculates a scaling factor 'k'
 * based on the number of intervals. Starting from the initial sigma value, it generates
 * additional sigma values by multiplying the initial sigma with powers of 'k'. The generated
 * sigma values are stored in a vector and returned.
 */
vector<double> SIFTX::generateSigmaValues(double sigma, int intervals) {
    double newSigma;
    int numOfImagesPerOctave = intervals + 3;
    double k = pow(2, (1.0 / intervals));
    vector<double> sigmas;
    sigmas.push_back(sigma);

    for (int i = 1; i < numOfImagesPerOctave; i++) {
        newSigma = pow(k, i) * sigma;
        sigmas.push_back(newSigma);
    }

    return sigmas;
}

/**
 * @brief Creates the scale space and difference of Gaussian (DoG) images.
 *
 * @param src The input image.
 * @param intervals Number of intervals for generating scale space.
 * @param sigmas Vector of sigma values.
 *
 * @return A tuple containing the scale space and DoG images.
 *
 * This function constructs the scale space representation of the input image and computes the difference
 * of Gaussian (DoG) images. It takes the input image, the number of intervals for generating scale space,
 * and a vector of sigma values as inputs. It computes the number of octaves based on the size of the input
 * image and initializes empty matrices for storing scale space and DoG images. It then applies Gaussian blur
 * to the input image with the first sigma value. Next, it copies the blurred image to the first octave and
 * first scale image. It iterates through each octave and computes scale images and DoG images. For each scale,
 * it applies Gaussian blur to the previous scale image and computes the difference with the current scale image.
 * Additionally, it downsamples the images until reaching the final octave. Finally, it returns a tuple containing
 * the scale space and DoG images.
 */

tuple<vector<vector<Mat>>, vector<vector<Mat>>> SIFTX::generateGaussianPyramid(Mat src, int intervals, vector<double> sigmas) {
    int numOctaves = numberOfOctaves(src.size().height, src.size().width);

    vector<vector<Mat>> scaleSpace;
    vector<vector<Mat>> DoG;

    for (int oct = 0; oct < numOctaves; oct++) {
        scaleSpace.push_back(vector<Mat>(intervals + 3));
        DoG.push_back(vector<Mat>(intervals + 2));
    }

    GaussianBlur(src, src, Size(0, 0), sigmas[0], sigmas[0]);
    src.copyTo(scaleSpace[0][0]);

    for (int oct = 0; oct < numOctaves; oct++) {
        for (int scale = 1; scale < intervals + 3; scale++) {
            GaussianBlur(scaleSpace[oct][scale - 1], scaleSpace[oct][scale], Size(0, 0), sigmas[scale], sigmas[scale]);
            DoG[oct][scale - 1] = scaleSpace[oct][scale] - scaleSpace[oct][scale - 1];
        }

        if (oct < numOctaves - 1) {
            resize(scaleSpace[oct][0], scaleSpace[oct + 1][0], Size(0, 0), 0.5, 0.5, INTER_LINEAR);
        }
    }

    return make_tuple(scaleSpace, DoG);
}

/**
 * @brief Checks if the center pixel is an extremum among its 26 neighbors.
 *
 * @param currentK The 3x3 kernel of the current DoG image.
 * @param kUp The 3x3 kernel of the DoG image above the current one.
 * @param kDown The 3x3 kernel of the DoG image below the current one.
 * @param threshold The threshold value for considering a pixel as an extremum.
 *
 * @return True if the center pixel is an extremum, false otherwise.
 *
 * This function checks if the center pixel in the current kernel is an extremum among its 26 neighbors
 * in three adjacent DoG images (current, up, and down). It first retrieves the value of the center pixel
 * and compares it against a threshold value. If the absolute value of the center pixel is greater than
 * the threshold, it proceeds to compare the center pixel with its neighbors in all three kernels.
 * If the center pixel is greater than or less than all of its neighbors in all three kernels, it is
 * considered an extremum and the function returns true. Otherwise, it returns false.
 */

bool SIFTX::isKeyPoint(Mat currentK, Mat kUp, Mat kDown, double threshold){
    float centerPixel = currentK.at<float>(1, 1);

    if (abs(centerPixel) > threshold) {
        MatConstIterator_<float> itCurr = currentK.begin<float>(), itCurrEnd = currentK.end<float>();
        MatConstIterator_<float> itCurrBeforeCenter = next(currentK.begin<float>(), 4);
        MatConstIterator_<float> itCurrAfterCenter = next(currentK.begin<float>(), 5);

        MatConstIterator_<float> itUp = kUp.begin<float>(), itUpEnd = kUp.end<float>();
        MatConstIterator_<float> itDown = kDown.begin<float>(), itDownEnd = kDown.end<float>();

        if (all_of(itUp, itUpEnd, [centerPixel](float i) {return centerPixel > i; }) &&
            all_of(itDown, itDownEnd, [centerPixel](float i) {return centerPixel > i; }) &&
            all_of(itCurr, itCurrBeforeCenter, [centerPixel](float i) { return centerPixel > i; }) &&
            all_of(itCurrAfterCenter, itCurrEnd, [centerPixel](float i) {return centerPixel > i; })) {
            return true;
        } else if (all_of(itUp, itUpEnd, [centerPixel](float i) {return centerPixel < i; }) &&
                   all_of(itDown, itDownEnd, [centerPixel](float i) {return centerPixel < i; }) &&
                   all_of(itCurr, itCurrBeforeCenter, [centerPixel](float i) {return centerPixel < i; }) &&
                   all_of(itCurrAfterCenter, itCurrEnd, [centerPixel](float i) {return centerPixel < i; })) {
            return true;
        }
    }
    return false;
}

/**
 * @brief Obtains the interpolated estimate of the location of the extremum.
 *
 * @param ii Row coordinate of the extremum.
 * @param jj Column coordinate of the extremum.
 * @param sc Scale index of the extremum.
 * @param Octave Octave images containing the DoG images.
 * @param octaveIndex Index of the octave.
 *
 * @return A tuple containing the actual extremum point (Point) and the corresponding scale (int).
 *
 * This function iteratively localizes the extremum to sub-pixel accuracy by solving for the offset
 * in the extremum's location using the gradient and Hessian matrix computed from the DoG images.
 * It first initializes the current, up, and down images from the DoG octave. It then computes the
 * gradient and Hessian matrix at the given extremum coordinates. It iteratively solves for the
 * extremum update vector until it converges to an offset less than 0.5 in all dimensions. If the
 * extremum update exceeds the image boundaries or the number of iterations exceeds a threshold,
 * it returns an invalid extremum point. It also checks for low contrast and eliminates potential
 * edges based on the curvature of the Hessian matrix. Finally, it returns the localized extremum
 * point and its corresponding scale.
 */
tuple<Point, int> SIFTX::localizeExtremum(int ii, int jj, int sc, vector<Mat> Octave, int octaveIndex){
    Point P;
    Mat gradient, Hessian, extremumUpdate;
    Mat currentImg, imgUp, imgDown;
    int previousScale = -1;
    int attempt;

    for (attempt = 0; attempt < 5; attempt++) {
        Octave[sc].copyTo(currentImg);
        Octave[sc + 1].copyTo(imgUp);
        Octave[sc - 1].copyTo(imgDown);

        if (previousScale != sc) {
            previousScale = sc;
            normalize(currentImg, currentImg, 0, 1, NORM_MINMAX);
            normalize(imgUp, imgUp, 0, 1, NORM_MINMAX);
            normalize(imgDown, imgDown, 0, 1, NORM_MINMAX);
        }

        gradient = computeGradient(currentImg(Rect(jj - 1, ii - 1, 3, 3)),
                                    imgUp(Rect(jj - 1, ii - 1, 3, 3)), 
                                    imgDown(Rect(jj - 1, ii - 1, 3, 3)));

        Hessian = computeHessian(currentImg(Rect(jj - 1, ii - 1, 3, 3)),
                                  imgUp(Rect(jj - 1, ii - 1, 3, 3)), 
                                  imgDown(Rect(jj - 1, ii - 1, 3, 3)));

        solve(Hessian, gradient, extremumUpdate);
        extremumUpdate = - extremumUpdate;

        if (abs(extremumUpdate.at<float>(0)) < 0.5 && abs(extremumUpdate.at<float>(1)) < 0.5 && abs(extremumUpdate.at<float>(2)) < 0.5) {
            break;
        }

        ii += int(round(extremumUpdate.at<float>(1)));
        jj += int(round(extremumUpdate.at<float>(0)));
        sc += int(round(extremumUpdate.at<float>(2)));

        if (ii < 5 || ii > currentImg.size().height - 5 || jj < 5 || jj > currentImg.size().width - 5 || sc < 1 || sc >= Octave.size() - 1) {
            P.x = -1;
            P.y = -1;
            return make_tuple(P, -1);
        }
    }

    if (attempt >= 4) {
        P.x = -1;
        P.y = -1;
        return make_tuple(P, -1);
    }

    if (abs(currentImg.at<float>(ii, jj) < 0.03)) {
        P.x = -1;
        P.y = -1;
        return make_tuple(P, -1);
    }

    double trace = Hessian.at<float>(0, 0) + Hessian.at<float>(1, 1);
    double deter = Hessian.at<float>(0, 0) * Hessian.at<float>(1, 1) - Hessian.at<float>(0, 1) * Hessian.at<float>(1, 0);
    double curvature = (trace * trace / deter);

    if (deter < 0 || curvature > 10) {
        P.x = -1;
        P.y = -1;
        return make_tuple(P, -1);
    }

    P.x = jj * pow(2, octaveIndex);
    P.y = ii * pow(2, octaveIndex);

    return make_tuple(P, sc);
}

/**
 * @brief Computes the gradient vector at a given point in the difference of Gaussian (DoG) images.
 *
 * @param current The current DoG image.
 * @param up The DoG image corresponding to a higher scale level.
 * @param down The DoG image corresponding to a lower scale level.
 *
 * @return The gradient vector consisting of partial derivatives with respect to the x-direction, y-direction, and scale dimension.
 *
 * This function calculates the gradient vector at a specified point in the DoG images. The gradient vector
 * represents the rate of change of pixel intensities with respect to spatial dimensions (x and y) and the scale dimension.
 * The partial derivatives are computed using finite differences based on neighboring pixels in the DoG images.
 * The gradient vector is returned as a Mat object containing the partial derivatives in the order:
 * - dx: Partial derivative with respect to the x-direction.
 * - dy: Partial derivative with respect to the y-direction.
 * - dsigma: Partial derivative with respect to the scale dimension.
 */

Mat SIFTX::computeGradient(Mat current, Mat up, Mat down){
    double dx, dy, dsigma;
    dx = 0.5 * (current.at<float>(1, 2) - current.at<float>(1, 0));
    dy = 0.5 * (current.at<float>(2, 1) - current.at<float>(0, 1));
    dsigma = 0.5 * (up.at<float>(1, 1) - down.at<float>(1, 1));
    Mat gradient = (Mat_<float>(3,1) << dx, dy, dsigma);

    return gradient;
}

/**
 * @brief Computes the Hessian matrix at a given point in the difference of Gaussian (DoG) images.
 *
 * @param current The current DoG image.
 * @param up The DoG image corresponding to a higher scale level.
 * @param down The DoG image corresponding to a lower scale level.
 *
 * @return The Hessian matrix representing second-order partial derivatives with respect to the x-direction, y-direction, and scale dimension.
 *
 * This function calculates the Hessian matrix at a specified point in the DoG images. The Hessian matrix
 * represents second-order partial derivatives of pixel intensities with respect to spatial dimensions (x and y)
 * and the scale dimension. The partial derivatives are computed using finite differences based on neighboring pixels
 * in the DoG images. The Hessian matrix is returned as a Mat object containing the second-order partial derivatives
 * in the order:
 * - dxx: Second-order partial derivative with respect to the x-direction twice.
 * - dxy: Second-order partial derivative with respect to the x-direction and y-direction.
 * - dxs: Second-order partial derivative with respect to the x-direction and scale dimension.
 * - dxy: Second-order partial derivative with respect to the y-direction and x-direction (same as dxy).
 * - dyy: Second-order partial derivative with respect to the y-direction twice.
 * - dys: Second-order partial derivative with respect to the y-direction and scale dimension.
 * - dxs: Second-order partial derivative with respect to the scale dimension and x-direction (same as dxs).
 * - dys: Second-order partial derivative with respect to the scale dimension and y-direction (same as dys).
 * - dss: Second-order partial derivative with respect to the scale dimension twice.
 */

Mat SIFTX::computeHessian(Mat current, Mat up, Mat down){
    double dxx, dyy, dss, dxy, dxs, dys;
    dxx = current.at<float>(1, 2) - 2 * current.at<float>(1, 1) + current.at<float>(1, 0);
    dyy = current.at<float>(2, 1) - 2 * current.at<float>(1, 1) + current.at<float>(0, 1);
    dss = up.at<float>(1, 1) - 2 * current.at<float>(1, 1) + down.at<float>(1, 1);
    dxy = 0.25 * (current.at<float>(2, 2) - current.at<float>(0, 2) - current.at<float>(2, 0) + current.at<float>(0, 0));
    dxs = 0.25 * (up.at<float>(1, 2) - down.at<float>(1, 2) - up.at<float>(1, 0) + down.at<float>(1, 0));
    dys = 0.25 * (up.at<float>(2, 1) - down.at<float>(2, 1) - up.at<float>(0, 1) + down.at<float>(0, 1));
    Mat Hessian = (Mat_<float>(3, 3) << dxx, dxy, dxs,
                   dxy, dyy, dys,
                   dxs, dys, dss);
    return Hessian;
}


/**
 * @brief Detects keypoints (extrema) in the difference of Gaussian (DoG) images and localizes them.
 *
 * @param DoG The difference of Gaussian (DoG) images.
 * @param scale_images The scale space images.
 * @param num_intervals Number of intervals used in scale space.
 * @param sigma The initial sigma value.
 *
 * @return A vector of keypoints.
 *
 * This function detects keypoints (extrema) in the difference of Gaussian (DoG) images by iterating
 * through each pixel in each octave and each scale level. For each pixel, it checks if it is a local
 * extremum by comparing it with its 26 neighbors in a 3x3x3 window in the DoG images. If it is an extremum,
 * it localizes it to sub-pixel accuracy using the function 'localize_Extremum'. It then computes the
 * orientation(s) for each localized extremum using the function 'compute_orientation' and creates a
 * keypoint for each orientation. The keypoint's properties, such as position, octave, size, and orientation,
 * are set accordingly. Finally, it removes duplicate keypoints and returns the unique ones.
 */

vector<KeyPoint> SIFTX::getKeyPoints(vector<vector<Mat>> DoG, vector<vector<Mat>> scaledImages, int intervals, double sigma) {
    tuple<Point, int> candidate;
    double threshold = floor(0.5 * 0.04 / intervals * 255); // contrast_threshold=0.04
    vector<KeyPoint> keypoints;
    for (int oct = 0; oct < DoG.size(); oct++) {
        for (int scale = 1; scale < DoG[0].size() - 1; scale++) {
            for (int i = 5; i < DoG[oct][0].size().height - 5; i++) {
                for (int j = 5; j < DoG[oct][0].size().width - 5; j++) {
                    if (isKeyPoint(DoG[oct][scale](Rect(j - 1, i - 1, 3, 3)),
                                       DoG[oct][scale + 1](Rect(j - 1, i - 1, 3, 3)), 
                                       DoG[oct][scale - 1](Rect(j - 1, i - 1, 3, 3)), threshold)) {
                        candidate = localizeExtremum(i, j, scale, DoG[oct], oct);
                        if (get<0>(candidate).x != -1 && get<0>(candidate).y != -1) {
                            vector<float> Orientations = compute_orientation(get<0>(candidate), oct, scale, scaledImages[oct][get<1>(candidate)]);
                            for (int angle = 0; angle < Orientations.size(); angle++) {
                                KeyPoint key;
                                key.angle = Orientations[angle];
                                key.pt = get<0>(candidate);
                                key.octave = oct;
                                key.size = get<1>(candidate);
                                keypoints.push_back(key);
                            }
                        }
                    }
                }
            }
        }
    }

    vector<KeyPoint> unique_keys;
    unique_keys = remove_duplicate(keypoints);
    return unique_keys;
}

