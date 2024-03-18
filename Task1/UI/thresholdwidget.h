#ifndef THRESHOLDWIDGET_H
#define THRESHOLDWIDGET_H

#include <QWidget>
#include "Controllers/thresholdcontroller.h"
namespace Ui {
class ThresholdWidget;
}

class ThresholdWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ThresholdWidget(QWidget *parent = nullptr);
    ~ThresholdWidget();

private:
    Ui::ThresholdWidget *ui;
    ThresholdController *thresholdController;
    QPixmap originalImg;
    QPixmap processedImg;
private slots:
    void on_globalThresholdBtn_clicked();

    void on_localThresholdBtn_clicked();

    void on_uploadBtn_clicked();


};

#endif // THRESHOLDWIDGET_H



