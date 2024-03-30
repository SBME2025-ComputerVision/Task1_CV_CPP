#ifndef HOUGHCONTROLLER_H
#define HOUGHCONTROLLER_H
#include "controller.h"
#include "config.h"


class HoughController : public Controller
{
public:
    HoughController();
    QPixmap detectLines(int threshold);
    QPixmap detectCircles(int threshold,int minRadius , int maxRadius);
    QPixmap detectEllipses(unsigned int nmb_of_ellipses = 1,unsigned int minimised_size = 128);
};

#endif // HOUGHCONTROLLER_H
