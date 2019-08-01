#include "Score.h"
#include <QFont>
#include <iostream>
#include <fstream>
#include <string>
Score::Score(QGraphicsItem *parent): QGraphicsTextItem (parent){
    // int score to 0
    score = 0;

    // draw the text
    setPlainText("Score: " + QString::number(score)); // score: 0
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Score::increase(){
score++;
setPlainText("Score:  " + QString::number(score)); // score: 1

}

int Score::getScore(){
    return score;
}

void Score::saveScore()
{
    if (score > 99)
    {
        score = 99;
    }
    std::ofstream saver;
    saver.open("scores.txt",std::ios_base::app);
    saver<<score<<" "<<score<<std::endl;
    saver.close();
}


