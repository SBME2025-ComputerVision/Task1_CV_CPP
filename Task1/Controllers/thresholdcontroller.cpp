#include "thresholdcontroller.h"
#include "config.h"
#include "Helpers/helpers.h"

ThresholdController::ThresholdController() {}


QPixmap ThresholdController::ThresholdingFilter(int ThresholdingType,int ThresholdValue , int ThresholdkernelSize, int CParam){
    Mat res;
    switch (ThresholdingType) {
    case LocalThresholding:
        res = Threshold::localThresholding(processedImg,ThresholdkernelSize,CParam);
        break;
    case GlobalThresholding:
        res = Threshold::globalThresholding(processedImg,ThresholdValue);
        break;
    case OptimumThresholding:
        res = Threshold::optimumThresholding(img->getOriginalImg(),true);
        break;
    case OtsuThresholding:
        res = Threshold::otsuThresholding(img->getOriginalImg(),true);
        break;
    case SpectralThresholding:
        res = Threshold::spectralThresholding(img->getOriginalImg(),true);
        break;
    case LocalOptimum:
        res = Threshold::localOptimum(img->getOriginalImg());
        break;
    case LocalOtsu:
        res = Threshold::localOtsu(img->getOriginalImg());
        break;
    case LocalSpectral:
        res = Threshold::localspectral(img->getOriginalImg());
        break;
    default:
        res = img->getOriginalImg();
        break;
    }
    return Helpers::convertMatToPixmap(res);
}
