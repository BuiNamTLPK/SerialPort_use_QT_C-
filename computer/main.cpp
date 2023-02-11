#include <QtWidgets>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //Q_INIT_RESOURCE(qml);
    QCoreApplication::setApplicationName("Test system");
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);

    MainWindow w;
    w.show();

    return app.exec();
}
