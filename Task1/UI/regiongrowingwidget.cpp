#include "regiongrowingwidget.h"
#include "qevent.h"
#include <qdebug.h>
#include "ui_regiongrowingwidget.h"

RegionGrowingWidget::RegionGrowingWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RegionGrowingWidget)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    regionGrowingController = new RegionGrowingController();

    // Set this widget as an event filter for the QGraphicsView
    ui->graphicsView->viewport()->installEventFilter(this);

}

RegionGrowingWidget::~RegionGrowingWidget()
{
    delete ui;
}

bool RegionGrowingWidget::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->graphicsView->viewport() && event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if (mouseEvent->button() == Qt::LeftButton)
        {
            // Call your slot to handle the mouse press event
            on_graphicsView_pressed(mouseEvent);
            return true; // Event handled
        }
    }
    return QWidget::eventFilter(obj, event); // Let other events pass through
}

void RegionGrowingWidget::on_uploadBtn_clicked()
{
    originalImg = regionGrowingController->uploadImg();
    temp = originalImg;
    if(!originalImg.isNull())
    {
        scene->clear();
        pixmapItem = scene->addPixmap(originalImg);
        ui->graphicsView->setScene(scene);
        ui->graphicsView->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    }
}
void RegionGrowingWidget::on_graphicsView_pressed(QMouseEvent *event)
{
    // Get the position of the press
    QPointF scenePos = ui->graphicsView->mapToScene(event->pos());

    // Convert the scene position to image coordinates
    QPoint imagePos = pixmapItem->mapFromScene(scenePos).toPoint();

    // Check if the position is within the image bounds
    if (!originalImg.isNull() && originalImg.rect().contains(imagePos)) {
        // Convert to QImage for pixel manipulation
        QImage tempImage = originalImg.toImage();
        // Set the size of the point
        // Set the size of the circle
        int circleRadius = 2; // Adjust the radius as needed

        // Draw a circle around the point
        QPainter painter(&tempImage);
        painter.setPen(Qt::red);
        painter.drawEllipse(imagePos, circleRadius, circleRadius);
        painter.end();
        // Convert back to QPixmap
        originalImg = QPixmap::fromImage(tempImage);

        // Save the location of the press as col and row in the cv::Mat
        int row = imagePos.y();
        int col = imagePos.x();

        qDebug() << "Row: " << row << "Col: " << col;
        
        seedPoints.push_back({row, col});

        // Update the pixmap item
        pixmapItem->setPixmap(originalImg);
    }
}




void RegionGrowingWidget::on_applyBtn_clicked()
{
    processedImg = regionGrowingController->growSeedPoints(seedPoints,5);
    processedImg = processedImg.scaled(ui->processedImgLabel->size(),Qt::IgnoreAspectRatio);
    ui->processedImgLabel->setPixmap(processedImg);
}


void RegionGrowingWidget::on_resetBtn_clicked()
{
    scene->clear();
    seedPoints.clear();
    ui->processedImgLabel->clear();
    originalImg = temp;
    if(!originalImg.isNull())
    {
        scene->clear();
        pixmapItem = scene->addPixmap(originalImg);
        ui->graphicsView->setScene(scene);
        ui->graphicsView->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    }
}

