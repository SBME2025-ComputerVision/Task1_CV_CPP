#include"meansshiftcontroller.h"
#include"Helpers/helpers.h"
#include"config.h"
#include"Models/meansshift.h"

QPixmap MeansShiftController::getMeansShiftSegmentedImg(float distanceBandwidth,float colorBandwidth)
{
    if(img->isEmpty())return  Helpers::convertMatToPixmap(Mat::zeros(1,1,CV_8UC1));

     Mat res=MeansShift::meanShiftSegmentation(img->getOriginalImg(),distanceBandwidth,colorBandwidth);
     processedImg=res;
     return Helpers::convertMatToPixmap(processedImg);

}

