#ifndef SIFTCONTROLLER_H
#define SIFTCONTROLLER_H

#include "controller.h"
#include "config.h"

class SiftController : public Controller
{
public:
    SiftController();
    Image *img2;
    QPixmap uploadImg2();
    QPixmap convertToGrayScale2();
    Mat getOriginalImgMat();
    Mat getOriginalImgMat2();

    void extractPoints(Mat& keypoints_img,vector<vector<Mat>>&keypoints, vector<vector<Mat>>&scale_space,float sigma, float contrast_threshold, float edge_threshold, float k);
    void match(vector<vector<float>>&descriptors, vector<vector<cv::Mat>> scale_space, vector<vector<cv::Mat>>& keypoints,float magnitude_threshold,float sigma,float k);
    void appcon(Mat &output);
};

#endif // SIFTCONTROLLER_H
