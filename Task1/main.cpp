#include "UI/mainwindow.h"
#include<opencv2/opencv.hpp>
#include<Models/image.h>
#include<Models/filter.h>
#include<Models/noise.h>
#include<Models/histogram.h>
#include"config.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

    Image *mama = new Image("Gallery/cat.jpg");
     imwrite("original.jpg", mama->getOriginalImg());

     // Histogram::normalize_img(cur);
     Mat original=mama->getOriginalImg();
     // Mat norm=Histogram::normalize_img(original);
     // Mat cur= Histogram::calculate_histogram(original);
     Histogram::rgbHistogram(original);

//     Mat distCurve=Histogram::distributionCurve(cur);
//     Mat plot=Histogram::plotHistogram(cur,100,147,111);
    // Mat cur = Histogram::normalize_img(mama->getOriginalImg());
//     imwrite("saltAndPepperNoise.jpg",cur);
     return 0;


    return 0;


}
