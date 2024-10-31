#include "AnimationWidget.h"
#include<QtQuickWidgets/QQuickWidget>

AnimationWidget::AnimationWidget(QWidget *parent)
    : QWidget(parent) {
    quickWidget = new QQuickWidget(this);
    quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    quickWidget->setSource(QUrl(QStringLiteral("qrc:/Animation.qml")));

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(quickWidget);
    setLayout(layout);
    quickWidget->repaint();

    //Полечение ссылки на модель
    // Получаем корневой объект QML
    QObject *rootObject = quickWidget->rootObject();
    humanObject = rootObject->findChild<QObject*>("human");
}

void AnimationWidget::moveBones(QString boneName, QVector3D pos)
{
    // Поиск нужной кости по имени
    QObject* targetBone = nullptr;
    for (auto *bone : bones) {
        if (bone->objectName() == boneName) {
            targetBone = bone;
            break;
        }
    }

    // Проверка, что кость найдена
    if (!targetBone) {
        qDebug() << "Кость" << boneName << "не найдена";
        return;
    }

    // Установка нового значения позиции для найденной кости
    targetBone->setProperty("position", pos);

    qDebug() << "Позиция для кости" << boneName << "установлена в" << pos;
}

void AnimationWidget::rotarBones(QString boneName, QVector3D rot)
{
    // Поиск нужной кости по имени
    QObject* rotarBone = nullptr;
    for (auto *bone : bones) {
        if (bone->objectName() == boneName) {
            rotarBone = bone;
            break;
        }
    }

    // Проверка, что кость найдена
    if (!rotarBone) {
        qDebug() << "Кость" << boneName << "не найдена";
        return;
    }

    // Преобразуем углы поворота в кватернион
    QQuaternion newRotation = QQuaternion::fromEulerAngles(rot);

    // Устанавливаем новый поворот для найденной кости
    rotarBone->setProperty("rotation", newRotation);

    qDebug() << "Поворот для кости" << boneName << "установлен в" << rot;
}

// Вспомогательная функция для рекурсивного добавления костей и их дочерних объектов
void AnimationWidget::addBoneAndChildren(QObject *bone)
{
    if (!bone) return;

    // Добавляем текущую кость в вектор
    bones.append(bone);

    // Рекурсивно обходим все дочерние элементы
    for (QObject *child : bone->children()) {
        addBoneAndChildren(child);
    }
}

void AnimationWidget::setBones()
{
    // Проверяем, что humanObject указывает на модель
    if (!humanObject) {
        qWarning() << "Human model object not found!";
        return;
    }

    // Очищаем вектор костей перед обновлением
    bones.clear();

    // Находим главную кость
    QObject *mainBone = humanObject->findChild<QObject *>("skeleton_human_male");
    if (!mainBone) {
        qWarning() << "Main bone not found!";
        return;
    }

    // Рекурсивно обходим все дочерние объекты
    addBoneAndChildren(mainBone);

    // Отправляем сигнал с именами всех костей
    QVector<QString> bonesNames;
    for (auto *bone : bones) {
        bonesNames.append(bone->objectName());
    }
    emit bonesIsSet(bonesNames);

    // Выводим имена всех добавленных костей для проверки
    for (const QString &name : bonesNames) {
        qDebug() << name;
    }
}



