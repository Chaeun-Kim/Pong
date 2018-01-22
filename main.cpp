#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include "myrect.h"
#include "ball.h"
#include "game.h"

Pong * pong;

int main(int argc, char* argv[]){
    QApplication a(argc, argv);
    pong = new Pong();
    pong->show();
    pong->mainmenu();

    return a.exec();
}
