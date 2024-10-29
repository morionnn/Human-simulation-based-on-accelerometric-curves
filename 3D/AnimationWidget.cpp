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

}
