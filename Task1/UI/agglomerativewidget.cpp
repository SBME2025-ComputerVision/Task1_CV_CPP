#include "agglomerativewidget.h"
#include "ui_agglomerativewidget.h"

AgglomerativeWidget::AgglomerativeWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AgglomerativeWidget)
{
    ui->setupUi(this);
    agglomerativeController = new AgglomerativeController();

    ui->kCluserSlider->setMinimum(1);
    ui->kCluserSlider->setMaximum(10);
    ui->kCluserSlider->setValue(3);


    int numClusters = ui->kCluserSlider->value();
    std::string numClustersStr = std::to_string(numClusters);
    QString qNumClustersStr = QString::fromStdString(numClustersStr);
    ui->label_4->setText("Number of Clusters: " + qNumClustersStr);
}

AgglomerativeWidget::~AgglomerativeWidget()
{
    delete ui;
}




void AgglomerativeWidget::on_browseBtn_2_clicked()
{
    originalImg = agglomerativeController->uploadImg();
    processedImg = originalImg;
    originalImg = originalImg.scaled(ui->originalImage_2->size(),Qt::IgnoreAspectRatio);
    processedImg = processedImg.scaled(ui->processedImage_2->size(),Qt::IgnoreAspectRatio);
    ui->originalImage_2->setPixmap(originalImg);
    ui->processedImage_2->setPixmap(processedImg);
}


void AgglomerativeWidget::on_segmentBtn_clicked()
{
    int k = ui->kCluserSlider->value();
    processedImg = agglomerativeController->aggClustering(k);
    processedImg = processedImg.scaled(ui->processedImage_2->size(),Qt::IgnoreAspectRatio);
    ui->processedImage_2->setPixmap(processedImg);
}





void AgglomerativeWidget::on_kCluserSlider_sliderReleased()
{
    int numClusters = ui->kCluserSlider->value();
    std::string numClustersStr = std::to_string(numClusters);
    QString qNumClustersStr = QString::fromStdString(numClustersStr);
    ui->label_4->setText("Number of Clusters: " + qNumClustersStr);
}

