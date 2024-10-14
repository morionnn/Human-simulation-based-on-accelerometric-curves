#ifndef ANIM3DWIDGET_H
#define ANIM3DWIDGET_H

#include <QWidget>
#include <Qt3DCore/QEntity>
#include <Qt3DExtras/Qt3DWindow>
#include <Qt3DExtras/QPhongMaterial>
#include <Qt3DRender/QCamera>
#include <Qt3DExtras/QOrbitCameraController>
#include <Qt3DExtras/QPlaneMesh>
#include <Qt3DRender/QMesh>
#include <Qt3DExtras/Qt3DWindow>
#include <QColor>
#include <QRgb>
#include <QUrl>

class Anim3DWidget : public QWidget
{
    Q_OBJECT

public:
    explicit Anim3DWidget(QWidget *parent = nullptr);
    void loadModel(const QString &filePath); // Метод для загрузки модели
    void createPlaneXY(); // Метод для создания плоскости

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    QWidget *container; // Контейнер для Qt3D окна
    Qt3DExtras::Qt3DWindow *view;
    Qt3DCore::QEntity *rootEntity;
    Qt3DRender::QCamera *camera;
    Qt3DExtras::QOrbitCameraController *cameraController;

    Qt3DCore::QEntity *createScene();
    void setupCamera();

};


#endif // ANIM3DWIDGET_H
