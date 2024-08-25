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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *openButton;
    QPushButton *closeButton;
    QTextBrowser *textBrowser;
    QComboBox *baudRateComboBox;
    QPushButton *clearButton;
    QLabel *baudrateLabel;
    QPushButton *applyButton;
    QComboBox *serialPortComboBox;
    QLabel *portLabel;
    QTextBrowser *statusTextBrowser;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        openButton = new QPushButton(centralwidget);
        openButton->setObjectName("openButton");
        openButton->setGeometry(QRect(70, 250, 83, 29));
        closeButton = new QPushButton(centralwidget);
        closeButton->setObjectName("closeButton");
        closeButton->setGeometry(QRect(190, 250, 83, 29));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(70, 20, 256, 192));
        baudRateComboBox = new QComboBox(centralwidget);
        baudRateComboBox->setObjectName("baudRateComboBox");
        baudRateComboBox->setGeometry(QRect(70, 460, 82, 28));
        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName("clearButton");
        clearButton->setGeometry(QRect(350, 20, 83, 29));
        baudrateLabel = new QLabel(centralwidget);
        baudrateLabel->setObjectName("baudrateLabel");
        baudrateLabel->setGeometry(QRect(70, 410, 71, 31));
        applyButton = new QPushButton(centralwidget);
        applyButton->setObjectName("applyButton");
        applyButton->setGeometry(QRect(310, 460, 83, 29));
        serialPortComboBox = new QComboBox(centralwidget);
        serialPortComboBox->setObjectName("serialPortComboBox");
        serialPortComboBox->setGeometry(QRect(190, 460, 82, 28));
        portLabel = new QLabel(centralwidget);
        portLabel->setObjectName("portLabel");
        portLabel->setGeometry(QRect(190, 400, 81, 41));
        statusTextBrowser = new QTextBrowser(centralwidget);
        statusTextBrowser->setObjectName("statusTextBrowser");
        statusTextBrowser->setGeometry(QRect(470, 20, 256, 192));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
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
        clearButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        baudrateLabel->setText(QCoreApplication::translate("MainWindow", "Baudrate", nullptr));
        applyButton->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        portLabel->setText(QCoreApplication::translate("MainWindow", "Serial Port", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
