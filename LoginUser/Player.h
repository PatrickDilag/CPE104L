#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>

class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);
    int smallerScore;
    void keyPressEvent(QKeyEvent * event);
    void saveScore();
    void loadScore();
public slots:
    void spawn();
private:
    QMediaPlayer * bulletsound;
};

#endif // PLAYER_H
