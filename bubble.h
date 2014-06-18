#ifndef BUBBLE_H
#define BUBBLE_H

#include <QPainter>

class Bubble
{
public:
    Bubble(const QPointF &position, qreal radius, const QPointF &velocity);

    void drawBubble(QPainter *painter);
    void updateBrush();
    void move(const QRect &bbox);
    QRectF rect();

private:
    QColor randomColor();

    QBrush brush;
    QPointF position;
    QPointF vel;
    qreal radius;
    QColor innerColor;
    QColor outerColor;
};

#endif // BUBBLE_H
