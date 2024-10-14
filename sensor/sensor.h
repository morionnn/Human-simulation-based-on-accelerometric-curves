#ifndef SENSOR_H
#define SENSOR_H
#include <QVector3D>
#include <QObject>

class Sensor : public QObject
{
    Q_OBJECT
public:
    explicit Sensor(QObject *parent = nullptr);

public slots:
    void refreshPos(QVector3D axel, QVector3D giro);
    void setPos(QVector3D coords);

signals:
    void dataChange();

private:
    QVector3D lastPos;
    QVector3D nowPos;

};

#endif // SENSOR_H
