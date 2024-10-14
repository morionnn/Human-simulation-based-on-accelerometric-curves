QT       += core gui

QT +=openglwidgets

QT += 3dcore 3drender 3dinput 3dextras
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Graph3D
CONFIG += c++17

INCLUDEPATH += $$PWD/3D

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    3D/Graph3DWidget.cpp \
    3D/anim3dwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    sensor/sensor.cpp \
    sensorwidget.cpp \
    setsencwind.cpp

HEADERS += \
    3D/anim3dwidget.h \
    3D/graph3dwidget.h \
    mainwindow.h \
    sensor/sensor.h \
    sensorwidget.h \
    setsencwind.h

FORMS += \
    mainwindow.ui \
    sensorwidget.ui \
    setsencwind.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    data/data.csv
