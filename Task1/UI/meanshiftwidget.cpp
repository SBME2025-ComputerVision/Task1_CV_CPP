#include "meanshiftwidget.h"
#include "ui_meanshiftwidget.h"

MeanShiftWidget::MeanShiftWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MeanShiftWidget)
{
    ui->setupUi(this);
    meansShiftController = new MeansShiftController();
}

MeanShiftWidget::~MeanShiftWidget()
{
    delete ui;
}

void MeanShiftWidget::on_uploadMeansShiftBtn_clicked()
{
    originalImg=meansShiftController->uploadImg();
    processedImg=originalImg;
    originalImg=originalImg.scaled(ui->originalImgWidget->size(),Qt::IgnoreAspectRatio);
    processedImg=processedImg.scaled(ui->processedImgWidget->size(),Qt::IgnoreAspectRatio);
    ui->originalImgWidget->setPixmap(originalImg);
    ui->processedImgWidget->setPixmap(processedImg);
}


void MeanShiftWidget::on_applyMeansShiftBtn_clicked()
{
    float colorBandwidth,distanceBandwidth;
   colorBandwidth= ui->colorBandwidthSpinBox->value();
   distanceBandwidth=ui->distanceBandwidthSpinBox->value();
    processedImg=meansShiftController->getMeansShiftSegmentedImg(distanceBandwidth,colorBandwidth);
    processedImg=processedImg.scaled(ui->processedImgWidget->size(),Qt::IgnoreAspectRatio);
    ui->processedImgWidget->setPixmap(processedImg);
}


