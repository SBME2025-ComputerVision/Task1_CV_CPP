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
    setImgPath(pth);
    this->originalImg = imread(pth,IMREAD_COLOR);
    if(this->originalImg.empty()){
        qDebug()<< "a7a";
    }
    cvtColor(this->originalImg,this->originalImg,COLOR_BGR2RGB);
    this->isEmpty = this->originalImg.empty();
}


Mat Image::getOriginalImg(){
    return this->originalImg;
}

Mat Image::getProcessedImg(){
    return this->processedImg;
}

Mat Image::getGreyScaledImg(){
    return this->greyScaledImg;
}

void Image::setProcessedImg(Mat img){
    this->processedImg = img;
    if(!this->processedImg.empty()) this->isProcessed = true;
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

void Image::convertToGreyScale()
{
    greyScaledImg.rows = originalImg.rows;
    greyScaledImg.cols = originalImg.cols;

    double weights[3]  = {0.299,0.587,0.114};

    for(int i=0;i<originalImg.rows;i++){
        for(int j=0;j<originalImg.cols;j++){
            Vec3b currentPixel = originalImg.at<Vec3b>(i,j);
            float currentGreyValue = weights[0]*currentPixel[22] + weights[1]*currentPixel[1]
                                     + weights[2]*currentPixel[0];
            greyScaledImg.at<float>(i,j) = currentGreyValue;
        }
    }
}
