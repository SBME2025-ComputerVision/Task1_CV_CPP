#ifndef AGGLOMERATIVEWIDGET_H
#define AGGLOMERATIVEWIDGET_H

#include <QWidget>
#include <Controllers/agglomerativecontroller.h>
namespace Ui {
class AgglomerativeWidget;
}

class AgglomerativeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AgglomerativeWidget(QWidget *parent = nullptr);
    ~AgglomerativeWidget();

private slots:
    void on_browseBtn_2_clicked();

    void on_segmentBtn_clicked();


    void on_kCluserSlider_sliderReleased();

private:
    Ui::AgglomerativeWidget *ui;
    AgglomerativeController* agglomerativeController;
    QPixmap originalImg;
    QPixmap processedImg;
};

#endif // AGGLOMERATIVEWIDGET_H

