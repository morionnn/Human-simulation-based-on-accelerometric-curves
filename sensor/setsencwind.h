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
    void saveSet(QVector<QString> listNames);

public slots:
    void setBonesName(QVector<QString> bonesNames);

private slots:
    void on_numSencor_valueChanged(int arg1);
    void on_saveButton_clicked();

private:
    Ui::SetSencWind *ui;
    int numSencor;
    QVector<sensorWidget* > sensors;
    QVector<QString> bonesName;
    QVector<QString> allBonesNames;
};

#endif // SETSENCWIND_H
