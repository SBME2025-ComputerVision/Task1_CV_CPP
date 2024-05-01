#ifndef KMEANSCONTROLLER_H
#define KMEANSCONTROLLER_H
#include "controller.h"

class KmeansController : public Controller
{
public:
    KmeansController();
    QPixmap kmeanClustering( int k);
};

#endif // KMEANSCONTROLLER_H
