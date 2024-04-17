#include "sift.h"

SIFTX::SIFTX() {}

Mat SIFTX::baseLineImage(Mat image) {
     GaussianBlur(image, image, Size(0, 0), 0.5, 0.5);
             resize(image, image, Size(0, 0), 2, 2, INTER_LINEAR);
             return image;
 }

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
 *int octave, int scale, Mat gaussian_image);
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
    // qDebug()<<"4.1";
    for (int oct = 0; oct < DoG.size(); oct++) {
        // qDebug()<<"4.2";
        for (int scale = 1; scale < DoG[0].size() - 1; scale++) {
            // qDebug()<<"4.3";
            for (int i = 5; i < DoG[oct][0].size().height - 5; i++) {
                // qDebug()<<"4.4";
                for (int j = 5; j < DoG[oct][0].size().width - 5; j++) {
                    // qDebug()<<"4.5.1";
                    if (isKeyPoint(DoG[oct][scale](Rect(j - 1, i - 1, 3, 3)),
                                       DoG[oct][scale + 1](Rect(j - 1, i - 1, 3, 3)), 
                                       DoG[oct][scale - 1](Rect(j - 1, i - 1, 3, 3)), threshold)) {
                        // qDebug()<<"4.5.2";
                        candidate = localizeExtremum(i, j, scale, DoG[oct], oct);
                        if (get<0>(candidate).x != -1 && get<0>(candidate).y != -1) {
                            // qDebug()<<"4.5.3";
                            vector<float> Orientations = computeOrientation(get<0>(candidate), oct, scale, scaledImages[oct][get<1>(candidate)]);
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
qDebug()<<"4.6";

    vector<KeyPoint> unique_keys;
    unique_keys = SIFTX::removeDuplicates(keypoints);
    return unique_keys;
}


vector<float> SIFTX::computeOrientation(Point P, int octave, int scale, Mat gaussian_image) {

    double sigma = scale * 1.5;
    vector<float> Orientations;
    Mat kernel = gaussian_kernel(sigma);
    int radius = int(2 * ceil(sigma) + 1);
    int x, y;
    double weight;
    Mat raw_histogram = Mat::zeros(36, 1, CV_64FC1); // num_bins  = 36


    for (int i = -radius; i <= radius; i++)
    {
        y = int(round((P.y / pow(2, octave)))) + i;
        if (y <= 0 || y >= gaussian_image.rows - 1) continue;

        for (int j = -radius; j <= radius; j++)
        {
            x = int(round((P.x / pow(2, octave)))) + j;
            if (x <= 0 || x >= gaussian_image.cols - 1) continue;

            double dx = gaussian_image.at<float>(y, x + 1) - gaussian_image.at<float>(y, x - 1);
            double dy = gaussian_image.at<float>(y + 1, x) - gaussian_image.at<float>(y - 1, x);
            double magnitude = sqrt(dx * dx + dy * dy);
            double orientation = atan2(dy, dx)  * (180.0 / 3.14159265);

            if (orientation < 0) orientation = orientation + 360;

            int histogram_index = int(floor(orientation * 36.0 / 360.0));
            /*Each sample added to the histogram is weighted by its gradient magnitude
                and by a Gaussian-weighted circular window with a  that is 1.5 times that of the scale
                of the keypoint.*/
            weight = kernel.at<double>(j + radius, i + radius) * magnitude;
            raw_histogram.at<double>(histogram_index, 0) += weight;
        }
    }

    /*Finally, a parabola is fit to the 3 histogram values closest to each peak to interpolate the peak position
        for better accuracy.
        You can find more details from here: https://ccrma.stanford.edu/~jos/sasp/Quadratic_Interpolation_Spectral_Peaks.html
        */

    double maxVal;
    Point maxLoc;
    double left_value, right_value, orientation, interpolated_peak_index;
    minMaxLoc(raw_histogram, NULL, &maxVal, NULL, &maxLoc);

    for (int bin = 0; bin < raw_histogram.rows; bin++)
    {
        if (raw_histogram.at<double>(bin, 0) >= (0.8 * maxVal))
        {
            if (bin == 0) left_value = raw_histogram.at<double>(35, 0);
            else left_value = raw_histogram.at<double>(bin - 1, 0);

            if (bin == 35) right_value = raw_histogram.at<double>(0, 0);
            else right_value = raw_histogram.at<double>(bin + 1, 0);

            interpolated_peak_index = bin + 0.5 * (left_value - right_value) / (left_value - 2 * raw_histogram.at<double>(bin, 0) + right_value);
            orientation = interpolated_peak_index * 360.0 / 36.0;

            if (orientation < 0 || orientation >= 360) orientation = abs(360 - abs(orientation));
            Orientations.push_back(orientation);
        }
    }
    return Orientations;

}


vector<KeyPoint> SIFTX::removeDuplicates(vector<KeyPoint> keypoints) {
    vector<KeyPoint> unique_keypoints;

    if (keypoints.size() < 2)
    {
        return keypoints;
    }

    struct myclass {
        bool operator() (KeyPoint key1, KeyPoint key2) {
            if (key1.pt.x != key2.pt.x)
            {
                return (key1.pt.x < key2.pt.x);
            }
            else
            {
                return (key1.pt.y < key2.pt.y);
            }
        }
    } myobject;
    sort(keypoints.begin(), keypoints.end(), myobject);

    unique_keypoints.push_back(keypoints[0]);
    for (int i = 1; i < keypoints.size(); i++)
    {
        if (unique_keypoints.back().pt.x != keypoints[i].pt.x || unique_keypoints.back().pt.y != keypoints[i].pt.y || unique_keypoints.back().angle != keypoints[i].angle)
        {
            unique_keypoints.push_back(keypoints[i]);
        }
    }

    return unique_keypoints;
}


Mat SIFTX::gaussian_kernel(double sigma) {
    /* https://theailearner.com/2019/05/06/gaussian-blurring/
        For Gaussian, we know that 99.3% of the distribution falls within 3 standard deviations after
        which the values are effectively close to zero. So, we limit the kernel size to contain only
        values within 3? from the mean. This approximation generally yields a result sufficiently
        close to that obtained by the entire Gaussian distribution.*/

    /*Note: The approximated kernel weights would not sum exactly 1 so, normalize the weights
        by the overall kernel sum. Otherwise, this will cause darkening or brightening of the image.
        A normalized 3×3 Gaussian filter is shown below (See the weight distribution)*/

    /*First, the Gaussian kernel is linearly separable. This means we can break
        any 2-d filter into two 1-d filters. Because of this, the computational complexity
        is reduced from O(n2) to O(n). Lets see an example*/
    int r = ceil(3 * sigma);
    Mat kernel(2 * r + 1, 2 * r + 1, CV_64FC1);
    for (int i = -r; i <= r; i++)
    {
        for (int j = -r; j <= r; j++)
        {
            kernel.at<double>(i + r, j + r) = exp(-(i*i + j*j) / (2.0 * sigma*sigma));
        }
    }
    kernel = kernel / sum(kernel);
    return kernel;
}



vector<Mat> SIFTX::getDescriptors(vector<KeyPoint> keypoints, vector<vector<Mat>> scale_space) {
    int w = 16;
    Mat kernel = gaussian_kernel(w / 6.0);
    Mat feature_vector = Mat::zeros(128, 1, CV_64FC1);
    vector<Mat> features;
    for (int kp = 0; kp < keypoints.size(); kp++)
    {
        int octave = keypoints[kp].octave;
        int scale = keypoints[kp].size;
        int y_c = keypoints[kp].pt.y / pow(2, octave);
        int x_c = keypoints[kp].pt.x / pow(2, octave);

        Mat magnitude = Mat::zeros(Size(17, 17), CV_64FC1);
        Mat orientation = Mat::zeros(Size(17, 17), CV_64FC1);

        Mat gaussian_image = scale_space[octave][scale];
        if (x_c - w/2 >0 && y_c - w/2 > 0 && x_c + w/2 < gaussian_image.cols -1 && y_c + w/2 < gaussian_image.rows -1)
        {
            for (int i = -w / 2; i <= w / 2; i++)
            {
                int y = y_c + i;
                for (int j = -w / 2; j <= w / 2; j++)
                {
                    int x = x_c + j;

                    double dx = gaussian_image.at<float>(y, x + 1) - gaussian_image.at<float>(y, x - 1);
                    double dy = gaussian_image.at<float>(y + 1, x) - gaussian_image.at<float>(y - 1, x);
                    magnitude.at<double>(i + w/2, j + w/2) = sqrt(dx * dx + dy * dy);
                    double theta = atan2(dy, dx)  * (180.0 / 3.14159265);
                    if (theta < 0) theta = theta + 360;
                    orientation.at<double>(i + w/2, j + w/2) = theta;
                }
            }
            Mat weighted_grad = magnitude.mul(kernel);
            Mat Q, hist_Q;
            for (int i = 0; i <=13 ; i = i+4)
            {
                int m = 0;
                for (int j = 0; j <=13; j = j+4)
                {
                    Q = orientation(Rect(i, j, 4, 4));
                    hist_Q = compute_hist(Q);
                    hist_Q.copyTo(feature_vector(Rect(0, m, 1, 8)));
                    m = m + 8;
                    if (j == 4) j = j + 1;
                }
                if (i == 4) i = i + 1;
            }
            feature_vector = feature_vector / max(1e-6, norm(feature_vector, NORM_L2));
            threshold(feature_vector, feature_vector, 0.2, 255,THRESH_TRUNC);
            feature_vector = feature_vector / max(1e-6, norm(feature_vector, NORM_L2));
            features.push_back(feature_vector);
        }
    }
    return features;
}

Mat SIFTX::compute_hist(Mat scr) {
    Mat hist = Mat::zeros(8, 1, CV_64FC1);
    int value = 0;
    int quantize_value;
    for (int i = 0; i < scr.rows; i++)
    {
        for (int j = 0; j < scr.cols; j++)
        {
            value = scr.at<double>(i, j);
            quantize_value = quantize_orientation(value);
            hist.at<double>(quantize_value) = hist.at<double>(quantize_value) + 1;
        }
    }
    return hist;
}

//-------------------------------------------------------------------------------

int SIFTX::quantize_orientation(double angle) {
    return floor(angle / 45.0);
}

