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
    QPixmap getGreyScaledImg();
    QPixmap getProcessedImg();
    QPixmap FilterImg(Mat (*filter)(Mat img, int kernelSize), int kernelSize);
    QPixmap addNoise(int noiseType, int r, float mean, float sigma);
    
};

#endif // IMAGECONTROLLER_H&
