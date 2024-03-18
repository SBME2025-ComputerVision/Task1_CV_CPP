#ifndef HYBRID_H
#define HYBRID_H

#include <bits/stdc++.h>
#include<opencv2/opencv.hpp>
using namespace cv;

class hybrid
{
private:
    Mat lowpassImg;
    Mat highpassImg;
    Mat hybridImg;
public:
    //constructor
    hybrid();

    static Mat getLpImg();

    static Mat mixImg();

};

#endif // HYBRID_H
