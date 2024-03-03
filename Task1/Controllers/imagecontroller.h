#ifndef IMAGECONTROLLER_H
#define IMAGECONTROLLER_H

#include "Models/image.h"
#include <opencv2/opencv.hpp>
#include "Helpers/helpers.h"

class ImageController
{
private:
    Image *img;
    QPixmap processAndReturnImage(Mat (Image::*processFunction)(), Image *img);
public:
    ImageController();
    QPixmap uploadImg();
    QPixmap greyScaledImg();
    QPixmap orignImg();
    QPixmap processedImg();


};

#endif // IMAGECONTROLLER_H&
