#include "segmentationwidget.h"
#include "ui_segmentationwidget.h"

SegmentationWidget::SegmentationWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SegmentationWidget)
{
    ui->setupUi(this);
    ui->stackedWidget->addWidget(regionWidget);
    ui->stackedWidget->addWidget(meansShiftWidget);
    ui->stackedWidget->addWidget(agglomerativeWidget);
    ui->stackedWidget->addWidget(kmeansWidget);
    menuBtns.append(ui->meanShiftBtn);
    menuBtns.append(ui->kmeansBtn);
    menuBtns.append(ui->aggBtn);
    menuBtns.append(ui->regionGrowingBtn);

    style="\
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
            height: 40px;\
    }\
        QPushButton:hover {\
            background-color: rgba(118, 171, 174, 203);\
            text-decoration: none;\
    }\
        QPushButton:focus {\
            outline: 1px transparent;\
    }";

    ui->regionGrowingBtn->setStyleSheet("background-color: #76ABAE;");
}


void SegmentationWidget::changeButtonColors(QList<QPushButton*> list, QString style){
    foreach (QPushButton *btn, list) {
        btn->setStyleSheet(style);
    }
}

SegmentationWidget::~SegmentationWidget()
{
    delete ui;
}

void SegmentationWidget::on_kmeansBtn_clicked()
{

    changeButtonColors(menuBtns,style);
    ui->kmeansBtn->setStyleSheet("background-color: #76ABAE;");
    ui->stackedWidget->setCurrentWidget(kmeansWidget);
    setWindowState(Qt::WindowMaximized);
    // TODO: merege with k means


}


void SegmentationWidget::on_regionGrowingBtn_clicked()
{
    changeButtonColors(menuBtns,style);
    ui->regionGrowingBtn->setStyleSheet("background-color: #76ABAE;");
    ui->stackedWidget->setCurrentWidget(regionWidget);
    setWindowState(Qt::WindowMaximized);

}


void SegmentationWidget::on_meanShiftBtn_clicked()
{
    changeButtonColors(menuBtns,style);
    ui->meanShiftBtn->setStyleSheet("background-color: #76ABAE;");
    ui->stackedWidget->setCurrentWidget(meansShiftWidget);
    setWindowState(Qt::WindowMaximized);
}


void SegmentationWidget::on_aggBtn_clicked()
{
    changeButtonColors(menuBtns,style);
    ui->aggBtn->setStyleSheet("background-color: #76ABAE;");
    ui->stackedWidget->setCurrentWidget(agglomerativeWidget);
    setWindowState(Qt::WindowMaximized);
}

