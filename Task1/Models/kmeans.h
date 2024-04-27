#ifndef KMEANS_H
#define KMEANS_H
/*
* K-Means algorithm
* Steps:
* 1. Initialize the clusters:
*    select k points from the dataset as the initial centroids
* 2. Compute the Centroids of the clusters:
* 3. Assign each point to the nearest cluster and redefine the cluster
* 4. Repeat steps 2 and 3 until the centroids do not change

* As we are working with images we will use the RGB values of the pixels as the features
*/
#include <ctime>     
#include <vector>
#include "config.h"

using namespace std;
using namespace cv;




class Kmeans
{
public:
    Kmeans();
    static Mat KmeansClustering(Mat &image, int k, int maxIter = 100);
    static vector<KMeanPoint> getCentroids(int k);
    static Mat assignClusters(Mat &image, vector<KMeanPoint> &centroids);
    static vector<KMeanPoint> computeCentroids(Mat &image, Mat &clusters, int k, vector<KMeanPoint> &centroids);
    static Mat mapPointsToCentroids(Mat &image, vector<KMeanPoint> &centroids, Mat &clusters);
     
};

#endif // KMEANS_H
