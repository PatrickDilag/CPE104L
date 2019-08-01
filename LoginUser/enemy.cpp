#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include "game.h"
#include "Player.h"

extern Game * game;

Enemy::Enemy(): QObject (), QGraphicsPixmapItem (){
    //set random pos
    int random_number = rand() % 700;
    setPos(random_number,0);

    // drew the rect
    setPixmap(QPixmap(":/images/enemy.png"));
    setTransformOriginPoint(50,50);
    setRotation(180);

    // connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Enemy::move(){
    // move enemy down
    setPos(x(),y()+5);

    //destroy enemy when it goes out of the screen
    if (pos().y() > 600 ){
        //dec the health
        game->health->decrease();

        scene()->removeItem(this);

        delete this;
    }

}

