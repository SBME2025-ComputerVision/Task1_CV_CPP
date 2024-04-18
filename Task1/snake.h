#ifndef SNAKE_H
#define SNAKE_H

#include <bits/stdc++.h>
#include<opencv2/opencv.hpp>
#include<config.h>
using namespace cv;

class Snake
{
public:
    Snake();
    static double contEnergy(Point Pt, Point prevPt, Point nextPt, double alpha);
    static double externalEnergy(Mat img, Point pt, double beta);
    static double smoothnessEnergy(Point Pt, Point prevPt, Point nextPt, double gamma);
    static double balooningEnergy(Point Pt, Point prevPt, Point nextPt, double delta);
    static double pointEnergy(Mat img, Point Pt, Point prevPt, Point nextPt, double delta, double gamma, double beta, double alpha);
    static vector<Point> updateCurve(Mat img, vector<Point> curve, double alpha, double beta, double gamma, double delta);
    static vector<Point> snakeCurve(Point center, int radius);
    static Mat preprocess(Mat img);
    void applySnake(Mat img, vector<Point> curve, int interations, double alpha, double beta, double gamma, double delta);
    static vector<Point> activeContour(Mat img, Point center, int radius, int iterations, double alpha, double beta, double gamma, double delta);
};

#endif // SNAKE_H
