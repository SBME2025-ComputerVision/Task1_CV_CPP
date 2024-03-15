#include "frequency.h"
#include "config.h"

Frequency::Frequency() {}

Mat Frequency::applyFrequencyFilter(Mat img, int radius, bool flag){
// flag 1 (true) for low pass
// flag 0 (false) for high pass

    Mat dftImage = Fourier::applyDFT(img);
    Mat planes[2];
    split(dftImage,planes);
    Mat real, imag;
    real = Fourier::applyShifting(planes[0]);
    imag = Fourier::applyShifting(planes[1]);

    int centerX = real.cols/2;
    int centerY = real.rows/2;

    Mat mask = Mat::zeros(real.size(),CV_8U);

    circle(mask, Point(centerX,centerY), radius,Scalar(255),-1);

    Mat highPassMask;
    Mat flaggedMask;
    bitwise_not(mask, highPassMask);
    if (flag == 1){
        real.setTo(Scalar(0), ~mask);
        imag.setTo(Scalar(0), ~mask);
    }else{
        real.setTo(Scalar(0), ~highPassMask);
        imag.setTo(Scalar(0), ~highPassMask);
    }


    Mat shifted_DFT_plane_img[] = {real ,imag };

    Mat MergeImg;
    merge(shifted_DFT_plane_img, 2, MergeImg);

    Mat inversedImg = Fourier::applyIDFT(MergeImg);

    return inversedImg;
}
