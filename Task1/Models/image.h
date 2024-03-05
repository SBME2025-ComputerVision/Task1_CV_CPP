#ifndef IMAGE_H
#define IMAGE_H

#include <bits/stdc++.h>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

class Image
{
private:
    // Image properties
    // to store the original image
    Mat originalImg;
    // to store the processed image (gray scale, noised, filtered, etc.)
    Mat processedImg;
    // to know if the image is empty
    bool isEmpty;
    // to know if any processing has been done on the image
    bool isProcessed;
    // to store the noised image
    string path;

public:

    // Initiallize an empty Image object
    Image();

    // Initiallize an Image object with the path to the image file
    Image(string pth);

    // Returns img property
    // to get the original image
    Mat getOriginalImg();
    // to get the processed image
    Mat getProcessedImg();

    // set the processed image
    void setProcessedImg(Mat& img);

    // Returns empty property
    bool Empty();

    // Returns processed property
    bool Processed();

    // Returns noised property
    string getImgPath();

    // Set the path to the image file
    void setImgPath(string pth);

    // Load/Update a new image
    void loadImage(string pth);


    ~Image();


};

#endif // IMAGE_H
