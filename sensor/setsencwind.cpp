#include "setsencwind.h"
#include "ui_setsencwind.h"
#include "QLayout"
#include "QComboBox"
SetSencWind::SetSencWind(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetSencWind)
{
    ui->setupUi(this);
    ui->numSencor->setMinimum(1);
    ui->numSencor->setMaximum(4);
    ui->numSencor->setValue(1);
}

SetSencWind::~SetSencWind()
{
    delete ui;
}


void SetSencWind::on_numSencor_valueChanged(int arg1) {
    numSencor = arg1;

    // Если количество виджетов меньше, чем arg1, добавляем недостающие виджеты
    if (sensors.length() < numSencor) {
        int delta = numSencor - sensors.length();
        for (int i = 0; i < delta; ++i) {
            sensorWidget *sensor = new sensorWidget();  // Создаём новый виджет датчика
            sensors.append(sensor);                    // Добавляем в список
            sensor->boneNames = allBonesNames;
            sensor->refresh();
            sensors.back()->setSencorNum(sensors.length());
            ui->mainLayout->insertWidget(sensors.length()-1, sensor);         // Добавляем в макет

        }
    }

    // Если количество виджетов больше, чем arg1, удаляем лишние виджеты
    else if (sensors.length() > numSencor) {
        int delta = sensors.length() - numSencor;
        for (int i = 0; i < delta; ++i) {
            sensorWidget *sensor = sensors.takeLast();  // Удаляем последний виджет из списка
            ui->mainLayout->removeWidget(sensor);       // Убираем из макета
            sensor->deleteLater();                      // Очищаем память
        }
    }


}

void SetSencWind::setBonesName(QVector<QString> bonesNames)
{
    allBonesNames = bonesNames;
    ui->numSencor->setMaximum(allBonesNames.length());
    for(int i =0; i < sensors.length(); i++){
        sensors[i]->boneNames = bonesNames;
        sensors[i]->refresh();
    }
}



void SetSencWind::on_saveButton_clicked()
{
    //Сохранение нового списка имен костей
    bonesName.clear();
    for(int i=0; i < sensors.length(); i++){
        bonesName.append(sensors[i]->getName());
    }
    //Сигнал о новых настройках
    emit saveSet(bonesName);
}

