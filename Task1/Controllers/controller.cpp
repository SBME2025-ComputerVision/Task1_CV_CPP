#include "controller.h"
#include "Helpers/helpers.h"
#include "config.h"

Controller::Controller() {
    img = new Image();
}

QPixmap Controller::uploadImg() {

    QString path = Helpers::openFile();
    if(!path.isEmpty()){
        delete img;
        img = new Image(path.toStdString());
        if(!img->isEmpty()){
            return Helpers::convertMatToPixmap(img->getOriginalImg());
        }
    }
    return Helpers::convertMatToPixmap(Mat::zeros(1,1,CV_8UC1));
}

QPixmap Controller::convertToGrayScale() {
    if(!img->isEmpty()){
        processedImg = Filter::convertToGrayScale(img->getOriginalImg());
        img->setIsProcessed(true);
        return Helpers::convertMatToPixmap(processedImg);
    }
    return Helpers::convertMatToPixmap(Mat::zeros(1,1,CV_8UC1));
}
