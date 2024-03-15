#ifndef FREQUENCY_H
#define FREQUENCY_H

#include <bits/stdc++.h>
#include<opencv2/opencv.hpp>
using namespace cv;


class Frequency
{
public:
    Frequency();

    static Mat applyFrequencyFilter(Mat img,int radius,bool flag);

};

#endif // FREQUENCY_H
