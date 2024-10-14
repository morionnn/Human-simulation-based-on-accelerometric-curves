#include "anim3dwidget.h"

#include "Anim3DWidget.h"
#include <QVBoxLayout>
#include <Qt3DExtras>
#include <Qt3DCore/QTransform>
#include <Qt3DRender/QMesh>
#include <Qt3DRender/QCamera>

Anim3DWidget::Anim3DWidget(QWidget *parent) : QWidget(parent)
{
    // Создаем окно Qt3D
    view = new Qt3DExtras::Qt3DWindow();

    // Создаем корневую сущность
    rootEntity = new Qt3DCore::QEntity();

    // Настраиваем камеру
    setupCamera();

    // Создаем контейнер для Qt3D окна и добавляем в интерфейс
    container = QWidget::createWindowContainer(view, this);
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(container);
    setLayout(layout);

    // Устанавливаем корневую сущность
    view->setRootEntity(rootEntity);
}

void Anim3DWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    container->resize(event->size());
}

void Anim3DWidget::setupCamera()
{
    camera = view->camera();
    camera->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
    camera->setPosition(QVector3D(0.0f, 2.0f, 10.0f));
    camera->setViewCenter(QVector3D(0.0f, 0.0f, 0.0f));

    // Контроллер камеры для управления мышью
    cameraController = new Qt3DExtras::QOrbitCameraController(rootEntity);
    cameraController->setCamera(camera);
}

void Anim3DWidget::createPlaneXY()
{
    // Создаем плоскость XOY
    Qt3DExtras::QPlaneMesh *planeMesh = new Qt3DExtras::QPlaneMesh();
    planeMesh->setWidth(10);
    planeMesh->setHeight(10);

    // Трансформация для плоскости
    Qt3DCore::QTransform *planeTransform = new Qt3DCore::QTransform();
    planeTransform->setRotation(QQuaternion::fromEulerAngles(0, 0, 0));

    // Материал для плоскости
    Qt3DExtras::QPhongMaterial *planeMaterial = new Qt3DExtras::QPhongMaterial();
    planeMaterial->setDiffuse(QColor("white"));

    // Создаем сущность для плоскости
    Qt3DCore::QEntity *planeEntity = new Qt3DCore::QEntity(rootEntity);
    planeEntity->addComponent(planeMesh);
    planeEntity->addComponent(planeTransform);
    planeEntity->addComponent(planeMaterial);
}

void Anim3DWidget::loadModel(const QString &filePath)
{
    // Создаем объект mesh и загружаем модель
    Qt3DRender::QMesh *modelMesh = new Qt3DRender::QMesh();
    modelMesh->setSource(QUrl::fromLocalFile(filePath));

    // Трансформация для модели
    Qt3DCore::QTransform *modelTransform = new Qt3DCore::QTransform();
    modelTransform->setScale(1.0f);
    modelTransform->setTranslation(QVector3D(0.0f, 0.0f, 0.0f));

    // Материал для модели
    Qt3DExtras::QPhongMaterial *modelMaterial = new Qt3DExtras::QPhongMaterial();
    modelMaterial->setDiffuse(QColor(QRgb(0x928327)));

    // Создаем сущность для модели
    Qt3DCore::QEntity *modelEntity = new Qt3DCore::QEntity(rootEntity);
    modelEntity->addComponent(modelMesh);
    modelEntity->addComponent(modelTransform);
    modelEntity->addComponent(modelMaterial);

    this->repaint();
}
