#ifndef IMAGE_H
#define IMAGE_H

#include <bits/stdc++.h>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

class Image
{
private:
    Mat originalImg;
    Mat processedImg;
    Mat noisedImg;
    Mat greyScaledImg;
    bool isEmpty;
    bool isProcessed;
    string path;

public:

    // Initiallize an empty Image object
    Image();

    // Initiallize an Image object with the path to the image file
    Image(string pth);

    // Returns img property
    Mat getOriginalImg();

    Mat getProcessedImg();

    Mat getGreyScaledImg();

    Mat getNoisedImg();


    void setProcessedImg(Mat img);

    void setNoisedImg(Mat img);

    // Returns empty property
    bool Empty();

    bool Processed();

    //
    string getImgPath();

    void setImgPath(string pth);

    // Load/Update a new image
    void loadImage(string pth);

    void convertToGreyScale();


    ~Image();


};

#endif // IMAGE_H
