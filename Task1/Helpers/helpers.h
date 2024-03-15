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
    static QString openFile();
    static QPixmap convertMatToPixmap(Mat img);
    
};

#endif // HELPERS_H
