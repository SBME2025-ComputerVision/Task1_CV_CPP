#ifndef THRESHOLD_H
#define THRESHOLD_H

#include <bits/stdc++.h>
#include<opencv2/opencv.hpp>
using namespace cv;


class Threshold
{
private:

public:
    Threshold();
    static Mat globalThresholding(Mat img);
    static Mat localThresholding(Mat img, int blockSize, int C);
};

#endif // THRESHOLD_H
