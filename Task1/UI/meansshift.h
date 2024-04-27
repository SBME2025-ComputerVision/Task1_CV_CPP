#ifndef MEANSSHIFT_H
#define MEANSSHIFT_H

#include <QWidget>
#include"config.h"
#include"Controllers/meansShiftcontroller.h"

namespace Ui {
class MeansShift;
}

class MeansShift : public QWidget
{
    Q_OBJECT

public:
    explicit MeansShift(QWidget *parent = nullptr);
    ~MeansShift();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_applyMeansShiftBtn_clicked();

    void on_uploadMeansShiftBtn_clicked();

private:
    Ui::MeansShift *ui;
    MeansShiftController*meansShiftController;
    QPixmap originalImg;
    QPixmap processedImg;

};

#endif // MEANSSHIFT_H
