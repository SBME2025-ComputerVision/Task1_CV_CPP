#include"histogram.h"

void calculate_histogram(Mat img_grayscale,map<int,int>&histogram,vector<float>&accumelated_histogram){
    for(int row=0;row<img_grayscale.rows;row++){
        for(int col=0;col<img_grayscale.cols;col+=){
            int pixel=img_grayscale.at<uchar>(row,col);
            histogram[pixel]++;
        }
    }
    int accumlator=0;
        for(auto &x :histogram){
        accumlator+=x.second;
        accumelated_histogram.push_back(accumlator);

    }

}

void normalize_img(Mat&img){
    float img_min=img.at<uchar>(0,0), img_max=0;
    for(int row=0;row<img.rows;row++){
        for(int col=0;col<img.cols;col++){
            if(img.at<uchar>(row,col)<=img_min){
                img_min=img.at<uchar>(row,col);
            }
            if(img.at<uchar>(row,col)>img_max){
                img_max=img.at<uchar>(row,col);
            }
        }
    }

    for(int row=0;row<img.rows;row++){
        for(int col=0;col<img.cols;col++){
            img.at<uchar>(row,col)=((img.at<uchar>(row,col)-img_min)/(img_max-img_min))*255;

        }
    }

}

Mat Equalize_img(Mat &img);
