#ifndef CNTDEVICE_H
#define CNTDEVICE_H

#include "qcombobox.h"
#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>

QT_BEGIN_NAMESPACE
class QComboBox;
class QPushButton;
class QGroupBox;
class QLabel;
QT_END_NAMESPACE

class cntdevice: public QWidget
{
    Q_OBJECT;
private:
    QLabel *labelPortCnt;
    QLabel *labelBaudCnt;
    QLabel *labelBitDataCnt;
    QLabel *labelBitStopCnt;
    QLabel *labelBitFlowerCnt;
    QLabel *labelbuttonCnt;
    QLabel *labelShowTT;
    //QLabel *Cnt_yn;

    QComboBox *PortCnt;
    QComboBox *BaudCnt;
    QComboBox *BitDataCnt;
    QComboBox *BitStopCnt;
    QComboBox *BitFlowerCnt;
    QPushButton *buttonCnt;

    QSerialPort *serialPort;
public:
    //For UART chuyen doi qua USB
    cntdevice(QWidget *parent = 0 ); //cho ket noi uart

    void click_Btn();
    void upload_Uart();
    //QString composeData(const QString& file);

};

#endif // CNT_DEVICE_H
