#include "sift2.h"

SIFT2::SIFT2() {}


/**
 * Generates a scale space pyramid of Gaussian blurred images.
 *
 * @param img The input image.
 * @param sigmaMin Minimum sigma value for Gaussian blur.
 * @param numOctaves Number of octaves in the scale space pyramid.
 * @param scalesPerOctave Number of scales (or images) per octave.
 * @return ScaleSpacePyramid containing the scale space pyramid.
 */
ScaleSpacePyramid SIFT2::generateGaussianPyramid(const Mat img, float sigmaMin,int numOctaves, int scalesPerOctave) {
    // assume initial sigma is 1.0 (after resizing) and smooth
    // the image with sigmaDiff to reach requried baseSigma
    float baseSigma = sigmaMin/MIN_PIX_DIST;
    Mat baseMat;
    // resize the image to double its size
    resize(img,baseMat,Size(img.cols*2,img.rows*2),0,0,BILINEAR);
    float sigmaDiff = sqrt(baseSigma*baseSigma - 1.0); // sigmaDiff is the difference between the sigma of the first image and the base sigma.
    // Apply Gaussian blur to the image.
    GaussianBlur(baseMat,baseMat,Size(3,3),sigmaDiff,sigmaDiff);

    int imgsPerOctave = scalesPerOctave + 3;

    // determine sigma values for bluring
    // sigma_i = k^(i-1) * sigma_0
    float k = pow(2,1.0/scalesPerOctave);
    vector<float> sigmas(imgsPerOctave);
    sigmas[0] = baseSigma;
    for(int i=1;i<imgsPerOctave;i++) {
        float sigmaPrev = baseSigma * pow(k,i-1);
        float sigmaTotal = sigmaPrev * k;
        sigmas[i] = sqrt(sigmaTotal*sigmaTotal - sigmaPrev*sigmaPrev);
    }

    // create a scale space pyramid of gaussian images
    // images in each octave are half the size of images in the previous one
    ScaleSpacePyramid pyramid;
    pyramid.numOctaves = numOctaves;
    pyramid.numScales = scalesPerOctave;
    pyramid.octaves = vector<vector<Mat>>(numOctaves);

    for (int i = 0; i < numOctaves; i++)
    {
        pyramid.octaves[i].reserve(imgsPerOctave);
        // add the first image to the octave
        // TODO: zxz
        pyramid.octaves[i].push_back(baseMat);
        for (int j = 1; j < sigmas.size(); j++)
        {
            const Mat prevMat = pyramid.octaves[i].back();
            Mat img;
            GaussianBlur(prevMat, img, Size(3, 3), sigmas[j], sigmas[j]);
            pyramid.octaves[i].push_back(img);
        }
        // prepare base image for next octave
        const Mat nextBaseMat = pyramid.octaves[i][imgsPerOctave - 3];
        resize(nextBaseMat, baseMat, Size(nextBaseMat.cols / 2, nextBaseMat.rows / 2), 0, 0, NEAREST);
    }

    return pyramid;
}

/**
 * Generates a scale space pyramid of Difference of Gaussian (DoG) images.
 *
 * @param img_pyramid The scale space pyramid of Gaussian blurred images.
 * @return ScaleSpacePyramid containing the scale space pyramid of DoG images.
 */

ScaleSpacePyramid SIFT2::generateDogPyramid(const ScaleSpacePyramid img_pyramid){
    ScaleSpacePyramid dog_pyramid;
    dog_pyramid.numOctaves = img_pyramid.numOctaves;
    dog_pyramid.numScales = img_pyramid.numScales - 1;
    dog_pyramid.octaves = vector<vector<Mat>>(dog_pyramid.numOctaves);

    for (int i = 0; i < dog_pyramid.numOctaves; i++)
    {
        dog_pyramid.octaves[i].reserve(dog_pyramid.numScales);
        for (int j = 1; j < img_pyramid.numScales; j++)
        {
            Mat dog;
            subtract(img_pyramid.octaves[i][j], img_pyramid.octaves[i][j - 1], dog);
            dog_pyramid.octaves[i].push_back(dog);
        }
    }

    return dog_pyramid;
}

/**
 * Generates a scale space pyramid of gradient images.
 *
 * @param pyramid The scale space pyramid of Gaussian blurred images.
 * @return ScaleSpacePyramid containing the scale space pyramid of gradient images.
 */

bool SIFT2::isExtremum(const vector<Mat> octave, int scale, int row, int col) {
    Mat img = octave[scale];
    Mat img_prev = octave[scale - 1];
    Mat img_next = octave[scale + 1];
    bool isMax = true;
    bool isMin = true;
    float val = img.at<float>(row, col);
    float neighborVal;

    for (int dx = -1; dx <= 1; i++){
        for (int dy = -1; dy <= 1; j++){
            neighborVal = img_prev.at<float>(row + dx, col + dy);
            if (val < neighborVal){
                isMax = false;
            }
            if (val > neighborVal){
                isMin = false;
            }
            neighborVal = img.at<float>(row + dx, col + dy);
            if (val < neighborVal){
                isMax = false;
            }
            if (val > neighborVal){
                isMin = false;
            }
            neighborVal = img_next.at<float>(row + dx, col + dy);
            if (val < neighborVal){
                isMax = false;
            }
            if (val > neighborVal){
                isMin = false;
            }

            if (!isMax && !isMin){
                return false;
            }

        }
    }

    return true;
    
}
    
