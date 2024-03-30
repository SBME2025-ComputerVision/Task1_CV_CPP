#include "houghtransormwidget.h"
#include "ui_houghtransormwidget.h"

HoughTransormWidget::HoughTransormWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HoughTransormWidget)
{
    ui->setupUi(this);
    shapes.append(ui->EllipseShapeBtn);
    shapes.append(ui->circleShapeBtn);
    shapes.append(ui->lineShapeBtn);

    style ="\
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
    ui->lineShapeBtn->setStyleSheet("background-color: #76ABAE;");
    houghController = new HoughController();

}

HoughTransormWidget::~HoughTransormWidget()
{
    delete ui;
}

void HoughTransormWidget::changeButtonColors(QList<QPushButton*> list, QString style){
    foreach (QPushButton *btn, list) {
        btn->setStyleSheet(style);
    }
}

void HoughTransormWidget::on_uploadImgBtn_clicked()
{
    originalImg = houghController->uploadImg();
    processedImg = houghController->convertToGrayScale();
    originalImg = originalImg.scaled(ui->imageOriginal->size(),Qt::IgnoreAspectRatio);
    processedImg = processedImg.scaled(ui->imageDetected->size(),Qt::IgnoreAspectRatio);
    ui->imageOriginal->setPixmap(originalImg);
    ui->imageDetected->setPixmap(processedImg);





}


void HoughTransormWidget::on_lineShapeBtn_clicked()
{
    changeButtonColors(shapes,style);
    ui->lineShapeBtn->setStyleSheet("background-color: #76ABAE;");
}


void HoughTransormWidget::on_circleShapeBtn_clicked()
{
    changeButtonColors(shapes,style);
    ui->circleShapeBtn->setStyleSheet("background-color: #76ABAE;");
}


void HoughTransormWidget::on_EllipseShapeBtn_clicked()
{
    changeButtonColors(shapes,style);
    ui->EllipseShapeBtn->setStyleSheet("background-color: #76ABAE;");
}





void HoughTransormWidget::on_lineThresholdSlider_valueChanged(int value)
{
    ui->lineThresholdValue->clear();
    double r = (((double) value+1) / 100.0 )*150;
    ui->lineThresholdValue->setNum((int) r-1);
}


void HoughTransormWidget::on_minRadiusSlider_valueChanged(int value)
{
    ui->minRadiusValue->clear();
    double r = (((double) value+1) / 100.0 )*150;
    ui->minRadiusValue->setNum((int) r-1);
}


void HoughTransormWidget::on_maxRadiusSlider_valueChanged(int value)
{
    ui->maxRadiusValue->clear();
    double r = (((double) value+1) / 100.0 )*150;
    ui->maxRadiusValue->setNum((int) r-1);
}

