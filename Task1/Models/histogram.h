#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include<opencv2/opencv.hpp>

#include<iostream>
#include"config.h"

using namespace cv;


class Histogram{
private:

public:

    static Mat normalize_img(Mat input_image);

    static Mat Equalize_img(const Mat& input_image);

    static Mat plot_histogram(cv::Mat histogram,int r=0,int g=0,int b=0);

    static Mat calculate_histogram(cv::Mat image);

    static Mat distributionCurve(Mat histogram);



};


#endif // HISTOGRAM_H
