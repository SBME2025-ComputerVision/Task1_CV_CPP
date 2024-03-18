#include "thresholdwidget.h"
#include "ui_thresholdwidget.h"
#include "config.h"

ThresholdWidget::ThresholdWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ThresholdWidget)
{
    ui->setupUi(this);
    thresholdController = new ThresholdController();
}

ThresholdWidget::~ThresholdWidget()
{
    delete ui;
}




void ThresholdWidget::on_globalThresholdBtn_clicked()
{

}


void ThresholdWidget::on_localThresholdBtn_clicked()
{

}


void ThresholdWidget::on_uploadBtn_clicked()
{
    originalImg = thresholdController->uploadImg();
    processedImg = thresholdController->convertToGrayScale();
    originalImg = originalImg.scaled(ui->originalImage->size(),Qt::IgnoreAspectRatio);
    processedImg = processedImg.scaled(ui->processedImage->size(),Qt::IgnoreAspectRatio);
    ui->originalImage->setPixmap(originalImg);
    ui->processedImage->setPixmap(processedImg);
}

