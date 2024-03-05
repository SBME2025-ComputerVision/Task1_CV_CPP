#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <bits/stdc++.h>
#include<opencv2/opencv.hpp>
using namespace cv;

class Histogram{
private:

public:
    void calculate_histogram(Mat img_grayscale,map<int,int>&histogram,vector<float>&accumelated_histogram;)

    Mat normalize_img(Mat&img);

    Mat Equalize_img(Mat &img);



};


#endif // HISTOGRAM_H
