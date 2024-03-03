#ifndef IMAGE_H
#define IMAGE_H

#include <bits/stdc++.h>
#include<opencv2/opencv.hpp>
#include<QString>
using namespace std;
using namespace cv;

class Image
{
private:
    Mat originalImg;
    Mat processedImg;
    Mat greyScaledImg;
    bool isEmpty = true;
    bool isProcessed;
    QString path;

public:

    // Initiallize an empty Image object
    Image();

    // Initiallize an Image object with the path to the image file
    Image(string pth);

    // Returns img property
    Mat getOriginalImg();

    Mat getProcessedImg();

    Mat getGreyScaledImg();

    void setProcessedImg();

    // Returns empty property
    bool isEmpty();

    bool isProcessed();

    //
    QString getImgPath();

    void setImgPath();

    // Load/Update a new image
    void loadImage(string pth);

    void convertToGreyScale();


    ~Image();


};

#endif // IMAGE_H
