#include "regiongrowingcontroller.h"

RegionGrowingController::RegionGrowingController():Controller() {}

QPixmap RegionGrowingController::growSeedPoints(vector<pair<int,int>> seedPoints, int threshold)
{
    Mat img = this->img->getOriginalImg();
    Mat res;
    res = RegionGrowing::growSeedPoints(img, seedPoints, threshold);
    return Helpers::convertMatToPixmap(res);
}
