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

Mat HoughTransform::preProcessImg(Mat image,Mat &edges,Mat &grayImage,int canny_min_thresold, int canny_max_thresold){
    // Convert the image to grayscale
    cvtColor(image, grayImage, COLOR_BGR2GRAY);
    // Perform edge detection
    Canny(grayImage, edges, canny_min_thresold, canny_max_thresold);
    return grayImage;
}

Mat HoughTransform::Hough_Circle_Transform (Mat image , int threshold , int min_radius  , int max_radius  , int canny_min_thresold  , int canny_max_thresold  )
{
    Mat grayImage,edges;
    grayImage = HoughTransform::preProcessImg(image,edges,grayImage,canny_min_thresold,canny_max_thresold);
    // Perform Hough Circles Transform
    // rows is image height , cols is image width
    int rows = grayImage.rows;
    int cols = grayImage.cols;
    // Define Hough parameters
    int num_thetas = 100;
    double dtheta = (int) (360 / num_thetas);
    int theta_bins = 360;
    // Initialize 3D Accumulator
    vector<vector<vector<int>>> accumulator(cols+1, vector<vector<int>>(rows+1, vector<int>((max_radius-min_radius+1), 0)));
    /* Loop over edge points then raduis and theta values to incrment accumulator */
    // Loop over edge points
    for (int y = 0; y < rows; y++)
    {
        for (int x = 0; x < cols; x++)
        {
            // Check if edge point
            if (edges.at<uchar>(y, x) > 0)
            {
                // Loop over r values
                for (int r = min_radius; r < max_radius; r++)
                {
                    // Loop over theta values
                    for (int theta = 0; theta < num_thetas; theta+= dtheta)
                    {
                        // Calculate x_center and y_center
                        double x_center = x - r * cos(theta * deg2rad);
                        double y_center = y - r * sin(theta * deg2rad);
                        // check that xcenter and ycenter is in valid range
                        if (x_center >= 0 && x_center < cols && y_center >= 0 && y_center < rows)
                        {
                            // Increment accumulator
                            accumulator[(int)x_center][(int)y_center][r-min_radius]++;
                        }
                    }
                }
            }
        }
    }

    Mat circles_img = image.clone();
    // Loop over accumulator to find circles
    for (int y = 0; y < rows; y++)
    {
        for (int x = 0; x < cols; x++)
        {
            for  (int r = min_radius; r < max_radius; r++)
            {
                // int current_vote = accumulator[x][y][r-min_radius] ;
                // if (current_vote >= threshold)
                // Check For accumulator threshold
                if (accumulator[x][y][r-min_radius] > threshold)
                {
                // Draw circle
                    circle(circles_img, Point(x , y ), r -min_radius, Scalar(0, 0, 255), 1, LINE_AA);
                }
            }
        }
    }
    return circles_img;
}

