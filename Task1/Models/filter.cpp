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

// TODO: Implement median filter optimization , ET:10sec
// Mat Filter::medianFilter(Mat img, int kernelSize) {
//     Mat result = img.clone();
//     int center = kernelSize / 2;
//         for(int x = center; x < result.rows - center; x++){
//             for(int y = center; y < result.cols - center; y++){
//                 vector<int> values;
//                 for(int i = -center; i <= center; i++){
//                     for(int j = -center; j <= center; j++){
//                         values.push_back(result.at<uchar>(x + i, y + j));
//                     }
//                 }
//                 sort(values.begin(), values.end());
//                 result.at<uchar>(x, y) = values[values.size() / 2];
//             }
//         }


//     return result;
// }

Mat Filter::medianFilter(Mat img, int kernelSize) {
    Mat result = img.clone();
    int center = kernelSize / 2;

    for (int x = center; x < result.rows - center; x++) {
        for (int y = center; y < result.cols - center; y++) {
            // Extract the kernel region
            Mat kernel = result(Rect(y - center, x - center, kernelSize, kernelSize)).clone();

            // Reshape the kernel to a column vector
            Mat kernelVec = kernel.reshape(1, kernelSize * kernelSize);

            // Sort the values along the column vector
            std::nth_element(kernelVec.data, kernelVec.data + kernelVec.rows * kernelVec.cols / 2, kernelVec.data + kernelVec.rows * kernelVec.cols);

            // Get the median value
            result.at<uchar>(x, y) = kernelVec.at<uchar>(kernelVec.rows * kernelVec.cols / 2);
        }
    }

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

Mat Filter::detectEdgeSobel(Mat img){

    Mat sobelX = detectEdgeSobelX(img);
    Mat sobelY = detectEdgeSobelY(img);
    Mat magnitude = edgeMagnitude(sobelX,sobelY);
    return magnitude;

}
Mat Filter::detectEdgeSobelX(Mat img){
    // Mat xFilter= (Mat_<float>(3,3)<<-1, 0, 1,
    //                                -2, 0, 2,
    //                                -1, 0, 1);
    Mat xFilter= (Mat_<float>(3,3)<<-1, 0, 1,
                                   -2, 0, 2,
                                   -1, 0, 1);

    Mat result;
    filter2D(img, result,CV_32F,xFilter,Point(-1,-1),0,BORDER_DEFAULT);
    return result;

}

Mat Filter::detectEdgeSobelY(Mat img){
    // Mat yFilter= (Mat_<float>(3,3)<<   1,2,1,
    //                                    0,0,0,
    //                                   -1,-2,-1);
    Mat yFilter= (Mat_<float>(3,3)<<   -1,-2,-1,
                                           0,0,0,
                                           1,2,1);
    Mat result;
    filter2D(img, result,CV_32F,yFilter,Point(-1,-1),0,BORDER_DEFAULT);

    return result;
}

Mat Filter::edgeMagnitude(Mat edgeX, Mat edgeY){


    Mat magnitude_Gradient = Mat::zeros(edgeX.rows,edgeX.cols,edgeX.type());
    // for (int i = 0; i < edgeX.rows; i++)
    // {
    //     for (int j = 0; j < edgeX.cols; j++)
    //     {
    //         Magnitude_Gradient.at<float>(i, j) = sqrt(pow(edgeX.at<float>(i, j), 2) + pow(edgeY.at<float>(i, j), 2));
    //     }
    // }
    // Magnitude_Gradient = edgeX + edgeY;


    magnitude(edgeX,edgeY,magnitude_Gradient);
    // cout <<Magnitude_Gradient.size();
    return magnitude_Gradient;

}

Mat Filter::convertToGrayScale(Mat img)
{
    Mat greyScaledImg(img.rows, img.cols, CV_8UC1);
    float weights[3]  = {0.299, 0.587, 0.114};
    for(int i = 0; i < img.rows; i++){
        for(int j = 0; j < img.cols; j++){
            Vec3b currentPixel = img.at<Vec3b>(i, j); // Access pixel from input image
            float currentGreyValue = weights[0] * currentPixel[2] + weights[1] * currentPixel[1]
                                     + weights[2] * currentPixel[0];
            greyScaledImg.at<uchar>(i, j) = static_cast<uchar>(currentGreyValue);
        }
    }
    return greyScaledImg;
}

