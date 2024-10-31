#ifndef SENSORWIDGET_H
#define SENSORWIDGET_H

#include <QWidget>
#include <QWidget>
#include <QComboBox>
#include <QVector>
#include <QString>
#include <QDebug>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

namespace Ui {
class sensorWidget;
}

class sensorWidget : public QWidget
{
    Q_OBJECT

public:
    explicit sensorWidget(QWidget *parent = nullptr);
    ~sensorWidget();
    void setSencorNum(int num);
    void loadBonesFromFile(const QString &filePath); // Метод для загрузки имен костей из файла
    void refresh();
    int bonesNum;
    QVector<QString> boneNames; // Вектор для хранения имен костей
    QString getName();

private:
    Ui::sensorWidget *ui;

};

#endif // SENSORWIDGET_H
