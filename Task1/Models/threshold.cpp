#include "threshold.h"

Threshold::Threshold() {}


Mat Threshold::globalThresholding(Mat img){
    Mat res =img;
    for(int i = 0;i<res.rows;i++){
        for(int j=0;j<res.cols;j++){
            if(res.at<float>(i,j) >= 210 ){
                res.at<float>(i,j)= 250;
            }else{
                res.at<float>(i,j)=0;
            }
        }
    }
    return res;
}

Mat Threshold::localThresholding(Mat img, int blockSize, int C){
    int rows = img.rows;
    int cols = img.cols;
    Mat res = img;
    // Iterate over each pixel in the image
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // Calculate the local threshold
            int sum = 0;
            int count = 0;
            for (int m = -blockSize / 2; m <= blockSize / 2; ++m) {
                for (int n = -blockSize / 2; n <= blockSize / 2; ++n) {
                    int x = i + m;
                    int y = j + n;
                    if (x >= 0 && x < rows && y >= 0 && y < cols) {
                        sum += img.at<float>(x,y);
                        ++count;
                    }
                }
            }
            int localThreshold = sum / count - C;

            // Apply thresholding
            res.at<float>(i,j) = (img.at<float>(i,j) > localThreshold) ? 255 : 0;
            return res;
        }
    }
}
