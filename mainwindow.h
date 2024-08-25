#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openSerialPort();              // Opening the serial port
    void closeSerialPort();             // Closing the serial port
    void readData();                    // Reading data from UART
    void clearTextBrowser();            // Clearing text browser
    void applyChanges();                // applies changes to baudrate and serial port
    void populateSerialPortList();      // populates port list

private:
    Ui::MainWindow *ui;
    QSerialPort *serial;    // Serial port object
};
#endif // MAINWINDOW_H
