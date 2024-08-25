#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>

// MainWindow::MainWindow(QWidget *parent)
//     : QMainWindow(parent)
//     , ui(new Ui::MainWindow)
//     , serial(new QSerialPort(this))
// {
//     ui->setupUi(this);

//     // Connecting buttons
//     connect(ui->openButton, &QPushButton::clicked, this, &MainWindow::openSerialPort);
//     connect(ui->closeButton, &QPushButton::clicked, this, &MainWindow::closeSerialPort);

//     // Connecting serial ports readyRead signal to readData
//     connect(serial, &QSerialPort::readyRead, this, &MainWindow::readData);
// }

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , serial(new QSerialPort(this))
{
    ui->setupUi(this);

    // Populate baud rate options
    ui->baudRateComboBox->addItem("9600");
    ui->baudRateComboBox->addItem("19200");
    ui->baudRateComboBox->addItem("38400");
    ui->baudRateComboBox->addItem("57600");
    ui->baudRateComboBox->addItem("115200");
    ui->baudRateComboBox->setCurrentIndex(4); // Set default to 115200

    populateSerialPortList();

    // Connecting buttons
    connect(ui->openButton, &QPushButton::clicked, this, &MainWindow::openSerialPort);
    connect(ui->closeButton, &QPushButton::clicked, this, &MainWindow::closeSerialPort);
    connect(ui->clearButton, &QPushButton::clicked, this, &MainWindow::clearTextBrowser);
    connect(ui->applyButton, &QPushButton::clicked, this, &MainWindow::applyChanges);

    // Connecting serial port's readyRead signal to readData
    connect(serial, &QSerialPort::readyRead, this, &MainWindow::readData);
}

void MainWindow::populateSerialPortList()
{
    // Clear any existing items
    ui->serialPortComboBox->clear();

    // Get the list of available serial ports
    const auto serialPortInfos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &serialPortInfo : serialPortInfos) {
        ui->serialPortComboBox->addItem(serialPortInfo.portName());
    }
}

MainWindow::~MainWindow(){
    serial->close();
    delete ui;
}

// void MainWindow::openSerialPort(){
//     if (serial->isOpen()) {
//         QMessageBox::warning(this, "Error", "Serial port is already open.");
//         return;
//     }

//     // Get the selected serial port name
//     QString portName = ui->serialPortComboBox->currentText();
//     serial->setPortName(portName);

//     // Get the baud rate from the combo box
//     int baudRate = ui->baudRateComboBox->currentText().toInt();
//     serial->setBaudRate(baudRate);

//     // Serial port parameters
//     // serial->setPortName("COM3");
//     serial->setDataBits(QSerialPort::Data8);
//     serial->setParity(QSerialPort::NoParity);
//     serial->setStopBits(QSerialPort::OneStop);
//     serial->setFlowControl(QSerialPort::NoFlowControl);

//     if (serial->open(QIODevice::ReadOnly)) {
//         QMessageBox::information(this, "Serial Port", "Opened successfully.");
//     } else {
//         QMessageBox::critical(this, "Error", "Failed to open serial port.");
//     }
// }

void MainWindow::openSerialPort(){
    // Check if the serial port is already open
    if (serial->isOpen()) {
        ui->statusTextBrowser->append("Error: Serial port is already open.");
        QMessageBox::warning(this, "Error", "Serial port is already open.");
        return;
    }

    // Get the selected serial port name
    QString portName = ui->serialPortComboBox->currentText();
    serial->setPortName(portName);

    // Get the baud rate from the combo box
    int baudRate = ui->baudRateComboBox->currentText().toInt();
    serial->setBaudRate(baudRate);

    // Serial port parameters
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    if (serial->open(QIODevice::ReadOnly)) {
        ui->statusTextBrowser->append("Serial Port opened successfully.");
    } else {
        ui->statusTextBrowser->append("Error: Failed to open serial port.");
        QMessageBox::critical(this, "Error", "Failed to open serial port.");
    }
}

void MainWindow::closeSerialPort(){
    if (serial->isOpen()) {
        serial->close();
        ui->statusTextBrowser->append("Serial Port closed successfully.");
        QMessageBox::information(this, "Serial Port", "Closed successfully.");
    } else {
        QMessageBox::warning(this, "Error", "Serial port is not open.");
    }
}

void MainWindow::applyChanges(){
    if (serial->isOpen()) {
        closeSerialPort();
        // serial->close();
    }

    // Get the selected serial port name
    QString portName = ui->serialPortComboBox->currentText();
    serial->setPortName(portName);

    // Get the baud rate from the combo box
    int baudRate = ui->baudRateComboBox->currentText().toInt();
    serial->setBaudRate(baudRate);

    // Serial port parameters
    // serial->setPortName("COM3");
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    if (serial->open(QIODevice::ReadOnly)) {
        ui->statusTextBrowser->append("Serial Port opened successfully.");
    } else {
        ui->statusTextBrowser->append("Error: Failed to open serial port.");
        QMessageBox::critical(this, "Error", "Failed to open serial port.");
    }
}

// void MainWindow::readData(){
//     QByteArray data = serial->readAll();
//     ui->textBrowser->append(QString::fromUtf8(data));  // Display received data
// }

void MainWindow::readData(){
    static QByteArray buffer;  // Buffer to accumulate data
    buffer.append(serial->readAll());

    // Check for complete lines
    int endIndex = buffer.indexOf('\n');  // Assuming lines are terminated with a newline character
    while (endIndex != -1) {
        QString line = QString::fromUtf8(buffer.left(endIndex));
        ui->textBrowser->append(line.trimmed());  // Display the complete line
        buffer.remove(0, endIndex + 1);  // Remove the processed line from the buffer
        endIndex = buffer.indexOf('\n');  // Look for the next complete line
    }
}

void MainWindow::clearTextBrowser()
{
    ui->textBrowser->clear();  // Clear the text browser
}
