#ifndef SETSENCWIND_H
#define SETSENCWIND_H

#include <QDialog>
#include "QLayout"
#include <sensorwidget.h>

namespace Ui {
class SetSencWind;
}

class SetSencWind : public QDialog
{
    Q_OBJECT

public:
    explicit SetSencWind(QWidget *parent = nullptr);
    ~SetSencWind();

signals:
    void numSencChange();

private slots:
    void on_numSencor_valueChanged(int arg1);

private:
    Ui::SetSencWind *ui;
    int numSencor;
    QVector<sensorWidget* > sensors;
};

#endif // SETSENCWIND_H
