#include "sensorwidget.h"
#include "ui_sensorwidget.h"

sensorWidget::sensorWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sensorWidget),
    bonesNum(0)
{
    ui->setupUi(this);
}

sensorWidget::~sensorWidget()
{
    delete ui;
}

void sensorWidget::setSencorNum(int num)
{
    bonesNum = 0;
    ui->labelNum->setText("Датчик "+ QString::number(num));
    loadBonesFromFile("3d/model/BaseHuman.gltf");
}

void sensorWidget::loadBonesFromFile(const QString &filePath)
{
    // Очищаем вектор имен костей перед загрузкой нового скелета
    boneNames.clear(); // Добавлено: очищаем вектор имен костей

    // Создаем узел
    Qt3DCore::QNode* parentNode = new Qt3DCore::QNode();

    // Создаем загрузчик скелета
    Qt3DCore::QSkeletonLoader* skeletonLoader = new Qt3DCore::QSkeletonLoader(parentNode);
    skeletonLoader->setSource(QUrl::fromLocalFile(filePath));

    // Проверяем статус загрузки
    connect(skeletonLoader, &Qt3DCore::QSkeletonLoader::statusChanged, this, [this, skeletonLoader, filePath](Qt3DCore::QSkeletonLoader::Status status) {
        if (status == Qt3DCore::QSkeletonLoader::Ready) {
            // Получаем корневую кость скелета
            const Qt3DCore::QJoint* rootJoint = skeletonLoader->rootJoint();
            if (rootJoint) {
                // Получаем имена костей, начиная с корневой
                collectBoneNames(rootJoint);

                // Загружаем имена костей в QComboBox
                ui->comboBox->clear(); // Очистка QComboBox перед добавлением новых имен
                bonesNum = 0; // Обнуляем счетчик костей
                for (const QString &boneName : boneNames) {
                    bonesNum++;
                    ui->comboBox->addItem(QString::number(bonesNum) + ". " + boneName); // Добавляем имя кости в QComboBox
                }

                qDebug() << "Loaded bones from file:" << filePath;
                qDebug() << "Total bones loaded:" << bonesNum; // Вывод общего числа костей
            } else {
                qDebug() << "Failed to retrieve root joint from skeleton.";
            }
        } else if (status == Qt3DCore::QSkeletonLoader::Error) {
            qDebug() << "Error loading skeleton from file:" << filePath;
        }
    });
}

void sensorWidget::collectBoneNames(const Qt3DCore::QJoint* joint) {
    if (joint) {
        boneNames.append(joint->name()); // Добавляем имя текущей кости в вектор
        qDebug() << "Bone found:" << joint->name(); // Выводим имя кости

        // Получаем список дочерних костей
        const auto childJoints = joint->childJoints();
        for (const Qt3DCore::QJoint* childJoint : childJoints) {
            collectBoneNames(childJoint); // Рекурсивно добавляем имена дочерних костей
        }
    }
}



QString sensorWidget::getName()
{
    return ui->comboBox->currentText().split(". ")[1];
}
