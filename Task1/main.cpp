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
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();



    // Image* cat = new Image("./Gallery/whale.jpg");

    // imwrite("orignal.jpg",cat->getOriginalImg());

    // Mat grey = Filter::convertToGrayScale(cat->getOriginalImg());
    // imwrite("grey.jpg",grey);

    // Mat saltandpeper = Noise::saltAndPepperNoise(grey,15);

    // imwrite("salt.jpg",saltandpeper);


    // Mat res = Frequency::applyFrequencyFilter(grey, 10,1);

    // imwrite("yarab.jpg",res);


    // Mat dftImg = Fourier::applyDFT(grey);

    // Mat planes[2];
    // split(dftImg,planes);

    // Mat mag, phaz;

    // magnitude(planes[0],planes[1],mag);
    // phase(planes[0],planes[1],phaz,true);


    // log(mag,mag);
    // mag *=20;
    // normalize(mag,mag,0,1,NORM_MINMAX);
    // Mat real, imag;
    // real = Fourier::applyShifting(planes[0]);
    // imag = Fourier::applyShifting(planes[1]);


    // int cx = real.cols / 2;
    // int cy = real.rows / 2;


    // int radius = 100;



    // // Create a mask to zero out frequencies outside the central region
    // Mat mask = Mat::zeros(mag.size(), CV_8U);

    // circle(mask, Point(cx, cy), radius, Scalar(255), -1);

    // Mat highPassMask;
    // bitwise_not(mask, highPassMask);


    // real.setTo(Scalar(0), ~mask);
    // imag.setTo(Scalar(0), ~mask);

    // Mat shifted_DFT_plane_img[] = {real ,imag };

    // Mat MergeImg;
    // merge(shifted_DFT_plane_img, 2, MergeImg);




    // Mat img = Fourier::applyIDFT(MergeImg);



    // imwrite("inversing.jpg",img);
    return 0;


}
