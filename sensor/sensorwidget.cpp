#include "sensorwidget.h"
#include "ui_sensorwidget.h"

sensorWidget::sensorWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sensorWidget)
{
    ui->setupUi(this);
    bonesNum = 0;
}

sensorWidget::~sensorWidget()
{
    delete ui;
}

void sensorWidget::setSencorNum(int num)
{
    bonesNum = 0;
    ui->labelNum->setText("Датчик "+ QString::number(num));
    loadBonesFromFile("model\\BaseHuman.gltf");
}

void sensorWidget::loadBonesFromFile(const QString &filePath)
{
    // Открываем файл
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Cannot open file:" << filePath;
        return;
    }

    // Читаем содержимое файла
    QByteArray fileData = file.readAll();
    file.close();

    // Парсим JSON (предполагается, что файл в формате GLTF)
    QJsonDocument jsonDoc = QJsonDocument::fromJson(fileData);
    if (jsonDoc.isNull()) {
        qDebug() << "Failed to parse JSON.";
        return;
    }

    QJsonObject jsonObj = jsonDoc.object();
    if (!jsonObj.contains("nodes")) {
        qDebug() << "No nodes found in the file.";
        return;
    }

    // Получаем массив узлов
    QJsonArray nodesArray = jsonObj["nodes"].toArray();

    // Перебираем узлы и извлекаем имена костей
    for (const QJsonValue &nodeValue : nodesArray) {
        QJsonObject nodeObj = nodeValue.toObject();
        if (nodeObj.contains("name")) {
            QString boneName = nodeObj["name"].toString();
            boneNames.append(boneName); // Добавляем имя кости в вектор
        }
    }

    // Загружаем имена костей в QComboBox
    ui->comboBox->clear(); // Очистка QComboBox перед добавлением новых имен
    for (const QString &boneName : boneNames) {
        bonesNum++;
        ui->comboBox->addItem(QString::number(bonesNum) + ". " + boneName); // Добавляем имя кости в QComboBox
    }

    qDebug() << "Loaded bones from file:" << filePath;
}

QString sensorWidget::getName()
{
    return ui->comboBox->currentText().split(". ")[1];
}
