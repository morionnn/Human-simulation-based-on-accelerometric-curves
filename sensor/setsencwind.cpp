#include "setsencwind.h"
#include "ui_setsencwind.h"
#include "QLayout"
#include "QComboBox"
#define Max_Widget 4
SetSencWind::SetSencWind(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetSencWind)
{
    ui->setupUi(this);
    ui->numSencor->setMinimum(1);
    ui->numSencor->setMaximum(Max_Widget);
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

