#ifndef SEGMENTATIONWIDGET_H
#define SEGMENTATIONWIDGET_H

#include <QWidget>
#include "UI/regiongrowingwidget.h"
#include"UI/meanshiftwidget.h"
#include "UI/agglomerativewidget.h"
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
    QWidget *meansShiftWidget=new MeanShiftWidget();
    QWidget *agglomerativeWidget = new AgglomerativeWidget();
    QWidget *kmeansWidget = new KmeansWidget();
    ~SegmentationWidget();

private slots:
    void on_kmeansBtn_clicked();

    void on_regionGrowingBtn_clicked();

    void on_meanShiftBtn_clicked();

    void on_aggBtn_clicked();

private:
    Ui::SegmentationWidget *ui;
    QList<QPushButton*> menuBtns;
    QString style;

    void changeButtonColors(QList<QPushButton *> list, QString style);
};

#endif // SEGMENTATIONWIDGET_H
