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


QPixmap ImageController::getGreyScaledImg() {
    if(!img->Empty()){
        Mat greyScaledImg = Filter::convertToGrayScale(img->getOriginalImg());
        img->setProcessedImg(greyScaledImg);
        return Helpers::convertMatToPixmap(img->getProcessedImg());
    }
    return Helpers::convertMatToPixmap(Mat::zeros(1,1,CV_8UC1));
}


QPixmap ImageController::getProcessedImg() {
    if(!img->Empty()&&img->Processed()){
        return Helpers::convertMatToPixmap(this->img->getProcessedImg());
    }
    return Helpers::convertMatToPixmap(Mat::zeros(1,1,CV_8UC1));
}

QPixmap ImageController::FilterImg(Mat(*filter)(Mat img,int kernelSize),int kernelSize) {
    if(!img->Empty() && img->Processed()){
        Mat res = filter(img->getProcessedImg(),kernelSize);
        return Helpers::convertMatToPixmap(res);
    }
    return Helpers::convertMatToPixmap(Mat::zeros(1,1,CV_8UC1));
}

QPixmap ImageController::addNoise(int noiseType, int r, float mean, float sigma) {
    if(!img->Empty()){
        Mat res;
        switch (noiseType) {
            case 1:
                res = Noise::uniformNoise(img->getOriginalImg());
                break;
            case 2:
                res = Noise::saltAndPepperNoise(img->getProcessedImg(),r);
                break;
            case 3:
                res = Noise::gasussianNoise(img->getOriginalImg(),mean,sigma);
                break;
            default:
                res = img->getOriginalImg();
                break;
        }
        img->setProcessedImg(res);

        qDebug()<<"Ahmed";
        return Helpers::convertMatToPixmap(res);
    }
    return Helpers::convertMatToPixmap(Mat::zeros(1,1,CV_8UC1));
}








