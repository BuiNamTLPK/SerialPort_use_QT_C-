QT += widgets
QT += serialport
qtHaveModule(opengl): QT += opengl

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        cntdevice.cpp \
        main.cpp \
        mainwindow.cpp \
        statesapp.cpp

HEADERS += \
    cntdevice.h \
    mainwindow.h \
    statesapp.h

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
target.path = D:\PHAN_CUNG\file_Qt\HocQt\Main_app3\system3

INSTALLS += target

simulator: warning(This example might not fully work on Simulator platform)
