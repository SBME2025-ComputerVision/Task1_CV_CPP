#include "UI/mainwindow.h"
#include "Models/houghtransform.h"
#include <opencv2/opencv.hpp>
#include <QApplication>
#include <QFile>



int main(int argc, char *argv[])
{
    // QApplication  a(argc, argv);
    // MainWindow w;
    //  w.setWindowState(Qt::WindowMaximized);
    // w.show();


    // //  import style sheets
    //     QFile file("ManjaroMix.qss");
    //     file.open(QFile::ReadOnly);

    //     QString styleSheet { QLatin1String(file.readAll()) };

    //     //setup stylesheet
    //     a.setStyleSheet(styleSheet);
    // //


    // return a.exec();

    Image* img = new Image("./Gallery/f.jpg");

    Mat ori = img->getOriginalImg();
    Mat v = HoughTransform::detectLines(ori,150);

    imwrite("beta3y.jpg",v);
    return 5;
}
