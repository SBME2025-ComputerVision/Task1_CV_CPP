#include "kmeanscontroller.h"
#include "config.h"
#include "Models/kmeans.h"
#include "Helpers/helpers.h"

KmeansController::KmeansController():Controller() {}

QPixmap KmeansController::kmeanClustering(int k){

    Mat res;
    res = img->getOriginalImg(); // Retrieves the original image
    res = Kmeans::KmeansClustering(res,k); // Applies k-means clustering
    res.convertTo(res,CV_8UC1); // Converts the image to the appropriate format
    processedImg = res;
    return Helpers::convertMatToPixmap(processedImg); // Converts the processed image to QPixmap


}
