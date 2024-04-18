/********************************************************************************
** Form generated from reading UI file 'thresholdwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THRESHOLDWIDGET_H
#define UI_THRESHOLDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ThresholdWidget
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame_7;
    QHBoxLayout *horizontalLayout_4;
    QFrame *frame_8;
    QVBoxLayout *verticalLayout_2;
    QLabel *originalImage;
    QSpacerItem *horizontalSpacer_3;
    QFrame *frame_9;
    QVBoxLayout *verticalLayout_3;
    QLabel *processedImage;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *uploadBtn;
    QPushButton *globalThresholdBtn;
    QPushButton *localThresholdBtn;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSlider *radiusSLider;

    void setupUi(QWidget *ThresholdWidget)
    {
        if (ThresholdWidget->objectName().isEmpty())
            ThresholdWidget->setObjectName("ThresholdWidget");
        ThresholdWidget->resize(1222, 670);
        verticalLayout = new QVBoxLayout(ThresholdWidget);
        verticalLayout->setObjectName("verticalLayout");
        frame_7 = new QFrame(ThresholdWidget);
        frame_7->setObjectName("frame_7");
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_7);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        frame_8 = new QFrame(frame_7);
        frame_8->setObjectName("frame_8");
        frame_8->setMinimumSize(QSize(500, 500));
        frame_8->setMaximumSize(QSize(500, 500));
        frame_8->setStyleSheet(QString::fromUtf8("\n"
"           border: 2px solid  #316669;\n"
"          border-radius: 10px;\n"
"      "));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_8);
        verticalLayout_2->setObjectName("verticalLayout_2");
        originalImage = new QLabel(frame_8);
        originalImage->setObjectName("originalImage");

        verticalLayout_2->addWidget(originalImage);


        horizontalLayout_4->addWidget(frame_8);

        horizontalSpacer_3 = new QSpacerItem(31, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        frame_9 = new QFrame(frame_7);
        frame_9->setObjectName("frame_9");
        frame_9->setMinimumSize(QSize(500, 500));
        frame_9->setMaximumSize(QSize(500, 500));
        frame_9->setStyleSheet(QString::fromUtf8("\n"
"           border: 2px solid  #316669;\n"
"          border-radius: 10px;\n"
"      "));
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_9);
        verticalLayout_3->setObjectName("verticalLayout_3");
        processedImage = new QLabel(frame_9);
        processedImage->setObjectName("processedImage");

        verticalLayout_3->addWidget(processedImage);


        horizontalLayout_4->addWidget(frame_9);


        verticalLayout->addWidget(frame_7);

        frame = new QFrame(ThresholdWidget);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        uploadBtn = new QPushButton(frame);
        uploadBtn->setObjectName("uploadBtn");

        horizontalLayout->addWidget(uploadBtn);

        globalThresholdBtn = new QPushButton(frame);
        globalThresholdBtn->setObjectName("globalThresholdBtn");

        horizontalLayout->addWidget(globalThresholdBtn);

        localThresholdBtn = new QPushButton(frame);
        localThresholdBtn->setObjectName("localThresholdBtn");

        horizontalLayout->addWidget(localThresholdBtn);


        horizontalLayout_3->addLayout(horizontalLayout);

        frame_2 = new QFrame(frame);
        frame_2->setObjectName("frame_2");
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(frame_2);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        radiusSLider = new QSlider(frame_2);
        radiusSLider->setObjectName("radiusSLider");
        radiusSLider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(radiusSLider);


        horizontalLayout_3->addWidget(frame_2);


        verticalLayout->addWidget(frame);


        retranslateUi(ThresholdWidget);

        QMetaObject::connectSlotsByName(ThresholdWidget);
    } // setupUi

    void retranslateUi(QWidget *ThresholdWidget)
    {
        ThresholdWidget->setWindowTitle(QCoreApplication::translate("ThresholdWidget", "Form", nullptr));
        originalImage->setText(QString());
        processedImage->setText(QString());
        uploadBtn->setText(QCoreApplication::translate("ThresholdWidget", "Upload", nullptr));
        globalThresholdBtn->setText(QCoreApplication::translate("ThresholdWidget", "Global Thresholding", nullptr));
        localThresholdBtn->setText(QCoreApplication::translate("ThresholdWidget", "Local Thresholding", nullptr));
        label->setText(QCoreApplication::translate("ThresholdWidget", "Global threshold", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ThresholdWidget: public Ui_ThresholdWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THRESHOLDWIDGET_H
