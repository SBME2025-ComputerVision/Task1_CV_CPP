#include "filterswidget.h"
#include "ui_filterswidget.h"

FiltersWidget::FiltersWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FiltersWidget)
{
    ui->setupUi(this);
}

FiltersWidget::~FiltersWidget()
{
    delete ui;
}
