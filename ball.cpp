#include "ball.h"
#include "myrect.h"
#include "game.h"
#include <QTimer>
#include <QGraphicsView>
#include <QApplication>
#include <QGraphicsScene>
#include <QPainter>
#include <qmath.h>
#include <QList>
#include <stdlib.h>

extern Pong * pong;

Ball::Ball(MyRect *p1){
    P1 = p1;
    setRect(0,0,13,13);
    setBrush(QBrush(Qt::black));

    //connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this, SLOT(move()));

    timer->start(13);
}

void Ball::move(){

    QList<QGraphicsItem *> collision = collidingItems();
    // see if the ball collides with anything that has type of "MyRect"
    // and if it does change the direction of the ball
    for(int i = 0; i < collision.size(); i++){
        if(typeid(*(collision[i])) == typeid(MyRect)){
            BallDir.ry() *= -1;
        }
    }

    if(BallDir.rx() == 0 && BallDir.ry() == 0){
        BallDir.rx()=4;
        BallDir.ry()=4;
    }

    qreal p1newx = P1->pos().x() + P1Dir;
    qreal newX = this->pos().x() + BallDir.x();
    qreal newY = this->pos().y() + BallDir.y();

    if ( ( newX < 0 ) || ( newX + this->boundingRect().right() > 300 ) )
    {
        BallDir.rx() *= -1;
    }
    if ( ( newY < 0 ) || ( newY + this->boundingRect().top() > 300 ) )
    {
        if(newY < 0)
            pong->score->add();
        if(newY + this->boundingRect().top() > 300)
            pong->PCscore->add();

        BallDir.ry() *= -1;
    }
    if ( ( p1newx < 0 ) || ( p1newx + P1->boundingRect().right() > 300 ) )
    {
        P1Dir = 0;
    }
    if ( qrand() % 5 == 0 )
    {
        P1Dir = calculateP1Direction();
    }

    this->moveBy(BallDir.x(), BallDir.y());
    P1->moveBy(P1Dir, 0);

}

qreal Ball::calculateP1Direction()
{
    qreal move = 0;

    if (BallDir.x() + this->pos().x() > P1->sceneBoundingRect().right())
        move = qrand() % 10 + 1;
    else if (BallDir.x() + this->pos().x() < P1->sceneBoundingRect().left())
        move = (qrand() % 10 + 1) * -1;

    return move;

}

