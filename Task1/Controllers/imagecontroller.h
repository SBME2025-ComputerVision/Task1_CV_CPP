#ifndef IMAGECONTROLLER_H
#define IMAGECONTROLLER_H

#include "Models/image.h"
#include <opencv2/opencv.hpp>
#include "Helpers/helpers.h"

class ImageController
{
private:
    Image *img;
public:
    ImageController();
    QPixmap uploadImg();
};

#endif // IMAGECONTROLLER_H
