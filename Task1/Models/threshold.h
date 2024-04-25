#ifndef THRESHOLD_H
#define THRESHOLD_H
#define UCHAR_FLAG 4
#define FLOAT_FLAG 16

#include <bits/stdc++.h>
#include<opencv2/opencv.hpp>
#include<QDebug>
#include<vector>
using namespace cv;


class Threshold
{
private:

public:
    Threshold();
    static Mat globalThresholding(Mat img,int thresholdValue);
    static Mat localThresholding(Mat img, int kernelSize, int C);
    static Mat local_threshold_mean_calculation(const Mat &src, int target_app, int C);
    static Mat Padd_Mono(const Mat &src ,int padding_margin , int data_type = UCHAR_FLAG);
    static Mat thresholdingHistogram(Mat img);
    static Mat optimumThresholding(Mat img);
    static Mat applyThresholding(Mat grey_img, float currentThreshold);
    static Mat otsuThresholding(Mat img);
};

#endif // THRESHOLD_H
