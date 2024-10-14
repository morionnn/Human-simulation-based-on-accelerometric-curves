#include "sensorwidget.h"
#include "ui_sensorwidget.h"

sensorWidget::sensorWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sensorWidget)
{
    ui->setupUi(this);
}

sensorWidget::~sensorWidget()
{
    delete ui;
}

void sensorWidget::setSencorNum(int num)
{
    ui->labelNum->setText("Датчик "+ QString::number(num));
}
