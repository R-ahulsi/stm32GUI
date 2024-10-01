#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QFileDialog>
#include <QProcess>

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
    , portUpdateTimer(new QTimer(this))
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

    connect(ui->openButton, &QPushButton::clicked, this, &MainWindow::openSerialPort);
    connect(ui->closeButton, &QPushButton::clicked, this, &MainWindow::closeSerialPort);
    connect(ui->clearLogButton, &QPushButton::clicked, this, &MainWindow::clearTextBrowser);
    connect(ui->applyButton, &QPushButton::clicked, this, &MainWindow::applyChanges);
    connect(ui->clearStatusButton, &QPushButton::clicked, this, &MainWindow::clearStatusBrowser);
    connect(ui->selectFileButton, &QPushButton::clicked, this, &MainWindow::selectFile);
    connect(ui->uploadFileButton, &QPushButton::clicked, this, &MainWindow::uploadFile);
    connect(portUpdateTimer, &QTimer::timeout, this, &MainWindow::updateSerialPortList);
    portUpdateTimer->start(3000); // 3000 ms = 3 seconds
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

void MainWindow::updateSerialPortList()
{
    populateSerialPortList();
}

MainWindow::~MainWindow(){
    serial->close();
    delete ui;
}

void MainWindow::openSerialPort(){
    // Check if the serial port is already open
    if (serial->isOpen()) {
        ui->statusTextBrowser->append("Error: Serial port is already open.");
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
    } else {
        ui->statusTextBrowser->append("Error: Serial port is not open.");
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

void MainWindow::clearTextBrowser(){
    ui->textBrowser->clear();  // Clear the text browser
    ui->statusTextBrowser->append("Text browser cleared");
}

void MainWindow::clearStatusBrowser(){
    ui->statusTextBrowser->clear();  // Clear the status text browser
}

void MainWindow::selectFile() {
    // QString fileName = QFileDialog::getOpenFileName(this, "Select File", "", "Binary Files (*.bin);;All Files (*)");

    QString fileName = QFileDialog::getOpenFileName(
        this,
        "Select File",
        "C:/osProjects",  // Starting directory, correctly specified as a string
        "Binary Files (*.elf);;All Files (*)"
        );

    if (!fileName.isEmpty()) {
        ui->selectedFileLabel->setText(fileName);  // Display the selected file path
    } else {
        ui->selectedFileLabel->setText("No file selected");
    }
}

void MainWindow::uploadFile() {
    QString portName = ui->serialPortComboBox->currentText();
    serial->setPortName(portName);

    if (serial->portName().isEmpty()) {
        ui->statusTextBrowser->append("Error: No serial port selected. Please select a serial port.");
        QMessageBox::warning(this, "Error", "No serial port selected. Please select a serial port.");
        return;
    }

    QString fileName = ui->selectedFileLabel->text();

    if (fileName.isEmpty() || fileName == "No file selected") {
        ui->statusTextBrowser->append("Error: No file selected.");
        return;
    }

    ui->statusTextBrowser->append("Starting upload process...");

    // Assuming STM32_Programmer_CLI is available in PATH
    QProcess *process = new QProcess(this);
    QString command = QString("\"C:/ST/STM32CubeIDE_1.16.0/STM32CubeIDE/plugins/com.st.stm32cube.ide.mcu.externaltools.cubeprogrammer.win32_2.1.400.202404281720/tools/bin/STM32_Programmer_CLI.exe\" -c port=SWD -d %1 -run")
                          .arg(fileName);

    process->start(command);

    // if (!process->waitForStarted()) {
    //     ui->statusTextBrowser->append("Error: Failed to start upload process.");
    //     return;
    // }

    if (!process->waitForStarted()) {
        ui->statusTextBrowser->append("Error: Failed to start upload process. " + process->errorString());
        return;
    }

    if (!process->waitForFinished()) {
        ui->statusTextBrowser->append("Error: Upload process failed.");
        return;
    }

    QString output = process->readAllStandardOutput();
    QString errorOutput = process->readAllStandardError();
    ui->statusTextBrowser->append("Upload process complete.");
    ui->statusTextBrowser->append(output);
    if (!errorOutput.isEmpty()) {
        ui->statusTextBrowser->append("Error Output: " + errorOutput);
    }
    process->deleteLater();
}

// void MainWindow::selectDirectory() {
//     // QString directory = QFileDialog::getExistingDirectory(
//     //     this,
//     //     "Select Directory",
//     //     "C:/osProjects",
//     //     QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks
//     //     );

//     // if (!directory.isEmpty()) {
//     //     ui->directoryLabel->setText(directory);  // Update a QLabel or similar widget with the selected directory
//     // }
// }
