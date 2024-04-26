#include "UI/mainwindow.h"
#include "Models/kmeans.h"
#include <opencv2/opencv.hpp>
#include <QApplication>
#include <QFile>

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
     //




     return a.exec();

    // Mat img = imread("./Gallery/tiger.png");
    // Mat result = Kmeans::KmeansClustering(img, 6);
    // imwrite("./Gallery/tiger_kmeans.png", result);
    return 5;
}
