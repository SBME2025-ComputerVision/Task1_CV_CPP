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
    index = 0;
    struct Pages{
        int FilterPage =0;
        int EdgeDetectionPage=1;
        int HistogramPage=2;
        int ThresholdingPage =3;
        int HybridPage=4;
    };
    FiltersWidget *filterWidget = new FiltersWidget();


    ui->stackedWidget->addWidget(filterWidget);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_filteringBtn_clicked()
{
    index = Pages.FilterPage;
    MainWindow::setFrameIndex(index);
}


void MainWindow::on_edgeDetectionBtn_clicked()
{
    index = Pages.EdgeDetectionPage;
    MainWindow::setFrameIndex(index);
}


void MainWindow::on_histogramsBtn_clicked()
{
    index = Pages.HistogramPage;
    MainWindow::setFrameIndex(index);
}


void MainWindow::on_thresholdingBtn_clicked()
{
    index = Pages.ThresholdingPage;
    MainWindow::setFrameIndex(index);
}


void MainWindow::on_hybridBtn_clicked()
{
    index = Pages.HybridPage;
    MainWindow::setFrameIndex(index);
}

void MainWindow::setFrameIndex(index){

    if(index <ui->stackedWidget->count()-1){
        ui->stackedWidget->setCurrentIndex(index);
    }

}
