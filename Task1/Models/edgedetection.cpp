#include "edgedetection.h"

EdgeDetection::EdgeDetection()
{

}


Mat EdgeDetection::detectEdgeSobel(Mat img){

    Mat sobelX = detectEdgeSobelX(img);
    Mat sobelY = detectEdgeSobelY(img);
    Mat magnitude = edgeMagnitude(sobelX,sobelY);
    return magnitude;

}
Mat EdgeDetection::detectEdgeSobelX(Mat img){
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

Mat EdgeDetection::detectEdgeSobelY(Mat img){
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
Mat EdgeDetection::detectEdgeRobertX(Mat img){
    Mat yFilter= (Mat_<float>(2,2)<< 1,0,0,-1);
    Mat result;
    filter2D(img, result,CV_32F,yFilter,Point(-1,-1),0,BORDER_DEFAULT);

    return result;
}

Mat EdgeDetection::detectEdgeRobertY(Mat img){

    Mat yFilter= (Mat_<float>(2,2)<< 0,1,-1,0);

    Mat result;
    filter2D(img, result,CV_32F,yFilter,Point(-1,-1),0,BORDER_DEFAULT);

    return result;
}

Mat EdgeDetection::detectEdgeRobert(Mat img){

    Mat robertX = detectEdgeRobertX(img);
    Mat robertY = detectEdgeRobertY(img);
    Mat magnitude = edgeMagnitude(robertX,robertY);
    return magnitude;

}


Mat EdgeDetection::detectEdgePrewittX(Mat img){

    Mat yFilter= (Mat_<float>(3,3)<< -1,0,1,-1,0,1,-1,0,1);

    Mat result;
    filter2D(img, result,CV_32F,yFilter,Point(-1,-1),0,BORDER_DEFAULT);

    return result;
}
Mat EdgeDetection::detectEdgePrewittY(Mat img){
    Mat yFilter= (Mat_<float>(3,3)<<-1,-1,-1,0,0,0,1,1,1 );
    Mat result;
    filter2D(img, result,CV_32F,yFilter,Point(-1,-1),0,BORDER_DEFAULT);

    return result;
}
Mat EdgeDetection::detectEdgePrewitt(Mat img){

    Mat PrewittX = detectEdgePrewittX(img);
    Mat PrewittY = detectEdgePrewittY(img);
    Mat magnitude = edgeMagnitude(PrewittX,PrewittY);
    return magnitude;

}
Mat EdgeDetection::detectEdgeCanny(Mat img, int t_low ,int t_high){
//    int t_low = 50;
//    int t_high= 250;
    Mat edges;
    cv::Canny(img,edges,t_low,t_high);
    return edges;
}


Mat EdgeDetection::edgeMagnitude(Mat edgeX, Mat edgeY){


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
