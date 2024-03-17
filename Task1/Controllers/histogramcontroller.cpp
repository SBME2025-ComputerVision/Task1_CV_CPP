#include "histogramcontroller.h"
#include "Helpers/helpers.h"
#include"Models/histogram.h"

HistogramController::HistogramController():Controller()
{

}



QPixmap HistogramController::getProcessedHistogram()
{
    Mat processedHistogram;
    if(!img->isEmpty()){
        processedHistogram=Histogram::calculateHistogram(processedImg);
        processedHistogram=Histogram::plotHistogram(processedHistogram,255,200,100);
        return Helpers::convertMatToPixmap(processedHistogram);

    }
    return Helpers::convertMatToPixmap(Mat::zeros(1,1,CV_8UC1));

}

QPixmap HistogramController::getOriginalHistogram()
{
    Mat originalHistogram;
    if(!img->isEmpty()){
        originalHistogram=Histogram::calculateHistogram(img->getOriginalImg());
        originalHistogram=Histogram::plotHistogram(originalHistogram,255,200,100);
        return Helpers::convertMatToPixmap(originalHistogram);
    }
    return Helpers::convertMatToPixmap(Mat::zeros(1,1,CV_8UC1));

}

QPixmap HistogramController::normalizeImg()
{
    Mat normalizedImg;
    if(!img->isEmpty()){
       normalizedImg= Histogram::normalizeImg(img->getOriginalImg());
       img->setIsProcessed(true);
       processedImg=normalizedImg;
       return Helpers::convertMatToPixmap(processedImg);
    }
    return Helpers::convertMatToPixmap(Mat::zeros(1,1,CV_8UC1));


}

QPixmap HistogramController::equalizeImg()
{
    Mat equalizeImg;
    if(!img->isEmpty()){
        equalizeImg=Histogram::equalizeImg(img->getOriginalImg());
        img->setIsProcessed(true);
        processedImg=equalizeImg;

        return Helpers::convertMatToPixmap(processedImg);
    }
    return Helpers::convertMatToPixmap(Mat::zeros(1,1,CV_8UC1));

}

HistogramData HistogramController::rgbHistogram()
{
    HistogramData data;
    if(!img->isEmpty()){
        data=Histogram::rgbHistogram(img->getOriginalImg());
    }
    return data;
}

QPixmap HistogramController::plotgrayscaleHistogram()
{
    Mat grayscaleimg;
    if(!img->isEmpty()){
        grayscaleimg=Histogram::calculateHistogram(img->getOriginalImg());
        grayscaleimg=Histogram::plotHistogram(grayscaleimg,255,255,100);
        return Helpers::convertMatToPixmap(grayscaleimg);
    }
    return Helpers::convertMatToPixmap(Mat::zeros(1,1,CV_8UC1));


}

QPixmap HistogramController::plotgrayscaleDistribution()
{
    Mat grayscaleimg;
    if(!img->isEmpty()){
        grayscaleimg=Histogram::calculateHistogram(img->getOriginalImg());
        grayscaleimg=Histogram::distributionCurve(grayscaleimg,255,255,100);
        return Helpers::convertMatToPixmap(grayscaleimg);
    }
    return Helpers::convertMatToPixmap(Mat::zeros(1,1,CV_8UC1));

}


