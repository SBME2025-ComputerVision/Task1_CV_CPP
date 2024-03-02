#ifndef IMAGE_H
#define IMAGE_H

#include <bits/stdc++.h>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

class Image
{
private:
    Mat img;
    bool empty = true;
    void loadImage();


public:

    // Initiallize an empty Image object
    Image();

    // Initiallize an Image object with the path to the image file
    Image(string pth);

    // Returns img property
    Mat getImage();

    // Returns empty property
    bool isEmpty();

    // Load/Update a new image
    void loadImage(string pth);

    ~Image();


};

#endif // IMAGE_H
