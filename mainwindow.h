#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QTimer>

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
    void clearStatusBrowser();          // Clearing status browser
    void applyChanges();                // applies changes to baudrate and serial port
    void populateSerialPortList();      // populates port list
    void updateSerialPortList();        // Updates port list periodically
    void selectFile();                  // selects file to upload
    void uploadFile();                  // uploads selected file

private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
    QTimer *portUpdateTimer;
    QString selectedFilePath;
};
#endif // MAINWINDOW_H
