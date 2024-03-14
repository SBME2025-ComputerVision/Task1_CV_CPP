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
    // QApplication a(argc, argv);
    // MainWindow w;
    // w.show();
    // return a.exec();

    Image *mama = new Image("Gallery/output.jpg");
    imwrite("original.jpg", mama->getOriginalImg());
    // Mat avgFilter = Filter::avgFilter(mama->getOriginalImg(),5);
    // mama->setProcessedImg(avgFilter);
    // imwrite("myAvg.jpg",avgFilter);


    // Mat cur =mama->getOriginalImg();
    // Histogram::normalize_img(cur);
    Mat original=mama->getOriginalImg();
    // Mat norm=Histogram::normalize_img(original);
    Mat cur= Histogram::calculate_histogram(original);
    Mat distCurve=Histogram::distributionCurve(cur);
    Mat plot=Histogram::plot_histogram(cur,100,147,111);
   // Mat cur = Histogram::normalize_img(mama->getOriginalImg());
    mama->setProcessedImg(distCurve);
    imwrite("saltAndPepperNoise.jpg",distCurve);
    return 0;


}
