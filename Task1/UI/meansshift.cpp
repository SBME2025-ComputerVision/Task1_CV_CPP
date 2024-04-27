#include "meansshift.h"
#include "ui_meansshift.h"

MeansShift::MeansShift(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MeansShift)
{
    ui->setupUi(this);
}

MeansShift::~MeansShift()
{
    delete ui;
}

void MeansShift::on_applyMeansShiftBtn_clicked()
{
    float colorBandwidth,distanceBandwidth;
    colorBandwidth= ui->colorBandwidthSpinBox->value();
    distanceBandwidth=ui->distanceBandwidthSpinBox->value();
    processedImg=meansShiftController->getMeansShiftSegmentedImg(distanceBandwidth,colorBandwidth);
}


void MeansShift::on_uploadMeansShiftBtn_clicked()
{
    originalImg=meansShiftController->uploadImg();
    processedImg=originalImg;
    originalImg=originalImg.scaled(ui->originalImgWidget->size(),Qt::IgnoreAspectRatio);
    processedImg=processedImg.scaled(ui->processedImgWidget->size(),Qt::IgnoreAspectRatio);
    ui->originalImgWidget->setPixmap(originalImg);
    ui->processedImgWidget->setPixmap(processedImg);
}

