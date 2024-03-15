#include "histogramcontroller.h"
#include "Helpers/helpers.h"
#include"Models/histogram.h"

HistogramController::HistogramController()
{
    img=new Image();
}

HistogramController::HistogramController(string path)
{
    img=new Image(path);
}

QPixmap HistogramController::uploadImg()
{
    QString appDirPath = QCoreApplication::applicationDirPath();
    QString path = QFileDialog::getOpenFileName(nullptr, "Choose an Image", appDirPath);

    if (!path.isEmpty()) {
        delete this->img;
        this->img = new Image(path.toStdString());
        if (!img->isEmpty()) {
            return Helpers::convertMatToPixmap(this->img->getOriginalImg());
        }
    }
    return Helpers::convertMatToPixmap(Mat::zeros(1,1,CV_8UC1));
}

QPixmap HistogramController::getOriginalImg()
{   Mat result;
    if(!img->isEmpty()){
        result=img->getOriginalImg();
        return Helpers::convertMatToPixmap(result);
    }

    return Helpers::convertMatToPixmap(Mat::zeros(1,1,CV_8UC1));

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

