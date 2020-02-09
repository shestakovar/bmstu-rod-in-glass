#ifndef QPAINTWIDGET_H
#define QPAINTWIDGET_H

#include <QWidget>
#include "raytracer.h"

class QPaintEvent;

class QPaintWidget : public QWidget
{
    Q_OBJECT
public:
    QPaintWidget(QWidget * parent = 0);
protected:
    void paintEvent(QPaintEvent *);
};

#endif // QPAINTWIDGET_H
