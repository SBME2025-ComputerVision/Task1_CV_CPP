#ifndef SEGMENTATIONWIDGET_H
#define SEGMENTATIONWIDGET_H

#include <QWidget>
#include "UI/regiongrowingwidget.h"

namespace Ui {
class SegmentationWidget;
}

class SegmentationWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SegmentationWidget(QWidget *parent = nullptr);
    QWidget *regionWidget = new RegionGrowingWidget();
    ~SegmentationWidget();

private:
    Ui::SegmentationWidget *ui;

};

#endif // SEGMENTATIONWIDGET_H
