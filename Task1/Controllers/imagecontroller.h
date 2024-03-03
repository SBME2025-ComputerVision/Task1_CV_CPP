#ifndef IMAGECONTROLLER_H
#define IMAGECONTROLLER_H

#include "Models/image.h"
#include <opencv2/opencv.hpp>


class ImageController
{
private:
    Image *img;
public:
    ImageController();
    Mat uploadImg();
};

#endif // IMAGECONTROLLER_H
