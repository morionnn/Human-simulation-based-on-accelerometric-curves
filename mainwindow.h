#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qtimer.h"
#include "QFile"
#include "3D/Graph3DWidget.h"
#include "3D/anim3dwidget.h"
#include "setsencwind.h"

#define TIMESPEED 12
#define TIMESTEP 12

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

    bool isStart = false;
    std::vector<QVector3D> newTrajectory;
    QVector3D lastPos;
    SetSencWind* settingSencor;

private slots:
    void getAxData();
    void on_downloadButton_clicked();
    void on_setSencbutton_clicked();
};
#endif // MAINWINDOW_H
