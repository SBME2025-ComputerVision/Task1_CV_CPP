#ifndef FREQUENCYWIDGET_H
#define FREQUENCYWIDGET_H

#include <QWidget>
#include "Controllers/imagecontroller.h"
namespace Ui {
class FrequencyWidget;
}

class FrequencyWidget : public QWidget
{
    Q_OBJECT
private:
    ImageController *imageController;
    QPixmap originalImg;
    QPixmap processedImg;
public:
    explicit FrequencyWidget(QWidget *parent = nullptr);
    ~FrequencyWidget();

private slots:
    void on_browseBtn_clicked();

    void on_highPassRadio_toggled(bool checked);

    void on_lowPassRadio_toggled(bool checked);

    void on_radiusSLider_sliderReleased();

private:
    Ui::FrequencyWidget *ui;
};

#endif // FREQUENCYWIDGET_H
