#ifndef KMEANSWIDGET_H
#define KMEANSWIDGET_H

#include <QWidget>
#include "Controllers/kmeanscontroller.h"
namespace Ui {
class KmeansWidget;
}

class KmeansWidget : public QWidget
{
    Q_OBJECT

public:
    explicit KmeansWidget(QWidget *parent = nullptr);
    ~KmeansWidget();

private slots:
    void on_browseBtn_clicked();

    void on_kCluserSlider_sliderReleased();

    void on_segmentBtn_clicked();

private:
    Ui::KmeansWidget *ui;
    KmeansController* kmeansController;
    QPixmap originalImg;
    QPixmap processedImg;
};

#endif // KMEANSWIDGET_H
