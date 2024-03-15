#ifndef FILTERSWIDGET_H
#define FILTERSWIDGET_H

#include <QWidget>
#include "Controllers/filtercontroller.h"
namespace Ui {
class FiltersWidget;
}

class FiltersWidget : public QWidget
{
    Q_OBJECT

private:
    FilterController *filterController;
    QPixmap originalImg;
    QPixmap processedImg;

public:
    explicit FiltersWidget(QWidget *parent = nullptr);
    ~FiltersWidget();



private slots:
    void on_apply_gaussian_noise_clicked();

    void on_apply_uniform_noise_clicked();

    void on_apply_saltpeper_noise_clicked();

    void on_apply_avg_filter_clicked();

    void on_apply_gaussian_filter_clicked();

    void on_apply_median_filter_clicked();

    void on_resetFilterBtn_clicked();

    void on_uploadImgBtn_clicked();

private:
    Ui::FiltersWidget *ui;
};

#endif // FILTERSWIDGET_H
