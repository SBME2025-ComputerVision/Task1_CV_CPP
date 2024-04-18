/********************************************************************************
** Form generated from reading UI file 'filterswidget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERSWIDGET_H
#define UI_FILTERSWIDGET_H

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

class Ui_FiltersWidget
{
public:
    QHBoxLayout *horizontalLayout_8;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_4;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_10;
    QLabel *label;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *threeByThreeKernelBtn;
    QPushButton *fiveByFiveKernelBtn;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *sigmaLineEdit;
    QPushButton *apply_gaussian_filter;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_8;
    QPushButton *apply_avg_filter;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_9;
    QPushButton *apply_median_filter;
    QFrame *frame_6;
    QVBoxLayout *verticalLayout_14;
    QLabel *label_2;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer;
    QLineEdit *meanNoiseLineEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *sigmaNoiseLineEdit;
    QPushButton *apply_gaussian_noise;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_12;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *rNoiseLineEdit;
    QPushButton *apply_saltpeper_noise;
    QGroupBox *groupBox_7;
    QVBoxLayout *verticalLayout_13;
    QPushButton *apply_uniform_noise;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame_7;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_6;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QLabel *imageOriginal;
    QSpacerItem *horizontalSpacer_5;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *imageFiltered;
    QSpacerItem *horizontalSpacer_7;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *resetFilterBtn;
    QPushButton *saveBtn;
    QPushButton *uploadImgBtn;

    void setupUi(QWidget *FiltersWidget)
    {
        if (FiltersWidget->objectName().isEmpty())
            FiltersWidget->setObjectName("FiltersWidget");
        FiltersWidget->resize(1411, 789);
        horizontalLayout_8 = new QHBoxLayout(FiltersWidget);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        frame_4 = new QFrame(FiltersWidget);
        frame_4->setObjectName("frame_4");
        frame_4->setMaximumSize(QSize(300, 16777215));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_4);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        frame_5 = new QFrame(frame_4);
        frame_5->setObjectName("frame_5");
        frame_5->setMaximumSize(QSize(300, 16777215));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        verticalLayout_10 = new QVBoxLayout(frame_5);
        verticalLayout_10->setSpacing(0);
        verticalLayout_10->setObjectName("verticalLayout_10");
        verticalLayout_10->setContentsMargins(0, 0, 0, -1);
        label = new QLabel(frame_5);
        label->setObjectName("label");
        label->setMaximumSize(QSize(16777215, 30));

        verticalLayout_10->addWidget(label);

        groupBox_4 = new QGroupBox(frame_5);
        groupBox_4->setObjectName("groupBox_4");
        horizontalLayout_3 = new QHBoxLayout(groupBox_4);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        threeByThreeKernelBtn = new QPushButton(groupBox_4);
        threeByThreeKernelBtn->setObjectName("threeByThreeKernelBtn");
        threeByThreeKernelBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #76ABAE;\n"
"}"));

        horizontalLayout->addWidget(threeByThreeKernelBtn);

        fiveByFiveKernelBtn = new QPushButton(groupBox_4);
        fiveByFiveKernelBtn->setObjectName("fiveByFiveKernelBtn");

        horizontalLayout->addWidget(fiveByFiveKernelBtn);


        horizontalLayout_3->addLayout(horizontalLayout);


        verticalLayout_10->addWidget(groupBox_4);

        groupBox = new QGroupBox(frame_5);
        groupBox->setObjectName("groupBox");
        verticalLayout_7 = new QVBoxLayout(groupBox);
        verticalLayout_7->setObjectName("verticalLayout_7");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");

        horizontalLayout_2->addWidget(label_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        sigmaLineEdit = new QLineEdit(groupBox);
        sigmaLineEdit->setObjectName("sigmaLineEdit");

        horizontalLayout_2->addWidget(sigmaLineEdit);


        verticalLayout_7->addLayout(horizontalLayout_2);

        apply_gaussian_filter = new QPushButton(groupBox);
        apply_gaussian_filter->setObjectName("apply_gaussian_filter");

        verticalLayout_7->addWidget(apply_gaussian_filter);


        verticalLayout_10->addWidget(groupBox);

        groupBox_2 = new QGroupBox(frame_5);
        groupBox_2->setObjectName("groupBox_2");
        verticalLayout_8 = new QVBoxLayout(groupBox_2);
        verticalLayout_8->setObjectName("verticalLayout_8");
        apply_avg_filter = new QPushButton(groupBox_2);
        apply_avg_filter->setObjectName("apply_avg_filter");

        verticalLayout_8->addWidget(apply_avg_filter);


        verticalLayout_10->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(frame_5);
        groupBox_3->setObjectName("groupBox_3");
        verticalLayout_9 = new QVBoxLayout(groupBox_3);
        verticalLayout_9->setObjectName("verticalLayout_9");
        apply_median_filter = new QPushButton(groupBox_3);
        apply_median_filter->setObjectName("apply_median_filter");

        verticalLayout_9->addWidget(apply_median_filter);


        verticalLayout_10->addWidget(groupBox_3);


        verticalLayout_4->addWidget(frame_5);

        frame_6 = new QFrame(frame_4);
        frame_6->setObjectName("frame_6");
        frame_6->setMaximumSize(QSize(300, 16777215));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        verticalLayout_14 = new QVBoxLayout(frame_6);
        verticalLayout_14->setSpacing(0);
        verticalLayout_14->setObjectName("verticalLayout_14");
        verticalLayout_14->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(frame_6);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(16777215, 30));

        verticalLayout_14->addWidget(label_2);

        groupBox_5 = new QGroupBox(frame_6);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_11 = new QVBoxLayout(groupBox_5);
        verticalLayout_11->setObjectName("verticalLayout_11");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_4 = new QLabel(groupBox_5);
        label_4->setObjectName("label_4");

        horizontalLayout_4->addWidget(label_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        meanNoiseLineEdit = new QLineEdit(groupBox_5);
        meanNoiseLineEdit->setObjectName("meanNoiseLineEdit");

        horizontalLayout_4->addWidget(meanNoiseLineEdit);


        verticalLayout_11->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_5 = new QLabel(groupBox_5);
        label_5->setObjectName("label_5");

        horizontalLayout_5->addWidget(label_5);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        sigmaNoiseLineEdit = new QLineEdit(groupBox_5);
        sigmaNoiseLineEdit->setObjectName("sigmaNoiseLineEdit");

        horizontalLayout_5->addWidget(sigmaNoiseLineEdit);


        verticalLayout_11->addLayout(horizontalLayout_5);

        apply_gaussian_noise = new QPushButton(groupBox_5);
        apply_gaussian_noise->setObjectName("apply_gaussian_noise");

        verticalLayout_11->addWidget(apply_gaussian_noise);


        verticalLayout_14->addWidget(groupBox_5);

        groupBox_6 = new QGroupBox(frame_6);
        groupBox_6->setObjectName("groupBox_6");
        verticalLayout_12 = new QVBoxLayout(groupBox_6);
        verticalLayout_12->setObjectName("verticalLayout_12");
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_6 = new QLabel(groupBox_6);
        label_6->setObjectName("label_6");

        horizontalLayout_6->addWidget(label_6);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        rNoiseLineEdit = new QLineEdit(groupBox_6);
        rNoiseLineEdit->setObjectName("rNoiseLineEdit");

        horizontalLayout_6->addWidget(rNoiseLineEdit);


        verticalLayout_12->addLayout(horizontalLayout_6);

        apply_saltpeper_noise = new QPushButton(groupBox_6);
        apply_saltpeper_noise->setObjectName("apply_saltpeper_noise");

        verticalLayout_12->addWidget(apply_saltpeper_noise);


        verticalLayout_14->addWidget(groupBox_6);

        groupBox_7 = new QGroupBox(frame_6);
        groupBox_7->setObjectName("groupBox_7");
        verticalLayout_13 = new QVBoxLayout(groupBox_7);
        verticalLayout_13->setObjectName("verticalLayout_13");
        apply_uniform_noise = new QPushButton(groupBox_7);
        apply_uniform_noise->setObjectName("apply_uniform_noise");

        verticalLayout_13->addWidget(apply_uniform_noise);


        verticalLayout_14->addWidget(groupBox_7);


        verticalLayout_4->addWidget(frame_6);


        horizontalLayout_8->addWidget(frame_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        frame_7 = new QFrame(FiltersWidget);
        frame_7->setObjectName("frame_7");
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        horizontalLayout_9 = new QHBoxLayout(frame_7);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_6);

        frame = new QFrame(frame_7);
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


        horizontalLayout_9->addWidget(frame);

        horizontalSpacer_5 = new QSpacerItem(31, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_5);

        frame_2 = new QFrame(frame_7);
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
        imageFiltered = new QLabel(frame_2);
        imageFiltered->setObjectName("imageFiltered");

        verticalLayout_2->addWidget(imageFiltered);


        horizontalLayout_9->addWidget(frame_2);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_7);


        verticalLayout_3->addWidget(frame_7);

        frame_3 = new QFrame(FiltersWidget);
        frame_3->setObjectName("frame_3");
        frame_3->setMaximumSize(QSize(16777215, 50));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_7 = new QHBoxLayout(frame_3);
        horizontalLayout_7->setSpacing(12);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        resetFilterBtn = new QPushButton(frame_3);
        resetFilterBtn->setObjectName("resetFilterBtn");

        horizontalLayout_7->addWidget(resetFilterBtn);

        saveBtn = new QPushButton(frame_3);
        saveBtn->setObjectName("saveBtn");

        horizontalLayout_7->addWidget(saveBtn);

        uploadImgBtn = new QPushButton(frame_3);
        uploadImgBtn->setObjectName("uploadImgBtn");
        uploadImgBtn->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_7->addWidget(uploadImgBtn);


        verticalLayout_3->addWidget(frame_3);


        horizontalLayout_8->addLayout(verticalLayout_3);


        retranslateUi(FiltersWidget);

        QMetaObject::connectSlotsByName(FiltersWidget);
    } // setupUi

    void retranslateUi(QWidget *FiltersWidget)
    {
        FiltersWidget->setWindowTitle(QCoreApplication::translate("FiltersWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("FiltersWidget", "Filters Menu", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("FiltersWidget", "Kernel Size", nullptr));
        threeByThreeKernelBtn->setText(QCoreApplication::translate("FiltersWidget", "3*3", nullptr));
        fiveByFiveKernelBtn->setText(QCoreApplication::translate("FiltersWidget", "5*5", nullptr));
        groupBox->setTitle(QCoreApplication::translate("FiltersWidget", "Gaussian Filter", nullptr));
        label_3->setText(QCoreApplication::translate("FiltersWidget", "Sigma: ", nullptr));
        apply_gaussian_filter->setText(QCoreApplication::translate("FiltersWidget", "Apply Gaussian", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("FiltersWidget", "Average Filter", nullptr));
        apply_avg_filter->setText(QCoreApplication::translate("FiltersWidget", "Apply Average", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("FiltersWidget", "Median Filter", nullptr));
        apply_median_filter->setText(QCoreApplication::translate("FiltersWidget", "Apply Median", nullptr));
        label_2->setText(QCoreApplication::translate("FiltersWidget", "Noise Menu", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("FiltersWidget", "Gaussian Noise", nullptr));
        label_4->setText(QCoreApplication::translate("FiltersWidget", "Mean:", nullptr));
        label_5->setText(QCoreApplication::translate("FiltersWidget", "Sigma:", nullptr));
        apply_gaussian_noise->setText(QCoreApplication::translate("FiltersWidget", "Apply Gaussian", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("FiltersWidget", "Salt and Pepper Noise", nullptr));
        label_6->setText(QCoreApplication::translate("FiltersWidget", "Ratio:", nullptr));
        apply_saltpeper_noise->setText(QCoreApplication::translate("FiltersWidget", "Apply Salt and Peper", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("FiltersWidget", "Uniform Noise", nullptr));
        apply_uniform_noise->setText(QCoreApplication::translate("FiltersWidget", "Apply Uniform", nullptr));
        imageOriginal->setText(QString());
        imageFiltered->setText(QString());
        resetFilterBtn->setText(QCoreApplication::translate("FiltersWidget", "Reset", nullptr));
        saveBtn->setText(QCoreApplication::translate("FiltersWidget", "Save", nullptr));
        uploadImgBtn->setText(QCoreApplication::translate("FiltersWidget", "Upload", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FiltersWidget: public Ui_FiltersWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERSWIDGET_H
