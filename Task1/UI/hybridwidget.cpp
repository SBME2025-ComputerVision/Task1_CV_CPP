#include "hybridwidget.h"
#include "ui_hybridwidget.h"

hybridwidget::hybridwidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::hybridwidget)
{
    ui->setupUi(this);
}

hybridwidget::~hybridwidget()
{
    delete ui;
}
