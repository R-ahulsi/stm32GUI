/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_8;
    QGridLayout *gridLayout_9;
    QVBoxLayout *verticalLayout_6;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *openButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *clearLogButton;
    QVBoxLayout *verticalLayout_7;
    QTextBrowser *statusTextBrowser;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *clearStatusButton;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_12;
    QGridLayout *gridLayout_3;
    QLabel *baudrateLabel;
    QComboBox *baudRateComboBox;
    QComboBox *serialPortComboBox;
    QLabel *portLabel;
    QPushButton *applyButton;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout;
    QLabel *selectedFileLabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *selectFileButton;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *uploadFileButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(861, 462);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget_3 = new QWidget(centralwidget);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(40, 10, 781, 391));
        verticalLayout_8 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName("gridLayout_9");
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        textBrowser = new QTextBrowser(verticalLayoutWidget_3);
        textBrowser->setObjectName("textBrowser");

        verticalLayout_6->addWidget(textBrowser);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        openButton = new QPushButton(verticalLayoutWidget_3);
        openButton->setObjectName("openButton");

        horizontalLayout_10->addWidget(openButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer);

        closeButton = new QPushButton(verticalLayoutWidget_3);
        closeButton->setObjectName("closeButton");

        horizontalLayout_10->addWidget(closeButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_2);

        clearLogButton = new QPushButton(verticalLayoutWidget_3);
        clearLogButton->setObjectName("clearLogButton");

        horizontalLayout_10->addWidget(clearLogButton);


        verticalLayout_6->addLayout(horizontalLayout_10);


        gridLayout_9->addLayout(verticalLayout_6, 0, 0, 1, 1);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        statusTextBrowser = new QTextBrowser(verticalLayoutWidget_3);
        statusTextBrowser->setObjectName("statusTextBrowser");

        verticalLayout_7->addWidget(statusTextBrowser);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_3);

        clearStatusButton = new QPushButton(verticalLayoutWidget_3);
        clearStatusButton->setObjectName("clearStatusButton");

        horizontalLayout_11->addWidget(clearStatusButton);


        verticalLayout_7->addLayout(horizontalLayout_11);


        gridLayout_9->addLayout(verticalLayout_7, 0, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_4, 0, 1, 1, 1);


        verticalLayout_8->addLayout(gridLayout_9);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_8->addItem(verticalSpacer);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        baudrateLabel = new QLabel(verticalLayoutWidget_3);
        baudrateLabel->setObjectName("baudrateLabel");

        gridLayout_3->addWidget(baudrateLabel, 0, 0, 1, 1);

        baudRateComboBox = new QComboBox(verticalLayoutWidget_3);
        baudRateComboBox->setObjectName("baudRateComboBox");

        gridLayout_3->addWidget(baudRateComboBox, 1, 0, 1, 1);

        serialPortComboBox = new QComboBox(verticalLayoutWidget_3);
        serialPortComboBox->setObjectName("serialPortComboBox");

        gridLayout_3->addWidget(serialPortComboBox, 1, 1, 1, 1);

        portLabel = new QLabel(verticalLayoutWidget_3);
        portLabel->setObjectName("portLabel");

        gridLayout_3->addWidget(portLabel, 0, 1, 1, 1);

        applyButton = new QPushButton(verticalLayoutWidget_3);
        applyButton->setObjectName("applyButton");

        gridLayout_3->addWidget(applyButton, 1, 2, 1, 1);


        horizontalLayout_12->addLayout(gridLayout_3);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_5);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        selectedFileLabel = new QLabel(verticalLayoutWidget_3);
        selectedFileLabel->setObjectName("selectedFileLabel");

        verticalLayout->addWidget(selectedFileLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        selectFileButton = new QPushButton(verticalLayoutWidget_3);
        selectFileButton->setObjectName("selectFileButton");

        horizontalLayout->addWidget(selectFileButton);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        uploadFileButton = new QPushButton(verticalLayoutWidget_3);
        uploadFileButton->setObjectName("uploadFileButton");

        horizontalLayout->addWidget(uploadFileButton);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_12->addLayout(verticalLayout);


        verticalLayout_8->addLayout(horizontalLayout_12);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 861, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        openButton->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        closeButton->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        clearLogButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        clearStatusButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        baudrateLabel->setText(QCoreApplication::translate("MainWindow", "Baudrate", nullptr));
        portLabel->setText(QCoreApplication::translate("MainWindow", "Serial Port", nullptr));
        applyButton->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        selectedFileLabel->setText(QCoreApplication::translate("MainWindow", "No file selected", nullptr));
        selectFileButton->setText(QCoreApplication::translate("MainWindow", "Select File", nullptr));
        uploadFileButton->setText(QCoreApplication::translate("MainWindow", "Upload", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
