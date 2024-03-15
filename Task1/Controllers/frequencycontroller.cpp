#include "frequencycontroller.h"
#include "Helpers/helpers.h"
#include "config.h"

FrequencyController::FrequencyController():Controller() {}

QPixmap FrequencyController::frequencyFilter(int radius, int Filter){
    if(!img->isEmpty()&&img->isProcessed()){
        Mat res;
        res = img->getOriginalImg();
        res= Filter::convertToGrayScale(res);
        res = Filter::applyFrequencyFilter(res, radius, Filter);
        res.convertTo(res,CV_8UC1);
        processedImg = res;
        return Helpers::convertMatToPixmap(processedImg);
    }
}
