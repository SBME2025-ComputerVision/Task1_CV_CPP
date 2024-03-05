#include "noise.h"

Noise::Noise() {}

Mat Noise::uniformNoise(Mat img)
{
    Mat result = img.clone();

    Mat noise = Mat(img.size(), img.type());
    randu(noise, 0, 255);
    result +=noise;
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
//                 resultImg.at<uchar>(i, k) = 255;

//             else if (random == 2)
//                 resultImg.at<uchar>(i, k) = 255;

//             else if (random == 3)
//                 resultImg.at<uchar>(i, k) = 255;
//         }
//     }
//     return resultImg;
// }


Mat Noise::saltAndPepperNoise(Mat img, float saltRatio, float pepperRatio) {
    Mat resultImg  = img.clone();
    int r = 15;
    int random = 0;

    for (int i = 0; i < resultImg.rows; i++) {

        for (int k = 0; k < resultImg.cols; k++) {

            random = rand() % r + 1;

            if (random == 1)
                resultImg.at<Vec3b>(i, k) = Vec3b(255,0,0);

            else if (random == 2)
                resultImg.at<Vec3b>(i, k) = Vec3b(0,255,0);

            else if (random == 3)
                resultImg.at<Vec3b>(i, k) = Vec3b(0,0,255);
        }
    }
    return resultImg;
}

Mat Noise::gasussianNoise(Mat img, float mean, float sigma){
    Mat result = img.clone();
    Mat noise = Mat(img.size(), img.type());
    randn(noise, mean, sigma);
    result += noise;
    return result;
}
