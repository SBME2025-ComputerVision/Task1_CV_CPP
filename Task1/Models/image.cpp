#include "image.h"

Image::Image() {
    empty = true;
    processed = false;
}
Image::Image(string pth){
    Mat opImg = imread(pth,IMREAD_COLOR);
    if(!opImg.empty()){
        setOriginalImg(opImg,pth);
    }else{
        qDebug()<<"Bad img path";
    }
    processed = false;
}
Image::Image(Mat img,string pth){
    setOriginalImg(img,pth);
    processed = false;
}
Mat Image::getOriginalImg(){
    return originalImg;
}

void Image::setOriginalImg(Mat img,string pth){
    if(!img.empty() && !pth.empty()){
        originalImg = img.clone();
        empty = false;
        imgPth = pth;
        qDebug()<<"Set Original image successfully";
    }else{
        qDebug()<<"Set Original image Error";
    }
}

void Image::setIsProcessed(bool processed){
    this->processed = processed;
}

bool Image::isEmpty(){
    return empty;
}
bool Image::isProcessed(){
    return processed;
}
