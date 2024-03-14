#include "fourier.h"
#include "config.h"


Fourier::Fourier(){}

Mat Fourier::applyDFT(Mat img){

    int m = getOptimalDFTSize(img.rows);
    int n = getOptimalDFTSize(img.cols);

    // Add zero padding to the image to reach the optimal size
    Mat padded;
    copyMakeBorder(img, padded, 0, m - img.rows, 0, n - img.cols, BORDER_CONSTANT, Scalar::all(0));

    // Convert the image to floating point
    padded.convertTo(padded, CV_32F);

    // Perform the DFT
    Mat fourierTransform;
    dft(padded, fourierTransform, DFT_SCALE|DFT_COMPLEX_OUTPUT);
    return fourierTransform;
}

Mat Fourier::applyIDFT(Mat img){
    Mat inverseOut;
    dft(img,inverseOut, DFT_INVERSE|DFT_REAL_OUTPUT);
    return inverseOut;
}

Mat Fourier::applyShifting(Mat img){


    Mat fourier_output_img = img.clone();
    int cx = fourier_output_img.cols / 2;
    int cy = fourier_output_img.rows / 2;

    // divide the fourier input img into four parts ----------------------------------
    // rect ( x, y , w, h)
    Mat left_up(fourier_output_img, Rect(0, 0, cx, cy));
    Mat right_up(fourier_output_img, Rect(cx, 0, cx, cy));
    Mat left_down(fourier_output_img, Rect(0, cy, cx, cy));
    Mat right_down(fourier_output_img, Rect(cx, cy, cx, cy));

    // switch the four parts places to center the fourier transform ------------------
    Mat switch_variable;
    left_up.copyTo(switch_variable);
    right_down.copyTo(left_up);
    switch_variable.copyTo(right_down);
    right_up.copyTo(switch_variable);
    left_down.copyTo(right_up);
    switch_variable.copyTo(left_down);

    return fourier_output_img;

    // Mat tmp, q0, q1, q2, q3; // quadrants that will be swapped

    // Mat outputShift = img.clone();

    // int centerX = img.cols /2;
    // int centerY = img.rows /2;


    // q0 = outputShift(Rect(0, 0, centerX, centerY)); // upper left corner
    // q1 = outputShift(Rect(centerX, 0, centerX, centerY)); // upper right corner
    // q2 = outputShift(Rect(0, centerY, centerX, centerY)); // lower left corner
    // q3 = outputShift(Rect(centerX, centerY, centerX, centerY)); //lower right corner


    // // switching q0 by q3 and q1 by q2
    // q0.copyTo(tmp);
    // q3.copyTo(q0);
    // tmp.copyTo(q3);

    // q1.copyTo(tmp);
    // q2.copyTo(q1);
    // tmp.copyTo(q2);

    // return outputShift;
}

