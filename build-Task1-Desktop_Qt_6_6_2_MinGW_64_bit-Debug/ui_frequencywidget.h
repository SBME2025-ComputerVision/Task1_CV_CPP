/********************************************************************************
** Form generated from reading UI file 'frequencywidget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FREQUENCYWIDGET_H
#define UI_FREQUENCYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FrequencyWidget
{
public:
    QFrame *frame_6;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout;
    QRadioButton *highPassRadio;
    QRadioButton *lowPassRadio;
    QFrame *frame_5;
    QSlider *radiusSLider;
    QLabel *label_3;
    QPushButton *browseBtn;
    QFrame *frame_7;
    QHBoxLayout *horizontalLayout_4;
    QFrame *frame_8;
    QVBoxLayout *verticalLayout_2;
    QLabel *originalImage;
    QSpacerItem *horizontalSpacer_3;
    QFrame *frame_9;
    QVBoxLayout *verticalLayout_3;
    QLabel *processedImage;

    void setupUi(QWidget *FrequencyWidget)
    {
        if (FrequencyWidget->objectName().isEmpty())
            FrequencyWidget->setObjectName("FrequencyWidget");
        FrequencyWidget->resize(1326, 869);
        frame_6 = new QFrame(FrequencyWidget);
        frame_6->setObjectName("frame_6");
        frame_6->setGeometry(QRect(260, 590, 681, 171));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        frame_4 = new QFrame(frame_6);
        frame_4->setObjectName("frame_4");
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_4);
        verticalLayout->setObjectName("verticalLayout");
        highPassRadio = new QRadioButton(frame_4);
        highPassRadio->setObjectName("highPassRadio");

        verticalLayout->addWidget(highPassRadio);

        lowPassRadio = new QRadioButton(frame_4);
        lowPassRadio->setObjectName("lowPassRadio");

        verticalLayout->addWidget(lowPassRadio);


        horizontalLayout_2->addWidget(frame_4);

        frame_5 = new QFrame(frame_6);
        frame_5->setObjectName("frame_5");
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        radiusSLider = new QSlider(frame_5);
        radiusSLider->setObjectName("radiusSLider");
        radiusSLider->setGeometry(QRect(19, 70, 251, 20));
        radiusSLider->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(frame_5);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 40, 61, 31));
        browseBtn = new QPushButton(frame_5);
        browseBtn->setObjectName("browseBtn");
        browseBtn->setGeometry(QRect(20, 10, 89, 25));

        horizontalLayout_2->addWidget(frame_5);

        frame_7 = new QFrame(FrequencyWidget);
        frame_7->setObjectName("frame_7");
        frame_7->setGeometry(QRect(110, 0, 1121, 561));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_7);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        frame_8 = new QFrame(frame_7);
        frame_8->setObjectName("frame_8");
        frame_8->setMinimumSize(QSize(500, 500));
        frame_8->setMaximumSize(QSize(500, 500));
        frame_8->setStyleSheet(QString::fromUtf8("\n"
"           border: 2px solid #316669;\n"
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


        retranslateUi(FrequencyWidget);

        QMetaObject::connectSlotsByName(FrequencyWidget);
    } // setupUi

    void retranslateUi(QWidget *FrequencyWidget)
    {
        FrequencyWidget->setWindowTitle(QCoreApplication::translate("FrequencyWidget", "Form", nullptr));
        highPassRadio->setText(QCoreApplication::translate("FrequencyWidget", "High Pass Filter", nullptr));
        lowPassRadio->setText(QCoreApplication::translate("FrequencyWidget", "Low Pass Filter", nullptr));
        label_3->setText(QCoreApplication::translate("FrequencyWidget", "Radius", nullptr));
        browseBtn->setText(QCoreApplication::translate("FrequencyWidget", "Browse", nullptr));
        originalImage->setText(QString());
        processedImage->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FrequencyWidget: public Ui_FrequencyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FREQUENCYWIDGET_H
