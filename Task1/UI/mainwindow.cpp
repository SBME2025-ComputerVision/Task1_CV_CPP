#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <opencv2/opencv.hpp>

#include "config.h"
#include "UI/filterswidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    index = FilterPage;

    FiltersWidget *filterWidget = new FiltersWidget();


    ui->stackedWidget->addWidget(filterWidget);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_filteringBtn_clicked()
{
    index = FilterPage;
    MainWindow::setFrameIndex(index);
}


void MainWindow::on_edgeDetectionBtn_clicked()
{
    index = EdgeDetectionPage;
    MainWindow::setFrameIndex(index);
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

void MainWindow::setFrameIndex(int index){

    if(index <ui->stackedWidget->count()-1){
        ui->stackedWidget->setCurrentIndex(index);
    }

}
