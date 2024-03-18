#ifndef HISTOGRAMCONTROLLER_H
#define HISTOGRAMCONTROLLER_H
#include "controller.h"
#include "config.h"

class HistogramController : public Controller
{
public:
    HistogramController();
    HistogramController(string path);
    QPixmap getProcessedHistogram();
    QPixmap getOriginalHistogram();
    QPixmap normalizeImg();
    QPixmap equalizeImg();
    HistogramData rgbHistogram();
    QPixmap plotgrayscaleHistogram();
    QPixmap plotgrayscaleDistribution();



};

#endif // HISTOGRAMCONTROLLER_H
