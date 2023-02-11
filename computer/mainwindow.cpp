#include "mainwindow.h"
//Qt
#include <QGraphicsView>
#include <QApplication>
#include <QMenu>
#include <QMenuBar>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent): QMainWindow{parent}
{
    OptionButton = new statesapp;
    setCentralWidget(OptionButton);
    MenuApp();
    //cnt_device = new cntdevice ;
    //setCentralWidget(cnt_device);

     setWindowState(Qt::WindowMinimized);

}
void MainWindow::triggerMain()
{
    cnt_device = new cntdevice;
    cnt_device->show();
    qDebug() << tr("show");

}
void MainWindow::MenuApp()
{
    QMenu *file = menuBar()-> addMenu(tr("&File"));
///[1] //! Dat muc chon lua file <tao | thoat>
    QAction *newAction = file->addAction(tr("New"));
        newAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_N)); //Ctrl + N new file
    QAction *quitAction = file->addAction(tr("Quit"));
        quitAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Q)); //Ctrl + Q thoat
        connect(quitAction, &QAction::triggered, qApp, &QApplication::quit);
        file->addAction(quitAction);

///[2] //! Chon kieu ket noi trong voi PC
    QMenu *connects = menuBar() -> addMenu(tr("&Connect"));

    QAction *uarts = connects->addAction(tr("UART"));
        //bool check_uarts = false;
        connect(uarts, &QAction::triggered, [&]{  triggerMain();  });
}

