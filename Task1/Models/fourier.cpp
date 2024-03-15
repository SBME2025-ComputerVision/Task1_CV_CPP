#include "fourier.h"
#include "config.h"


Fourier::Fourier(){}

Mat Fourier::applyDFT(Mat img){
    Mat fourierTransform;
    dft(img, fourierTransform, DFT_SCALE|DFT_COMPLEX_OUTPUT);
    return fourierTransform;
}

Mat Fourier::applyIDFT(Mat img){
    Mat inverseOut;
    dft(img,inverseOut, DFT_INVERSE|DFT_REAL_OUTPUT);
    return inverseOut;
}

Mat Fourier::applyShifting(Mat img){
    Mat tmp, q0, q1, q2, q3; // quadrants that will be swapped

    Mat outputShift = img.clone();

    int centerX = img.cols /2;
    int centerY = img.rows /2;


    q0 = outputShift(Rect(0, 0, centerX, centerY)); // upper left corner
    q1 = outputShift(Rect(centerX, 0, centerX, centerY)); // upper right corner
    q2 = outputShift(Rect(0, centerY, centerX, centerY)); // lower left corner
    q3 = outputShift(Rect(centerX, centerY, centerX, centerY)); //lower right corner

    // switching q0 by q3 and q1 by q2
    q0.copyTo(tmp);
    q3.copyTo(q0);
    tmp.copyTo(q3);

    q1.copyTo(tmp);
    q2.copyTo(q1);
    tmp.copyTo(q2);

    return outputShift;
}

