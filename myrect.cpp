#include "myrect.h"
#include <QKeyEvent>
#include <QGraphicsView>
#include <QApplication>
#include <QGraphicsScene>


MyRect::MyRect()
{
    setRect(0,0,80,15);
    setBrush(QBrush(Qt::magenta));

}

void MyRect::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left){
        if(pos().x() > 0)
            setPos(x()-40,y());
    }
    else if(event->key() == Qt::Key_Right){
        if(pos().x()+80 < 300)
            setPos(x()+40,y());
    }
}
