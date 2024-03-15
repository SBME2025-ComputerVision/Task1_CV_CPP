#include "helpers.h"
#include "config.h"

Helpers::Helpers() {}
Helpers::~Helpers(){}

// QPixmap Helpers::convertMatToPixmap (Mat img){
//     QPixmap outputPixmapImage;
//     QImage  curImg(img.data, img.cols,img.rows,static_cast<int>(img.step),QImage::Format_BGR888);
//     outputPixmapImage = QPixmap::fromImage(curImg);
//     return outputPixmapImage;
// }

QPixmap Helpers::convertMatToPixmap(Mat imageMat){

    QPixmap outputPixmap;

    // Check the image type
    switch(imageMat.type())
    {
    // Colored Image
    case CV_8UC3:
    {
        QImage qimage(imageMat.data, imageMat.cols, imageMat.rows, static_cast<int>(imageMat.step), QImage::Format_BGR888);
        outputPixmap = QPixmap::fromImage(qimage);
        break;
    }
        // Grayscale Image
    case CV_8UC1:
    {
        QImage qimage(imageMat.data, imageMat.cols, imageMat.rows, static_cast<int>(imageMat.step), QImage::Format_Grayscale8);
        outputPixmap = QPixmap::fromImage(qimage.rgbSwapped());
        break;
    }

        // float 32 Image
    case CV_32F:
    {
        // scaled image
        Mat scaled_image;
        double min_val, max_val;

        // get max & min value of the image
        minMaxLoc(imageMat, &min_val, &max_val);

        // convert image into grayscale 8bit image
        double scale_factor = 255.0 / (max_val - min_val);
        imageMat.convertTo(scaled_image, CV_8UC1, scale_factor, -scale_factor * min_val);

        QImage qimage(scaled_image.data,
                      scaled_image.cols,
                      scaled_image.rows,
                      static_cast<int>(scaled_image.step),
                      QImage::Format_Grayscale8);

        outputPixmap = QPixmap::fromImage(qimage.rgbSwapped());
    }
    }
    return outputPixmap;
}
QString Helpers::  getImgPath(){
    QString appDirPath = QCoreApplication::applicationDirPath();
    QString path = QFileDialog::getOpenFileName(nullptr, "Choose an Image", appDirPath);
    return path;
}
