#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "bullet.h"
#include "enemy.h"
#include "game.h"
#include <QList>
#include <QTimer>
#include <stdlib.h>
#include <fstream>
#include <queue>
#include <QDebug>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <regex>
#include "score.h"


extern Game * game;

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/bullet.mp3"));
    setPixmap(QPixmap(":/images/player.png"));
}

void Player::keyPressEvent(QKeyEvent *event){
    // move the player left and right
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800)
        setPos(x()+10,y());
    }
    // shoot with the spacebar
    else if (event->key() == Qt::Key_Space){
        // create a bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+55,y());
        scene()->addItem(bullet);

        // play bulletsound
        if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }

    }
}

void Player::saveScore()
{
    if (smallerScore > 99)
    {
        smallerScore = 99;
    }
    std::ofstream saver;
    saver.open("scores.txt",std::ios_base::app);
    saver.close();
}

void Player::loadScore()
{
    std::string name;
    std::ifstream loader;
    loader.open("scores.txt");
    std::stack<std::string> names;
    while (!loader.eof())
    {
        std::getline(loader,name);
        names.push(name);
        QString str = QString::fromUtf8(names.top().c_str());
        qDebug()<<str;
        qDebug()<<names.size();
    }
    loader.close();
    std::vector<std::string> namees;
    unsigned bse = 0;
    int flag = 0;
    unsigned long long size = names.size();
    while (bse!=size)
    {
        if (flag == 0)
        {
          names.pop();
          flag = 1;
        }
        else if (flag == 1)
        {
          namees.push_back(names.top());
          names.pop();
        }
        ++bse;
    }
    std::sort(namees.begin(),namees.end());
    std::ofstream sortedSaver;
    sortedSaver.open("sortedSaver.txt");
    for (unsigned i=0; i<namees.size();++i)
    {
    sortedSaver<<"Score: "<<namees[i]<<std::endl;
    }
}

void Player::spawn(){
    // create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}


