#include "kmeanswidget.h"
#include "ui_kmeanswidget.h"
#include "config.h"
#include "QString"


KmeansWidget::KmeansWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::KmeansWidget)
{
    ui->setupUi(this);
    kmeansController = new KmeansController();

    ui->kCluserSlider->setMinimum(1);
    ui->kCluserSlider->setMaximum(10);
    ui->kCluserSlider->setValue(3);


    int numClusters = ui->kCluserSlider->value();
    std::string numClustersStr = std::to_string(numClusters);
    QString qNumClustersStr = QString::fromStdString(numClustersStr);
    ui->clustersNum->setText("Number of Clusters: " + qNumClustersStr);
}

KmeansWidget::~KmeansWidget()
{
    delete ui;
}

void KmeansWidget::on_browseBtn_clicked()
{

    originalImg = kmeansController->uploadImg();
    processedImg = originalImg;
    originalImg = originalImg.scaled(ui->originalImage->size(),Qt::IgnoreAspectRatio);
    processedImg = processedImg.scaled(ui->processedImage->size(),Qt::IgnoreAspectRatio);
    ui->originalImage->setPixmap(originalImg);
    ui->processedImage->setPixmap(processedImg);

}

void KmeansWidget::on_kCluserSlider_sliderReleased()
{

    int numClusters = ui->kCluserSlider->value();
    std::string numClustersStr = std::to_string(numClusters);
    QString qNumClustersStr = QString::fromStdString(numClustersStr);
    ui->clustersNum->setText("Number of Clusters: " + qNumClustersStr);



}


void KmeansWidget::on_segmentBtn_clicked()
{

    int k = ui->kCluserSlider->value();
    processedImg = kmeansController->kmeanClustering(k);
    processedImg = processedImg.scaled(ui->processedImage->size(),Qt::IgnoreAspectRatio);
    ui->processedImage->setPixmap(processedImg);
}
