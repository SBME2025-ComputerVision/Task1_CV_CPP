#ifndef EDGEDETECTIONWIDGET_H
#define EDGEDETECTIONWIDGET_H

#include <QWidget>
#include "Controllers/imagecontroller.h"
namespace Ui {
class EdgeDetectionWidget;
}

class EdgeDetectionWidget : public QWidget
{
    Q_OBJECT

private:
    ImageController *imageController;
    QPixmap originalImg;
    QPixmap processedImg;


public:
    explicit EdgeDetectionWidget(QWidget *parent = nullptr);
    ~EdgeDetectionWidget();

private slots:
    void on_apply_robert_detector_clicked();

    void on_apply_prewitt_detector_clicked();

    void on_apply_sobel_detector_clicked();

    void on_apply_canny_detector_clicked();

    void on_uploadImgBtn_clicked();

    void on_resetFilterBtn_clicked();


private:
    Ui::EdgeDetectionWidget *ui;
};

#endif // EDGEDETECTIONWIDGET_H
