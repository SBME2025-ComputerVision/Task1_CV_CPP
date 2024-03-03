#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QDebug>
#include<opencv2/core/core.hpp>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_filteringBtn_clicked();

    void on_edgeDetectionBtn_clicked();

    void on_histogramsBtn_clicked();

    void on_thresholdingBtn_clicked();

    void on_hybridBtn_clicked();

private:
    Ui::MainWindow *ui;
    int index;
    void setFrameIndex(int index);
};
#endif // MAINWINDOW_H
