#include "houghcontroller.h"
#include "Helpers/helpers.h"


HoughController::HoughController():Controller()
{

}

QPixmap HoughController::detectLines(int threshold)
{
    Mat res;
    res = HoughTransform::detectLines(img->getOriginalImg(),threshold);
    return Helpers::convertMatToPixmap(res);

}

QPixmap HoughController::detectCircles(int threshold ,int minRadius, int maxRadius)
{
    Mat res;
    res = HoughTransform::Hough_Circle_Transform(img->getOriginalImg(),threshold,minRadius,maxRadius);
    return Helpers::convertMatToPixmap(res);
}

QPixmap HoughController::detectEllipses(unsigned int nmb_of_ellipses, unsigned int minimised_size)
{
    Mat res;
    res = HoughTransform::elipseTransform(img->getOriginalImg());
    return Helpers::convertMatToPixmap(res);
}
