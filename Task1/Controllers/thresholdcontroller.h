#ifndef THRESHOLDCONTROLLER_H
#define THRESHOLDCONTROLLER_H
#include "controller.h"
class ThresholdController :public Controller
{
public:
    ThresholdController();
    QPixmap localThresholdFilter();
    QPixmap globalThresholdFilter();
};

#endif // THRESHOLDCONTROLLER_H
