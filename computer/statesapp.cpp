#include "statesapp.h"
#include <QtWidgets>

statesapp::statesapp(QWidget *parent): QWidget(parent)
{
    FileSample = new QComboBox;
    FileSample ->addItem(tr("aaa1.txt"));
    FileSample ->addItem(tr("aaa2.txt"));
    FileSample ->addItem(tr("aaa3.txt"));
    //FileSample ->setEditable(true);
    //FileSample ->setCurrentIndex(1);

    StateWord = new QProgressBar;

    RunSample = new QPushButton(tr("&Run"));

    LoadFile = new QPushButton(tr("&Load"));

    CheckSample = new QPushButton(tr("&Check"));

    QGridLayout *OptionMenu = new QGridLayout;


    OptionMenu -> addWidget(FileSample,0,0);
    OptionMenu -> addWidget(RunSample,1,0);
    OptionMenu -> addWidget(StateWord,1,1);
    OptionMenu -> addWidget(LoadFile,2,0);
    OptionMenu -> addWidget(CheckSample,0,1);
    setLayout(OptionMenu);
}
