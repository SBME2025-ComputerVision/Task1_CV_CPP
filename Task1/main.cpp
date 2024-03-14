#include "UI/mainwindow.h"
#include<opencv2/opencv.hpp>
#include<Models/image.h>
#include<Models/filter.h>
#include<Models/noise.h>
#include<Models/histogram.h>
#include<Models/fourier.h>
#include"config.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    // QApplication a(argc, argv);
    // MainWindow w;
    // w.show();
    // return a.exec();

    Image* cat = new Image("./Gallery/cat.jpg");

    imwrite("orignal.jpg",cat->getOriginalImg());
    imwrite("grey.jpg",Filter::convertToGrayScale(cat->getOriginalImg()));

    Mat grey = Filter::convertToGrayScale(cat->getOriginalImg());

    Mat dftImg = Fourier::applyDFT(grey);

    Mat planes[2];

    split(dftImg,planes);

    Mat real,imaginary,mag,phase;

    real = planes[0];
    imaginary = planes[1];

    magnitude(real,imaginary,mag);
    cv::phase(real,imaginary,phase);


    imwrite("dftImg.jpg",phase);

    return 0;


}
