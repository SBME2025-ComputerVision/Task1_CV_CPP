#ifndef AGGLOMERATIVE_H
#define AGGLOMERATIVE_H
#include"config.h"

using namespace cv;
using namespace std;

class Agglomerative
{
public:
    Agglomerative();

    static double euclidean_distance(const std::vector<double> &point1, const std::vector<double> &point2);

    static double clusters_distance(const vector<vector<double>> &cluster1, const vector<vector<double>> &cluster2);

    static vector<vector<vector<double>>> initial_clusters(Mat PixelsMatrix);


    static void fit(int k, Mat &pixels, vector<int> &labels, map<int, vector<double>> &centers, map<vector<double>, int> &cluster_map);


    static int predict_cluster(map<vector<double>, int> &cluster_map, vector<double> &point);

    static  vector<double> predict_center(map<int, vector<double>> &centers, map<vector<double>, int> &cluster_map, vector<double> &point);

    static  std::pair<Mat, Mat> image_preperation(Mat &image);

    static  Mat image_color_segmentation(int k, Mat &pixels, Mat &resized_image);
};





#endif // AGGLOMERATIVE_H
