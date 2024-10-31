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

void AnimationWidget::moveBones(int id, QVector3D pos)
{

}

void AnimationWidget::rotarBones(int id, QVector3D rot)
{

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



