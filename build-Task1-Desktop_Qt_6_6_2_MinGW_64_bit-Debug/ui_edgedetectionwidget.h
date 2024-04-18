/********************************************************************************
** Form generated from reading UI file 'edgedetectionwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDGEDETECTIONWIDGET_H
#define UI_EDGEDETECTIONWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EdgeDetectionWidget
{
public:
    QHBoxLayout *horizontalLayout_5;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_8;
    QLabel *label;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QPushButton *apply_robert_detector;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_4;
    QPushButton *apply_prewitt_detector;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_6;
    QPushButton *apply_sobel_detector;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QLineEdit *cannyHighEditLine;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *cannyLowEditLine;
    QPushButton *apply_canny_detector;
    QVBoxLayout *verticalLayout_5;
    QFrame *frame_5;
    QHBoxLayout *horizontalLayout_4;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QLabel *imageOriginal;
    QSpacerItem *horizontalSpacer_3;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *imageDetected;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout;
    QPushButton *uploadImgBtn;
    QPushButton *resetFilterBtn;

    void setupUi(QWidget *EdgeDetectionWidget)
    {
        if (EdgeDetectionWidget->objectName().isEmpty())
            EdgeDetectionWidget->setObjectName("EdgeDetectionWidget");
        EdgeDetectionWidget->resize(1423, 788);
        horizontalLayout_5 = new QHBoxLayout(EdgeDetectionWidget);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setSizeConstraint(QLayout::SetNoConstraint);
        frame_3 = new QFrame(EdgeDetectionWidget);
        frame_3->setObjectName("frame_3");
        frame_3->setMaximumSize(QSize(300, 16777215));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_8 = new QVBoxLayout(frame_3);
        verticalLayout_8->setObjectName("verticalLayout_8");
        label = new QLabel(frame_3);
        label->setObjectName("label");
        label->setMaximumSize(QSize(16777215, 30));

        verticalLayout_8->addWidget(label);

        groupBox = new QGroupBox(frame_3);
        groupBox->setObjectName("groupBox");
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName("verticalLayout_3");
        apply_robert_detector = new QPushButton(groupBox);
        apply_robert_detector->setObjectName("apply_robert_detector");

        verticalLayout_3->addWidget(apply_robert_detector);


        verticalLayout_8->addWidget(groupBox);

        groupBox_2 = new QGroupBox(frame_3);
        groupBox_2->setObjectName("groupBox_2");
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setObjectName("verticalLayout_4");
        apply_prewitt_detector = new QPushButton(groupBox_2);
        apply_prewitt_detector->setObjectName("apply_prewitt_detector");

        verticalLayout_4->addWidget(apply_prewitt_detector);


        verticalLayout_8->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(frame_3);
        groupBox_3->setObjectName("groupBox_3");
        verticalLayout_6 = new QVBoxLayout(groupBox_3);
        verticalLayout_6->setObjectName("verticalLayout_6");
        apply_sobel_detector = new QPushButton(groupBox_3);
        apply_sobel_detector->setObjectName("apply_sobel_detector");

        verticalLayout_6->addWidget(apply_sobel_detector);


        verticalLayout_8->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(frame_3);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setMinimumSize(QSize(0, 212));
        verticalLayout_7 = new QVBoxLayout(groupBox_4);
        verticalLayout_7->setObjectName("verticalLayout_7");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        cannyHighEditLine = new QLineEdit(groupBox_4);
        cannyHighEditLine->setObjectName("cannyHighEditLine");

        horizontalLayout_2->addWidget(cannyHighEditLine);


        verticalLayout_7->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        cannyLowEditLine = new QLineEdit(groupBox_4);
        cannyLowEditLine->setObjectName("cannyLowEditLine");

        horizontalLayout_3->addWidget(cannyLowEditLine);


        verticalLayout_7->addLayout(horizontalLayout_3);

        apply_canny_detector = new QPushButton(groupBox_4);
        apply_canny_detector->setObjectName("apply_canny_detector");

        verticalLayout_7->addWidget(apply_canny_detector);


        verticalLayout_8->addWidget(groupBox_4);


        horizontalLayout_5->addWidget(frame_3);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        frame_5 = new QFrame(EdgeDetectionWidget);
        frame_5->setObjectName("frame_5");
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_5);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        frame = new QFrame(frame_5);
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

        frame_2 = new QFrame(frame_5);
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


        verticalLayout_5->addWidget(frame_5);

        frame_4 = new QFrame(EdgeDetectionWidget);
        frame_4->setObjectName("frame_4");
        frame_4->setMaximumSize(QSize(16777215, 60));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_4);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        uploadImgBtn = new QPushButton(frame_4);
        uploadImgBtn->setObjectName("uploadImgBtn");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(uploadImgBtn->sizePolicy().hasHeightForWidth());
        uploadImgBtn->setSizePolicy(sizePolicy);
        uploadImgBtn->setMinimumSize(QSize(300, 0));

        horizontalLayout->addWidget(uploadImgBtn);

        resetFilterBtn = new QPushButton(frame_4);
        resetFilterBtn->setObjectName("resetFilterBtn");
        sizePolicy.setHeightForWidth(resetFilterBtn->sizePolicy().hasHeightForWidth());
        resetFilterBtn->setSizePolicy(sizePolicy);
        resetFilterBtn->setMinimumSize(QSize(300, 0));

        horizontalLayout->addWidget(resetFilterBtn);


        verticalLayout_5->addWidget(frame_4);


        horizontalLayout_5->addLayout(verticalLayout_5);


        retranslateUi(EdgeDetectionWidget);

        QMetaObject::connectSlotsByName(EdgeDetectionWidget);
    } // setupUi

    void retranslateUi(QWidget *EdgeDetectionWidget)
    {
        EdgeDetectionWidget->setWindowTitle(QCoreApplication::translate("EdgeDetectionWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("EdgeDetectionWidget", "Edge Detection Menu", nullptr));
        groupBox->setTitle(QCoreApplication::translate("EdgeDetectionWidget", "Robert Technique", nullptr));
        apply_robert_detector->setText(QCoreApplication::translate("EdgeDetectionWidget", "Apply Robert Technique", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("EdgeDetectionWidget", "Prewitt Technique", nullptr));
        apply_prewitt_detector->setText(QCoreApplication::translate("EdgeDetectionWidget", "Apply Prewitt Technique", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("EdgeDetectionWidget", "Sobel Technique", nullptr));
        apply_sobel_detector->setText(QCoreApplication::translate("EdgeDetectionWidget", "Apply Sobel Technique", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("EdgeDetectionWidget", "Canny Technique", nullptr));
        label_2->setText(QCoreApplication::translate("EdgeDetectionWidget", "High Threshold:", nullptr));
        label_3->setText(QCoreApplication::translate("EdgeDetectionWidget", "Low Thershold:", nullptr));
        apply_canny_detector->setText(QCoreApplication::translate("EdgeDetectionWidget", "Apply Canny Technique", nullptr));
        imageOriginal->setText(QString());
        imageDetected->setText(QString());
        uploadImgBtn->setText(QCoreApplication::translate("EdgeDetectionWidget", "Upload", nullptr));
        resetFilterBtn->setText(QCoreApplication::translate("EdgeDetectionWidget", "Reset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EdgeDetectionWidget: public Ui_EdgeDetectionWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDGEDETECTIONWIDGET_H
