/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QFrame *sidebarFrame;
    QVBoxLayout *verticalLayout;
    QLabel *logo;
    QSpacerItem *verticalSpacer_2;
    QPushButton *filteringBtn;
    QPushButton *edgeDetectionBtn;
    QPushButton *equalizationBtn;
    QPushButton *histogramsBtn;
    QPushButton *thresholdingBtn;
    QPushButton *hybridBtn;
    QPushButton *frequencyBtn;
    QPushButton *houghTransformBtn;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *widgetsLayout;
    QStackedWidget *stackedWidget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1500, 615);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("#centralwidget{\n"
"	background-color: #222831;\n"
"}\n"
"#sidebarFrame{\n"
"	\n"
"	background-color: #31363F;\n"
"}\n"
"\n"
"QPushButton{\n"
"	background-color: #316669;\n"
"	border: none;\n"
" 	border-radius: 6px;\n"
"  	color: #EEEEEE;\n"
"  	font-size: 14px;\n"
"  	font-weight: 500;\n"
"  	line-height: 20px;\n"
"  	list-style: none;\n"
"  	padding: 4px 12px;\n"
"  	height:30px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: rgba(118, 171, 174, 203);\n"
" 	text-decoration: none;\n"
"}\n"
"QPushButton:focus{\n"
" 	outline: 1px transparent;\n"
"}\n"
"QLabel{\n"
"	color: #EEEEEE;\n"
"	font-weight: bold;\n"
"	font-size: 16px;\n"
"}\n"
"QGroupBox{\n"
"	color: #EEEEEE;\n"
"	font-weight: bold;\n"
"	font-size: 16px;\n"
"	padding:30px 0px 0px 0px;\n"
"	border:none;	\n"
"}\n"
"QLineEdit{\n"
"	background-color: #31363F;\n"
"	border:none;\n"
"	padding:4px 10px;\n"
"	border-radius: 3px;\n"
"}\n"
"QFrame{\n"
"	border:none;\n"
"}\n"
""));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        sidebarFrame = new QFrame(centralwidget);
        sidebarFrame->setObjectName("sidebarFrame");
        sidebarFrame->setMinimumSize(QSize(300, 0));
        sidebarFrame->setMaximumSize(QSize(300, 16777215));
        sidebarFrame->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	\n"
"  	height:40px;\n"
"}"));
        sidebarFrame->setFrameShape(QFrame::StyledPanel);
        sidebarFrame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(sidebarFrame);
        verticalLayout->setObjectName("verticalLayout");
        logo = new QLabel(sidebarFrame);
        logo->setObjectName("logo");

        verticalLayout->addWidget(logo);

        verticalSpacer_2 = new QSpacerItem(20, 203, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        filteringBtn = new QPushButton(sidebarFrame);
        filteringBtn->setObjectName("filteringBtn");

        verticalLayout->addWidget(filteringBtn);

        edgeDetectionBtn = new QPushButton(sidebarFrame);
        edgeDetectionBtn->setObjectName("edgeDetectionBtn");

        verticalLayout->addWidget(edgeDetectionBtn);

        equalizationBtn = new QPushButton(sidebarFrame);
        equalizationBtn->setObjectName("equalizationBtn");

        verticalLayout->addWidget(equalizationBtn);

        histogramsBtn = new QPushButton(sidebarFrame);
        histogramsBtn->setObjectName("histogramsBtn");

        verticalLayout->addWidget(histogramsBtn);

        thresholdingBtn = new QPushButton(sidebarFrame);
        thresholdingBtn->setObjectName("thresholdingBtn");

        verticalLayout->addWidget(thresholdingBtn);

        hybridBtn = new QPushButton(sidebarFrame);
        hybridBtn->setObjectName("hybridBtn");

        verticalLayout->addWidget(hybridBtn);

        frequencyBtn = new QPushButton(sidebarFrame);
        frequencyBtn->setObjectName("frequencyBtn");

        verticalLayout->addWidget(frequencyBtn);

        houghTransformBtn = new QPushButton(sidebarFrame);
        houghTransformBtn->setObjectName("houghTransformBtn");

        verticalLayout->addWidget(houghTransformBtn);

        verticalSpacer = new QSpacerItem(20, 202, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addWidget(sidebarFrame);

        widgetsLayout = new QHBoxLayout();
        widgetsLayout->setObjectName("widgetsLayout");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");

        widgetsLayout->addWidget(stackedWidget);


        horizontalLayout->addLayout(widgetsLayout);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        logo->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        filteringBtn->setText(QCoreApplication::translate("MainWindow", "Filtering", nullptr));
        edgeDetectionBtn->setText(QCoreApplication::translate("MainWindow", "Edge Deteiction", nullptr));
        equalizationBtn->setText(QCoreApplication::translate("MainWindow", "Equalization", nullptr));
        histogramsBtn->setText(QCoreApplication::translate("MainWindow", "Histogram Plots", nullptr));
        thresholdingBtn->setText(QCoreApplication::translate("MainWindow", "Thresholding", nullptr));
        hybridBtn->setText(QCoreApplication::translate("MainWindow", "Hybrid Image", nullptr));
        frequencyBtn->setText(QCoreApplication::translate("MainWindow", "Frequency filter", nullptr));
        houghTransformBtn->setText(QCoreApplication::translate("MainWindow", "Hough Transform", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
