#include "image.h"
#include "config.h"

Image::Image() {

}

Image::Image(string pth){
    this->loadImage(pth);
}

void Image::loadImage(){
    this->img = imread(palestinePth,IMREAD_COLOR);
    this->empty = this->img.empty();
}

void Image::loadImage(string pth){
    this->img = imread(pth,IMREAD_COLOR);
    this->empty = this->img.empty();
}


Mat Image::getImage(){
    return this->img;
}

bool Image::isEmpty(){
    return this->empty;
}



