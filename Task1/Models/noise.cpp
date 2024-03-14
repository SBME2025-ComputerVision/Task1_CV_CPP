#include "noise.h"

Noise::Noise() {}

Mat Noise::uniformNoise(Mat img)
{
    Mat result = img.clone();
    Mat noise = Mat(img.size(), img.type());
    randu(noise, 0, 50);
    result +=noise;
    return result;
}


Mat Noise::saltAndPepperNoise(Mat img, int r) {
    Mat resultImg  = img.clone();
    int random = 0;

    for (int i = 0; i < resultImg.rows; i++) {

        for (int k = 0; k < resultImg.cols; k++) {

            random = rand() % r + 1;

            if (random == 1)
                resultImg.at<uchar>(i, k) = 255;

            else if (random == 2)
                resultImg.at<uchar>(i, k) = 0;
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
