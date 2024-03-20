#ifndef HELPERS_H
#define HELPERS_H

#include<QPixmap>
#include<QFileDialog>
#include<QLabel>
#include<qstring.h>
#include<opencv2/opencv.hpp>
using namespace cv;
class Helpers
{
public:
    Helpers();
    ~Helpers();
    static QString getImgPath();
    static Mat readImageMat();
    static QString openFile();
    static QPixmap convertMatToPixmap(Mat img);
    static float  convertQstringToFloat(const QString input);
    
};

#endif // HELPERS_H
