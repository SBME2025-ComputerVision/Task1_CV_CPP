#include "UI/mainwindow.h"
#include "Models/filter.h"
#include <opencv2/opencv.hpp>
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    cv::Mat originalImga;
    cv::Mat originalImgb;
    // Load an image
    originalImga = cv::imread("Gallery/cat.jpg", cv::IMREAD_GRAYSCALE);
    originalImgb = cv::imread("Gallery/cutie.jpg", cv::IMREAD_GRAYSCALE);

    if (originalImga.empty()||originalImgb.empty()) {
        qDebug() << "Failed to load image!";
        return -1;
    }

    // Resize both images
    // cv::Size newSize(900, 900);
    cv::resize(originalImga, originalImga, originalImgb.size());
    // cv::resize(originalImgb, originalImgb, newSize);

    cv::Mat lowpassImg, highpassImg;

    lowpassImg = Filter::applyFrequencyFilter(originalImga,30,HighPassFilter);
    highpassImg = Filter::applyFrequencyFilter(originalImgb,30,LowPassFilter);

    cv::Mat hybridImg;
    hybridImg = lowpassImg + highpassImg;
    cv::normalize(hybridImg, hybridImg, 0, 255, cv::NORM_MINMAX);

    cv::imwrite("hybrid_image.jpg", hybridImg);


    // cv::imwrite("mama1.jpg", highpassImg);
    // cv::imwrite("mama2.jpg", lowpassImg);


    // // Verify sizes and types of matrices
    // if (filteredFourierImga.size() != filteredFourierImgb.size() ||
    //     filteredFourierImga.type() != filteredFourierImgb.type()) {
    //     qDebug() << "Sizes or types of filtered Fourier images do not match!";
    //     return -1;
    // }

    // // Normalize the hybrid image to 0-255 range

    // cv::imwrite("hybrid_image.jpg", hybridImg);
    return a.exec();
}
