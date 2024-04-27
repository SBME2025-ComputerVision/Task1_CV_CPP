#include "regiongrowing.h"

RegionGrowing::RegionGrowing() {}

Mat RegionGrowing::growSeedPoints(Mat& img, vector<pair<int,int>> seedPoints, int threshold)
{
    Mat result = Mat::zeros(img.size(), CV_8UC1);

    // convert the image to LUv color space
    Mat luvImg;
    cvtColor(img, luvImg, COLOR_BGR2Luv);
    // Create a queue to store the pixels to be processed
    queue<pair<int,int>> q;
    // Create a visited matrix to keep track of the visited pixels
    Mat visited = Mat::zeros(img.size(), CV_8UC1);
    // Add the seed pixel to the queue and mark it as processed
    for (auto seed : seedPoints)
    {
        q.push(seed);
        visited.at<uchar>(seed.first, seed.second) = 1;
    }
    // Define the neighborhood of a pixel 8-connected
    vector<pair<int,int>> neighbors = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};
    // Process the pixels in the queue
    while (!q.empty())
    {
        // Get the pixel from the queue
        pair<int,int> pixel = q.front();
        q.pop();
        // Process the pixel's neighbors
        for (auto neighbor : neighbors)
        {
            int x = pixel.first + neighbor.first;
            int y = pixel.second + neighbor.second;
            // Check if the neighbor is within the image boundaries
            if (x >= 0 && x < img.rows && y >= 0 && y < img.cols)
            {
                // Check if the neighbor is not visited
                if (!visited.at<uchar>(x, y))
                {
                    // Calculate the difference between the pixel and the neighbor using norm
                    double diff = norm(luvImg.at<Vec3b>(pixel.first, pixel.second) - luvImg.at<Vec3b>(x, y));

                    // Check if the difference is less than the threshold
                    if (diff < threshold)
                    {
                        // Add the neighbor to the queue and mark it as visited
                        q.push({x, y});
                        visited.at<uchar>(x, y) = 1;
                        // Mark the pixel as part of the region
                        result.at<uchar>(x, y) = 255;
                    }
                }
            }
        }
        
    }
    return result;
}
