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

    static vector <Vec3f> circles;
    static int Xc, Yc;
    static int maxradius;
    static int minradius;
    static int radius;
    struct centerData
    {
      int bright;
      int Xbright;
      int Ybright;
    };

    static Mat detectEdge(Mat Image); 
    static void polarToCartesian(double rho, int theta, Point& p1, Point& p2);
    static Mat detectLines(Mat Image, int threshold);
    static Mat detectCircles(Mat HoughCircle, int minRadius=10, int maxRadius=35);
    static Mat lineTransform(Mat edges, Mat output ,int threshold, double rho, int theta);
    static Mat circleTransform(Mat src, int maxradius, int minradius);
};

#endif // HOUGHTRANSFORM_H
