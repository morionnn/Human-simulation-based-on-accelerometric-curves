#ifndef SENSORWIDGET_H
#define SENSORWIDGET_H

#include <QWidget>

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

private:
    Ui::sensorWidget *ui;
};

#endif // SENSORWIDGET_H
