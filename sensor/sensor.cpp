#include "sensor.h"

Sensor::Sensor(QObject *parent)
    : QObject{parent}
{

}

void Sensor::refreshPos(QVector3D axel, QVector3D giro)
{
    QVector3D axMetric = axel * 9.81;
    //TODO

    QVector3D deltaPos = axMetric;

    lastPos = nowPos;
    nowPos = lastPos + deltaPos;
}

void Sensor::setPos(QVector3D coords)
{
    lastPos = coords;
    nowPos = coords;
}
