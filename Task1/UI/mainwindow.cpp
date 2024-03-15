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

//    FiltersWidget *filterWidget = new FiltersWidget();
//    EdgeDetectionWidget *edgeDetectionWidget = new EdgeDetectionWidget();

    ui->stackedWidget->addWidget(filterWidget);
    ui->stackedWidget->addWidget(edgeDetectionWidget);
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
    index = HistogramPage;
    MainWindow::setFrameIndex(index);
}


void MainWindow::on_thresholdingBtn_clicked()
{
    index = ThresholdingPage;
    MainWindow::setFrameIndex(index);
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
