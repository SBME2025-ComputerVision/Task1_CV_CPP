#include"meansshift.h"
#include<math.h>

MeansShift::MeansShift()
{
}

const int dxdy[][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};	// Region Growing

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

    // FILTERING

    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            left=(j-distanceBandwidth)>0?(j-distanceBandwidth):0;
            right=(j+distanceBandwidth)<COLS?(j+distanceBandwidth):COLS;
            top=(i-distanceBandwidth)>0?(i-distanceBandwidth):0;
            bottom=(i+distanceBandwidth)<ROWS?(i+distanceBandwidth):ROWS;
            meanShiftSetPoint(&currentPoint,i,j,(float)ImgChannels[0].at<uchar>(i,j),(float)ImgChannels[1].at<uchar>(i,j),(float)ImgChannels[2].at<uchar>(i,j));
            meanShiftPointToLab(&currentPoint);
            step=0;
            do{
                meanShiftCopyPoint(&prevPoint,&currentPoint);
                meanShiftSetPoint(&pointSum,0,0,0,0,0);
                pointsNumber=0;
                for(int hx=top;hx<bottom;hx++){
                    for(int hy=left;hy<right;hy++){
                        meanShiftSetPoint(&point,hx,hy,(float)ImgChannels[0].at<uchar>(hx, hy), (float)ImgChannels[1].at<uchar>(hx, hy), (float)ImgChannels[2].at<uchar>(hx, hy));
                        meanShiftPointToLab(&point);
                        if(meanShiftColorDistance(point,currentPoint)<colorBandwidth){
                            meanShiftPointAccumelate(&pointSum,point);
                            pointsNumber++;
                        }

                    }

                }
                meanShiftPointScale(&pointSum,1.0/pointsNumber);
                meanShiftCopyPoint(&currentPoint,&pointSum);
                step++;

            }while((meanShiftColorDistance(currentPoint,prevPoint)>MEANSHIFT_COLOR_THRESHOLD_TO_TERMINATE)&&(meanShiftSpatialDistance(currentPoint,prevPoint)>MEANSHIFT_SPATIAL_THRESHOLD_TO_TERMINATE)&&(step<MEANSHIFT_MAX_NUMBER_OF_ITERATION_STEPS));
            meanShiftPointRGB(&currentPoint);
            ImgOut.at<Vec3b>(i,j)=Vec3b(currentPoint.l,currentPoint.a,currentPoint.b);

        }
    }

    /*--------------------------------*/
    /* SEGMENTATION */
    int label=-1; // label number
    vector<float>mode(ROWS*COLS*3); // store the LAB color of each region
    vector<int>memberModeCount(ROWS*COLS,0); // store the number of each region
    split(ImgOut,ImgChannels);
    vector<vector<int>>labels(ROWS);  // optimize
    // Initialization
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            labels[i].push_back(-1);
        }
    }

    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            if(labels[i][j]<0){  // if the point is not labeled
                labels[i][j]=++label;  // give it a new label number
                meanShiftSetPoint(&currentPoint,i,j, (float)ImgChannels[0].at<uchar>(i, j), (float)ImgChannels[1].at<uchar>(i, j), (float)ImgChannels[2].at<uchar>(i, j));
                meanShiftPointToLab(&currentPoint);

                // store each value of the LAB
                mode[label*3+0]=currentPoint.l;
                mode[label*3+1]=currentPoint.a;
                mode[label*3+2]=currentPoint.b;

                // region growing 8 neighbors
                vector<Pixel>neighborPoints;
                neighborPoints.push_back(currentPoint);
                while(!neighborPoints.empty()){
                    point=neighborPoints.back();
                    neighborPoints.pop_back();

                    // get 8 neighbours
                    for(int k=0;k<8;k++){
                        int hx=point.x+dxdy[k][0];
                        int hy=point.y+dxdy[k][1];
                        if((hx>=0)&&(hy>=0)&&(hx<ROWS)&&(hy<COLS)&&(labels[hx][hy]<0)){
                            Pixel p;
                            meanShiftSetPoint(&p,hx, hy, (float)ImgChannels[0].at<uchar>(hx, hy), (float)ImgChannels[1].at<uchar>(hx, hy), (float)ImgChannels[2].at<uchar>(hx, hy));
                            meanShiftPointToLab(&p);

                            // check if color is smaller than threshold
                            if(meanShiftColorDistance(currentPoint,p)<colorBandwidth){
                                labels[hx][hy]=label; // give the pixel the same label
                                neighborPoints.push_back(p);
                                memberModeCount[label]++; // this region number + 1
                                mode[label*3+0]+=p.l;
                                mode[label*3+1]+=p.a;
                                mode[label*3+2]+=p.b;



                            }
                        }
                    }
                }
                memberModeCount[label]++;  // count the point itself
                mode[label*3+0]/=memberModeCount[label]; // get averge color
                mode[label*3+1]/=memberModeCount[label]; // get averge color
                mode[label*3+2]/=memberModeCount[label]; // get averge color
            }
        }
    }

    // get result image from the mode array
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            label=labels[i][j];
            float l=mode[label*3+0];
            float a=mode[label*3+1];
            float b=mode[label*3+2];
            Pixel pixel;
            meanShiftSetPoint(&pixel,i,j,l,a,b);
            meanShiftPointRGB(&pixel);
            ImgOut.at<Vec3b>(i,j)=Vec3b(pixel.l,pixel.a,pixel.b);
        }
    }
    cvtColor(ImgOut,ImgOut,COLOR_Lab2BGR);
    return ImgOut;


}


