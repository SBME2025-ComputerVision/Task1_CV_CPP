#include"histogram.h"


void Histogram:: calculate_histogram(Mat img_grayscale,map<int,int>&histogram ,vector<float>&accumelated_histogram){
    for(int row=0;row<img_grayscale.rows;row++){
        for(int col=0;col<img_grayscale.cols;col++){
            int pixel=img_grayscale.at<uchar>(row,col);
            histogram[pixel]++;
        }
    }
    int accumlator=0;
        for(auto &x :histogram){
        accumlator+=x.second;
        accumelated_histogram.push_back(accumlator);

    }
    // Mat histogram;
    // histogram=Mat::zeros(256,1,CV_32F);
    // img.convertTo(img,CV_32F);
    // flaot value=0;
    // for(int row=0;row<img.rows;row++){
    //     for(int col=0;col<img.cols;col++){
    //         value=img.at<float>(row,col);
    //         histogram.at<float>(value)+=1;
    //     }
    // }


}

Mat Histogram:: normalize_img(Mat img){
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
    return img;
}

Mat Histogram:: Equalize_img(Mat img){
    map<int,int> histogram;
    map<int,int>intensity_value;
    vector<float>cumulative_histogram;
    Mat output_image=img.clone();
    calculate_histogram(img,histogram,cumulative_histogram);
    float cumulative_distribtion_function=0;
    int pixels_sum=0;
    for(auto &x:histogram){
        pixels_sum+=x.second;
    }
    for(auto &x:histogram){
        float value=(float)(x.second)/pixels_sum;
        cumulative_distribtion_function+=value;
        intensity_value.insert({x.first,round((float)cumulative_distribtion_function*255)});
    }
    for(int row=0;row<output_image.rows;row++){
        for(int col=0;col<output_image.cols;col++){
            output_image.at<uchar>(row,col)=intensity_value[img.at<uchar>(row,col)];
        }
    }
    return output_image;

}
