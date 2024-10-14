#include "Graph3DWidget.h"

void Graph3DWidget::updateBuffer(const std::vector<QVector3D> &newTrajectory) {
    trajectory = newTrajectory;

    vbo.bind();
    vbo.allocate(trajectory.data(), trajectory.size() * sizeof(QVector3D));
    vbo.release();

    update();  // Перерисовать виджет после обновления данных
}

void Graph3DWidget::redraw() {
    update();
}

void Graph3DWidget::centerCamera() {
    // Установить камеру в центр графика, если требуется
    QVector3D center(0.0f, 0.0f, 0.0f);  // Например, центр графика можно рассчитать как среднее значение траектории
    cameraOffset = -center;
    update();
}

void Graph3DWidget::initializeGL() {
    initializeOpenGLFunctions();
    glEnable(GL_DEPTH_TEST);

    // Установка цвета фона
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    // Подготовка шейдеров и буферов
    setupShaders();
    setupBuffers();
}

void Graph3DWidget::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);

    // Настройка матрицы проекции
    projectionMatrix.setToIdentity();
    projectionMatrix.perspective(45.0f, float(w) / float(h), 0.1f, 10000.0f);
}

void Graph3DWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Устанавливаем матрицу модели-вида
    QMatrix4x4 modelViewMatrix;
    modelViewMatrix.translate(cameraOffset); // Учёт смещения камеры
    modelViewMatrix.translate(0.0f, 0.0f, -20.0f * zoom);
    modelViewMatrix.rotate(xRot / 16.0f, 1.0f, 0.0f, 0.0f);
    modelViewMatrix.rotate(yRot / 16.0f, 0.0f, 1.0f, 0.0f);
    modelViewMatrix.rotate(zRot / 16.0f, 0.0f, 0.0f, 1.0f);

    // Применяем шейдерную программу для осей
    axisShaderProgram.bind();
    axisShaderProgram.setUniformValue("mvp_matrix", projectionMatrix * modelViewMatrix);

    axisVAO.bind();
    glDrawArrays(GL_LINES, 0, axisLines.size());
    axisVAO.release();

    axisShaderProgram.release();

    // Применяем шейдерную программу для графика
    shaderProgram.bind();
    shaderProgram.setUniformValue("mvp_matrix", projectionMatrix * modelViewMatrix);

    vao.bind();
    glDrawArrays(GL_LINE_STRIP, 0, trajectory.size());
    vao.release();

    shaderProgram.release();
}

void Graph3DWidget::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::MiddleButton) {
        isPanning = true;  // Начало панорамирования
    }
    lastMousePosition = event->pos();
}

void Graph3DWidget::mouseMoveEvent(QMouseEvent *event) {
    int dx = event->x() - lastMousePosition.x();
    int dy = event->y() - lastMousePosition.y();

    if (event->buttons() & Qt::LeftButton) {
        setXRotation(xRot + 8 * dy);
        setYRotation(yRot + 8 * dx);
    } else if (event->buttons() & Qt::RightButton) {
        setZRotation(zRot + 8 * dx);
    } else if (isPanning) {
        // Панорамирование камеры (перемещение по осям X и Y)
        float panSpeed = 0.05f;
        cameraOffset.setX(cameraOffset.x() + panSpeed * dx);
        cameraOffset.setY(cameraOffset.y() - panSpeed * dy);  // Инвертируем Y для логичности
    }

    lastMousePosition = event->pos();
    update();  // Обновляем картину после перемещения
}

void Graph3DWidget::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::MiddleButton) {
        isPanning = false;  // Завершение панорамирования
    }
}

void Graph3DWidget::wheelEvent(QWheelEvent *event) {
    if (event->angleDelta().y() > 0)
        zoom *= 1.1f;
    else
        zoom /= 1.1f;

    update();
}

void Graph3DWidget::setupShaders() {
    // Шейдер для отрисовки графика
    const char* vertexShaderSource = R"(
            #version 330 core
            layout(location = 0) in vec3 vertexPosition;
            uniform mat4 mvp_matrix;
            void main() {
                gl_Position = mvp_matrix * vec4(vertexPosition, 1.0);
            }
        )";

    const char* fragmentShaderSource = R"(
            #version 330 core
            out vec4 fragColor;
            void main() {
                fragColor = vec4(1.0, 0.0, 0.0, 1.0);  // Красный цвет для траектории
            }
        )";

    shaderProgram.addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
    shaderProgram.addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
    shaderProgram.link();

    // Шейдер для отрисовки осей координат
    const char* axisVertexShaderSource = R"(
            #version 330 core
            layout(location = 0) in vec3 vertexPosition;
            uniform mat4 mvp_matrix;
            void main() {
                gl_Position = mvp_matrix * vec4(vertexPosition, 1.0);
            }
        )";

    const char* axisFragmentShaderSource = R"(
            #version 330 core
            out vec4 fragColor;
            void main() {
                fragColor = vec4(0.0, 1.0, 0.0, 1.0);  // Зеленый цвет для осей
            }
        )";

    axisShaderProgram.addShaderFromSourceCode(QOpenGLShader::Vertex, axisVertexShaderSource);
    axisShaderProgram.addShaderFromSourceCode(QOpenGLShader::Fragment, axisFragmentShaderSource);
    axisShaderProgram.link();
}

void Graph3DWidget::setupBuffers() {
    // Генерация начальной траектории
    trajectory = generateTrajectoryData();

    // Создание и заполнение VBO для траектории
    vbo.create();
    vbo.bind();
    vbo.allocate(trajectory.data(), trajectory.size() * sizeof(QVector3D));

    // Создание VAO для траектории
    vao.create();
    vao.bind();

    // Настройка атрибута вершин для траектории
    shaderProgram.bind();
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    vao.release();
    vbo.release();

    // Создание и заполнение VBO для осей
    axisLines = generateAxisLines();

    axisVBO.create();
    axisVBO.bind();
    axisVBO.allocate(axisLines.data(), axisLines.size() * sizeof(QVector3D));

    // Создание VAO для осей
    axisVAO.create();
    axisVAO.bind();

    // Настройка атрибута вершин для осей
    axisShaderProgram.bind();
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    axisVAO.release();
    axisVBO.release();
}

std::vector<QVector3D> Graph3DWidget::generateTrajectoryData() {
    // Пример данных для траектории
    std::vector<QVector3D> trajectory;
    float t = -200.0f;
    for (int i = -1000; i < 1000; ++i) {
        float x = std::sin(t);
        float y = std::cos(t);
        float z = t / 10;
        trajectory.emplace_back(x, y, z);
        t += 0.2f;
    }
    return trajectory;
}

std::vector<QVector3D> Graph3DWidget::generateAxisLines() {
    std::vector<QVector3D> lines;
    float axisLength = 1000.0f;

    // Ось X
    lines.emplace_back(-axisLength, 0.0f, 0.0f);
    lines.emplace_back(axisLength, 0.0f, 0.0f);

    // Ось Y
    lines.emplace_back(0.0f, -axisLength, 0.0f);
    lines.emplace_back(0.0f, axisLength, 0.0f);

    // Ось Z
    lines.emplace_back(0.0f, 0.0f, -axisLength);
    lines.emplace_back(0.0f, 0.0f, axisLength);

    return lines;
}

void Graph3DWidget::setXRotation(int angle) {
    xRot = normalizeAngle(angle);
    update();
}

void Graph3DWidget::setYRotation(int angle) {
    yRot = normalizeAngle(angle);
    update();
}

void Graph3DWidget::setZRotation(int angle) {
    zRot = normalizeAngle(angle);
    update();
}

int Graph3DWidget::normalizeAngle(int angle) {
    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360 * 16)
        angle -= 360 * 16;
    return angle;
}
