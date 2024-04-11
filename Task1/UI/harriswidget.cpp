#include "harriswidget.h"
#include "ui_harriswidget.h"

HarrisWidget::HarrisWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HarrisWidget)
{
    ui->setupUi(this);
}

HarrisWidget::~HarrisWidget()
{
    delete ui;
}
