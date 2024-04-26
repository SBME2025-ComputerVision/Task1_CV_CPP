#include <math.h>
#include <opencv2\opencv.hpp>
#include <vector>
#include <iostream>
#include"config.h"


using namespace cv;
using namespace std;

#define MEANSHIFT_MAX_NUMBER_OF_ITERATION_STEPS

struct Pixel{
    float x; // x coordinate of the point - spatial value
    float y; // y coordinate of the point - spatial value
    float l; // Lab
    float a; // Lab
    float b; // Lab
};

class MeansShift{
    MeansShift();
    static void meanShiftPointAccumelate(Pixel*,Pixel);
    static void meanShiftSetPoint(Pixel*,float,float,float,float,float);
    static void meanShiftCopyPoint(Pixel*,Pixel*);
    static float meanShiftColorDistance(Pixel,Pixel);
    static float meanShiftSpatialDistance(Pixel,Pixel);
    static Mat meanShiftSegmentation(Mat,float,float);
    static void meanShiftPointRGB(Pixel*);
    static void meanShiftPointToLab(Pixel*);
    static void meanShiftPointScale(Pixel*,float);

};
