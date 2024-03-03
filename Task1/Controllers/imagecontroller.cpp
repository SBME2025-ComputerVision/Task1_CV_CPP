#include "imagecontroller.h"
#include"config.h"

ImageController::ImageController() {
    this->img = new Image();
}
Mat ImageController::uploadImg(){
    QString appDirPath = QCoreApplication::applicationDirPath();
    QString path = QFileDialog::getOpenFileName(nullptr, "Choose an Image", appDirPath);

    if(!path.isEmpty()){
        this->img->loadImage(path.toStdString());
        if(!this->img->Empty()){
            return this->img->getOriginalImg();
        }

    }
    return Mat::zeros(1,1,CV_8UC1);

}

