#ifndef HOUGHTRANSFORM_H
#define HOUGHTRANSFORM_H

#include <opencv2/opencv.hpp>
#include <time.h>
#include <cmath>
#include "config.h"
using namespace cv;
using namespace std;

class HoughTransform
{
public:
    HoughTransform();
    static Mat detectEdge(Mat Image); 
    static void polarToCartesian(double rho, int theta, Point& p1, Point& p2);
    static Mat detectLines(Mat Image, int threshold);
    static Mat lineTransform(Mat edges, Mat output ,int threshold, double rho, int theta);
};

#endif // HOUGHTRANSFORM_H
