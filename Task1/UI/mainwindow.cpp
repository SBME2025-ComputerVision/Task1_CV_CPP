#include "mainwindow.h"

#include "ui_mainwindow.h"
#include <opencv2/opencv.hpp>

#include "config.h"

#include "UI/filterswidget.h"

#include "UI/edgedetectionwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    index = FilterPage;



    // FiltersWidget *filterWidget = new FiltersWidget();
    // FrequencyWidget *frequencyWidget = new FrequencyWidget();


    ui->stackedWidget->addWidget(filterWidget);
    ui->stackedWidget->addWidget(edgeDetectionWidget);
    ui->stackedWidget->addWidget(histogramWidget);
    ui->stackedWidget->addWidget(plotWidget);
    ui->stackedWidget->addWidget(frequencyWidget);
    ui->stackedWidget->setCurrentIndex(index);



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_filteringBtn_clicked()
{
    // index = FilterPage;
    // MainWindow::setFrameIndex(index);
    // while(index != FilterPage){
    //     onBtnMinus();
    // }
    ui->stackedWidget->setCurrentWidget(filterWidget);

}


void MainWindow::on_edgeDetectionBtn_clicked()
{
    // index = EdgeDetectionPage;
    // setFrameIndex(index);
    // while(index != EdgeDetectionPage){
    //     if(index < EdgeDetectionPage){
    //         onBtnPlus();
    //     }else{
    //         onBtnMinus();
    //     }
    // }
   ui->stackedWidget->setCurrentWidget(edgeDetectionWidget);

}


void MainWindow::on_histogramsBtn_clicked()
{
    index = 1;
//    qDebug()<<1;
//    MainWindow::setFrameIndex(index);
    ui->stackedWidget->setCurrentWidget(plotWidget);
}


void MainWindow::on_thresholdingBtn_clicked()
{
//    index = ThresholdingPage;
//    ui->stackedWidget->setCurrentWidget(plotWidget);
}


void MainWindow::on_hybridBtn_clicked()
{
    index = HybridPage;
    MainWindow::setFrameIndex(index);
}

void MainWindow::on_frequencyBtn_clicked()
{
    // index = FrequencyPage;
    // MainWindow::setFrameIndex(index);
    ui->stackedWidget->setCurrentWidget(frequencyWidget);
}

void MainWindow::setFrameIndex(int index){
    cout<<"idx"<<index<<endl;
    // cout <<ui->stackedWidget->count()-1<<"mama"<<endl;

    if(index <ui->stackedWidget->count()-1){

        ui->stackedWidget->setCurrentIndex(index);
    }

}

void MainWindow::onBtnPlus(){
    if (index < ui->stackedWidget->count()-1){
        ui->stackedWidget->setCurrentIndex(++index);
    }
}

void MainWindow::onBtnMinus(){
    if (index > 0){
        ui->stackedWidget->setCurrentIndex(--index);
    }
}

void MainWindow::on_equalizationBtn_clicked()
{
    ui->stackedWidget->setCurrentWidget(histogramWidget);
}

