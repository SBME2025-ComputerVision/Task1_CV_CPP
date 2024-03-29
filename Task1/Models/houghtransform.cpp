#include "houghtransform.h"
#include <bits/stdc++.h>



HoughTransform::HoughTransform() {}

Mat HoughTransform::detectEdge(Mat Image) {
  Mat output;
  Canny(Image, output, 50 , 150, 3);
  return output;
}

void HoughTransform::polarToCartesian(double rho, int theta, Point& p1, Point& p2) {

  int x0 = cvRound(rho * cos(theta));
  int y0 = cvRound(rho * sin(theta));

  p1.x = cvRound(x0 + 1000 * (-sin(theta)));
  p1.y = cvRound(y0 + 1000 * (cos(theta)));

  p2.x = cvRound(x0 - 1000 * (-sin(theta)));
  p2.y = cvRound(y0 - 1000 * (cos(theta)));
}

Mat HoughTransform::lineTransform(Mat edges, Mat output, int threshold ,double rho = 0, int theta = 0){

  int maxDistance = hypot(edges.rows, edges.cols);
  vector<vector<int>> votes(2 * maxDistance, vector<int>(180, 0));

  for (int i = 0; i < int(votes.size()); ++i) {
      for (int j = 0; j < int(votes[0].size()); ++j) {
          votes[i][j]=0;
      }
  }

  for(int i = 0; i < edges.rows; ++i) {
      for(int j = 0; j < edges.cols; ++j) {
          if(edges.at<uchar>(i, j) == 255) {
              for(theta = 0; theta <= 180; theta += 1) {
                  rho = round(j * cos(theta - 90) + i * sin(theta - 90)) + maxDistance;
                  votes[rho][theta]++;
                }
            }
        }
    }

  // find peaks
  for(int i = 0; i < int(votes.size()); ++i) {
      for(int j = 0; j <int(votes[0].size()); ++j) {
          if(votes[i][j] > threshold) {
              rho = i - maxDistance;
              theta = j - 90;
              Point p1, p2;
              polarToCartesian(rho, theta, p1, p2);
              line(output, p1, p2, Scalar(0, 0, 255), 2, LINE_AA);
            }
        }
    }

  return output;
}

Mat HoughTransform::detectLines(Mat Image,int threshold = 160){

  cvtColor(Image, Image, COLOR_BGR2GRAY);
  Mat edges = detectEdge(Image);
  Mat linesImage = lineTransform(edges, Image, threshold, 0, 0);
  return linesImage;
}
