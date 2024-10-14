#ifndef GRAPH3DWIDGET_H
#define GRAPH3DWIDGET_H

#include <QApplication>
#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QMatrix4x4>
#include <QVector3D>
#include <vector>
#include <cmath>

class Graph3DWidget : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core {
    Q_OBJECT

public:
    Graph3DWidget(QWidget* parent = nullptr)
        : QOpenGLWidget(parent), xRot(0), yRot(0), zRot(0), zoom(1.0f), isPanning(false), cameraOffset(0.0f, 0.0f, 0.0f) {
    }

public slots:
    // Слот для обновления данных в буфере
    void updateBuffer(const std::vector<QVector3D>& newTrajectory);

    // Слот для перерисовки (запуск анимации)
    void redraw();

    // Слот для перемещения камеры на центр графика
    void centerCamera();

protected:
    void initializeGL() override;

    void resizeGL(int w, int h) override;

    void paintGL() override;

    void mousePressEvent(QMouseEvent* event) override;

    void mouseMoveEvent(QMouseEvent* event) override;

    void mouseReleaseEvent(QMouseEvent* event) override;

    void wheelEvent(QWheelEvent* event) override;

private:
    void setupShaders();

    void setupBuffers();

    std::vector<QVector3D> generateTrajectoryData();

    std::vector<QVector3D> generateAxisLines();

    void setXRotation(int angle);

    void setYRotation(int angle);

    void setZRotation(int angle);

    int normalizeAngle(int angle);

    QPoint lastMousePosition;
    int xRot;
    int yRot;
    int zRot;
    float zoom;

    bool isPanning;  // Флаг панорамирования
    QVector3D cameraOffset;  // Вектор смещения камеры

    QMatrix4x4 projectionMatrix;
    QOpenGLShaderProgram shaderProgram;
    QOpenGLShaderProgram axisShaderProgram;
    QOpenGLBuffer vbo{QOpenGLBuffer::VertexBuffer};
    QOpenGLVertexArrayObject vao;
    QOpenGLBuffer axisVBO{QOpenGLBuffer::VertexBuffer};
    QOpenGLVertexArrayObject axisVAO;
    std::vector<QVector3D> trajectory;
    std::vector<QVector3D> axisLines;
};

#endif // GRAPH3DWIDGET_H
