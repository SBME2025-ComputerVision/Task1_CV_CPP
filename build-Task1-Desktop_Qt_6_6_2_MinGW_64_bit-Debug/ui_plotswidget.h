/********************************************************************************
** Form generated from reading UI file 'plotswidget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOTSWIDGET_H
#define UI_PLOTSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlotsWidget
{
public:
    QGridLayout *gridLayout;
    QPushButton *uploadImgBtn;
    QSplitter *splitter;
    QLabel *redHistogramLabel;
    QLabel *greenHistogramLabel;
    QLabel *blueHistogramLabel;
    QSplitter *splitter_2;
    QLabel *rgbDistributionHistogramLabel;
    QLabel *grayscaleDistributionCurveLabel;
    QLabel *grayscaleHistogramlabel;
    QComboBox *comboBox;

    void setupUi(QWidget *PlotsWidget)
    {
        if (PlotsWidget->objectName().isEmpty())
            PlotsWidget->setObjectName("PlotsWidget");
        PlotsWidget->resize(1314, 751);
        gridLayout = new QGridLayout(PlotsWidget);
        gridLayout->setObjectName("gridLayout");
        uploadImgBtn = new QPushButton(PlotsWidget);
        uploadImgBtn->setObjectName("uploadImgBtn");

        gridLayout->addWidget(uploadImgBtn, 2, 0, 1, 1);

        splitter = new QSplitter(PlotsWidget);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Horizontal);
        redHistogramLabel = new QLabel(splitter);
        redHistogramLabel->setObjectName("redHistogramLabel");
        redHistogramLabel->setStyleSheet(QString::fromUtf8("border: 2px solid  #316669;\n"
"padding: 10px;"));
        splitter->addWidget(redHistogramLabel);
        greenHistogramLabel = new QLabel(splitter);
        greenHistogramLabel->setObjectName("greenHistogramLabel");
        greenHistogramLabel->setStyleSheet(QString::fromUtf8("border: 2px solid #316669;\n"
"padding: 10px;"));
        splitter->addWidget(greenHistogramLabel);
        blueHistogramLabel = new QLabel(splitter);
        blueHistogramLabel->setObjectName("blueHistogramLabel");
        blueHistogramLabel->setStyleSheet(QString::fromUtf8("border: 2px solid  #316669;\n"
"padding: 10px;"));
        splitter->addWidget(blueHistogramLabel);

        gridLayout->addWidget(splitter, 0, 0, 1, 1);

        splitter_2 = new QSplitter(PlotsWidget);
        splitter_2->setObjectName("splitter_2");
        splitter_2->setOrientation(Qt::Horizontal);
        rgbDistributionHistogramLabel = new QLabel(splitter_2);
        rgbDistributionHistogramLabel->setObjectName("rgbDistributionHistogramLabel");
        rgbDistributionHistogramLabel->setStyleSheet(QString::fromUtf8("border: 2px solid  #316669;\n"
"padding: 10px;"));
        splitter_2->addWidget(rgbDistributionHistogramLabel);
        grayscaleDistributionCurveLabel = new QLabel(splitter_2);
        grayscaleDistributionCurveLabel->setObjectName("grayscaleDistributionCurveLabel");
        grayscaleDistributionCurveLabel->setStyleSheet(QString::fromUtf8("border: 2px solid #316669;\n"
"padding: 10px;"));
        splitter_2->addWidget(grayscaleDistributionCurveLabel);
        grayscaleHistogramlabel = new QLabel(splitter_2);
        grayscaleHistogramlabel->setObjectName("grayscaleHistogramlabel");
        grayscaleHistogramlabel->setStyleSheet(QString::fromUtf8("border: 2px solid  #316669;\n"
"padding: 10px;"));
        splitter_2->addWidget(grayscaleHistogramlabel);

        gridLayout->addWidget(splitter_2, 1, 0, 1, 1);

        comboBox = new QComboBox(PlotsWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");

        gridLayout->addWidget(comboBox, 3, 0, 1, 1);


        retranslateUi(PlotsWidget);

        QMetaObject::connectSlotsByName(PlotsWidget);
    } // setupUi

    void retranslateUi(QWidget *PlotsWidget)
    {
        PlotsWidget->setWindowTitle(QCoreApplication::translate("PlotsWidget", "Form", nullptr));
        uploadImgBtn->setText(QCoreApplication::translate("PlotsWidget", "Upload Image", nullptr));
        redHistogramLabel->setText(QString());
        greenHistogramLabel->setText(QString());
        blueHistogramLabel->setText(QString());
        rgbDistributionHistogramLabel->setText(QString());
        grayscaleDistributionCurveLabel->setText(QString());
        grayscaleHistogramlabel->setText(QString());
        comboBox->setItemText(0, QCoreApplication::translate("PlotsWidget", "Normal", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("PlotsWidget", "CDF", nullptr));

    } // retranslateUi

};

namespace Ui {
    class PlotsWidget: public Ui_PlotsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTSWIDGET_H
