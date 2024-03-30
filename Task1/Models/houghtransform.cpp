#include "houghtransform.h"
#include <bits/stdc++.h>


int HoughTransform::maxradius = 35;
int HoughTransform::minradius = 9;
int HoughTransform::radius = HoughTransform::maxradius;

int HoughTransform::Xc, HoughTransform::Yc;
vector <Vec3f> HoughTransform::circles;

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

Mat HoughTransform::detectCircles(Mat HoughCircle,int minRadius,int maxRadius){
    Mat imageCircles = HoughCircle.clone();

    for(radius = maxradius; radius > minradius; radius--)							// Varying radial values
      {
        imageCircles = circleTransform(imageCircles, maxRadius, minRadius);															// Creating an accumulator for every radial value
        waitKey(1);																// Causing a delay to allow image in trackbar to render
      }
    return imageCircles;
}


Mat HoughTransform::circleTransform(Mat src, int maxradius, int minradius){
    centerData accumul[maxradius];
      // Array of structs to store center points
      Mat SrcImgGray, Acc, Edges;
      cvtColor( src, SrcImgGray, COLOR_BGR2GRAY);
      Acc.create(SrcImgGray.size(), SrcImgGray.type());
      blur( SrcImgGray, Edges, Size(3,3));
      Canny( Edges, Edges, 90, 270, 3);
      // looping over the canny adges to create the accumelator
      for(int i = 0;i < Acc.rows; i++)
        {
          for(int j = 0; j < Acc.cols; j++)
            {
              if (Edges.at<uchar>(i,j) > 256/3)//if edge intensity is stronger than a certain value we add it to the accumaltor
                {
                  for (int theta = 0; theta <= 360; theta++)			// Calculating center points for each edge point
                    {
                      Xc = i + (radius * cos(theta*PI/180));
                      Yc = j + (radius * sin(theta*PI/180));
                      if(Xc < Acc.rows && Yc < Acc.cols && Xc > 0 && Yc > 0)
                        {
                          Acc.at<uchar>(Xc,Yc) = Acc.at<uchar>(Xc,Yc) + 1;	// Incrementing center point values
                        }
                    }
                }
            }
        }

      int votes = 0;						// Highest pixel intensity value
      int Xbright = 0;					// X-index of highest pixel intensity value
      int Ybright = 0;					// Y-index of highest pixel intensity value
      int sum = 0;						// Sum of differences between candidate center point and its neighbors + candidate center point intensity value
      int bigsum = 0;						// Largest sum of differences between candidate center point and its neighbors + candidate center point intensity value
      for(int i = 0; i < Acc.rows; i++)
        {
          for(int j = 0; j < Acc.cols; j++)
            {
              sum += Acc.at<uchar>(i,j);						// Adding candidate center point's intensity value to sum
              if(sum > bigsum)									// Finding largest sum
                {
                  accumul[radius].bright = Acc.at<uchar>(i,j);	// Storing corresponding center point in array of structs
                  accumul[radius].Xbright = i;
                  accumul[radius].Ybright = j;
                  votes = Acc.at<uchar>(i,j);					// Storing corresponding center point in variables for quicker access and readability
                  Xbright = i;
                  Ybright = j;
                  bigsum = sum;									// Updating largest sum of differences
                }
              sum = 0;											// Resetting sum of differences
            }
        }

      double dist;											// Distance between two points
      double radco = 1;									// Radial coefficient (used to calculate minimum distance between centers)
      bool valid = true;										// Valid/Invalid center point
      Point center(Ybright, Xbright);
      for (int i = maxradius; i > radius ; i--)				// Calculating distance between candidate center point and previously found center points
        {
          dist = sqrt(pow((double(accumul[radius].Xbright - accumul[i].Xbright)), 2) + pow((double(accumul[radius].Ybright - accumul[i].Ybright)), 2));
          if (dist < radco*i)									// If distance between candidate center point and any previous center point is less than the radial coefficient multiplied by any of the previously found radii, it is not a valid center point
            {
              valid = false;									// Set valid to false
            }
        }
      if (valid == true)										// If the center point is valid, draw the corresponding circle
        {
          circle( src, center, 3, Scalar(0,255,0), -1, 8, 0 );		// Draw circle center point
          circle( src, center, radius, Scalar(0,0,255), 3, 8, 0 );	// Draw circle outline
        }
      Acc = Scalar::all(0);
      // Reset accumulator to zero
      return src;
}
