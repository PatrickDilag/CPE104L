#include "Health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent): QGraphicsTextItem (parent){
    // int score to 0
    health = 3;

    // draw the text
    setPlainText(QString("Health: " )+ QString::number(health)); // Health: 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Health::decrease(){
health--;
setPlainText("Health: " + QString::number(health)); // health: 1

if(health == 0)
    emit dead();
}

int Health::getHealth(){
    return health;
}
