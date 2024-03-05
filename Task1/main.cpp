#include "UI/mainwindow.h"
#include<opencv2/opencv.hpp>
#include<Models/image.h>
#include<Models/filter.h>
#include<Models/noise.h>
#include"config.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

    // Image *mama = new Image("Gallery/cat.jpg");
    // imwrite("original.jpg", mama->getOriginalImg());
    // Mat avgFilter = Filter::avgFilter(mama->getOriginalImg(),5);
    // mama->setProcessedImg(avgFilter);
    // imwrite("myAvg.jpg",avgFilter);

    // Mat medianFilter = Filter::medianFilter(mama->getOriginalImg(),5);
    // mama->setProcessedImg(medianFilter);
    // imwrite("myMedian.jpg",medianFilter);

    // Mat gaussianFilter = Filter::gaussionFilter(mama->getOriginalImg(),5);
    // mama->setProcessedImg(gaussianFilter);
    // imwrite("myGaussian.jpg",gaussianFilter);

    // Mat opencvAvgFilter = Filter::opencvAvgFilter(mama->getOriginalImg(),5);
    // mama->setProcessedImg(opencvAvgFilter);
    // imwrite("opencvAvg.jpg",opencvAvgFilter);

    // Mat opencvMedianFilter = Filter::opencvMedianFilter(mama->getOriginalImg(),5);
    // mama->setProcessedImg(opencvMedianFilter);
    // imwrite("opencvMedian.jpg",opencvMedianFilter);

    // Mat opencvGaussianFilter = Filter::opencvGaussianFilter(mama->getOriginalImg(),5);
    // mama->setProcessedImg(opencvGaussianFilter);
    // imwrite("opencvGaussian.jpg",opencvGaussianFilter);

    // Mat uniformNoise = Noise::uniformNoise(mama->getOriginalImg());
    // mama->setProcessedImg(uniformNoise);
    // imwrite("uniformNoise.jpg",uniformNoise);

    // Mat gaussianNoise = Noise::gasussianNoise(mama->getOriginalImg(),0,10);
    // mama->setProcessedImg(gaussianNoise);
    // imwrite("gaussianNoise.jpg",gaussianNoise);

    // Mat saltAndPepperNoise = Noise::saltAndPepperNoise(mama->getOriginalImg(),0.5,0.7);
    // mama->setProcessedImg(saltAndPepperNoise);
    // imwrite("saltAndPepperNoise.jpg",saltAndPepperNoise);



    return 0;


}
