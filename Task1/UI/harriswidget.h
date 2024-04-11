#ifndef HARRISWIDGET_H
#define HARRISWIDGET_H

#include <QWidget>

namespace Ui {
class HarrisWidget;
}

class HarrisWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HarrisWidget(QWidget *parent = nullptr);
    ~HarrisWidget();

private:
    Ui::HarrisWidget *ui;
};

#endif // HARRISWIDGET_H
