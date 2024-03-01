#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <opencv2/opencv.hpp>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug()<<"Opencv Version" << CV_VERSION;
    qDebug()<<"Opencv Version" << CV_VERSION_MAJOR;
    qDebug()<<"Opencv Version" << CV_VERSION_MINOR;


}

MainWindow::~MainWindow()
{
    delete ui;
}

