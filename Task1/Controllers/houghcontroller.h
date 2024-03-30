#ifndef HOUGHCONTROLLER_H
#define HOUGHCONTROLLER_H
#include "controller.h"
#include "config.h"


class HoughController : public Controller
{
public:
    HoughController();
    QPixmap detectLines(int threshold);
};

#endif // HOUGHCONTROLLER_H
