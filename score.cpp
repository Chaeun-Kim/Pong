#include "score.h"
#include "game.h"
#include <QFont>

extern Pong * pong;

Score::Score(QWidget *parent)
{
    score = 0;
    setPlainText(QString::number(score));
    setDefaultTextColor(Qt::lightGray);
    setFont(QFont("comic sans",30));

}

void Score::add(){
    score++;
    if(score >= 5){
        pong->gameover();
    }
    setPlainText(QString::number(score));
}
int Score::getScore(){
    return score;
}
