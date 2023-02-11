#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//QT
#include <QMainWindow>
#include "statesapp.h"
#include "cntdevice.h"

QT_BEGIN_NAMESPACE
class QGraphicsView;
class statesapp;
class cntdevice;
class QAction;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);

private:
    cntdevice *cnt_device;
    statesapp *OptionButton;
    void MenuApp();
    //void creatAction();
private slots:
    void triggerMain();

};

#endif // MAINWINDOW_H
