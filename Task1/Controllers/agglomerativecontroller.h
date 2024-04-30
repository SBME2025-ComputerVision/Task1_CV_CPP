#ifndef AGGLOMERATIVECONTROLLER_H
#define AGGLOMERATIVECONTROLLER_H
#include "controller.h"

class AgglomerativeController: public Controller
{
public:
    AgglomerativeController();
    QPixmap aggClustering(int k);
};

#endif // AGGLOMERATIVECONTROLLER_H
