#ifndef FILTERSWIDGET_H
#define FILTERSWIDGET_H

#include <QWidget>
namespace Ui {
class FiltersWidget;
}

class FiltersWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FiltersWidget(QWidget *parent = nullptr);
    ~FiltersWidget();

private:
    Ui::FiltersWidget *ui;
};

#endif // FILTERSWIDGET_H
