#include "snake.h"

Snake::Snake() {}


double ptDistance(const cv::Point& pt1, const cv::Point& pt2) {
    int dx = pt1.x - pt2.x;
    int dy = pt1.y - pt2.y;
    return std::sqrt(dx*dx + dy*dy);
}

vector<Point> Snake::snakeCurve(Point center, int radius){
    vector<Point> curve;

    for (int i = 0; i <= 360; i += 1) {
        double angle = i * CV_PI / 180;
        int x = center.x + radius * cos(angle);
        int y = center.y + radius * sin(angle);
        curve.push_back(Point(x, y));
    }

    return curve;
}

static Mat preprocess(Mat img){
    Mat imgCanny;
    Canny(img, imgCanny,10,350);
}

// internal energy that penalizes discontinuities or irregularities in the curve
// curvature normalization, done by dividing by the average distance between neighboring points
static double contEnergy(Point Pt, Point prevPt, Point nextPt, double alpha){
    //initialization for continuity energy
    double cE = 0.0;
    double dx1 = Pt.x - prevPt.x;
    double dy1 = Pt.y - prevPt.y;
    double dx2 = nextPt.x - Pt.x;
    double dy2 = nextPt.y - Pt.y;
    double tangentLength = (ptDistance(Pt, prevPt) + ptDistance(Pt, nextPt)) / 2.0;
    double curvature = (dx1 * dy2 - dx2 * dy1) / pow(tangentLength, 1.5);
    cE = alpha * curvature;
    return cE;
}

// it's an internal energy that focuses on penalizing abrupt changes in curvature
static double smoothnessEnergy(Point Pt, Point prevPt, Point nextPt, double gamma){
    double sE = 0.0;
    double dx = nextPt.x - 2*Pt.x + prevPt.x;
    double dy = nextPt.y - 2*Pt.y + prevPt.y;
    sE = gamma*(dx*dx + dy*dy);

    return sE;
}

// focuses on controlling the expansion or contraction of the curve.
static double balooningEnergy(Point Pt, Point prevPt, Point nextPt, double delta){
    double bE = 0.0;
    double dx = Pt.x - prevPt.x;
    double dy = Pt.y - prevPt.y;
    bE = delta * (dx*dx + dy*dy);
    return bE;
}

// energy of the picture, which the strenght of the gradient magnitude
static double externalEnergy(Mat img, Point pt, double beta){
    double eE = -beta * img.at<uchar>(pt.y, pt.x);
    return eE;
}

// total energy per point
static double pointEnergy(Mat img, Point Pt, Point prevPt, Point nextPt, double delta, double gamma, double beta, double alpha){
    //total energy
    double tE = 0.0;
    double cE = contEnergy(Pt, prevPt, nextPt, alpha);
    double sE = smoothnessEnergy(Pt, prevPt, nextPt, gamma);
    double bE = balooningEnergy(Pt, prevPt, nextPt, delta);
    double eE = externalEnergy(img, Pt, beta);
    tE = eE+ cE+ bE+ sE;
    return tE;
}
