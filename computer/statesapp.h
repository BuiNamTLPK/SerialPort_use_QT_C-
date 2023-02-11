#ifndef STATESAPP_H
#define STATESAPP_H

#include "qcombobox.h"
#include <QWidget>
#include <QFile>
QT_BEGIN_NAMESPACE
class QPushButton;
class QComboBox;
class QProgressBar;
QT_END_NAMESPACE

class statesapp: public QWidget
{
    Q_OBJECT
public:
    statesapp(QWidget *parent =0);
private:
    QComboBox   *FileSample;
    QProgressBar *StateWord = nullptr;
    QPushButton *RunSample;
    QPushButton *LoadFile;
    QPushButton *CheckSample;
};

#endif // STATEAPP_H
