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

#include <Qt3DCore/QEntity>
#include <Qt3DCore/QNode>
#include <Qt3DCore/QJoint>
#include <Qt3DCore/QSkeletonLoader>
#include <Qt3DCore/QSkeleton>
#include <Qt3DCore/QTransform>
#include <QString>
#include <QUrl>
#include <QComboBox>

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
    int bonesNum;
    QVector<QString> boneNames; // Вектор для хранения имен костей
    QString getName();

private:
    Ui::sensorWidget *ui;
    void collectBoneNames(const Qt3DCore::QJoint* joint);
};

#endif // SENSORWIDGET_H
