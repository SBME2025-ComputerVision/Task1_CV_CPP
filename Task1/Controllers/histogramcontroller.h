#ifndef HISTOGRAMCONTROLLER_H
#define HISTOGRAMCONTROLLER_H
#include "Models/image.h"

class HistogramController
{
private:
    Image *img;
    Mat processedImg;
public:
    HistogramController();
    HistogramController(string path);
    QPixmap uploadImg();
    QPixmap getOriginalImg();
    QPixmap getProcessedImg();
    QPixmap getProcessedHistogram();
    QPixmap getOriginalHistogram();
    QPixmap normalizeImg();
    QPixmap equalizeImg();



};

#endif // HISTOGRAMCONTROLLER_H
