#include "edgedetection.h"

EdgeDetection::EdgeDetection() {}

/**
 * @brief Detects edges using Sobel operator.
 *
 * This function detects edges in the input image using Sobel operator.
 *
 * @param img Input image.
 * @return Mat representing the edge-detected image.
 */
Mat EdgeDetection::detectEdgeSobel(Mat img){
    Mat sobelX = detectEdgeSobelX(img);
    Mat sobelY = detectEdgeSobelY(img);
    Mat magnitude = edgeMagnitude(sobelX,sobelY);
    magnitude.convertTo(magnitude, CV_8U);
    return magnitude;
}

/**
 * @brief Detects edges using Sobel operator along the X-axis.
 *
 * This function detects edges in the input image using Sobel operator along the X-axis.
 *
 * @param img Input image.
 * @return Mat representing the edge-detected image along the X-axis.
 */
Mat EdgeDetection::detectEdgeSobelX(Mat img){
    Mat xFilter= (Mat_<float>(3,3)<<-1, 0, 1,
                   -2, 0, 2,
                   -1, 0, 1);
    Mat result;
    filter2D(img, result,CV_32F,xFilter,Point(-1,-1),0,BORDER_DEFAULT);
    return result;
}

/**
 * @brief Detects edges using Sobel operator along the Y-axis.
 *
 * This function detects edges in the input image using Sobel operator along the Y-axis.
 *
 * @param img Input image.
 * @return Mat representing the edge-detected image along the Y-axis.
 */
Mat EdgeDetection::detectEdgeSobelY(Mat img){
    Mat yFilter= (Mat_<float>(3,3)<<   -1,-2,-1,
                   0,0,0,
                   1,2,1);
    Mat result;
    filter2D(img, result,CV_32F,yFilter,Point(-1,-1),0,BORDER_DEFAULT);
    return result;
}

/**
 * @brief Detects edges using Robert operator.
 *
 * This function detects edges in the input image using Robert operator.
 *
 * @param img Input image.
 * @return Mat representing the edge-detected image.
 */
Mat EdgeDetection::detectEdgeRobert(Mat img){
    Mat robertX = detectEdgeRobertX(img);
    Mat robertY = detectEdgeRobertY(img);
    Mat magnitude = edgeMagnitude(robertX,robertY);
    magnitude.convertTo(magnitude, CV_8U);
    return magnitude;
}

/**
 * @brief Detects edges using Robert operator along the X-axis.
 *
 * This function detects edges in the input image using Robert operator along the X-axis.
 *
 * @param img Input image.
 * @return Mat representing the edge-detected image along the X-axis.
 */
Mat EdgeDetection::detectEdgeRobertX(Mat img){
    Mat yFilter= (Mat_<float>(2,2)<< 1,0,0,-1);
    Mat result;
    filter2D(img, result,CV_32F,yFilter,Point(-1,-1),0,BORDER_DEFAULT);
    return result;
}

/**
 * @brief Detects edges using Robert operator along the Y-axis.
 *
 * This function detects edges in the input image using Robert operator along the Y-axis.
 *
 * @param img Input image.
 * @return Mat representing the edge-detected image along the Y-axis.
 */
Mat EdgeDetection::detectEdgeRobertY(Mat img){
    Mat yFilter= (Mat_<float>(2,2)<< 0,1,-1,0);
    Mat result;
    filter2D(img, result,CV_32F,yFilter,Point(-1,-1),0,BORDER_DEFAULT);
    return result;
}

/**
 * @brief Detects edges using Prewitt operator.
 *
 * This function detects edges in the input image using Prewitt operator.
 *
 * @param img Input image.
 * @return Mat representing the edge-detected image.
 */
Mat EdgeDetection::detectEdgePrewitt(Mat img){
    Mat PrewittX = detectEdgePrewittX(img);
    Mat PrewittY = detectEdgePrewittY(img);
    Mat magnitude = edgeMagnitude(PrewittX,PrewittY);
    magnitude.convertTo(magnitude, CV_8U);
    return magnitude;
}

/**
 * @brief Detects edges using Prewitt operator along the X-axis.
 *
 * This function detects edges in the input image using Prewitt operator along the X-axis.
 *
 * @param img Input image.
 * @return Mat representing the edge-detected image along the X-axis.
 */
Mat EdgeDetection::detectEdgePrewittX(Mat img){
    Mat yFilter= (Mat_<float>(3,3)<< -1,0,1,-1,0,1,-1,0,1);
    Mat result;
    filter2D(img, result,CV_32F,yFilter,Point(-1,-1),0,BORDER_DEFAULT);
    return result;
}

/**
 * @brief Detects edges using Prewitt operator along the Y-axis.
 *
 * This function detects edges in the input image using Prewitt operator along the Y-axis.
 *
 * @param img Input image.
 * @return Mat representing the edge-detected image along the Y-axis.
 */
Mat EdgeDetection::detectEdgePrewittY(Mat img){
    Mat yFilter= (Mat_<float>(3,3)<<-1,-1,-1,0,0,0,1,1,1 );
    Mat result;
    filter2D(img, result,CV_32F,yFilter,Point(-1,-1),0,BORDER_DEFAULT);
    return result;
}

/**
 * @brief Detects edges using Canny edge detection.
 *
 * This function detects edges in the input image using Canny edge detection algorithm.
 *
 * @param img Input image.
 * @param t_low Lower threshold for Canny edge detection.
 * @param t_high Upper threshold for Canny edge detection.
 * @return Mat representing the edge-detected image.
 */
Mat EdgeDetection::detectEdgeCanny(Mat img, int t_low ,int t_high){
    Mat edges;
    cv::Canny(img,edges,t_low,t_high);
    edges.convertTo(edges,CV_8U);
    return edges;
}

/**
 * @brief Computes edge magnitude from edge gradients.
 *
 * This function computes the edge magnitude from the gradients along X and Y directions.
 *
 * @param edgeX Gradient along the X direction.
 * @param edgeY Gradient along the Y direction.
 * @return Mat representing the edge magnitude.
 */
Mat EdgeDetection::edgeMagnitude(Mat edgeX, Mat edgeY){
    Mat Magnitude_Gradient = Mat::zeros(Size(edgeX.cols, edgeX.rows), edgeX.type());
    for (int i = 0; i < edgeX.rows; i++) {
        for (int j = 0; j < edgeX.cols; j++) {
            Magnitude_Gradient.at<float>(i, j) = sqrt(pow(edgeX.at<float>(i, j), 2) + pow(edgeY.at<float>(i, j), 2));
        }
    }
    return Magnitude_Gradient;
}
