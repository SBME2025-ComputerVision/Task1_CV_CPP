#ifndef HOUGHTRANSORMWIDGET_H
#define HOUGHTRANSORMWIDGET_H

#include <QWidget>

namespace Ui {
class HoughTransormWidget;
}

class HoughTransormWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HoughTransormWidget(QWidget *parent = nullptr);
    ~HoughTransormWidget();

private:
    Ui::HoughTransormWidget *ui;
};

#endif // HOUGHTRANSORMWIDGET_H
