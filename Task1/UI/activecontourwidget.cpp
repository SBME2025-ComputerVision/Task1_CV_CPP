#include "activecontourwidget.h"
#include "ui_activecontourwidget.h"
#include "config.h"
#include "Helpers/helpers.h"

ActiveContourWidget::ActiveContourWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ActiveContourWidget)
{
    ui->setupUi(this);
}

ActiveContourWidget::~ActiveContourWidget()
{
    delete ui;
}

void ActiveContourWidget::on_upload_btn_clicked()
{
       originalImg = activeContourController->uploadImg();
       scene = new Scene(false);
       scene->setRad(ui->raduis->value());
       reloadInitialContour();
}


void ActiveContourWidget::on_clear_clicked()
{
    reloadInitialContour();
    scene->setDrawFlag(false);
}

void ActiveContourWidget::reloadInitialContour(){
    if (originalImg != QImage(0)) {
        scene->addPixmap(QPixmap::fromImage(originalImg));
        ui->graphicsView->setScene(scene);
        ui->graphicsView->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);
    }
}

void ActiveContourWidget::on_raduis_valueChanged(int arg1)
{
    scene->setRad(arg1);
    reloadInitialContour();
    scene->drawCircle(false);
}

void ActiveContourWidget::resizeEvent(QResizeEvent *e)
{
  reloadInitialContour();
}

void ActiveContourWidget::on_generate_btn_clicked()
{

}

