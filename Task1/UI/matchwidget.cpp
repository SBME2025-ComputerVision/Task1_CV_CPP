#include "matchwidget.h"
#include "ui_matchwidget.h"

MatchWidget::MatchWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MatchWidget)
{
    ui->setupUi(this);
}

MatchWidget::~MatchWidget()
{
    delete ui;
}
