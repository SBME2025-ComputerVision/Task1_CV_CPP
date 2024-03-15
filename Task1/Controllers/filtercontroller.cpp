#include "filtercontroller.h"
#include "Helpers/helpers.h"
#include"config.h"

FilterController::FilterController():Controller() {

}

QPixmap FilterController::addNoise(int noiseType, int r, float mean, float sigma){
    if(!img->isEmpty()&&img->isProcessed()){
        Mat res;
        switch (noiseType) {
            case UniformNoise:
            res = Noise::uniformNoise(processedImg);
                break;
            case SaltAndPepperNoise:
                res = Noise::saltAndPepperNoise(processedImg,r);
                break;
            case GaussianNoise:
                res = Noise::gasussianNoise(processedImg,mean,sigma);
                break;
            default:
                res = img->getOriginalImg();
                break;
        }
        processedImg = res;
        return Helpers::convertMatToPixmap(processedImg);
    }
    return Helpers::convertMatToPixmap(Mat::zeros(1,1,CV_8UC1));
}

QPixmap FilterController::filterImg(int filterType, int kernelSize){
    if(!img->isEmpty()&&img->isProcessed()){
        Mat res;
        switch (filterType) {
            case AvgFilter:
                res = Filter::avgFilter(processedImg,kernelSize);
                break;
            case MedianFilter:
                res = Filter::medianFilter(processedImg,kernelSize);
                break;
            case GaussianFilter:
                res = Filter::gaussionFilter(processedImg,kernelSize);
                break;
            default:
                res = img->getOriginalImg();
                break;
        }
        processedImg = res;
        return Helpers::convertMatToPixmap(processedImg);
    }
    return Helpers::convertMatToPixmap(Mat::zeros(1,1,CV_8UC1));
}
