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

    // Image *mama = new Image("Gallery/whale.jpg");
    // Noise *noise = new Noise();
    // imwrite("original.jpg", mama->getOriginalImg());

    // Mat grey = Filter::convertToGrayScale(mama->getOriginalImg());

    // Mat res = noise->saltAndPepperNoise(grey,15);

    // imwrite("res.jpg",res);


    return 0;


}
