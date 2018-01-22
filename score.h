#ifndef SCORE_H
#define SCORE_H

#include <QWidget>
#include <QGraphicsTextItem>


class Score : public QGraphicsTextItem
{
    public:
        Score(QWidget *parent = 0);
        void add();
        int getScore();
    private:
        int score;
};

#endif // SCORE_H
