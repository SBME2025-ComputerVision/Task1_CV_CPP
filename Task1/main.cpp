#include "UI/mainwindow.h"
#include<opencv2/opencv.hpp>
#include<Models/image.h>
#include"config.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    // QApplication a(argc, argv);
    // MainWindow w;
    // w.show();
    // return a.exec();
    Image *mama = new Image("cat.jpg");
    qDebug() << mama->Empty();
    cv::imshow("anateez",mama->getOriginalImg());

}
