#include "UI/mainwindow.h"
#include "Models/houghtransform.h"
#include <opencv2/opencv.hpp>
#include <QApplication>
#include <QFile>
#include "snake.h"



int main(int argc, char *argv[])
{
     QApplication  a(argc, argv);
     MainWindow w;
      w.setWindowState(Qt::WindowMaximized);
     w.show();


     //  import style sheets
         QFile file("ManjaroMix.qss");
         file.open(QFile::ReadOnly);

         QString styleSheet { QLatin1String(file.readAll()) };

         //setup stylesheet
         a.setStyleSheet(styleSheet);
         // Mat ssssnakeTry = imread("./Gallery/snakeTry.png");


            Image* img = new Image("./Gallery/snakeTry.png");

            Mat ssssnakeTry = img->getOriginalImg();

         Point Ptry;
         Ptry.x = 100;
         Ptry.y = 100;
         // Snake anaElTho3ban();
         vector<Point> resultCurve = Snake::activeContour(ssssnakeTry, Ptry, 20, 100, 10.0,10.0,10.0,10.0);
         imwrite("ana_el_tho3ban.jpg", ssssnakeTry);


     return a.exec();

//    Image* img = new Image("./Gallery/f.jpg");

//    Mat ori = img->getOriginalImg();
//    Mat v = HoughTransform::detectLines(ori,150);

//    imwrite("emad.jpg",v);
    return 0;
}
