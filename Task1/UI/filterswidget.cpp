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


void FiltersWidget::on_apply_gaussian_noise_clicked()
{

}


void FiltersWidget::on_apply_uniform_noise_clicked()
{

}


void FiltersWidget::on_apply_saltpeper_noise_clicked()
{

}


void FiltersWidget::on_apply_avg_filter_clicked()
{

}


void FiltersWidget::on_apply_gaussian_filter_clicked()
{

}


void FiltersWidget::on_apply_median_filter_clicked()
{

}


void FiltersWidget::on_uploadFilterBtn_clicked()
{

}


void FiltersWidget::on_resetFilterBtn_clicked()
{

}

