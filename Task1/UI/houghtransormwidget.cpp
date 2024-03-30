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

