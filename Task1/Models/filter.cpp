#include "filter.h"
#include "config.h"

Filter::Filter(){}

Mat Filter::gaussianKernel(int kernelSize, float sigma){
    // The eq for the gaussian kernel is:
    // G(x,y) = 1/(2*pi*sigma^2) * e^(-((x^2 + y^2)/(2*sigma^2)))
    // The kernel is a 2D matrix with the center of the kernel at the center of the matrix
    Mat kernel = Mat::zeros(kernelSize, kernelSize, CV_32F);
    int center = kernelSize / 2;
    float sum = 0.0;
    for(int i = 0; i < kernelSize; i++){
        for(int j = 0; j < kernelSize; j++){
            int x = i - center;
            int y = j - center;
            kernel.at<float>(i, j) = exp(-((x * x + y * y) / (2 * sigma * sigma)));
            sum += kernel.at<float>(i, j);
        }
    }
    kernel /= sum; // Normalize the kernel
    return kernel;
}

Mat Filter::avgFilter(Mat img, int kernelSize) {
    Mat result = img.clone();
    Mat kernel = Mat::ones(kernelSize, kernelSize, CV_32F) / (float)(kernelSize * kernelSize);
    filter2D(img, result, -1, kernel,Point(-1,-1), 0, BORDER_DEFAULT);
    return result;
}

Mat Filter::gaussionFilter(Mat img, int kernelSize) {
    Mat result = img.clone();
    vector<Mat> channels;
    split(img, channels);
    for(int i = 0; i < 3; i++){
        Mat channel = channels[i];
        Mat kernel = gaussianKernel(kernelSize, 1.0);
        filter2D(channel, channel, -1, kernel, Point(-1, -1), 0, BORDER_DEFAULT);
        channels[i] = channel;
    }
    merge(channels, result);
    return result;
}

Mat Filter::medianFilter(Mat img, int kernelSize) {
    Mat result = img.clone();
    int center = kernelSize / 2;
    vector<Mat> channels;
    split(img, channels);
    for(int i = 0; i < 3; i++){
        Mat channel = channels[i];
        for(int x = center; x < channel.rows - center; x++){
            for(int y = center; y < channel.cols - center; y++){
                vector<int> values;
                for(int i = -center; i <= center; i++){
                    for(int j = -center; j <= center; j++){
                        values.push_back(channel.at<uchar>(x + i, y + j));
                    }
                }
                sort(values.begin(), values.end());
                channel.at<uchar>(x, y) = values[values.size() / 2];
            }
        }
        channels[i] = channel;
    }
    merge(channels, result);
    return result;
}

Mat Filter::opencvGaussianFilter(Mat img, int kernelSize) {
    Mat result = img.clone();
    GaussianBlur(img, result, Size(kernelSize, kernelSize), 0, 0, BORDER_DEFAULT);
    return result;
}

Mat Filter::opencvMedianFilter(Mat img, int kernelSize) {
    Mat result = img.clone();
    medianBlur(img, result, kernelSize);
    return result;
}

Mat Filter::opencvAvgFilter(Mat img, int kernelSize) {
    Mat result = img.clone();
    blur(img, result, Size(kernelSize, kernelSize), Point(-1, -1), BORDER_DEFAULT);
    return result;
}
