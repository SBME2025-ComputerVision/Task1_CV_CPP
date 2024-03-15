#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QDebug>
#include<opencv2/core/core.hpp>

#include "UI/filterswidget.h"

#include "UI/edgedetectionwidget.h"
#include "UI/frequencywidget.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    FiltersWidget *filterWidget = new FiltersWidget();

    EdgeDetectionWidget *edgeDetectionWidget = new EdgeDetectionWidget();
    FrequencyWidget *frequencyWidget = new FrequencyWidget();


private slots:
    void onBtnPlus();

    void onBtnMinus();

    void on_filteringBtn_clicked();

    void on_edgeDetectionBtn_clicked();

    void on_histogramsBtn_clicked();

    void on_thresholdingBtn_clicked();

    void on_hybridBtn_clicked();

    void on_frequencyBtn_clicked();

private:
    Ui::MainWindow *ui;
    int index;
    void setFrameIndex(int index);
};
#endif // MAINWINDOW_H
