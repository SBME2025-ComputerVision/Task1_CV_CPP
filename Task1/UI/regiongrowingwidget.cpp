#include "regiongrowingwidget.h"
#include "ui_regiongrowingwidget.h"

RegionGrowingWidget::RegionGrowingWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RegionGrowingWidget)
{
    ui->setupUi(this);
}

RegionGrowingWidget::~RegionGrowingWidget()
{
    delete ui;
}
