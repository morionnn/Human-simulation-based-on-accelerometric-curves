#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTimer"
#include <QOpenGLWidget>
#include "QStringList"
#include "QFileDialog"
#include <Qt3DCore/QEntity>
#include <Qt3DCore/QTransform>

bool animIsStart = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    settingSencor = new SetSencWind(this);
    dataFile = new QFile();

    timerForData = new QTimer();
    timerForData->setInterval(TIMESPEED);

    connect(timerForData, &QTimer::timeout , this, &MainWindow::getAxData);
    connect(settingSencor, &SetSencWind::saveSet, this, &MainWindow::saveSensorSetting);
    connect(ui->widget, &AnimationWidget::bonesIsSet, settingSencor, &SetSencWind::setBonesName);
    ui->widget->setBones();

    //----
    ui->widget->repaint();
    //ui->animationWidget->createPlaneXY();
    //ui->animationWidget->loadModel("data\\BaseHuman2.gltf");
    //bonesBody = new BonesAnimation(ui->animationWidget->rootEntity);
    //bonesBody->createAnimation("data\\BaseHuman2.gltf");

}

//Функции обработки значений с датчиков
//------------------------------------------------
QMatrix3x3 rotationMatrix(QVector3D angle) {
    QVector3D radians (qDegreesToRadians(angle.x()), qDegreesToRadians(angle.y()),qDegreesToRadians(angle.z()));  // Преобразование угла из градусов в радианы
    QMatrix3x3 matrix_x;
    matrix_x(0, 0) = 1; matrix_x(0, 1) = 0;           matrix_x(0, 2) = 0;
    matrix_x(1, 0) = 0; matrix_x(1, 1) = std::cos(radians.x()); matrix_x(1, 2) = -std::sin(radians.x());
    matrix_x(2, 0) = 0; matrix_x(2, 1) = std::sin(radians.x()); matrix_x(2, 2) = std::cos(radians.x());

    QMatrix3x3 matrix_y;
    matrix_y(0, 0) = std::cos(radians.y()); matrix_y(0, 1) = 0; matrix_y(0, 2) = std::sin(radians.y());
    matrix_y(1, 0) = 0;                 matrix_y(1, 1) = 1; matrix_y(1, 2) = 0;
    matrix_y(2, 0) = -std::sin(radians.y()); matrix_y(2, 1) = 0; matrix_y(2, 2) = std::cos(radians.y());

    QMatrix3x3 matrix_z;
    matrix_z(0, 0) = std::cos(radians.z()); matrix_z(0, 1) = -std::sin(radians.z()); matrix_z(0, 2) = 0;
    matrix_z(1, 0) = std::sin(radians.z()); matrix_z(1, 1) = std::cos(radians.z());  matrix_z(1, 2) = 0;
    matrix_z(2, 0) = 0;                 matrix_z(2, 1) = 0;                 matrix_z(2, 2) = 1;

    return matrix_x*matrix_y*matrix_z;
}

QMatrix3x3 rotationMatrixX(float angle_x) {
    float radians_x = qDegreesToRadians(angle_x);  // Преобразование угла из градусов в радианы
    QMatrix3x3 matrix_x;
    matrix_x(0, 0) = 1; matrix_x(0, 1) = 0;           matrix_x(0, 2) = 0;
    matrix_x(1, 0) = 0; matrix_x(1, 1) = std::cos(radians_x); matrix_x(1, 2) = -std::sin(radians_x);
    matrix_x(2, 0) = 0; matrix_x(2, 1) = std::sin(radians_x); matrix_x(2, 2) = std::cos(radians_x);
    return matrix_x;
}

QMatrix3x3 rotationMatrixY(float angle_y) {
    float radians_y = qDegreesToRadians(angle_y);  // Преобразование угла из градусов в радианы
    QMatrix3x3 matrix_y;
    matrix_y(0, 0) = std::cos(radians_y); matrix_y(0, 1) = 0; matrix_y(0, 2) = std::sin(radians_y);
    matrix_y(1, 0) = 0;                 matrix_y(1, 1) = 1; matrix_y(1, 2) = 0;
    matrix_y(2, 0) = -std::sin(radians_y); matrix_y(2, 1) = 0; matrix_y(2, 2) = std::cos(radians_y);
    return matrix_y;
}

QMatrix3x3 rotationMatrixZ(float angle) {
    float radians_z = qDegreesToRadians(angle);  // Преобразование угла из градусов в радианы
    QMatrix3x3 matrix_z;
    matrix_z(0, 0) = std::cos(radians_z); matrix_z(0, 1) = -std::sin(radians_z); matrix_z(0, 2) = 0;
    matrix_z(1, 0) = std::sin(radians_z); matrix_z(1, 1) = std::cos(radians_z);  matrix_z(1, 2) = 0;
    matrix_z(2, 0) = 0;                 matrix_z(2, 1) = 0;                 matrix_z(2, 2) = 1;
    return matrix_z;
}

QVector3D multiplyMatrixVector(const QMatrix3x3& mat, const QVector3D& vec) {
    // Каждый компонент результирующего вектора вычисляется как скалярное произведение строки матрицы на вектор
    float x = mat(0, 0) * vec.x() + mat(0, 1) * vec.y() + mat(0, 2) * vec.z();
    float y = mat(1, 0) * vec.x() + mat(1, 1) * vec.y() + mat(1, 2) * vec.z();
    float z = mat(2, 0) * vec.x() + mat(2, 1) * vec.y() + mat(2, 2) * vec.z();

    // Возвращаем новый вектор
    return QVector3D(x, y, z);
}

QVector3D findPos(QVector3D acceleration, QVector3D angular_velocity, QVector3D lastPos){
    QVector3D deltaPos;
    QVector3D angular_grad;
    QVector3D speed;

    //Первое интегрирование
    speed = acceleration * TIMESTEP/1000;

    angular_grad = angular_velocity*TIMESTEP/1000;

    //Второе интегрирование
    deltaPos = speed * TIMESTEP/1000;

    //Поворот
    /*QMatrix3x3 R_x = rotationMatrixX(angular_grad.x());
    QMatrix3x3 R_y = rotationMatrixY(angular_grad.y());
    QMatrix3x3 R_z = rotationMatrixZ(angular_grad.z());
    QMatrix3x3 rotationM = R_x * R_y * R_z;*/


    QMatrix3x3 rotationM = rotationMatrix(angular_grad);

    //deltaPos = multiplyMatrixVector(rotationM, deltaPos);

    //Новая координата
    return lastPos+angular_grad;
}
//----------------------------------------------------

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getAxData()
{

    if(!dataFile->atEnd()){
        QStringList data = QString(dataFile->readLine()).split(";");
        QVector3D acceleration(data[1].toFloat(),data[2].toFloat(),data[3].toFloat());
        QVector3D angular_velocity(data[4].toFloat(), data[5].toFloat(),data[6].toFloat());

        lastPos = findPos(acceleration,angular_velocity, lastPos);
        //if(newTrajectory.size() > 100) newTrajectory.erase(newTrajectory.begin());

        newTrajectory.push_back(lastPos);

    }else{
        dataFile->close();
        QVector3D nulVec(0,0,0);
        lastPos = nulVec;

        newTrajectory.clear();

        dataFile->open(QIODevice::ReadOnly | QIODevice::Text);
        getAxData();
    }

}


void MainWindow::on_downloadButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Выберите файл", "", "Текстовые файлы (*.txt)");
    if(fileName!=""){
        dataFile->setFileName(fileName);
    }

}


void MainWindow::on_setSencbutton_clicked()
{
    if(!settingSencor->isVisible()){
        settingSencor->show();
    }
}


void MainWindow::on_pushButton_clicked()
{
    if(animIsStart){
        ui->pushButton->setText("Пуск");
        timerForData->stop();
    }else{
        ui->pushButton->setText("Стоп");
        timerForData->start();
    }
    animIsStart = !animIsStart;
}


void MainWindow::saveSensorSetting(QVector<QString> listNames)
{
    if (listNames.isEmpty()) {
        qDebug() << "No joint names provided.";
        return;
    }

    QVector3D rotar(45,45,45); //поворот по x,y,z
    QVector3D coord(45,45,45); //новые координаты по x,y,z
    for(auto jointName:listNames){
        //ui->widget->rotarBones(jointName, rotar); // поворот
        ui->widget->rotarBones(jointName, coord); //Перемещение
        qDebug() << "Transforming joint:" << jointName;
    }

}

