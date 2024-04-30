#ifndef REGIONGROWINGWIDGET_H
#define REGIONGROWINGWIDGET_H

#include <QWidget>
#include "Controllers/regiongrowingcontroller.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>



namespace Ui {
class RegionGrowingWidget;
}

class RegionGrowingWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RegionGrowingWidget(QWidget *parent = nullptr);
    ~RegionGrowingWidget();

private slots:
    void on_uploadBtn_clicked();
    void on_graphicsView_pressed(QMouseEvent *event); // New slot for mouse press event



    void on_applyBtn_clicked();

    void on_resetBtn_clicked();

private:
    Ui::RegionGrowingWidget *ui;
    RegionGrowingController *regionGrowingController;
    QGraphicsScene *scene;
    QPixmap originalImg;
    QPixmap processedImg;
    QPixmap temp;
    QGraphicsPixmapItem *pixmapItem;
    vector<pair<int,int>> seedPoints;
private:
    bool eventFilter(QObject *obj, QEvent *event); // Declare the event filter method

};

#endif // REGIONGROWINGWIDGET_H
