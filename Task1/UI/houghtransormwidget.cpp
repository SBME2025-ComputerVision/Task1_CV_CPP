#include "houghtransormwidget.h"
#include "ui_houghtransormwidget.h"

HoughTransormWidget::HoughTransormWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HoughTransormWidget)
{
    ui->setupUi(this);
}

HoughTransormWidget::~HoughTransormWidget()
{
    delete ui;
}
