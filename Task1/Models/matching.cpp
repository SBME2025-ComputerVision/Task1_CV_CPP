#include "matching.h"

Matching::Matching()
{

}


void Matching::SumOfSqauredDiff(Mat img , Mat src, Rect & roi){
 Mat ret;
 int width = img.cols-src.cols+1;
 int height = img.rows-src.rows+1;
 ret.create(height,width,CV_32S);
 for(int i =0;i<height;i++){
     for(int j = 0;j<width;j++){
         Rect roiTemp = Rect(j,i,src.cols,img.cols);
         Mat roiToImg = img(roiTemp);
         Mat cur = roiToImg - src;
         cur = (cur*cur);
         cv::Scalar ans = cv::sum(cur);
         ret.at<int>(i,j) = ans.val[0];
     }
 }

 double p1Val,p2Val;
 cv::Point p1,p2;
 cv::minMaxLoc(ret, &p1Val,&p2Val,&p1,&p2);
 roi = cv::Rect(p1.x,p1.y,src.cols,src.rows);

}

void Matching::CrossCorrelation(Mat img, Mat src, Rect & roi){

 Mat ret;
 int width = img.cols-src.cols+1;
 int height = img.rows-src.rows+1;
  cv::Scalar srcMean,srcStd;
  cv::meanStdDev(src,srcMean,srcStd);
  ret.create(height,width,CV_32FC1);

  for(int i = 0; i<height;i++){
      for(int j=0;j<width;j++){
         cv::Rect roiTemp = cv::Rect(j,i,src.cols,src.rows);
         Mat roiToImg = img(roiTemp);
         cv::Scalar imgMean = cv::mean(roiToImg);
         double sum1=0,sum2=0;
         int cnt = 0;
         for(int k = 0;k<src.rows;k++){
             for(int m=0;m<src.cols;m++){
               sum1+= (roiToImg.at<uchar>(k,m)-imgMean[0]) *(src.at<uchar>(k,m) - srcMean[0]);
               sum2+= (roiToImg.at<uchar>(k,m)-imgMean[0]) *(roiToImg.at<uchar>(k,m)-imgMean[0]);
               cnt++;
             }
         }
       sum1 /=cnt;
       sum2 /=cnt;
       ret.at<float>(i,j) = sum1 / ( srcStd[0]* srcStd[0] *sum2 * sum2);
      }
  }
  double p1Val,p2Val;
  cv::Point p1,p2;
  cv::minMaxLoc(ret, &p1Val,&p2Val,&p1,&p2);
  roi = cv::Rect(p2.x,p2.y,src.cols,src.rows);

}


void Matching::applyMatching(Mat img1,Mat img2, vector<Vec3d>& matched){




}
