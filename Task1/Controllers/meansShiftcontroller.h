#ifndef MEANSSHIFTCONTROLLER_H
#define MEANSSHIFTCONTROLLER_H
#include"controller.h"

class MeansShiftController:public Controller{
public:
    MeansShiftController();
    QPixmap getMeansShiftSegmentedImg(Mat Img,float distanceBandwidth,float colorBandwidth);
};

#endif // MEANSSHIFTCONTROLLER_H
