#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include<opencv2/opencv.hpp>

#include<iostream>
#include"config.h"

using namespace cv;


class Histogram{
private:

public:

    static Mat normalizeImg(Mat input_image);

    static Mat equalizeImg(const Mat& input_image);

    static Mat plotHistogram(Mat histogram,int r=0,int g=0,int b=0);

    static Mat calculateHistogram(Mat image);

    static Mat distributionCurve(Mat histogram);



};


#endif // HISTOGRAM_H
