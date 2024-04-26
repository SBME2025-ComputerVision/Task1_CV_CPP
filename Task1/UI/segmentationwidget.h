#ifndef SEGMENTATIONWIDGET_H
#define SEGMENTATIONWIDGET_H

#include <QWidget>
#include "UI/regiongrowingwidget.h"
#include "UI/kmeanswidget.h"

namespace Ui {
class SegmentationWidget;
}

class SegmentationWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SegmentationWidget(QWidget *parent = nullptr);
    QWidget *regionWidget = new RegionGrowingWidget();
    QWidget *kmeansWidget = new KmeansWidget();
    ~SegmentationWidget();

private:
    Ui::SegmentationWidget *ui;

};

#endif // SEGMENTATIONWIDGET_H
