QT       += core gui

QT +=openglwidgets

QT += 3dcore 3drender 3dinput 3dlogic 3dextras 3danimation

QT += quick qml quick3d quickwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Graph3D
CONFIG += c++17

INCLUDEPATH += $$PWD/3D
INCLUDEPATH += $$PWD/sensor

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    3D/AnimationWidget.cpp \
    animationthread.cpp \
    main.cpp \
    mainwindow.cpp \
    sensor/sensor.cpp \
    sensor/sensorwidget.cpp \
    sensor/setsencwind.cpp \

HEADERS += \
    3D/AnimationWidget.h \
    animationthread.h \
    mainwindow.h \
    sensor/sensor.h \
    sensor/sensorwidget.h \
    sensor/setsencwind.h \

FORMS += \
    mainwindow.ui \
    sensor/sensorwidget.ui \
    sensor/setsencwind.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    .gitattributes \
    README.md \
    3D/animation.qml \
    data/BaseHuman.fbx \
    data/BaseHuman2.gltf \

RESOURCES += \
    3D/resources.qrc
