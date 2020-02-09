#include <cmath>
#include "qpaintwidget.h"

#include <QPainter>
#include <string>

//pofloat_t left_corner_circle = {100, 100};

QPaintWidget::QPaintWidget(QWidget * parent) : QWidget(parent)
{
}

void QPaintWidget::paintEvent(QPaintEvent *) {
    QPainter p(this); // Создаём новый объект рисовальщика
    p.setPen(QPen(Qt::red,1,Qt::SolidLine)); // Настройки рисования

    const int canvas_width = 640;
    const int canvas_height = 640;

    auto scene = myrender(canvas_width, canvas_height);

    for (auto i = 0; i < scene.size(); i++)
        for (auto j = 0; j < scene[0].size(); j++) {
            QColor color = QColor::fromRgb(scene[i][j].r, scene[i][j].g, scene[i][j].b);
            p.setPen(QPen(color, 1, Qt::SolidLine)); // Настройки рисования
            p.drawPoint (i, canvas_height - j);
        }

}
