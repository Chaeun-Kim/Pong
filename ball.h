#ifndef BALL_H
#define BALL_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include "myrect.h"



class Ball : public QObject, public QGraphicsRectItem{
    Q_OBJECT
    public :
        Ball(MyRect*);
    public slots:
        void move();
    signals:
        void goal(int player);
    private:
        qreal calculateP1Direction();
        QPointF BallDir;
        QGraphicsItem *P1;
        qreal P1Dir;
};

#endif // BALL_H
