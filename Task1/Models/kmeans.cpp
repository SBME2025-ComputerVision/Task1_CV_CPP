#include "kmeans.h"

Kmeans::Kmeans() {}

/*
* @brief K-Means algorithm
* 
* @param Mat image the image to be clustered
* @param int k the number of clusters
* @param int maxIter the maximum number of iterations
*
* @return Mat the clustered image

*/

Mat Kmeans::KmeansClustering(Mat &image, int k, int maxIter)
{
    vector<KMeanPoint> centroids = getCentroids(k);
    bool stop = true;
    Mat clusters = Mat::zeros(image.size(), CV_8UC1);
    for (int i = 0; i < maxIter; i++)
    {
        Mat newClusters = assignClusters(image, centroids);
        vector<KMeanPoint> newCentroids = computeCentroids(image, newClusters, k, centroids);

        for(int i = 0; i < k; i++)
        {
            if (abs(newCentroids[i].r - centroids[i].r) < KMEANS_THRESHOLD && abs(newCentroids[i].g - centroids[i].g) < KMEANS_THRESHOLD && abs(newCentroids[i].b - centroids[i].b) < KMEANS_THRESHOLD)
            {
                continue;
            }
            stop = false;

        }
        
        centroids = newCentroids;
        clusters = newClusters;
        if (stop)
        {
            break;
        }
    }
    Mat result = mapPointsToCentroids(image, centroids, clusters);
    return result;
}

/*
* @brief Get the centroids of the clusters
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
* @brief each point to the nearest cluster and redefine the cluster
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
    return clusters;
}

/*
* @brief Compute the Centroids of the clusters
* @param Mat image the image to be clustered
* @param Mat clusters the clusters
* @param int k the number of clusters
* @param vector<KMeanPoint> centroids the centroids of the clusters
*
* @return vector<KMeanPoint> the new centroids
*/

vector<KMeanPoint> Kmeans::computeCentroids(Mat &image, Mat &clusters, int k, vector<KMeanPoint> &centroids)
{
    vector<KMeanPoint> newCentroids(k);
    vector<int> count(k, 0);
    for (int i = 0; i < image.rows; i++)
    {
        for (int j = 0; j < image.cols; j++)
        {
            int cluster = clusters.at<uchar>(i, j);
            Vec3b pixel = image.at<Vec3b>(i, j);
            newCentroids[cluster].r += pixel[2];
            newCentroids[cluster].g += pixel[1];
            newCentroids[cluster].b += pixel[0];
            count[cluster]++;
        }
    }
    for (int i = 0; i < k; i++)
    {
        if (count[i] == 0){
            continue;
        }
        newCentroids[i].r /= count[i];
        newCentroids[i].g /= count[i];
        newCentroids[i].b /= count[i];
    }
    return newCentroids;
}

Mat Kmeans::mapPointsToCentroids(Mat &image, vector<KMeanPoint> &centroids, Mat &clusters)
{
    Mat result = image.clone();
    for (int i = 0; i < image.rows; i++)
    {
        for (int j = 0; j < image.cols; j++)
        {
            int cluster = clusters.at<uchar>(i, j);
            Vec3b pixel = result.at<Vec3b>(i, j);
            pixel[2] = centroids[cluster].r;
            pixel[1] = centroids[cluster].g;
            pixel[0] = centroids[cluster].b;
            result.at<Vec3b>(i, j) = pixel;
        }
    }
    return result;
}

