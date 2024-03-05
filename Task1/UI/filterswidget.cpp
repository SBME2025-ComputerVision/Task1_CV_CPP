#include "filterswidget.h"
#include "ui_filterswidget.h"
#include "config.h"

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
    originalImg = imageController->applyGaussianNoise();
    originalImg = originalImg.scaled(ui->imageOriginal->size(),Qt::IgnoreAspectRatio);
    ui->imageOriginal->setPixmap(originalImg);

}


void FiltersWidget::on_apply_uniform_noise_clicked()
{
    originalImg = imageController->applyUniformNoise();
    originalImg = originalImg.scaled(ui->imageOriginal->size(),Qt::IgnoreAspectRatio);
    ui->imageOriginal->setPixmap(originalImg);
}


void FiltersWidget::on_apply_saltpeper_noise_clicked()
{
    originalImg = imageController->applySaltPepperNoise();
    originalImg = originalImg.scaled(ui->imageOriginal->size(),Qt::IgnoreAspectRatio);
    ui->imageOriginal->setPixmap(originalImg);
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



void FiltersWidget::on_resetFilterBtn_clicked()
{

}


void FiltersWidget::on_uploadImgBtn_clicked()
{
    originalImg = imageController->uploadImg();
    processedImg = imageController->greyScaledImg();

    originalImg = originalImg.scaled(ui->imageOriginal->size(),Qt::IgnoreAspectRatio);
    processedImg = processedImg.scaled(ui->imageFiltered->size(),Qt::IgnoreAspectRatio);
    ui->imageOriginal->setPixmap(originalImg);
    ui->imageFiltered->setPixmap(processedImg);
}



