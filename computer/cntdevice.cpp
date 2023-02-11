#include "cntdevice.h"


#include <QFile>
#include <QString>
#include <QByteArrayData>
#include <QDebug>

#include <QBoxLayout>
#include <QComboBox>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

#include <QtWidgets>
#include <QTimer>

//Tao khuon chung chua thay do

cntdevice::cntdevice(QWidget *parent): QWidget(parent)
{
    labelPortCnt = new QLabel(tr("Port"));
    labelPortCnt ->setBuddy(PortCnt);

    labelBaudCnt = new QLabel(tr("Baud"));
    labelBaudCnt ->setBuddy(BaudCnt);

    labelBitDataCnt = new QLabel(tr("BitData"));
    labelBitDataCnt ->setBuddy(BitDataCnt);

    labelBitStopCnt = new QLabel(tr("BitStop"));
    labelBitStopCnt ->setBuddy(BitStopCnt);

    labelBitFlowerCnt = new QLabel(tr("BitFlower"));
    labelBitFlowerCnt ->setBuddy(BitFlowerCnt);

    labelbuttonCnt = new QLabel(tr("Hoan tat"));
    labelbuttonCnt ->setBuddy(buttonCnt);

    labelShowTT = new QLabel("Chua ket noi");

    //Cnt_yn = new QLabel("chua co cong");
    //QTimer *timer = new QTimer(this);
        //connect(timer,& QTimer :: timeout);
        //timer->start(1000);
    //Cnt_yn->setText(serialPort->portName()) ;

    PortCnt = new QComboBox;
    PortCnt ->addItem(tr("COM 3"));
    PortCnt ->addItem(tr("COM 7"));

    BaudCnt= new QComboBox;
    BaudCnt ->addItem(tr("9600"));
    BaudCnt ->addItem(tr("19200"));
    BaudCnt ->addItem(tr("38400"));
    BaudCnt ->addItem(tr("57600"));
    BaudCnt ->addItem(tr("115200"));
    BaudCnt->setEditable(true);
//undefined reference to 'vtable for cnt-device'
    BitDataCnt = new  QComboBox;
    BitDataCnt ->addItem(tr("5"));
    BitDataCnt ->addItem(tr("6"));
    BitDataCnt ->addItem(tr("7"));
    BitDataCnt ->addItem(tr("8"));
    BaudCnt->setEditable(true);

    BitStopCnt = new QComboBox;
    BitStopCnt ->addItem(tr("0"));
    BitStopCnt ->addItem(tr("1"));
    BitStopCnt ->addItem(tr("2"));
    BaudCnt->setEditable(true);

    BitFlowerCnt = new QComboBox;
    BitFlowerCnt ->addItem(tr("No BitFlower"));
    BitFlowerCnt ->addItem(tr("Yes BitFlower"));

    buttonCnt = new QPushButton(tr("&OK"));
    connect(buttonCnt,&QPushButton::clicked,[&] {click_Btn(); });
    //if(buttonCnt->clicked())
    //Cac ket noi voi label

    //Vi tri cho tung block option
    QGridLayout *CntLayout = new QGridLayout;

    CntLayout ->addWidget(labelPortCnt,0,0);
    CntLayout ->addWidget(labelBaudCnt,1,0);
    CntLayout ->addWidget(labelBitDataCnt,2,0);
    CntLayout ->addWidget(labelBitStopCnt,3,0);
    CntLayout ->addWidget(labelBitFlowerCnt,4,0);
    CntLayout ->addWidget(labelbuttonCnt,5,0);
    CntLayout ->addWidget(labelShowTT,6,0);
    //CntLayout ->addWidget(Cnt_yn,7,0);

    CntLayout ->addWidget(PortCnt,0,1);
    CntLayout ->addWidget(BaudCnt,1,1);
    CntLayout ->addWidget(BitDataCnt,2,1);
    CntLayout ->addWidget(BitStopCnt,3,1);
    CntLayout ->addWidget(BitFlowerCnt,4,1);
    CntLayout ->addWidget(buttonCnt,5,1);
    setLayout(CntLayout);

    setWindowTitle(tr("Chon thong so cua UART"));
}
//[2]
void cntdevice::click_Btn()
{
    upload_Uart();
}
//[3]
void cntdevice::upload_Uart()
{
    //QSerialPort serialPort;

    QString re_port = PortCnt ->currentText();
    serialPort->setPortName(re_port);

    QString re_baud = BaudCnt ->currentText();
    bool re_bauds;
    int re_baudss = re_baud.toInt(&re_bauds);
    switch (re_baudss)
    {
    case 9600:
       serialPort->setBaudRate(QSerialPort::Baud9600);
        break;
    case 19200:
        serialPort->setBaudRate(QSerialPort::Baud19200);
        break;
    case 38400:
        serialPort->setBaudRate(QSerialPort::Baud38400);
        break;
    case 57600:
        break;
        serialPort->setBaudRate(QSerialPort::Baud57600);
        break;
    case 115200:
        serialPort->setBaudRate(QSerialPort::Baud115200);
        break;
    }

    QString re_data = BitDataCnt ->currentText();
    bool re_dataso;
    int re_datass = re_data.toInt(&re_dataso);

    switch (re_datass){
    case 5:
            serialPort->setDataBits(QSerialPort::Data5);
            break;
    case 6:
        serialPort->setDataBits(QSerialPort::Data6);
            break;
    case 7:
        serialPort->setDataBits(QSerialPort::Data7);
            break;
    case 8:
        serialPort->setDataBits(QSerialPort::Data8);
            break;
    }

    QString re_stop = BitStopCnt ->currentText();
    bool re_stops;
    int re_stopss = re_stop.toInt(&re_stops);
    switch (re_stopss)
    {
    case 1:
        serialPort->setStopBits(QSerialPort::OneStop);
        break;
    case 2:
        serialPort->setStopBits(QSerialPort::TwoStop);
        break;
    case 3:
       serialPort->setStopBits(QSerialPort::OneAndHalfStop);
        break;
    }

    QString re_Flower = BitFlowerCnt ->currentText();
    bool re_Flowers;
    int re_Flowerss = re_Flower.toInt(&re_Flowers);

    switch(re_Flowerss)
    {
    case 1:
       serialPort->setFlowControl(QSerialPort::NoFlowControl);
        break;
    case 2:
       serialPort->setFlowControl(QSerialPort::HardwareControl);
        break;
    case 3:
        serialPort->setFlowControl(QSerialPort::SoftwareControl);
        break;
    }

    labelShowTT ->setText(re_port +", "+ re_baud +", "+re_data+", "+ re_stop +", "+ re_Flower);

}
//[4]
