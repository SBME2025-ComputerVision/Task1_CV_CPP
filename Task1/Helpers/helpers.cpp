#include "helpers.h"

Helpers::Helpers() {}
Helpers::~Helpers(){}

QPixmap Helpers::convertMatToPixmap (Mat img){
    QPixmap outputPixmapImage;
    QImage  curImg(img.data, img.cols,img.rows,static_cast<int>(img.step),QImage::Format_BGR888);
    outputPixmapImage = QPixmap::fromImage(curImg);
}
