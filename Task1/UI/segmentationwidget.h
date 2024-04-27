#ifndef SEGMENTATIONWIDGET_H
#define SEGMENTATIONWIDGET_H

#include <QWidget>
#include "UI/regiongrowingwidget.h"
#include"UI/meanshiftwidget.h"
#include "UI/agglomerativewidget.h"

namespace Ui {
class SegmentationWidget;
}

class SegmentationWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SegmentationWidget(QWidget *parent = nullptr);
    QWidget *regionWidget = new RegionGrowingWidget();
    QWidget *meansShiftWidget=new MeanShiftWidget();
    QWidget *agglomerativeWidget = new AgglomerativeWidget();
    ~SegmentationWidget();

private:
    Ui::SegmentationWidget *ui;

};

#endif // SEGMENTATIONWIDGET_H
