#ifndef ANIMATIONWIDGET_H
#define ANIMATIONWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QtQuickWidgets/QQuickWidget>
#include<QtQuickWidgets/QtQuickWidgets>
class AnimationWidget : public QWidget {
    Q_OBJECT
public:
    explicit AnimationWidget(QWidget *parent = nullptr);

private:
    QQuickWidget *quickWidget;
    QObject *humanObject;
};

#endif // ANIMATIONWIDGET_H
