#ifndef FILTER_H
#define FILTER_H


#include <bits/stdc++.h>
#include<opencv2/opencv.hpp>
using namespace cv;



class Filter
{
private:
    static Mat gaussianKernel(int kernelSize, float sigma);
public:

    // Initiallize Filter object
    Filter();
    static Mat gaussionFilter(Mat img,int kernelSize);
    static Mat medianFilter(Mat img,int kernelSize);
    static Mat avgFilter(Mat img,int kernelSize);

    static Mat opencvGaussianFilter(Mat img, int kernelSize);
    static Mat opencvMedianFilter(Mat img, int kernelSize);
    static Mat opencvAvgFilter(Mat img, int kernelSize);
};

#endif // FILTER_H
