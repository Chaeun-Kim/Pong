#include "button.h"
#include <QGraphicsTextItem>
#include <QBrush>

Button::Button(QString txt, QGraphicsItem *parent) : QGraphicsRectItem(parent)
{
    setRect(0,0,100,30);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);

    msg = new QGraphicsTextItem(txt,this);
    int xpos = rect().width()/2 - msg->boundingRect().width()/2;
    int ypos = rect().height()/2 - msg->boundingRect().height()/2;
    msg->setPos(xpos,ypos);

    setAcceptHoverEvents(true);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::cyan);
    setBrush(brush);
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);
}
