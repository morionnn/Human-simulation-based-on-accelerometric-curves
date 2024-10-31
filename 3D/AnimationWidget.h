#ifndef ANIMATIONWIDGET_H
#define ANIMATIONWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QtQuickWidgets/QQuickWidget>
#include<QtQuickWidgets/QtQuickWidgets>
class AnimationWidget : public QWidget {
    Q_OBJECT
public:
    explicit AnimationWidget(QWidget *parent = nullptr);

signals:
    void bonesIsSet(QVector<QString> bonesName);

public slots:
    void moveBones(QString boneName, QVector3D pos); //Преместить кость по номеру датчика (новая координата)
    void rotarBones(QString boneName, QVector3D rot); //Повернуть кость по номеру датчика (новый угол поворота)
    void setBones();
private:
    void addBoneAndChildren(QObject *bone);
    QQuickWidget *quickWidget;
    QObject *humanObject;
    QVector<QObject *> bones; //ССылка на кости, номер элемента соответсвует номеру датчика
};

#endif // ANIMATIONWIDGET_H
