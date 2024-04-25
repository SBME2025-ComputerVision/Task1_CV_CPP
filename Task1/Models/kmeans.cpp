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

/*
* Assign each point to the nearest cluster and redefine the cluster
* @param Mat image the image to be clustered
* @param vector<KMeanPoint> centroids the centroids of the clusters
*
* @return Mat the clusters
*/

Mat Kmeans::assignClusters(Mat &image, vector<KMeanPoint> &centroids)
{
    Mat clusters = Mat::zeros(image.size(), CV_8UC1);
    for (int i = 0; i < image.rows; i++)
    {
        for (int j = 0; j < image.cols; j++)
        {
            Vec3b pixel = image.at<Vec3b>(i, j);
            KMeanPoint p(pixel[2], pixel[1], pixel[0]);
            for (int k = 0; k < centroids.size(); k++)
            {
                double dist = p.distance(centroids[k]);
                if (dist < p.minDistance)
                {
                    p.minDistance = dist;
                    p.cluster = k;
                }
            }
            clusters.at<uchar>(i, j) = p.cluster;
        }
    }

}

vector<KMeanPoint> Kmeans::computeCentroids(Mat &image, Mat &clusters, int k)
{

}
