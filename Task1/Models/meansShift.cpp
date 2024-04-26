#include"meansShift.h"
#include<math.h>

MeansShift::MeansShift()
{
}

void MeansShift::meanShiftPointAccumelate(Pixel* original, Pixel point)
{
    original->x+=point.x;
    original->y+=point.y;
    original->l+=point.l;
    original->a+=point.a;
    original->b+=point.b;

}

void MeansShift::meanShiftSetPoint(Pixel *point, float x, float y, float l, float a, float b)
{
    point->x=x;
    point->y=y;
    point->l=l;
    point->a=a;
    point->b=b;

}

void MeansShift::meanShiftCopyPoint(Pixel *point1, Pixel *point2)
{
    point1->x=point2->x;
    point1->y=point2->y;
    point1->l=point2->l;
    point1->a=point2->a;
    point1->b=point2->b;

}

float MeansShift::meanShiftColorDistance(Pixel point1, Pixel point2)
{
    return sqrt((point1.l-point2.l)*(point1.l-point2.l)+(point1.a-point2.a)*(point1.a-point2.a)+(point1.b-point2.b)*(point1.b-point2.b));
}

float MeansShift::meanShiftSpatialDistance(Pixel point1, Pixel point2)
{
    return sqrt((point1.x-point2.x)*(point1.x-point2.x)+(point1.y-point2.y)*(point1.y-point2.y));
}

void MeansShift::meanShiftPointRGB(Pixel *point)
{
    point->l=point->l*255/100;
    point->a+=128;
    point->b+=128;
}

void MeansShift::meanShiftPointToLab(Pixel *point)
{
    point->l=point->l*100/255;
    point->a-=128;
    point->b-=128;
}

void MeansShift::meanShiftPointScale(Pixel *point, float scale)
{
    point->x*=scale;
    point->y*=scale;
    point->l*=scale;
    point->a*=scale;
    point->b*=scale;
}

cv::Mat MeansShift::meanShiftSegmentation(Mat Img, float distanceBandwidth, float colorBandwidth)
{
    Mat ImgOut=Img.clone();
    cvtColor(ImgOut,ImgOut,COLOR_BGR2Lab);
    int ROWS=Img.rows;
    int COLS=Img.cols;
    vector<Mat>ImgChannels(3);
    split(ImgOut,ImgChannels); // split LAB color
    Pixel currentPoint;
    Pixel prevPoint;
    Pixel pointSum; // sum vector of the shift
    Pixel point;
    int left; // left boundary
    int right;
    int top;
    int bottom; // bottom boundary
    int pointsNumber; // number of points in a hypersphere
    int step;

    for(int i=0;i<ROWS;i++){
        for(int j=0;i<COLS;j++){
            left=(j-distanceBandwidth)>0?(j-distanceBandwidth):0;
            right=(j+distanceBandwidth)<COLS?(j+distanceBandwidth):COLS;
            top=(i-distanceBandwidth)>0?(i-distanceBandwidth):0;
            bottom=(i+distanceBandwidth)<ROWS?(i+distanceBandwidth):ROWS;
            meanShiftSetPoint(&currentPoint,i,j,(float)ImgChannels[0].at<uchar>(i,j),(float)ImgChannels[1].at<uchar>(i,j),(float)ImgChannels[2].at<uchar>(i,j));

        }
    }

}

