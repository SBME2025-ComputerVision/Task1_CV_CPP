// Use this file in cpp files to avoid Circular Depnd.
#ifndef CONFIG_H
#define CONFIG_H

#include <bits/stdc++.h>
#include<opencv2/opencv.hpp>
#include"Models/noise.h"
#include"Models/filter.h"
#include "Models/image.h"
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

extern const int FilterPage;
extern const int EdgeDetectionPage;
extern const int HistogramPage;
extern const int ThresholdingPage;
extern const int HybridPage;
#endif // CONFIG_H
