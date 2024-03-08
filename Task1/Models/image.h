#ifndef IMAGE_H
#define IMAGE_H

#include<opencv2/opencv.hpp>
#include<QDebug>
using namespace cv;
using namespace std;

class Image
{
private:
    Mat originalImg;
    string imgPth;
    bool empty;
    bool processed;

public:
    Image();
    Image(string pth);
    Image(Mat img,string pth);
    Mat getOriginalImg();
    void setOriginalImg(Mat img ,string pth);
    void setIsProcessed(bool processed);
    bool isEmpty();
    bool isProcessed();
};

#endif // IMAGE_H
