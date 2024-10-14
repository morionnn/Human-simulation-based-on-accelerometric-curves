#include "BonesAnimation.h"

// Конструктор, принимающий rootEntity
BonesAnimation::BonesAnimation(Qt3DCore::QEntity *rootEntity)
    : m_rootEntity(rootEntity), m_animationController(nullptr) {}

// Метод для создания анимации
void BonesAnimation::createAnimation(const QVector<QString> &boneNames) {
    // Создаем контроллер анимации
    m_animationController = new Qt3DAnimation::QAnimationController(m_rootEntity);

    for (const QString &boneName : boneNames) {
        // Создаем новую сущность для каждой кости
        Qt3DCore::QEntity *boneEntity = new Qt3DCore::QEntity(m_rootEntity);
        boneEntity->setObjectName(boneName);

        // Присоединяем компонент трансформации для управления позицией
        Qt3DCore::QTransform *transform = new Qt3DCore::QTransform();
        boneEntity->addComponent(transform);

        // Сохраняем кость в мапе
        m_boneMap.insert(boneName, boneEntity);
    }

    m_bonesPos.resize(boneNames.size(), QVector3D(0.0f, 0.0f, 0.0f));
}

// Метод для обновления позиции костей на основе bonesPos
void BonesAnimation::updateBonesPositions() {
    int index = 0;
    for (auto it = m_boneMap.begin(); it != m_boneMap.end(); ++it) {
        QString boneName = it.key();
        Qt3DCore::QEntity *boneEntity = it.value();

        // Обновляем позицию трансформации кости
        Qt3DCore::QTransform *transform = boneEntity->findChild<Qt3DCore::QTransform*>();
        if (transform) {
            transform->setTranslation(m_bonesPos[index]);
        }
        ++index;
    }
}

// Метод для установки позиции конкретной кости
void BonesAnimation::setBonePosition(const QString &boneName, const QVector3D &position) {
    if (m_boneMap.contains(boneName)) {
        int index = m_boneMap.keys().indexOf(boneName);
        if (index >= 0 && index < m_bonesPos.size()) {
            m_bonesPos[index] = position;
        }
    }
}
