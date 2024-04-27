#include "agglomerativecontroller.h"
#include "config.h"
#include "Models/agglomerative.h"
#include "Helpers/helpers.h"

AgglomerativeController::AgglomerativeController() {}


QPixmap AgglomerativeController::aggClustering(int k){

    Mat res,pixels,resizedImg;
    res = img->getOriginalImg(); // Retrieves the original image
    auto result  = Agglomerative::image_preperation(res);
    res = Agglomerative::image_color_segmentation(k,result.first,result.second);
   
    res.convertTo(res,CV_8UC1); // Converts the image to the appropriate format
    processedImg = res;
    return Helpers::convertMatToPixmap(processedImg);
}
