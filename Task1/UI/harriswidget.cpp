#include "harriswidget.h"
#include "ui_harriswidget.h"

HarrisWidget::HarrisWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HarrisWidget)
{
    ui->setupUi(this);
     harriscontroller=new HarrisController;
     kernels.append(ui->threeByThreeKernelBtn);
     kernels.append(ui->fiveByFiveKernelBtn);
}

HarrisWidget::~HarrisWidget()
{
    delete ui;
}

void HarrisWidget::changeButtonColors(QList<QPushButton*> list, QString style){
    foreach (QPushButton *btn, list) {
        btn->setStyleSheet(style);
    }
}

void HarrisWidget::on_threeByThreeKernelBtn_clicked()
{
    QString style ="\
        QPushButton {\
            background-color: #316669;\
            border: none;\
            border-radius: 6px;\
            color: #EEEEEE;\
            font-size: 14px;\
            font-weight: 500;\
            line-height: 20px;\
            list-style: none;\
            padding: 4px 12px;\
            height: 30px;\
    }\
        QPushButton:hover {\
            background-color: rgba(118, 171, 174, 203);\
            text-decoration: none;\
    }\
        QPushButton:focus {\
            outline: 1px transparent;\
    }";
    changeButtonColors(kernels,style);

    ui->threeByThreeKernelBtn->setStyleSheet("background-color: #76ABAE;");
      cornerDetectionParams.kernelSize = 3;
}


void HarrisWidget::on_fiveByFiveKernelBtn_clicked()
{
    QString style ="\
        QPushButton {\
            background-color: #316669;\
            border: none;\
            border-radius: 6px;\
            color: #EEEEEE;\
            font-size: 14px;\
            font-weight: 500;\
            line-height: 20px;\
            list-style: none;\
            padding: 4px 12px;\
            height: 30px;\
    }\
        QPushButton:hover {\
            background-color: rgba(118, 171, 174, 203);\
            text-decoration: nonethreeByThreeKernelBtn;\
    }\
        QPushButton:focus {\
            outline: 1px transparent;\
    }";
    changeButtonColors(kernels,style);
    ui->fiveByFiveKernelBtn->setStyleSheet("background-color: #76ABAE;");
    cornerDetectionParams.kernelSize = 5;
}

void HarrisWidget::on_uploadImgBtn_clicked()
{
    originalImg = harriscontroller->uploadImg();
    processedImg = originalImg;
    originalImg = originalImg.scaled(ui->imageOriginal->size(),Qt::IgnoreAspectRatio);
    processedImg = processedImg.scaled(ui->imageDetected->size(),Qt::IgnoreAspectRatio);
    ui->imageOriginal->setPixmap(originalImg);
    ui->imageDetected->setPixmap(processedImg);
}


void HarrisWidget::on_applyBtn_clicked()
{
    processedImg = harriscontroller->detectCorners(ui->comboBox->currentIndex()+1, ui->threshold->value(),cornerDetectionParams.kernelSize );
    processedImg = processedImg.scaled(ui->imageDetected->size(),Qt::IgnoreAspectRatio);
    ui->imageDetected->setPixmap(processedImg);
}


void HarrisWidget::on_resetFilterBtn_clicked()
{
    processedImg = originalImg;
    processedImg = processedImg.scaled(ui->imageDetected->size(),Qt::IgnoreAspectRatio);
    ui->imageDetected->setPixmap(processedImg);
    ui->threshold->setValue(100.0);
}

