#include "UI/mainwindow.h"
#include "Models/houghtransform.h"
#include <opencv2/opencv.hpp>
#include <QApplication>
#include <QFile>
#include <Models/sift.h>


int main(int argc, char *argv[])
{
//     QApplication  a(argc, argv);
//     MainWindow w;
//      w.setWindowState(Qt::WindowMaximized);
//     w.show();


//     //  import style sheets
//         QFile file("ManjaroMix.qss");
//         file.open(QFile::ReadOnly);

//         QString styleSheet { QLatin1String(file.readAll()) };

//         //setup stylesheet
//         a.setStyleSheet(styleSheet);
//     //


//     return a.exec();

//    Image* img = new Image("./Gallery/f.jpg");

//    Mat ori = img->getOriginalImg();
//    Mat v = HoughTransform::detectLines(ori,150);

//    imwrite("emad.jpg",v);

    Mat img, scr, base_img;

        img = imread("./Gallery/match_images/0.png");
        img.convertTo(scr, CV_32FC1);

        int num_intervals = 3;
        double sigma = 1.6;
        SIFTX *mama = new SIFTX();

        base_img = mama->baseLineImage(scr);

        vector<double> sigmas = mama->generateSigmaValues(sigma, num_intervals);
        tuple<vector<vector<Mat>>, vector<vector<Mat>>> Scale_DoG = mama->generateGaussianPyramid(base_img, num_intervals, sigmas);
        vector<KeyPoint> keypoints = mama->getKeyPoints(get<1>(Scale_DoG), get<0>(Scale_DoG), num_intervals, sigma);
        vector<Mat> key_descriptors = mama->getDescriptors(keypoints, get<0>(Scale_DoG));

    return 5;
}
