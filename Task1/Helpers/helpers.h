#ifndef HELPERS_H
#define HELPERS_H

#include<QPixmap>
#include<QFileDialog>
#include<QLabel>
#include<opencv2/opencv.hpp>
using namespace cv;
class Helpers
{
public:
    Helpers();
    ~Helpers();
    static Mat readImageMat();
    static QPixmap convertMatToPixmap(Mat img);
    static void displayImg(Mat newImg,  QLabel *label);
};

#endif // HELPERS_H
