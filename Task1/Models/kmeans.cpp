#include "kmeans.h"

Kmeans::Kmeans() {}

Mat Kmeans::KmeansClustering(Mat &image, int k, int maxIter)
{

}

/*
* Get the centroids of the clusters
* random initialization of the centroids
* select k points from the dataset as the initial centroids
* 
* @param int k the number of clusters
*
* @return vector<KMeanPoint> the centroids of the clusters
*/

vector<KMeanPoint> Kmeans::getCentroids(int k)
{
    vector<KMeanPoint> centroids;
    srand(time(0));
    for (int i = 0; i < k; i++)
    {
        int r = rand() % 256;
        int g = rand() % 256;
        int b = rand() % 256;
        centroids.push_back(KMeanPoint(r, g, b));
    }
    return centroids;
}

Mat Kmeans::assignClusters(Mat &image, vector<KMeanPoint> &centroids)
{

}

vector<KMeanPoint> Kmeans::computeCentroids(Mat &image, Mat &clusters, int k)
{

}
