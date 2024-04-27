#ifndef MEANSHIFTWIDGET_H
#define MEANSHIFTWIDGET_H

#include <QWidget>
#include"config.h"
#include"Controllers/meansshiftcontroller.h"


namespace Ui {
class MeanShiftWidget;
}

class MeanShiftWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MeanShiftWidget(QWidget *parent = nullptr);
    ~MeanShiftWidget();

private slots:
    void on_uploadMeansShiftBtn_clicked();

    void on_applyMeansShiftBtn_clicked();

private:
    Ui::MeanShiftWidget *ui;
    MeansShiftController*meansShiftController;
    QPixmap originalImg;
    QPixmap processedImg;
};

#endif // MEANSHIFTWIDGET_H
