#ifndef SIFT_H
#define SIFT_H
#include <config.h>

class SIFTX
{
public:
    SIFTX();
    Mat baseLineImage(Mat image);
    int numberOfOctaves(int width, int height);
    vector<double> generateSigmaValues(double sigma, int intervals);
    tuple<vector<vector<Mat>>, vector<vector<Mat>>> generateGaussianPyramid(Mat scr, int intervals, vector<double> sigmas);
    vector<KeyPoint> getKeyPoints(vector<vector<Mat>> DoG, vector<vector<Mat>> scaledImages, int intervals, double sigma);
    bool isKeyPoint(Mat currentK, Mat kUp, Mat kDown, double threshold);
    tuple<Point, int> localizeExtremum(int ii, int jj, int sc, vector<Mat> Octave, int octaveIndex);
    Mat computeGradient(Mat current, Mat up, Mat down);
    Mat computeHessian(Mat current, Mat up, Mat down);
};

#endif // SIFTX_H
