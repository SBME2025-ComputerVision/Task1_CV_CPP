#include "image.h"

/**
 * @brief Default constructor.
 *
 * Initializes an empty image.
*/

Image::Image() {
    empty = true;
    processed = false;
}

/**
 * @brief Constructor that takes a file path as input.
 *
 * Reads the image from the given path.
 *
 * @param pth Path to the image file.
*/
Image::Image(string pth){
    Mat opImg = imread(pth,IMREAD_COLOR);
    if(!opImg.empty()){
        setOriginalImg(opImg,pth);
    }else{
        qDebug()<<"Bad img path";
    }
    processed = false;
}

/**
 * @brief Constructor that takes an image and a file path as input.
 *
 * @param img The input image.
 * @param pth Path to the image file.
*/
Image::Image(Mat img,string pth){
    setOriginalImg(img,pth);
    processed = false;
}
/**
 * @brief Get the original image.
 *
 * @return Original image.
*/
Mat Image::getOriginalImg(){
    return originalImg;
}
/**
 * @brief Set the original image data.
 *
 * @param img Original image.
 * @param pth Path to the image file.
*/
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

/**
 * @brief Set the processed status of the image.
 *
 * @param processed Processed status.
*/

void Image::setIsProcessed(bool processed){
    this->processed = processed;
}
/**
 * @brief Check if the image is empty.
 *
 * @return True if the image is empty, otherwise false.
*/
bool Image::isEmpty(){
    return empty;
}
/**
 * @brief Check if the image has been processed.
 *
 * @return True if the image has been processed, otherwise false.
*/
bool Image::isProcessed(){
    return processed;
}
