#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include<opencv2/opencv.hpp>

#include<iostream>
#include"config.h"

using namespace cv;


class Histogram{
private:

public:
    void calculate_histogram(Mat &img_grayscale,map<int,int>&histogram, vector<float>&accumelated_histogram);

    void normalize_img(Mat&img);

    Mat Equalize_img(Mat &img);



};


#endif // HISTOGRAM_H
