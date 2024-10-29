#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "QtQuickWidgets/QQuickWidget"
#include "AnimationWidget.h"
#include <QMainWindow>
#include "qtimer.h"
#include "QFile"
#include "setsencwind.h"
#include <Qt3DCore/QEntity>
#include <Qt3DAnimation/QAnimationClip>
#include <Qt3DAnimation/QAnimationController>


#define TIMESPEED 10
#define TIMESTEP 10

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    QTimer *timerForData;
    QFile *dataFile;
    //BonesAnimation* bonesBody;

    bool isStart = false;
    std::vector<QVector3D> newTrajectory;
    QVector3D lastPos;
    SetSencWind* settingSencor;

private slots:
    void getAxData();
    void on_downloadButton_clicked();
    void on_setSencbutton_clicked();
    void on_pushButton_clicked();
    void saveSensorSetting(QVector<QString> listNames);
};
#endif // MAINWINDOW_H
