#ifndef HISTOGRAMCONTROLLER_H
#define HISTOGRAMCONTROLLER_H
#include "Models/image.h"
#include "Models/histogram.h"

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
    HistogramData rgbHistogram();
    QPixmap plotgrayscaleHistogram();
    QPixmap plotgrayscaleDistribution();



};

#endif // HISTOGRAMCONTROLLER_H
