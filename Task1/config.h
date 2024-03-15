// Use this file in cpp files to avoid Circular Depnd.
#ifndef CONFIG_H
#define CONFIG_H

#include <bits/stdc++.h>
#include<opencv2/opencv.hpp>
#include"Models/noise.h"
#include"Models/filter.h"
#include "Models/image.h"
#include "Models/fourier.h"
#include "Models/frequency.h"
#include <QString>
#include <QFileDialog>
#include <QCoreApplication>
#include <QDir>

using namespace std;
using namespace cv;
// externs

extern string birdPth;
extern string catPth;
extern string cutiePth;
extern string palestinePth;
extern string whalePth;

 enum NoiseType{
    UniformNoise = 1,
    SaltAndPepperNoise = 2,
    GaussianNoise = 3
};

 enum FilterType{
    AvgFilter = 1,
    MedianFilter,
    GaussianFilter,
    HighPassFilter,
    LowPassFilter
};

 enum Pages{
    FilterPage = 0,
    EdgeDetectionPage = 1,
    HistogramPage = 2,
    ThresholdingPage = 3,
    HybridPage = 4,
    FrequencyPage = 5
};
#endif // CONFIG_H
