/********************************************************************************
** Form generated from reading UI file 'houghtransormwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOUGHTRANSORMWIDGET_H
#define UI_HOUGHTRANSORMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HoughTransormWidget
{
public:
    QHBoxLayout *horizontalLayout_6;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer_2;
    QPushButton *uploadImgBtn;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *lineShapeBtn;
    QPushButton *circleShapeBtn;
    QPushButton *EllipseShapeBtn;
    QSpacerItem *verticalSpacer_3;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QSlider *lineThresholdSlider;
    QLabel *lineThresholdValue;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QHBoxLayout *horizontalLayout_3;
    QSlider *minRadiusSlider;
    QLabel *minRadiusValue;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_5;
    QSlider *maxRadiusSlider;
    QLabel *maxRadiusValue;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_8;
    QSlider *circleThresholdSlider;
    QLabel *circleThresholdValue;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_7;
    QSlider *minElipseRadiusSlider;
    QLabel *minElipseRadiusValue;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_9;
    QSlider *maxElipseRadiusSlider;
    QLabel *maxElipseRadiusValue;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_10;
    QSlider *elipseThresholdSlider;
    QLabel *elipseThresholdValue;
    QSpacerItem *verticalSpacer;
    QPushButton *applyBtn;
    QSpacerItem *verticalSpacer_4;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_4;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QLabel *imageOriginal;
    QSpacerItem *horizontalSpacer_3;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *imageDetected;

    void setupUi(QWidget *HoughTransormWidget)
    {
        if (HoughTransormWidget->objectName().isEmpty())
            HoughTransormWidget->setObjectName("HoughTransormWidget");
        HoughTransormWidget->resize(1531, 677);
        horizontalLayout_6 = new QHBoxLayout(HoughTransormWidget);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        frame_4 = new QFrame(HoughTransormWidget);
        frame_4->setObjectName("frame_4");
        frame_4->setMaximumSize(QSize(300, 16777215));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(frame_4);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_2);

        uploadImgBtn = new QPushButton(frame_4);
        uploadImgBtn->setObjectName("uploadImgBtn");

        verticalLayout_5->addWidget(uploadImgBtn);

        groupBox = new QGroupBox(frame_4);
        groupBox->setObjectName("groupBox");
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName("horizontalLayout");
        lineShapeBtn = new QPushButton(groupBox);
        lineShapeBtn->setObjectName("lineShapeBtn");

        horizontalLayout->addWidget(lineShapeBtn);

        circleShapeBtn = new QPushButton(groupBox);
        circleShapeBtn->setObjectName("circleShapeBtn");

        horizontalLayout->addWidget(circleShapeBtn);

        EllipseShapeBtn = new QPushButton(groupBox);
        EllipseShapeBtn->setObjectName("EllipseShapeBtn");

        horizontalLayout->addWidget(EllipseShapeBtn);


        verticalLayout_5->addWidget(groupBox);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_3);

        groupBox_2 = new QGroupBox(frame_4);
        groupBox_2->setObjectName("groupBox_2");
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lineThresholdSlider = new QSlider(groupBox_2);
        lineThresholdSlider->setObjectName("lineThresholdSlider");
        lineThresholdSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(lineThresholdSlider);

        lineThresholdValue = new QLabel(groupBox_2);
        lineThresholdValue->setObjectName("lineThresholdValue");

        horizontalLayout_2->addWidget(lineThresholdValue);


        verticalLayout_5->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(frame_4);
        groupBox_3->setObjectName("groupBox_3");
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label = new QLabel(groupBox_3);
        label->setObjectName("label");

        verticalLayout_3->addWidget(label);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        minRadiusSlider = new QSlider(groupBox_3);
        minRadiusSlider->setObjectName("minRadiusSlider");
        minRadiusSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(minRadiusSlider);

        minRadiusValue = new QLabel(groupBox_3);
        minRadiusValue->setObjectName("minRadiusValue");

        horizontalLayout_3->addWidget(minRadiusValue);


        verticalLayout_3->addLayout(horizontalLayout_3);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName("label_2");

        verticalLayout_3->addWidget(label_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        maxRadiusSlider = new QSlider(groupBox_3);
        maxRadiusSlider->setObjectName("maxRadiusSlider");
        maxRadiusSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(maxRadiusSlider);

        maxRadiusValue = new QLabel(groupBox_3);
        maxRadiusValue->setObjectName("maxRadiusValue");

        horizontalLayout_5->addWidget(maxRadiusValue);


        verticalLayout_3->addLayout(horizontalLayout_5);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName("label_3");

        verticalLayout_3->addWidget(label_3);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        circleThresholdSlider = new QSlider(groupBox_3);
        circleThresholdSlider->setObjectName("circleThresholdSlider");
        circleThresholdSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_8->addWidget(circleThresholdSlider);

        circleThresholdValue = new QLabel(groupBox_3);
        circleThresholdValue->setObjectName("circleThresholdValue");

        horizontalLayout_8->addWidget(circleThresholdValue);


        verticalLayout_3->addLayout(horizontalLayout_8);


        verticalLayout_5->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(frame_4);
        groupBox_4->setObjectName("groupBox_4");
        verticalLayout_4 = new QVBoxLayout(groupBox_4);
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName("label_4");

        verticalLayout_4->addWidget(label_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        minElipseRadiusSlider = new QSlider(groupBox_4);
        minElipseRadiusSlider->setObjectName("minElipseRadiusSlider");
        minElipseRadiusSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(minElipseRadiusSlider);

        minElipseRadiusValue = new QLabel(groupBox_4);
        minElipseRadiusValue->setObjectName("minElipseRadiusValue");

        horizontalLayout_7->addWidget(minElipseRadiusValue);


        verticalLayout_4->addLayout(horizontalLayout_7);

        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName("label_5");

        verticalLayout_4->addWidget(label_5);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        maxElipseRadiusSlider = new QSlider(groupBox_4);
        maxElipseRadiusSlider->setObjectName("maxElipseRadiusSlider");
        maxElipseRadiusSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_9->addWidget(maxElipseRadiusSlider);

        maxElipseRadiusValue = new QLabel(groupBox_4);
        maxElipseRadiusValue->setObjectName("maxElipseRadiusValue");

        horizontalLayout_9->addWidget(maxElipseRadiusValue);


        verticalLayout_4->addLayout(horizontalLayout_9);

        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName("label_6");

        verticalLayout_4->addWidget(label_6);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        elipseThresholdSlider = new QSlider(groupBox_4);
        elipseThresholdSlider->setObjectName("elipseThresholdSlider");
        elipseThresholdSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_10->addWidget(elipseThresholdSlider);

        elipseThresholdValue = new QLabel(groupBox_4);
        elipseThresholdValue->setObjectName("elipseThresholdValue");

        horizontalLayout_10->addWidget(elipseThresholdValue);


        verticalLayout_4->addLayout(horizontalLayout_10);


        verticalLayout_5->addWidget(groupBox_4);

        verticalSpacer = new QSpacerItem(20, 70, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);

        applyBtn = new QPushButton(frame_4);
        applyBtn->setObjectName("applyBtn");

        verticalLayout_5->addWidget(applyBtn);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_4);


        horizontalLayout_6->addWidget(frame_4);

        frame_3 = new QFrame(HoughTransormWidget);
        frame_3->setObjectName("frame_3");
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_3);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        frame = new QFrame(frame_3);
        frame->setObjectName("frame");
        frame->setMinimumSize(QSize(500, 500));
        frame->setMaximumSize(QSize(500, 500));
        frame->setStyleSheet(QString::fromUtf8("\n"
"           border: 2px solid  #316669;\n"
"          border-radius: 10px;\n"
"      "));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName("verticalLayout");
        imageOriginal = new QLabel(frame);
        imageOriginal->setObjectName("imageOriginal");

        verticalLayout->addWidget(imageOriginal);


        horizontalLayout_4->addWidget(frame);

        horizontalSpacer_3 = new QSpacerItem(31, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        frame_2 = new QFrame(frame_3);
        frame_2->setObjectName("frame_2");
        frame_2->setMinimumSize(QSize(500, 500));
        frame_2->setMaximumSize(QSize(500, 500));
        frame_2->setStyleSheet(QString::fromUtf8("\n"
"           border: 2px solid  #316669;\n"
"          border-radius: 10px;\n"
"      "));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        imageDetected = new QLabel(frame_2);
        imageDetected->setObjectName("imageDetected");

        verticalLayout_2->addWidget(imageDetected);


        horizontalLayout_4->addWidget(frame_2);


        horizontalLayout_6->addWidget(frame_3);


        retranslateUi(HoughTransormWidget);

        QMetaObject::connectSlotsByName(HoughTransormWidget);
    } // setupUi

    void retranslateUi(QWidget *HoughTransormWidget)
    {
        HoughTransormWidget->setWindowTitle(QCoreApplication::translate("HoughTransormWidget", "Form", nullptr));
        uploadImgBtn->setText(QCoreApplication::translate("HoughTransormWidget", "Upload", nullptr));
        groupBox->setTitle(QCoreApplication::translate("HoughTransormWidget", "Parametric Shape", nullptr));
        lineShapeBtn->setText(QCoreApplication::translate("HoughTransormWidget", "Line", nullptr));
        circleShapeBtn->setText(QCoreApplication::translate("HoughTransormWidget", "Circle", nullptr));
        EllipseShapeBtn->setText(QCoreApplication::translate("HoughTransormWidget", "Ellipse", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("HoughTransormWidget", "Line Threshold", nullptr));
        lineThresholdValue->setText(QCoreApplication::translate("HoughTransormWidget", "0", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("HoughTransormWidget", "Circle", nullptr));
        label->setText(QCoreApplication::translate("HoughTransormWidget", "Min Radius", nullptr));
        minRadiusValue->setText(QCoreApplication::translate("HoughTransormWidget", "0", nullptr));
        label_2->setText(QCoreApplication::translate("HoughTransormWidget", "Max Radius", nullptr));
        maxRadiusValue->setText(QCoreApplication::translate("HoughTransormWidget", "0", nullptr));
        label_3->setText(QCoreApplication::translate("HoughTransormWidget", "Threshold", nullptr));
        circleThresholdValue->setText(QCoreApplication::translate("HoughTransormWidget", "0", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("HoughTransormWidget", "Elipse", nullptr));
        label_4->setText(QCoreApplication::translate("HoughTransormWidget", "Min Radius", nullptr));
        minElipseRadiusValue->setText(QCoreApplication::translate("HoughTransormWidget", "0", nullptr));
        label_5->setText(QCoreApplication::translate("HoughTransormWidget", "Max Radius", nullptr));
        maxElipseRadiusValue->setText(QCoreApplication::translate("HoughTransormWidget", "0", nullptr));
        label_6->setText(QCoreApplication::translate("HoughTransormWidget", "Threshold", nullptr));
        elipseThresholdValue->setText(QCoreApplication::translate("HoughTransormWidget", "0", nullptr));
        applyBtn->setText(QCoreApplication::translate("HoughTransormWidget", "Apply", nullptr));
        imageOriginal->setText(QString());
        imageDetected->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HoughTransormWidget: public Ui_HoughTransormWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOUGHTRANSORMWIDGET_H
