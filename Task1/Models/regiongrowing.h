#ifndef REGIONGROWING_H
#define REGIONGROWING_H

#include "config.h"
using namespace cv;
using namespace std;

class RegionGrowing
{
public:
    RegionGrowing();
    static Mat growSeedPoints(Mat& img, vector<pair<int,int>> seedPoints, int threshold);
};

#endif // REGIONGROWING_H
