#include"histogram.h"




Mat Histogram:: calculateHistogram(Mat image) {
    Mat hist;
    hist = Mat::zeros(256, 1, CV_32F);
    // convert each pixel to be stored in float
    image.convertTo(image, CV_32F);
    double value = 0;
    for (int i = 0; i < image.rows; i++)
    {
        for (int j = 0; j < image.cols; j++)
        {
            value = image.at<float>(i, j);
            hist.at<float>(value) = hist.at<float>(value) + 1;
        }
    }
    return hist;
}
Mat Histogram:: plotHistogram(Mat histogram ,int r,int g,int b) {
    Mat histogram_image(400, 512, CV_8UC3, Scalar(0, 0, 0));
    Mat normalized_histogram;
    normalize(histogram, normalized_histogram, 0, 255, NORM_MINMAX, -1, Mat());

    for (int i = 0; i < 256; i++)
    {
        rectangle(histogram_image, Point(2 * i, histogram_image.rows - normalized_histogram.at<float>(i)),
                  Point(2 * (i + 1), histogram_image.rows), Scalar(r, g, b));
    }

    return histogram_image;

};


Mat Histogram:: normalizeImg(Mat input_image){
    Mat normalized_image;
    normalize(input_image,normalized_image,0,255,NORM_MINMAX,CV_8U);
    return normalized_image;
}




Mat Histogram:: equalizeImg(const Mat& input_image){
    Mat equalized_image;

     Mat gray_image;
     if (input_image.channels() > 1) {
         cvtColor(input_image, gray_image, COLOR_BGR2GRAY);
     } else {
         gray_image = input_image.clone();
     }

     // Compute histogram
     int histSize = 256;
     // const float* histRange = {range};
     Mat histogram;
     // calcHist(&gray_image, 1, nullptr, Mat(), histogram, 1, &histSize, &histRange, true, false);
     histogram=calculateHistogram(gray_image);

     // Calculate cumulative distribution function (CDF)
     Mat cdf(histSize, 1, CV_32F);
     cdf.at<float>(0) = histogram.at<float>(0) / (gray_image.rows * gray_image.cols);
     for (int i = 1; i < histSize; ++i) {
         cdf.at<float>(i) = cdf.at<float>(i - 1) + histogram.at<float>(i) / (gray_image.rows * gray_image.cols);
     }

     // Normalize the CDF
     Mat normalized_cdf;
     normalize(cdf, normalized_cdf, 0, 255, NORM_MINMAX, CV_8U);

     // Apply histogram equalization
     equalized_image = gray_image.clone();
     for (int i = 0; i < gray_image.rows; ++i) {
         for (int j = 0; j < gray_image.cols; ++j) {
             equalized_image.at<uchar>(i, j) = saturate_cast<uchar>(normalized_cdf.at<uchar>(gray_image.at<uchar>(i, j)));
         }
     }

     return equalized_image;

}

Mat Histogram:: distributionCurve(Mat histogram) {

    int num_bins = histogram.rows;
    // This is used to create the image where the curve is drawn
    Mat curve_image(400, 512, CV_8UC3, Scalar(0, 0, 0));

    Mat normalized_histogram;
    // normalizing
    normalize(histogram, normalized_histogram, 0, 255, NORM_MINMAX, -1, Mat());
    // vector containing the points that define the distribution curve
    vector<Point> curve_points(num_bins);
    for (int i = 0; i < num_bins; i++) {
        // point constructor that takes the x and y coordinates of the point, 2*i to space the points horizontally and to make the distrubution curve wider
        // second parameter to make the graph start from bottom to top
        curve_points[i] = Point(2 * i, curve_image.rows - normalized_histogram.at<float>(i));
    }
    const Point *pts = (const Point*)Mat(curve_points).data;
    // total number of points in the vector
    int npts = Mat(curve_points).rows;

    // polylines is used to draw the curve on the points
    polylines(curve_image, &pts, &npts, 1, false, Scalar(255, 255, 0), 2);

    return curve_image;

};
