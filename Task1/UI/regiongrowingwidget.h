#ifndef REGIONGROWINGWIDGET_H
#define REGIONGROWINGWIDGET_H

#include <QWidget>

namespace Ui {
class RegionGrowingWidget;
}

class RegionGrowingWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RegionGrowingWidget(QWidget *parent = nullptr);
    ~RegionGrowingWidget();

private:
    Ui::RegionGrowingWidget *ui;
};

#endif // REGIONGROWINGWIDGET_H
