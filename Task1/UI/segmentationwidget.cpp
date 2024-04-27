#include "segmentationwidget.h"
#include "ui_segmentationwidget.h"

SegmentationWidget::SegmentationWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SegmentationWidget)
{
    ui->setupUi(this);
    // Create a layout for the workFrame
    QVBoxLayout *layout = new QVBoxLayout(ui->workFrame);

    // Set the layout to the workFrame
    ui->workFrame->setLayout(layout);

    // Add the regionWidget to the layout
    layout->addWidget(meansShiftWidget);


}

SegmentationWidget::~SegmentationWidget()
{
    delete ui;
}
