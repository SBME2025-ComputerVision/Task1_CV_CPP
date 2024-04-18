/********************************************************************************
** Form generated from reading UI file 'hybridwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HYBRIDWIDGET_H
#define UI_HYBRIDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HybridWidget
{
public:
    QVBoxLayout *verticalLayout_4;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QLabel *hybridLpImg;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *hybridHpImg;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *hybridMixedImg;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer_3;
    QFrame *frame_5;
    QHBoxLayout *horizontalLayout;
    QPushButton *lpImgBtn;
    QPushButton *hpImgBtn;
    QPushButton *mixImgBtn;

    void setupUi(QWidget *HybridWidget)
    {
        if (HybridWidget->objectName().isEmpty())
            HybridWidget->setObjectName("HybridWidget");
        HybridWidget->resize(1253, 691);
        verticalLayout_4 = new QVBoxLayout(HybridWidget);
        verticalLayout_4->setObjectName("verticalLayout_4");
        frame_4 = new QFrame(HybridWidget);
        frame_4->setObjectName("frame_4");
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(frame_4);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(frame_4);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        frame = new QFrame(frame_4);
        frame->setObjectName("frame");
        QSizePolicy sizePolicy(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMinimumSize(QSize(391, 481));
        frame->setMaximumSize(QSize(16777215, 500));
        frame->setStyleSheet(QString::fromUtf8("\n"
"           border: 2px solid  #316669;\n"
"          border-radius: 10px;\n"
"      "));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        hybridLpImg = new QLabel(frame);
        hybridLpImg->setObjectName("hybridLpImg");
        hybridLpImg->setMinimumSize(QSize(361, 451));

        horizontalLayout_2->addWidget(hybridLpImg);


        verticalLayout->addWidget(frame);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_5->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(0, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_2 = new QLabel(frame_4);
        label_2->setObjectName("label_2");

        verticalLayout_2->addWidget(label_2);

        frame_2 = new QFrame(frame_4);
        frame_2->setObjectName("frame_2");
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setMinimumSize(QSize(391, 481));
        frame_2->setMaximumSize(QSize(16777215, 500));
        frame_2->setStyleSheet(QString::fromUtf8("\n"
"           border: 2px solid #316669;\n"
"          border-radius: 10px;\n"
"      "));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        hybridHpImg = new QLabel(frame_2);
        hybridHpImg->setObjectName("hybridHpImg");

        horizontalLayout_3->addWidget(hybridHpImg);


        verticalLayout_2->addWidget(frame_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout_5->addLayout(verticalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(0, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_3 = new QLabel(frame_4);
        label_3->setObjectName("label_3");

        verticalLayout_3->addWidget(label_3);

        frame_3 = new QFrame(frame_4);
        frame_3->setObjectName("frame_3");
        sizePolicy.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy);
        frame_3->setMinimumSize(QSize(391, 481));
        frame_3->setMaximumSize(QSize(16777215, 500));
        frame_3->setStyleSheet(QString::fromUtf8("\n"
"           border: 2px solid  #316669;\n"
"          border-radius: 10px;\n"
"      "));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_3);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        hybridMixedImg = new QLabel(frame_3);
        hybridMixedImg->setObjectName("hybridMixedImg");

        horizontalLayout_4->addWidget(hybridMixedImg);


        verticalLayout_3->addWidget(frame_3);

        pushButton = new QPushButton(frame_4);
        pushButton->setObjectName("pushButton");

        verticalLayout_3->addWidget(pushButton);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);


        horizontalLayout_5->addLayout(verticalLayout_3);


        verticalLayout_4->addWidget(frame_4);

        frame_5 = new QFrame(HybridWidget);
        frame_5->setObjectName("frame_5");
        frame_5->setMaximumSize(QSize(16777215, 40));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_5);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lpImgBtn = new QPushButton(frame_5);
        lpImgBtn->setObjectName("lpImgBtn");

        horizontalLayout->addWidget(lpImgBtn);

        hpImgBtn = new QPushButton(frame_5);
        hpImgBtn->setObjectName("hpImgBtn");

        horizontalLayout->addWidget(hpImgBtn);

        mixImgBtn = new QPushButton(frame_5);
        mixImgBtn->setObjectName("mixImgBtn");

        horizontalLayout->addWidget(mixImgBtn);


        verticalLayout_4->addWidget(frame_5);


        retranslateUi(HybridWidget);

        QMetaObject::connectSlotsByName(HybridWidget);
    } // setupUi

    void retranslateUi(QWidget *HybridWidget)
    {
        HybridWidget->setWindowTitle(QCoreApplication::translate("HybridWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("HybridWidget", "Low Pass Image ", nullptr));
        hybridLpImg->setText(QString());
        label_2->setText(QCoreApplication::translate("HybridWidget", "High Pass Image", nullptr));
        hybridHpImg->setText(QString());
        label_3->setText(QCoreApplication::translate("HybridWidget", "Hybrid Image", nullptr));
        hybridMixedImg->setText(QString());
        pushButton->setText(QCoreApplication::translate("HybridWidget", "\331\215Save Image", nullptr));
        lpImgBtn->setText(QCoreApplication::translate("HybridWidget", "upload Low Pass Image", nullptr));
        hpImgBtn->setText(QCoreApplication::translate("HybridWidget", "upload High Pass Image", nullptr));
        mixImgBtn->setText(QCoreApplication::translate("HybridWidget", "mix", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HybridWidget: public Ui_HybridWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HYBRIDWIDGET_H
