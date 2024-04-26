#include"meansShift.h"
#include<math.h>

MeansShift::MeansShift()
{
}

void MeansShift::meanShiftPointAccumelate(Pixel* original, Pixel point)
{
    original->x+=point.x;
    original->y+=point.y;
    original->l+=point.l;
    original->a+=point.a;
    original->b+=point.b;

}

