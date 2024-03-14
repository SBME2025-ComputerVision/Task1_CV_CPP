#include "fourier.h"
#include "config.h"


Fourier::Fourier(){}

Mat Fourier::applyDFT(Mat img){
    Mat dftOut;
    dft(img,dftOut, DFT_COMPLEX_OUTPUT);
    return dftOutl;
}

Mat Fourier::applyIDFT(Mat img){
    Mat inverseOut;
    dft(img,inverseOut, DFT_INVERSE);
    return inverseOut;
}

Mat Fourier::applyShifting(Mat mat){

    Mat tmp, q0, q1, q2, q3; // quadrants that will be swapped

    Mat outputShift = mat.clone();

    int centerX = mat.cols /2;
    int centerY = mat.rows /2;


    q0 = outputShift(Rect(0, 0, cx, cy)); // upper left corner
    q1 = outputShift(Rect(cx, 0, cx, cy)); // upper right corner
    q2 = outputShift(Rect(0, cy, cx, cy)); // lower left corner
    q3 = outputShift(Rect(cx, cy, cx, cy)); //lower right corner


    // switching q0 by q3 and q1 by q2
    q0.copyTo(tmp);
    q3.copyTo(q0);
    tmp.copyTo(q3);

    q1.copyTo(tmp);
    q2.copyTo(q1);
    tmp.copyTo(q2);

    return outputShift;
}

