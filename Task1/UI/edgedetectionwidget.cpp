#include "edgedetectionwidget.h"
#include "ui_edgedetectionwidget.h"
#include "config.h"

EdgeDetectionWidget::EdgeDetectionWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EdgeDetectionWidget)
{
    imageController = new ImageController();
    ui->setupUi(this);
}

EdgeDetectionWidget::~EdgeDetectionWidget()
{
    delete ui;
}

void EdgeDetectionWidget::on_apply_robert_detector_clicked()
{
    processedImg = imageController->DetectEdges(RobertDetector,50,250);
    processedImg = processedImg.scaled(ui->imageDetected->size(),Qt::IgnoreAspectRatio);
    ui->imageDetected->setPixmap(processedImg);
}


void EdgeDetectionWidget::on_apply_prewitt_detector_clicked()
{
    processedImg = imageController->DetectEdges(PrewittDetector,50,250);
    processedImg = processedImg.scaled(ui->imageDetected->size(),Qt::IgnoreAspectRatio);
    ui->imageDetected->setPixmap(processedImg);
}


void EdgeDetectionWidget::on_apply_sobel_detector_clicked()
{
    processedImg = imageController->DetectEdges(SobelDetector,50,250);
    processedImg = processedImg.scaled(ui->imageDetected->size(),Qt::IgnoreAspectRatio);
    ui->imageDetected->setPixmap(processedImg);
}


void EdgeDetectionWidget::on_apply_canny_detector_clicked()
{
    processedImg = imageController->DetectEdges(CannyDetector,30,120);
    processedImg = processedImg.scaled(ui->imageDetected->size(),Qt::IgnoreAspectRatio);
    ui->imageDetected->setPixmap(processedImg);

}


void EdgeDetectionWidget::on_uploadImgBtn_clicked()
{
    originalImg = imageController->uploadImg();
    processedImg = imageController->getGreyScaledImg();
    originalImg = originalImg.scaled(ui->imageOriginal->size(),Qt::IgnoreAspectRatio);
    processedImg = processedImg.scaled(ui->imageDetected->size(),Qt::IgnoreAspectRatio);
    ui->imageOriginal->setPixmap(originalImg);
    ui->imageDetected->setPixmap(processedImg);
}


void EdgeDetectionWidget::on_resetFilterBtn_clicked()
{
    processedImg = imageController->getGreyScaledImg();
    processedImg = processedImg.scaled(ui->imageDetected->size(),Qt::IgnoreAspectRatio);
    ui->imageDetected->setPixmap(processedImg);
}


