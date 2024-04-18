/********************************************************************************
** Form generated from reading UI file 'histogramwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTOGRAMWIDGET_H
#define UI_HISTOGRAMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HistogramWidget
{
public:
    QGridLayout *gridLayout_3;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QLabel *originalEqualizedHistogramLabel;
    QLabel *processedEqualizedHistogramLabel;
    QLabel *processedImgLabel;
    QLabel *originalImgLabel;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QPushButton *uploadImgBtn;
    QPushButton *normalizeBtn;
    QPushButton *equalizeImg;

    void setupUi(QWidget *HistogramWidget)
    {
        if (HistogramWidget->objectName().isEmpty())
            HistogramWidget->setObjectName("HistogramWidget");
        HistogramWidget->resize(1299, 666);
        gridLayout_3 = new QGridLayout(HistogramWidget);
        gridLayout_3->setObjectName("gridLayout_3");
        splitter = new QSplitter(HistogramWidget);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Vertical);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName("layoutWidget");
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        originalEqualizedHistogramLabel = new QLabel(layoutWidget);
        originalEqualizedHistogramLabel->setObjectName("originalEqualizedHistogramLabel");
        originalEqualizedHistogramLabel->setStyleSheet(QString::fromUtf8("border: 2px solid  #316669;\n"
"padding: 10px;"));

        gridLayout_2->addWidget(originalEqualizedHistogramLabel, 1, 0, 1, 1);

        processedEqualizedHistogramLabel = new QLabel(layoutWidget);
        processedEqualizedHistogramLabel->setObjectName("processedEqualizedHistogramLabel");
        processedEqualizedHistogramLabel->setStyleSheet(QString::fromUtf8("border: 2px solid  #316669;\n"
"padding: 10px;"));

        gridLayout_2->addWidget(processedEqualizedHistogramLabel, 1, 1, 1, 1);

        processedImgLabel = new QLabel(layoutWidget);
        processedImgLabel->setObjectName("processedImgLabel");
        processedImgLabel->setStyleSheet(QString::fromUtf8("border: 2px solid  #316669;\n"
"padding: 10px;"));

        gridLayout_2->addWidget(processedImgLabel, 0, 1, 1, 1);

        originalImgLabel = new QLabel(layoutWidget);
        originalImgLabel->setObjectName("originalImgLabel");
        originalImgLabel->setStyleSheet(QString::fromUtf8("border: 2px solid  #316669;\n"
"padding: 10px;"));

        gridLayout_2->addWidget(originalImgLabel, 0, 0, 1, 1);

        splitter->addWidget(layoutWidget);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName("layoutWidget1");
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        uploadImgBtn = new QPushButton(layoutWidget1);
        uploadImgBtn->setObjectName("uploadImgBtn");

        gridLayout->addWidget(uploadImgBtn, 0, 0, 1, 1);

        normalizeBtn = new QPushButton(layoutWidget1);
        normalizeBtn->setObjectName("normalizeBtn");

        gridLayout->addWidget(normalizeBtn, 0, 1, 1, 1);

        equalizeImg = new QPushButton(layoutWidget1);
        equalizeImg->setObjectName("equalizeImg");

        gridLayout->addWidget(equalizeImg, 0, 2, 1, 1);

        splitter->addWidget(layoutWidget1);

        gridLayout_3->addWidget(splitter, 0, 0, 1, 1);


        retranslateUi(HistogramWidget);

        QMetaObject::connectSlotsByName(HistogramWidget);
    } // setupUi

    void retranslateUi(QWidget *HistogramWidget)
    {
        HistogramWidget->setWindowTitle(QCoreApplication::translate("HistogramWidget", "Form", nullptr));
        originalEqualizedHistogramLabel->setText(QString());
        processedEqualizedHistogramLabel->setText(QString());
        processedImgLabel->setText(QString());
        originalImgLabel->setText(QString());
        uploadImgBtn->setText(QCoreApplication::translate("HistogramWidget", "upload Img", nullptr));
        normalizeBtn->setText(QCoreApplication::translate("HistogramWidget", "Normalize", nullptr));
        equalizeImg->setText(QCoreApplication::translate("HistogramWidget", "Equalize", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HistogramWidget: public Ui_HistogramWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTOGRAMWIDGET_H
