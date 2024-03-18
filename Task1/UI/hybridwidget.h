#ifndef HYBRIDWIDGET_H
#define HYBRIDWIDGET_H

#include <QWidget>

namespace Ui {
class hybridwidget;
}

class hybridwidget : public QWidget
{
    Q_OBJECT

public:
    explicit hybridwidget(QWidget *parent = nullptr);
    ~hybridwidget();

private:
    Ui::hybridwidget *ui;
};

#endif // HYBRIDWIDGET_H
