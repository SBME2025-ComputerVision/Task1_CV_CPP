#include "filterswidget.h"
#include "ui_filterswidget.h"
#include "config.h"


FiltersWidget::FiltersWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FiltersWidget)
{
    filterController = new FilterController();
    ui->setupUi(this);
}

FiltersWidget::~FiltersWidget()
{
    delete ui;
}


void FiltersWidget::on_apply_gaussian_noise_clicked()
{
    processedImg = filterController->addNoise(GaussianNoise, 0, 3, 2);
    processedImg = processedImg.scaled(ui->imageFiltered->size(),Qt::IgnoreAspectRatio);
    ui->imageFiltered->setPixmap(processedImg);
}


void FiltersWidget::on_apply_uniform_noise_clicked()
{
    processedImg = filterController->addNoise(UniformNoise, 0, 0, 0);
    processedImg = processedImg.scaled(ui->imageFiltered->size(),Qt::IgnoreAspectRatio);
    ui->imageFiltered->setPixmap(processedImg);

}


void FiltersWidget::on_apply_saltpeper_noise_clicked()
{
    processedImg = filterController->addNoise(SaltAndPepperNoise, 15, 0, 0);
    processedImg = processedImg.scaled(ui->imageFiltered->size(),Qt::IgnoreAspectRatio);
    ui->imageFiltered->setPixmap(processedImg);
}


void FiltersWidget::on_apply_avg_filter_clicked()
{
    processedImg = filterController->filterImg(AvgFilter, 3);
    processedImg = processedImg.scaled(ui->imageFiltered->size(),Qt::IgnoreAspectRatio);
    ui->imageFiltered->setPixmap(processedImg);

}


void FiltersWidget::on_apply_gaussian_filter_clicked()
{
    processedImg = filterController->filterImg(GaussianFilter, 3);
    processedImg = processedImg.scaled(ui->imageFiltered->size(),Qt::IgnoreAspectRatio);
    ui->imageFiltered->setPixmap(processedImg);

}


void FiltersWidget::on_apply_median_filter_clicked()
{
    processedImg = filterController->filterImg(MedianFilter, 3);
    processedImg = processedImg.scaled(ui->imageFiltered->size(),Qt::IgnoreAspectRatio);
    ui->imageFiltered->setPixmap(processedImg);
}



void FiltersWidget::on_resetFilterBtn_clicked()
{
    processedImg = filterController->convertToGrayScale();
    processedImg = processedImg.scaled(ui->imageFiltered->size(),Qt::IgnoreAspectRatio);
    ui->imageFiltered->setPixmap(processedImg);

}


void FiltersWidget::on_uploadImgBtn_clicked()
{
    originalImg = filterController->uploadImg();
    processedImg = filterController->convertToGrayScale();
    originalImg = originalImg.scaled(ui->imageOriginal->size(),Qt::IgnoreAspectRatio);
    processedImg = processedImg.scaled(ui->imageFiltered->size(),Qt::IgnoreAspectRatio);
    ui->imageOriginal->setPixmap(originalImg);
    ui->imageFiltered->setPixmap(processedImg);
}



