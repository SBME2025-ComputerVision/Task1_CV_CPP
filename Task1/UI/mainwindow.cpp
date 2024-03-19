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
    ui->stackedWidget->addWidget(filterWidget);
    ui->stackedWidget->addWidget(edgeDetectionWidget);
    ui->stackedWidget->addWidget(histogramWidget);
    ui->stackedWidget->addWidget(plotWidget);
    ui->stackedWidget->addWidget(hybridWidget);
    ui->stackedWidget->addWidget(frequencyWidget);
    ui->stackedWidget->addWidget(thresholdWidget);




}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_filteringBtn_clicked()
{
    ui->stackedWidget->setCurrentWidget(filterWidget);
     setWindowState(Qt::WindowMaximized);

}


void MainWindow::on_edgeDetectionBtn_clicked()
{
   ui->stackedWidget->setCurrentWidget(edgeDetectionWidget);
    setWindowState(Qt::WindowMaximized);

}


void MainWindow::on_histogramsBtn_clicked()
{
    ui->stackedWidget->setCurrentWidget(plotWidget);
     setWindowState(Qt::WindowMaximized);
}


void MainWindow::on_thresholdingBtn_clicked()
{
    ui->stackedWidget->setCurrentWidget(thresholdWidget);
     setWindowState(Qt::WindowMaximized);
}


void MainWindow::on_hybridBtn_clicked()
{
 ui->stackedWidget->setCurrentWidget(hybridWidget);
  setWindowState(Qt::WindowMaximized);
}

void MainWindow::on_frequencyBtn_clicked()
{
    ui->stackedWidget->setCurrentWidget(frequencyWidget);
     setWindowState(Qt::WindowMaximized);
}

void MainWindow::setFrameIndex(int index){
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
     setWindowState(Qt::WindowMaximized);
}

