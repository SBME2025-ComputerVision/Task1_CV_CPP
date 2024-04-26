#include "UI/mainwindow.h"
#include "Models/houghtransform.h"
#include <opencv2/opencv.hpp>
#include"Models/meansShift.h"
#include"config.h"
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


//     return a.exec();
         double bandwidth=45;
         Image *hello=new Image("./Gallery/kmeans.jpg");

         Mat image=meanShift_Segmentation(hello->getOriginalImg(),10,20);
         imwrite("meanShift.jpg",image);




    return 5;
}
