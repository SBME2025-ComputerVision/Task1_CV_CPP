#include "threshold.h"
#include "config.h"
Threshold::Threshold() {}

Mat Threshold::globalThresholding(Mat img, int thresholdValue){
    Mat res =img.clone();
    for(int i = 0;i<res.rows;i++){
        for(int j=0;j<res.cols;j++){
            if(res.at<uchar>(i,j) >= thresholdValue ){
                res.at<uchar>(i,j)= 255;
            }else{
                res.at<uchar>(i,j)=0;
            }
        }
    }
    return res;
}

Mat Threshold::localThresholding(Mat img, int kernelSize, int C){
    Mat res =img.clone();
      Mat mean_window = local_threshold_mean_calculation(img, 9, C);
    for (int i = 0; i < img.rows; i++)
       {
           for (int  j = 0; j < img.cols; j++)
           {
                   if (img.at<uchar>(i, j) >= mean_window.at<uchar>(i, j))
                   {
                       res.at<uchar>(i, j) = 255;
                   }
                   else
                   {
                       res.at<uchar>(i, j) = 0;
                   }
           }
       }
    return res;
}

Mat Threshold::Padd_Mono(const Mat &src, int padding_margin , int data_type)
{
    Mat padding_img;
    if (data_type == UCHAR_FLAG)
    {
        padding_img =  Mat::zeros(Size(src.cols + padding_margin * 2, src.rows + padding_margin * 2), src.type());
    }
    else if (data_type == FLOAT_FLAG)
    {
        padding_img =  Mat::zeros(Size(src.cols + padding_margin * 2, src.rows + padding_margin * 2), CV_32FC1);
    }
    for (int i = 0; i < src.rows; i++)
    {
        for (int j = 0; j < src.cols; j++)
        {
            if (data_type == UCHAR_FLAG)
            {
                padding_img.at<uchar>(i + padding_margin, j + padding_margin) = src.at<uchar>(i, j);
            }
            else if (data_type == FLOAT_FLAG)
            {
                padding_img.at<float>(i + padding_margin, j + padding_margin) = src.at<float>(i, j);
            }
        }
    }
    return padding_img;
}

Mat Threshold::thresholdingHistogram(Mat image)
{
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

Mat Threshold::optimumThresholding(Mat img, bool isGlobal = true)
{
    Mat grey_img = img.clone();
    if (isGlobal) cvtColor(img, grey_img, COLOR_BGR2GRAY);
    vector<float>foreground,background;
    float currentThreshold,prevThreshold;
    currentThreshold = grey_img.at<uchar>(0,0)+grey_img.at<uchar>(0,img.cols-1)+grey_img.at<uchar>(img.rows-1,0)+grey_img.at<uchar>(img.rows-1,img.cols-1);
    currentThreshold/=4;

    Mat pdf = Threshold::thresholdingHistogram(grey_img);

    // @TODO Epsilon by the user
    do{
        int sum1=0,sum2=0;
        int cdf1=0,cdf2=0;
        for(int i=0;i<256;i++){
            if(i>currentThreshold){
                sum1 += i* pdf.at<float>(i);
                cdf1 += pdf.at<float>(i);
            }
            else{
                sum2 += i* pdf.at<float>(i);
                cdf2 += pdf.at<float>(i);
            }
        }
        // @TODO Float div
        int muo1,muo2;
        muo1 = sum1/cdf1;
        muo2 = sum2/cdf2;
        prevThreshold = currentThreshold;
        currentThreshold = (muo1 + muo2)/2.0;
    }
    while(abs(currentThreshold-prevThreshold) > 0.002);
    grey_img = Threshold::applyThresholding(grey_img,currentThreshold);
    return grey_img;

}

Mat Threshold::applyThresholding(Mat grey_img, float currentThreshold)
{

    for(int i=0;i<grey_img.rows;i++){
        for(int j=0;j<grey_img.cols;j++){
            if(grey_img.at<uchar>(i,j) > currentThreshold){
                grey_img.at<uchar>(i,j) = 255;
            }
            else{
                grey_img.at<uchar>(i,j) = 0;
            }
        }
    }
    return grey_img;
}

Mat Threshold::otsuThresholding(Mat img, bool isGlobal = true)
{
    Mat grey_img = img.clone();
     if (isGlobal) cvtColor(img, grey_img, COLOR_BGR2GRAY);
    Mat pdf = Threshold::thresholdingHistogram(grey_img);
    Mat cdf = Mat::zeros(256,1,CV_32F);
    Mat weighted_cdf = Mat::zeros(256,1,CV_32F);
    cdf.at<float>(0) = pdf.at<float>(0);
    weighted_cdf.at<float>(0) = 0;

    for(int i=1;i<256;i++){
        cdf.at<float>(i) = cdf.at<float>(i-1) +  pdf.at<float>(i);
        weighted_cdf.at<float>(i) = weighted_cdf.at<float>(i-1) + i*pdf.at<float>(i);
    }
    float maxPixel = cdf.at<float>(255);
    cdf /= maxPixel;

    float best_k = 0, best_Variance = 0;

    for(int k=0;k<256;k++){
        float w0=0,w1=0,sum1=0,sum2=0,cdf1=0,cdf2=0;
        w0 = cdf.at<float>(k);
        w1 = 1-w0;
        sum1 = weighted_cdf.at<float>(k);
        sum2 = weighted_cdf.at<float>(255)-sum1;
        cdf1 = ( cdf.at<float>(k) )*maxPixel;
        cdf2 = (1-cdf.at<float>(k))*maxPixel;

        float muo=0,mu1=0;
        muo = sum1/cdf1;
        mu1 = sum2/cdf2;
        float interClassVar = w0*w1*(muo-mu1)*(muo-mu1);
        qDebug()<<"inter"<<interClassVar<<"best"<<best_Variance;
        if(interClassVar > best_Variance){
            best_k = k;
            best_Variance = interClassVar;
        }
    }
    grey_img = Threshold::applyThresholding(grey_img, best_k);
    return grey_img;
}

Mat Threshold::spectralThresholding(Mat img,bool isGlobal = true)
{
    Mat gray_image = img.clone();
     if (isGlobal) cvtColor(img, gray_image, COLOR_BGR2GRAY);
    Mat pdf = Threshold::thresholdingHistogram(gray_image);

    Mat cdf = Mat::zeros(256,1,CV_32F);
    Mat weighted_cdf = Mat::zeros(256,1,CV_32F);
    cdf.at<float>(0) = pdf.at<float>(0);
    weighted_cdf.at<float>(0) = 0;

    for(int i=1;i<256;i++){
        cdf.at<float>(i) = cdf.at<float>(i-1) +  pdf.at<float>(i);
        weighted_cdf.at<float>(i) = weighted_cdf.at<float>(i-1) + i*pdf.at<float>(i);
    }

    float maxPixel = cdf.at<float>(255);
    float mean = cdf.at<float>(255);
    mean /= maxPixel;

    float w0=0,w1=0,w2=0;
    float optimal_high = 0, optimal_low = 0, max_variance = 0;
    for(int high = 0;high<256;high++){
        for( int low = 0; low<high;low++){

            if(low>0)       w0 = cdf.at<float>(low-1);
            else  w0 = cdf.at<float>(low);
            if(!w0) continue;


            float mean0 = weighted_cdf.at<float>(low) / float(w0);

            if(high>0)  w1 = cdf.at<float>(high-1)-cdf.at<float>(low);
            else w1 = cdf.at<float>(high)-cdf.at<float>(low);
            if(!w1) continue;

            float mean1 = (weighted_cdf.at<float>(high)-weighted_cdf.at<float>(low)) / float(w1);


            w2 = cdf.at<float>(255)-cdf.at<float>(high)+pdf.at<float>(high);
            if(!w2) continue;
            float mean2 = (weighted_cdf.at<float>(255)-weighted_cdf.at<float>(high))/ float(w2);

            float variance = w0 * (mean0 - mean)*(mean0 - mean) + w1 * (mean1 - mean) * (mean1 - mean) + w2 * (mean2 - mean)*(mean2 - mean);

            if(variance>max_variance){
                optimal_high = high;
                optimal_low = low;
                max_variance = variance;
            }
        }
    }
    gray_image = Threshold::applyDoubleThresholding(gray_image, optimal_high,optimal_low);

    return gray_image;
}

Mat Threshold::applyDoubleThresholding(Mat gray_image, float optimal_high, float optimal_low)
{

    for( int row=0;row<gray_image.rows;row++){

        for(int col = 0; col<gray_image.cols;col++){

            if(gray_image.at<uchar>(row,col) > optimal_high ){
                gray_image.at<uchar>(row,col) = 255;
            }
            else if (gray_image.at<uchar>(row,col) < optimal_low){
                gray_image.at<uchar>(row,col) = 128;
            }
            else{
                gray_image.at<uchar>(row,col) = 0;
            }
        }
    }
    return gray_image;
}

Mat Threshold::localspectral(Mat img)
{
    cvtColor(img, img, COLOR_BGR2GRAY);
    int rows,cols;
    rows = img.rows;
    cols = img.cols;
    Rect roi1(0,0,cols/2,rows/2);
    Rect roi2(cols/2,0,cols/2,rows/2);
    Rect roi3(0,rows/2,cols/2,rows/2);
    Rect roi4(cols/2,rows/2,cols/2,rows/2);

    Mat part1 = img(roi1);
    part1 = Threshold::spectralThresholding(part1, false);
    Mat part2 = img(roi2);
    part2 = Threshold::spectralThresholding(part2, false);
    Mat part3 = img(roi3);
    part3 = Threshold::spectralThresholding(part3, false);
    Mat part4 = img(roi4);
    part4 = Threshold::spectralThresholding(part4, false);

    Mat gray_image = img.clone();

    part1.copyTo(gray_image(roi1));
    part2.copyTo(gray_image(roi2));
    part3.copyTo(gray_image(roi3));
    part4.copyTo(gray_image(roi4));
    return gray_image;
}

Mat Threshold::localOptimum(Mat img)
{
    cvtColor(img, img, COLOR_BGR2GRAY);
    int rows,cols;
    rows = img.rows;
    cols = img.cols;
    Rect roi1(0,0,cols/2,rows/2);
    Rect roi2(cols/2,0,cols/2,rows/2);
    Rect roi3(0,rows/2,cols/2,rows/2);
    Rect roi4(cols/2,rows/2,cols/2,rows/2);

    Mat part1 = img(roi1);
    part1 = Threshold::optimumThresholding(part1, false);
    Mat part2 = img(roi2);
    part2 = Threshold::optimumThresholding(part2, false);
    Mat part3 = img(roi3);
    part3 = Threshold::optimumThresholding(part3, false);
    Mat part4 = img(roi4);
    part4 = Threshold::optimumThresholding(part4, false);

    Mat gray_image = img.clone();

    part1.copyTo(gray_image(roi1));
    part2.copyTo(gray_image(roi2));
    part3.copyTo(gray_image(roi3));
    part4.copyTo(gray_image(roi4));
    return gray_image;
}

Mat Threshold::localOtsu(Mat img)
{
    cvtColor(img, img, COLOR_BGR2GRAY);
    int rows,cols;
    rows = img.rows;
    cols = img.cols;
    Rect roi1(0,0,cols/2,rows/2);
    Rect roi2(cols/2,0,cols/2,rows/2);
    Rect roi3(0,rows/2,cols/2,rows/2);
    Rect roi4(cols/2,rows/2,cols/2,rows/2);

    Mat part1 = img(roi1);
    part1 = Threshold::otsuThresholding(part1, false);
    Mat part2 = img(roi2);
    part2 = Threshold::otsuThresholding(part2, false);
    Mat part3 = img(roi3);
    part3 = Threshold::otsuThresholding(part3, false);
    Mat part4 = img(roi4);
    part4 = Threshold::otsuThresholding(part4, false);

    Mat gray_image = img.clone();

    part1.copyTo(gray_image(roi1));
    part2.copyTo(gray_image(roi2));
    part3.copyTo(gray_image(roi3));
    part4.copyTo(gray_image(roi4));
    return gray_image;
}


Mat adaptive_padding_function(Mat src){

    Mat dst;
    dst = Threshold::Padd_Mono(src, 1);

    for (int i = 0; i < src.rows; i++)
    {
        for (int j = 0; j < src.cols; j++)
        {
            if( i == 0  && j == 0 ) {
                dst.at<uchar>(i, j) = src.at<uchar>(i, j);
            }
            if(i == src.rows - 1 && j == src.cols - 1){
                dst.at<uchar>(i + 2, j + 2) = src.at<uchar>(i, j);
            }
            if(i == 0 &&  j == src.cols - 1){
                dst.at<uchar>(i , j + 2) = src.at<uchar>(i, j);
            }
            if(i == src.rows - 1 && j == 0){
                dst.at<uchar>(i + 2 , j) = src.at<uchar>(i, j);
            }
            if( i == 0 ){
                dst.at<uchar>(i , j + 1) = src.at<uchar>(i, j);
            }
            if ( j == 0 ){
                dst.at<uchar>(i + 1, j) = src.at<uchar>(i, j);
            }
            if( j == src.cols - 1){
                dst.at<uchar>(i + 1, j + 2) = src.at<uchar>(i, j);
            }
            if( i == src.rows - 1){
                dst.at<uchar>(i + 2 , j + 1) = src.at<uchar>(i, j);
            }
        }
    }

    return dst;
}

Mat Threshold::local_threshold_mean_calculation(const Mat &src, int target_app, int C)
{
    std::vector<int> mean_values;
    Mat padded_img = adaptive_padding_function(src);
    Mat convoluted_img = Mat::zeros(Size(src.cols, src.rows), src.type());

    float window_values[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    Mat mean_window = Mat(3, 3, CV_32F, window_values);

    int h = mean_window.rows / 2;
    int w = mean_window.cols / 2;

    float window_sum;
    for (int i = 1; i < (padded_img.rows - 1); i++)
    {
        for (int j = 1; j < (padded_img.cols - 1); j++)
        {
            window_sum = 0;
            for (int m = 0; m < mean_window.rows; m++)
            {
                for (int n = 0; n < mean_window.cols; n++)
                {
                    window_sum += padded_img.at<uchar>(i + m - h, j + n - w) * mean_window.at<float>(m, n);

                }
            }
            convoluted_img.at<uchar>(i - 1, j - 1) = window_sum/target_app - C;

        }
    }
    return convoluted_img;
}

