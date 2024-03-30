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
    static Mat preProcessImg(Mat image,Mat &edges,Mat &grayImage,int canny_min_thresold, int canny_max_thresold);
    static Mat Hough_Circle_Transform (Mat image , int threshold , int min_radius =10 , int max_radius =200 , int canny_min_thresold = 100 , int canny_max_thresold = 200 );
};

#endif // HOUGHTRANSFORM_H
