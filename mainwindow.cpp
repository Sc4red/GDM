#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>
#include <QDebug>
#include "ustawienia.h"

static QSerialPort *serial;
static QObject object;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    SerialConnect();
}

MainWindow::~MainWindow()
{
    delete ui;
    serial->close();
}

void MainWindow::SerialConnect()
{
    serial = new QSerialPort(this);
    serial->setPortName("COM2");
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->open(QIODevice::ReadWrite);
    serial->write("connected");
    connect(serial,SIGNAL(readyRead()),this,SLOT(SerialRecived()));
}

void MainWindow::SerialRecived()
{
    QByteArray ba;
    ba = serial->readAll();
    ui->LabelMoja->setText(ba);
    QDebug(serial)<<ba;
}

void MainWindow::WriteData(const QByteArray &data)
{
    serial->write(data);
}

void MainWindow::on_actionUstawienia_triggered()
{
    ustawienia Ustawienia;
    Ustawienia.show();
    Ustawienia.exec();
}
