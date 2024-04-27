#ifndef REGIONGROWINGCONTROLLER_H
#define REGIONGROWINGCONTROLLER_H

#include "controller.h"
#include "Helpers/helpers.h"
#include "Models/regiongrowing.h"

class RegionGrowingController : public Controller
{
public:
    RegionGrowingController();
    QPixmap growSeedPoints(vector<pair<int,int>> seedPoints, int threshold);
};

#endif // REGIONGROWINGCONTROLLER_H
