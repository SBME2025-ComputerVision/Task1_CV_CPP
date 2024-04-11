#ifndef MATCHWIDGET_H
#define MATCHWIDGET_H

#include <QWidget>

namespace Ui {
class MatchWidget;
}

class MatchWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MatchWidget(QWidget *parent = nullptr);
    ~MatchWidget();

private:
    Ui::MatchWidget *ui;
};

#endif // MATCHWIDGET_H
