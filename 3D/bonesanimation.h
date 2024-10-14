#ifndef BONESANIMATION_H
#define BONESANIMATION_H

#include <Qt3DCore/QEntity>
#include <Qt3DAnimation/QAnimationClip>
#include <Qt3DAnimation/QAnimationController>
#include <QVector>
#include <QVector3D>
#include <QString>
#include <QMap>

class BonesAnimation {
public:
    // Конструктор, принимающий rootEntity
    BonesAnimation(Qt3DCore::QEntity *rootEntity);

    // Метод для создания анимации
    void createAnimation(const QVector<QString> &boneNames);

    // Метод для обновления позиции костей на основе bonesPos
    void updateBonesPositions();

    // Метод для установки позиции кости
    void setBonePosition(const QString &boneName, const QVector3D &position);

private:
    Qt3DCore::QEntity *m_rootEntity;         // Ссылка на rootEntity сцены
    QVector<QVector3D> m_bonesPos;            // Вектор с позициями костей
    QMap<QString, Qt3DCore::QEntity*> m_boneMap;  // Мапа для хранения костей по их именам
    Qt3DAnimation::QAnimationController *m_animationController; // Контроллер анимации
};

#endif // BONESANIMATION_H
