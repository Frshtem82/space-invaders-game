#include"bullet.h"
#include "enemy.h"
#include "game.h"
#include "enemy2.h"

#include <QTimer>
#include <QPixmap>
#include <QGraphicsScene>
#include <QList>

extern Game * game ;

Bullet::Bullet(QGraphicsItem *parent) : QObject() , QGraphicsPixmapItem(parent)
{
    QPixmap oPixmap(":/bullettt.png");
    setPixmap(oPixmap.scaled(QSize(40 , 40) , Qt::KeepAspectRatio));

    QTimer * timer = new QTimer() ;
    connect(timer,SIGNAL(timeout()) , this , SLOT(move())) ;

    timer->start(10);
}

void Bullet::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i=0 , n = colliding_items.size() ; i < n ; i++) {
        if ((typeid(*(colliding_items[i])) == typeid(Enemy)) || (typeid(*(colliding_items[i])) == typeid(Enemy2))){

            game->score->increase();

            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this ;
            return ;
        }
    }

    setPos(x(),y()-10) ;
    if (pos().y() < 0) {
        scene()->removeItem(this);
        delete this ;
    }
}
