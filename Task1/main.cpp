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

    Image* cat = new Image("./Gallery/whale.jpg");

    imwrite("orignal.jpg",cat->getOriginalImg());
    imwrite("grey.jpg",Filter::convertToGrayScale(cat->getOriginalImg()));

    Mat grey = Filter::convertToGrayScale(cat->getOriginalImg());

    Mat dftImg = Fourier::applyDFT(grey);

   dftImg = Fourier::applyShifting(dftImg);

    Mat planes[2];
    split(dftImg,planes);

    Mat mag, phaz;

    magnitude(planes[0],planes[1],mag);
    phase(planes[0],planes[1],phaz,true);




    Mat img = Fourier::applyIDFT(phaz);



    imwrite("inversing.jpg",img);
    return 0;


}
