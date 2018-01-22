#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "myrect.h"
#include "ball.h"
#include "score.h"


class Pong : public QGraphicsView
{
    Q_OBJECT
public:
    Pong(QWidget * parent = 0);
    void mainmenu();
    QGraphicsScene * scene;
    Ball *ball;
    MyRect *p1;
    MyRect *p2;
    Score *score;
    Score *PCscore;
    void gameover();
    void displayGameover(QString msg);
private:
    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);

public slots:
    void start();
    void restartPong();


};

#endif // GAME_H
