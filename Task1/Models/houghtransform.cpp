#include "houghtransform.h"
#include <bits/stdc++.h>

// Static member initialization
int HoughTransform::maxradius = 35;
int HoughTransform::minradius = 9;
int HoughTransform::radius = HoughTransform::maxradius;
int HoughTransform::Xc, HoughTransform::Yc;
vector<Vec3f> HoughTransform::circles;

// Constructor
HoughTransform::HoughTransform() {}

/**
 * @brief Detect edges in the input image using Canny edge detector.
 *
 * @param Image The input image.
 * @return The edge-detected image.
 */
Mat HoughTransform::detectEdge(Mat Image) {
    Mat output;
    Canny(Image, output, 50, 150, 3);
    return output;
}

/**
 * @brief Convert polar coordinates to Cartesian coordinates.
 *
 * @param rho The distance from the origin to the line.
 * @param theta The angle (in degrees) from the x-axis to the line.
 * @param p1 The first endpoint of the line segment.
 * @param p2 The second endpoint of the line segment.
 */
void HoughTransform::polarToCartesian(double rho, int theta, Point& p1, Point& p2) {
    int x0 = cvRound(rho * cos(theta));
    int y0 = cvRound(rho * sin(theta));

    p1.x = cvRound(x0 + 1000 * (-sin(theta)));
    p1.y = cvRound(y0 + 1000 * (cos(theta)));

    p2.x = cvRound(x0 - 1000 * (-sin(theta)));
    p2.y = cvRound(y0 - 1000 * (cos(theta)));
}

/**
 * @brief Apply Hough line transform to detect lines in the edge-detected image.
 *
 * @param edges The edge-detected image.
 * @param output The output image to draw detected lines.
 * @param threshold The threshold for line detection.
 * @return The image with detected lines drawn.
 */
Mat HoughTransform::lineTransform(Mat edges, Mat output, int threshold) {
    int rho, theta;
    rho = theta = 0;
    int maxDistance = hypot(edges.rows, edges.cols);
    vector<vector<int>> votes(2 * maxDistance, vector<int>(180, 0));

    for (int i = 0; i < edges.rows; ++i) {
        for (int j = 0; j < edges.cols; ++j) {
            if (edges.at<uchar>(i, j) == 255) {
                for (theta = 0; theta <= 180; theta += 1) {
                    rho = round(j * cos(theta - 90) + i * sin(theta - 90)) + maxDistance;
                    votes[rho][theta]++;
                }
            }
        }
    }

    // Find peaks
    for (int i = 0; i < int(votes.size()); ++i) {
        for (int j = 0; j < int(votes[0].size()); ++j) {
            if (votes[i][j] > threshold) {
                rho = i - maxDistance;
                theta = j - 90;
                Point p1, p2;
                polarToCartesian(rho, theta, p1, p2);
                line(output, p1, p2, Scalar(0, 0, 255), 1, LINE_AA);
            }
        }
    }

    return output;
}

/**
 * @brief Detect lines in the input image.
 *
 * @param Image The input image.
 * @param threshold The threshold for line detection (default is 160).
 * @return The image with detected lines drawn.
 */
Mat HoughTransform::detectLines(Mat Image, int threshold) {
    Mat grey;
    cvtColor(Image, grey, COLOR_BGR2GRAY);
    Mat edges = detectEdge(Image);
    Mat linesImage = lineTransform(edges, Image, threshold);
    return linesImage;
}

/**
 * @brief Apply Hough circle transform to detect circles in the input image.
 *
 * @param HoughCircle The input image.
 * @param minRadius The minimum radius of the circles to detect.
 * @param maxRadius The maximum radius of the circles to detect.
 * @return The image with detected circles drawn.
 */
Mat HoughTransform::detectCircles(Mat HoughCircle, int minRadius, int maxRadius) {
    Mat imageCircles = HoughCircle.clone();

    for (radius = maxradius; radius > minradius; radius--) {
        imageCircles = circleTransform(imageCircles, maxRadius, minRadius);
        waitKey(1);
    }
    return imageCircles;
}

/**
 * @brief Apply Hough circle transform to detect circles in the input image.
 *
 * @param src The input image.
 * @param maxradius The maximum radius of the circles to detect.
 * @param minradius The minimum radius of the circles to detect.
 * @return The image with detected circles drawn.
 */
Mat HoughTransform::circleTransform(Mat src, int maxradius, int minradius) {
    centerData accumul[maxradius];
    // Array of structs to store center points
    Mat SrcImgGray, Acc, Edges;
    cvtColor(src, SrcImgGray, COLOR_BGR2GRAY);
    Acc.create(SrcImgGray.size(), SrcImgGray.type());
    blur(SrcImgGray, Edges, Size(3, 3));
    Canny(Edges, Edges, 90, 270, 3);

    // Looping over the canny edges to create the accumulator
    for (int i = 0; i < Acc.rows; i++) {
        for (int j = 0; j < Acc.cols; j++) {
            if (Edges.at<uchar>(i, j) > 256 / 3) { // If edge intensity is stronger than a certain value, add it to the accumulator
                for (int theta = 0; theta <= 360; theta++) {
                    // Calculating center points for each edge point
                    Xc = i + (radius * cos(theta * PI / 180));
                    Yc = j + (radius * sin(theta * PI / 180));
                    if (Xc < Acc.rows && Yc < Acc.cols && Xc > 0 && Yc > 0) {
                        Acc.at<uchar>(Xc, Yc) = Acc.at<uchar>(Xc, Yc) + 1; // Incrementing center point values
                    }
                }
            }
        }
    }

    int votes = 0; // Highest pixel intensity value
    int Xbright = 0; // X-index of highest pixel intensity value
    int Ybright = 0; // Y-index of highest pixel intensity value
    int sum = 0; // Sum of differences between candidate center point and its neighbors + candidate center point intensity value
    int bigsum = 0; // Largest sum of differences between candidate center point and its neighbors + candidate center point intensity value
    for (int i = 0; i < Acc.rows; i++) {
        for (int j = 0; j < Acc.cols; j++) {
            sum += Acc.at<uchar>(i, j); // Adding candidate center point's intensity value to sum
            if (sum > bigsum) // Finding largest sum
            {
                // Storing corresponding center point in array of structs
                accumul[radius].bright = Acc.at<uchar>(i, j);
                accumul[radius].Xbright = i;
                accumul[radius].Ybright = j;
                // Storing corresponding center point in variables for quicker access and readability
                votes = Acc.at<uchar>(i, j);
                Xbright = i;
                Ybright = j;
                // Updating largest sum of differences
                bigsum = sum;
            }
            sum = 0; // Resetting sum of differences
        }
    }

    double dist; // Distance between two points
    double radco = 1; // Radial coefficient (used to calculate minimum distance between centers)
    bool valid = true; // Valid/Invalid center point
    Point center(Ybright, Xbright);
    for (int i = maxradius; i > radius; i--) {
        // Calculating distance between candidate center point and previously found center points
        dist = sqrt(pow((double(accumul[radius].Xbright - accumul[i].Xbright)), 2) + pow((double(accumul[radius].Ybright - accumul[i].Ybright)), 2));
        if (dist < radco * i) {
            // If distance between candidate center point and any previous center point is less than the radial coefficient multiplied by any of the previously found radii, it is not a valid center point
            valid = false;
        }
    }
    if (valid == true) {
        // If the center point is valid, draw the corresponding circle
        circle(src, center, 3, Scalar(0, 255, 0), -1, 8, 0); // Draw circle center point
        circle(src, center, radius, Scalar(0, 0, 255), 3, 8, 0); // Draw circle outline
    }
    Acc = Scalar::all(0);
    // Reset accumulator to zero
    return src;
}

int HoughTransform :: approximate(float x, int step){
  int temp = round(x/step);
  return temp*step;
}

Mat HoughTransform::houghEllipseDetection(Mat img, float threshold, int neighbour_size, int rad_step, int center_step)
{
  Mat img_edge, img_ellipse;
  img_edge.create(img.size(), img.type());
  cvtColor(img, img, COLOR_BGR2GRAY);
  blur( img, img, Size(5,5));
  Canny(img, img_edge, 50, 270, 5);
  //return img_edge;
  int max_r = min(img_edge.rows, img_edge.cols) / 2;
  img_ellipse.create(img.size(), img.type());
  vector< vector<Mat> > accumelator;
  for(int r1 = rad_step; r1 < max_r; r1 += rad_step)
    {
      vector<Mat> temp;
      for(int r2 = rad_step; r2 < max_r; r2 += rad_step)
        {
          Mat ellipse_centers = Mat::zeros(img.rows, img.cols, CV_32F);
          temp.push_back(ellipse_centers);
        }
      //cout<<temp.size()<<" "<<max_r / rad_step<<endl;
      accumelator.push_back(temp);
    }

  for(int r1 = rad_step; r1 < max_r; r1 += rad_step)
    {
      int i = r1 / rad_step;
      for(int r2 = rad_step; r2 < max_r; r2 += rad_step)
        {
          int j = r2 / rad_step;
          for(int y = 0; y < img_edge.rows; y++)
            for(int x = 0; x < img_edge.cols; x++)
              {
                if(img_edge.at<float>(y, x) < 256/2)
                  continue;
                for(int a = rad_step; a < img_edge.rows - rad_step; a += center_step)
                  {
                    float d = r2 * r2 * (1 - (y - a) * (y - a) * 1.0 / (r1 * r1));
                    if(d < 0.0)
                      continue;
                    int b1 = approximate(x - sqrt(d), center_step);
                    int b2 = approximate(x + sqrt(d), center_step);
                    if(b1 >= rad_step && b1 < img_edge.cols - rad_step)
                      accumelator[i - 1][j - 1].at<float>(a, b1) += 1.0;
                    if(b2 >= rad_step && b2 < img_edge.cols - rad_step)
                      accumelator[i - 1][j - 1].at<float>(a, b2) += 1.0;
                  }
              }
        }
    }

  for(int r1 = rad_step; r1 < max_r; r1 += rad_step)
    {
      int i = r1 / rad_step;
      for(int r2 = rad_step; r2 < max_r; r2 += rad_step)
        {
          int j = r2 / rad_step;
          for(int a = rad_step; a < img_edge.rows - rad_step; a += center_step)
            for(int b = rad_step; b < img_edge.cols - rad_step; b += center_step)
              {

                if(accumelator[i - 1][j - 1].at<float>(a, b) <= threshold)
                  continue;
                bool local_max = true;
                for(int d1 = i - neighbour_size; local_max && d1 <= i + neighbour_size && d1 < max_r / rad_step; d1++)
                  {
                    if(d1 < 1)
                      continue;
                    for(int d2 = j - neighbour_size; local_max && d2 <= j + neighbour_size && d2 < max_r / rad_step; d2++)
                      {
                        if(d2 < 1)
                          continue;
                        for(int d3 = a - neighbour_size * center_step; local_max && d3 <= a + neighbour_size * center_step && d3 < img_edge.rows - rad_step; d3 += center_step)
                          {
                            if(d3 < rad_step)
                              continue;
                            for(int d4 = b - neighbour_size * center_step; local_max && d4 <= b + neighbour_size * center_step && d4 < img_edge.rows - rad_step; d4 += center_step)
                              {
                                if(d4 < rad_step)
                                  continue;
                                if(accumelator[i - 1][j - 1].at<float>(a, b) < accumelator[d1 - 1][d2 - 1].at<float>(d3, d4))
                                  local_max = false;
                              }
                          }
                      }
                  }

                if(local_max)
                  {
                    ellipse(img_ellipse, Point(b, a), Size(r2, r1), 0.0, 0.0, 360, Scalar(255, 255, 255));
                  }

              }
        }
    }
  return img_ellipse;
}
