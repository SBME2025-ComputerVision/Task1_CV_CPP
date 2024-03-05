#include "imagecontroller.h"
#include"config.h"

ImageController::ImageController() {
    this->img = new Image();
}

QPixmap ImageController::uploadImg() {
    QString appDirPath = QCoreApplication::applicationDirPath();
    QString path = QFileDialog::getOpenFileName(nullptr, "Choose an Image", appDirPath);

    if (!path.isEmpty()) {
        this->img->loadImage(path.toStdString());
        if (!this->img->Empty()) {
            return Helpers::convertMatToPixmap(this->img->getOriginalImg());
        }
    }
    return Helpers::convertMatToPixmap(Mat::zeros(1,1,CV_8UC1));
}

QPixmap ImageController::greyScaledImg() {
    if(!img->Empty()){
        QPixmap m = Helpers::convertMatToPixmap(this->img->getGreyScaledImg());
        return m;
    }
    return Helpers::convertMatToPixmap(Mat::zeros(1,1,CV_8UC1));
}

QPixmap ImageController::orignImg() {
    if(!img->Empty()){
        return Helpers::convertMatToPixmap(this->img->getOriginalImg());
    }
    return Helpers::convertMatToPixmap(Mat::zeros(1,1,CV_8UC1));
}

QPixmap ImageController::processedImg() {
    if(!img->Empty()&&img->Processed()){
        return Helpers::convertMatToPixmap(this->img->getProcessedImg());
    }
    return Helpers::convertMatToPixmap(Mat::zeros(1,1,CV_8UC1));
}

QPixmap ImageController::applyGaussianNoise() {
    if(!img->Empty()){
        img->setNoisedImg(Noise::gasussianNoise(img->getOriginalImg(),0,10));
        return Helpers::convertMatToPixmap(img->getNoisedImg());
    }
    return Helpers::convertMatToPixmap(Mat::zeros(1,1,CV_8UC1));
}

QPixmap ImageController::applyUniformNoise() {
    if(!img->Empty()){
        img->setNoisedImg(Noise::uniformNoise(img->getOriginalImg()));
        return Helpers::convertMatToPixmap(img->getNoisedImg());
    }
    return Helpers::convertMatToPixmap(Mat::zeros(1,1,CV_8UC1));
}

QPixmap ImageController::applySaltPepperNoise() {
    if(!img->Empty()){
        img->setNoisedImg(Noise::saltAndPepperNoise(img->getOriginalImg(),0.5,0.7));
        return Helpers::convertMatToPixmap(img->getNoisedImg());
    }
    return Helpers::convertMatToPixmap(Mat::zeros(1,1,CV_8UC1));
}

QPixmap ImageController::applyAvgFilter() {
    if(!img->Empty()){
        img->setProcessedImg(Filter::avgFilter(img->getOriginalImg(),5));
        return Helpers::convertMatToPixmap(img->getProcessedImg());
    }
    return Helpers::convertMatToPixmap(Mat::zeros(1,1,CV_8UC1));
}

QPixmap ImageController::applyGaussianFilter() {
    if(!img->Empty()){
        img->setProcessedImg(Filter::gaussionFilter(img->getOriginalImg(),5));
        return Helpers::convertMatToPixmap(img->getProcessedImg());
    }
    return Helpers::convertMatToPixmap(Mat::zeros(1,1,CV_8UC1));
}

QPixmap ImageController::applyMedianFilter() {
    if(!img->Empty()){
        img->setProcessedImg(Filter::medianFilter(img->getOriginalImg(),5));
        return Helpers::convertMatToPixmap(img->getProcessedImg());
    }
    return Helpers::convertMatToPixmap(Mat::zeros(1,1,CV_8UC1));
}






