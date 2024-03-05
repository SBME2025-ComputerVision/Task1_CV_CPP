#include "image.h"
#include "config.h"
#include<QDebug>
Image::Image() {
    this->isEmpty = true;
    this->isProcessed = false;
    setImgPath("");
}

Image::Image(string pth){
    this->loadImage(pth);
}


void Image::loadImage(string pth){
    this->originalImg = imread(pth,IMREAD_COLOR);
    if(this->originalImg.empty()){
        qDebug()<< "error";
    }
    setImgPath(pth);
    this->isProcessed = false;
    this->isEmpty = this->originalImg.empty();
}


Mat Image::getOriginalImg(){
    return this->originalImg;
}

Mat Image::getProcessedImg(){
    return this->processedImg;
}

void Image::setProcessedImg(Mat& img){
    this->processedImg = Mat::zeros(img.size(),img.type());
    this->isProcessed = true;
}


bool Image::Empty(){
    return this->isEmpty;
}

bool Image::Processed(){
    return this->isProcessed;
}

string Image::getImgPath(){
    return this->path;
}

void Image::setImgPath(string pth){
    this->path =  pth;;
}


