#include "noise.h"

Noise::Noise() {}

Mat Noise::uniformNoise(Mat img)
{
    Mat noise = img.clone();
    randu(noise, 0, 255);
    img +=noise;
    return img;
}

Mat Noise::saltAndPepperNoise(Mat img, float saltRatio, float pepperRatio) {
    Mat result = img.clone();
    int amount = img.rows * img.cols;
    int salt = static_cast<int>(amount * saltRatio);
    int pepper = static_cast<int>(amount * pepperRatio);

    // Add salt noise
    for (int i = 0; i < salt; ++i) {
        int x = rand() % img.rows;
        int y = rand() % img.cols;
        result.at<uchar>(x, y) = 255; // Set pixel to maximum intensity (white)
    }

    // Add pepper noise
    for (int i = 0; i < pepper; ++i) {
        int x, y;
        do {
            x = rand() % img.rows;
            y = rand() % img.cols;
        } while (result.at<uchar>(x, y) == 255); // Ensure not to overwrite salt noise
        result.at<uchar>(x, y) = 0; // Set pixel to minimum intensity (black)
    }

    return result;
}

// Mat Noise::saltAndPepperNoise(Mat img, float saltRatio, float pepperRatio) {
//     Mat resultImg  = img.clone();
//     int r = 15;
//     int random = 0;

//     for (int i = 0; i < resultImg.rows; i++) {

//         for (int k = 0; k < resultImg.cols; k++) {

//             random = rand() % r + 1;

//             if (random == 1)
//                 resultImg.at<Vec3b>(i, k) = Vec3b(255,255,255);

//             else if (random == 2)
//                 resultImg.at<Vec3b>(i, k) = Vec3b(255,255,255);

//             else if (random == 3)
//                 resultImg.at<Vec3b>(i, k) = Vec3b(255,255,255);
//         }
//     }
//     return resultImg;
// }


// Mat Noise::saltAndPepperNoise(Mat img, float saltRatio, float pepperRatio) {
//     Mat resultImg  = img.clone();
//     int r = 15;
//     int random = 0;

//     for (int i = 0; i < resultImg.rows; i++) {

//         for (int k = 0; k < resultImg.cols; k++) {

//             random = rand() % r + 1;

//             if (random == 1)
//                 resultImg.at<Vec3b>(i, k) = Vec3b(255,0,0);

//             else if (random == 2)
//                 resultImg.at<Vec3b>(i, k) = Vec3b(0,255,0);

//             else if (random == 3)
//                 resultImg.at<Vec3b>(i, k) = Vec3b(0,0,255);
//         }
//     }
//     return resultImg;
// }

Mat Noise::gasussianNoise(Mat img, float mean, float sigma){
    Mat result = img.clone();
    Mat noise = Mat(img.size(), img.type());
    randn(noise, mean, sigma);
    result += noise;
    return result;
}
