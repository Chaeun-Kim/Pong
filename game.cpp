#include "game.h"
#include "myrect.h"
#include "ball.h"
#include "score.h"
#include "button.h"
#include <QWidget>
#include <QTimer>
#include <QApplication>
#include <QGraphicsTextItem>

extern Pong * pong;

Pong::Pong(QWidget *parent)
{
    // create a scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,300,300);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(300,300);

}

void Pong::mainmenu()
{
    QGraphicsTextItem *title = new QGraphicsTextItem(QString("PONG GAME"));
    QFont titleFont("comic sans", 30);
    title->setFont(titleFont);
    int xpos = this->width()/2 - title->boundingRect().width()/2;
    int ypos = 30;
    title->setPos(xpos,ypos);
    scene->addItem(title);

    QGraphicsTextItem *exp = new QGraphicsTextItem(QString("Press <- to move left and -> to move right.\n\n           First 5 points win the game!\n\n\t       Go get it!"));
    QFont expFont("comic sans", 14);
    exp->setFont(expFont);
    xpos = this->width()/2 - exp->boundingRect().width()/2;
    ypos = 80;
    exp->setPos(xpos,ypos);
    scene->addItem(exp);

    Button* play = new Button(QString("PLAY"));
    int pxpos = this->width()/2 - play->boundingRect().width()/2;
    int pypos = 180;
    play->setPos(pxpos,pypos);
    connect(play,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(play);

    Button* quit = new Button(QString("QUIT"));
    int qxpos = this->width()/2 - quit->boundingRect().width()/2;
    int qypos = 220;
    quit->setPos(qxpos,qypos);
    connect(quit,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quit);


}

void Pong::gameover()
{
    QString displaymsg;
    if(this->score->getScore() > this->PCscore->getScore()){
        displaymsg = "YOU WON!!";
    }
    else if(this->PCscore->getScore() > this->score->getScore()){
        displaymsg = "YOU LOST";
    }
    displayGameover(displaymsg);

}

void Pong::displayGameover(QString msg)
{
    for (size_t i = 0, n = scene->items().size(); i < n; i++){
            scene->items()[i]->setEnabled(false);
    }

    drawPanel(0,0,300,300,Qt::black,1);
    drawPanel(75,90,150,150,Qt::lightGray,0.75);

    Button* restart = new Button(QString("RESTART"));
    restart->setPos(100,140);
    scene->addItem(restart);
    connect(restart,SIGNAL(clicked()),this,SLOT(restartPong()));

    Button* quit = new Button(QString("QUIT"));
    quit->setPos(100,180);
    scene->addItem(quit);
    connect(quit,SIGNAL(clicked()),this,SLOT(close()));

    QGraphicsTextItem* MSG = new QGraphicsTextItem(msg);
    MSG->setPos(100,100);
    scene->addItem(MSG);
}
void Pong::drawPanel(int x, int y, int width, int height, QColor color, double opacity){
    // draws a panel at the specified location with the specified properties
    QGraphicsRectItem* panel = new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    scene->addItem(panel);
}
void Pong::start()
{
    scene->clear();
    // create an item to add to the scene
    p1 = new MyRect();
    p2 = new MyRect();
    p1->setPos(90, 0);
    p2->setPos(90, 300 - p2->rect().height());

    //add a ball
    ball = new Ball(p1);
    ball->setPos(150,150);

    //add score
    score = new Score();
    PCscore = new Score();
    score->setPos(150,250);
    PCscore->setPos(150,30);
    scene->addItem(score);
    scene->addItem(PCscore);

    // add the item to the scene
    scene->addItem(p1);
    scene->addItem(p2);
    scene->addItem(ball);
    //scene->setBackgroundBrush(Qt::black);
    // make rect focusable
    p2->setFlag(QGraphicsItem::ItemIsFocusable);
    p2->setFocus();


    show();

}

void Pong::restartPong()
{
    scene->clear();
    start();
}
