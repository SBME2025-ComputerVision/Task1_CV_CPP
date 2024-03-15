#include "frequencywidget.h"
#include "ui_frequencywidget.h"
#include "config.h"

FrequencyWidget::FrequencyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FrequencyWidget)
{
    imageController = new ImageController();
    ui->setupUi(this);
    ui->radiusSLider->setMinimum(10);
    ui->radiusSLider->setMaximum(400);
    ui->radiusSLider->setValue(100);
}

FrequencyWidget::~FrequencyWidget()
{
    delete ui;
}


void FrequencyWidget::on_browseBtn_clicked()
{
    originalImg = imageController->uploadImg();
    processedImg = imageController->getGreyScaledImg();
    originalImg = originalImg.scaled(ui->originalImage->size(),Qt::IgnoreAspectRatio);
    processedImg = processedImg.scaled(ui->processedImage->size(),Qt::IgnoreAspectRatio);
    ui->originalImage->setPixmap(originalImg);
    ui->processedImage->setPixmap(processedImg);
}


void FrequencyWidget::on_highPassRadio_toggled(bool checked)
{
    // bool highPassRadioBtn = ui->highPassRadio->isChecked();
    processedImg = imageController->frequencyFilter(ui->radiusSLider->value(),HighPassFilter);
    processedImg = processedImg.scaled(ui->processedImage->size(),Qt::IgnoreAspectRatio);
    ui->processedImage->setPixmap(processedImg);
}


void FrequencyWidget::on_lowPassRadio_toggled(bool checked)
{   qDebug()<< ui->radiusSLider->value();
    // bool lowPassRadioBtn = ui->lowPassRadio->isChecked();
    processedImg = imageController->frequencyFilter(ui->radiusSLider->value(),LowPassFilter);
    processedImg = processedImg.scaled(ui->processedImage->size(),Qt::IgnoreAspectRatio);
    ui->processedImage->setPixmap(processedImg);
}


void FrequencyWidget::on_radiusSLider_sliderReleased()
{
    int flag;
    if(ui->lowPassRadio->isChecked()==1){
        flag =LowPassFilter;
    }else{
        flag =HighPassFilter;
    }
    processedImg = imageController->frequencyFilter(ui->radiusSLider->value(),flag);
    processedImg = processedImg.scaled(ui->processedImage->size(),Qt::IgnoreAspectRatio);
    ui->processedImage->setPixmap(processedImg);
}

