import QtQuick
import QtQuick3D
import QtQuick3D.Helpers
import "model/"

View3D {
    width: 800
    height: 600
    antialiasing: SceneEnvironment.SSAA  // Сглаживание для более качественной отрисовки

    // Установка камеры
    Node {
        id: originNode  // Узел-центр для вращения камеры
        PerspectiveCamera {
            id: cameraNode
            position: Qt.vector3d(0, 150, 300)  // Позиция камеры
            eulerRotation.x: -30
            fieldOfView: 90
        }
    }

    // Контроллер для управления камерой
    OrbitCameraController {
        anchors.fill: parent
        origin: originNode  // Указывает на узел-центр
        camera: cameraNode  // Указывает на камеру

        // Свойства управления
        mouseEnabled: true  // Включает управление мышью
        panEnabled: true  // Включает панорамирование
        xInvert: false  // Инвертировать движение по оси X
        yInvert: false  // Инвертировать движение по оси Y
        xSpeed: 1.0  // Скорость движения по оси X
        ySpeed: 1.0  // Скорость движения по оси Y
    }

    // Свет для освещения сцены с использованием каскадных теней
    DirectionalLight {
        position: Qt.vector3d(200, 300, 400)

        // Настройки каскадных теней
        csmBlendRatio: 0.1   // Степень смешивания теней
        csmNumSplits: 3      // Количество делений для каскадных теней
        csmSplit1: 20.0      // Первая позиция деления
        csmSplit2: 100.0     // Вторая позиция деления
        csmSplit3: 500.0     // Третья позиция деления
    }

    // 3D-модель с загруженным скелетом и анимацией
    // Model {
    //     id: model

    //     //----------EXAMPLE---------------
    //     source:"#Cube"
    //     materials: PrincipledMaterial {
    //             baseColor: "red"
    //             lighting: PrincipledMaterial.NoLighting
    //         }
    //     //--------------------------------

    //     position: Qt.vector3d(0, 0, 0)
    //     scale: Qt.vector3d(1.0, 1.0, 1.0)
    // }

    BaseHuman {
        id: human
        objectName: "human"
        position: Qt.vector3d(0, 0, 0)
        scale: Qt.vector3d(100.0, 100.0, 100.0)
    }
}
