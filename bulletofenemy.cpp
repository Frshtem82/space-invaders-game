#include "bulletofenemy.h"
#include "game.h"
#include "enemy2.h"

#include <QTimer>
#include <QPixmap>
#include <QGraphicsScene>
#include <QList>

extern Game * game ;

Bullet2::Bullet2(QGraphicsItem *parent) : QObject() , QGraphicsPixmapItem(parent)
{
    QPixmap oPixmap(":/bullet2.png");
    setPixmap(oPixmap.scaled(QSize(40 , 40) , Qt::KeepAspectRatio));

    QTimer * timer = new QTimer() ;
    connect(timer,SIGNAL(timeout()) , this , SLOT(move())) ;

    timer->start(10);
}

void Bullet2::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i=0 , n = colliding_items.size() ; i < n ; i++) {
        if (typeid(*(colliding_items[i])) == typeid(Player)){
            game->close();
        }
    }

    setPos(x(),y()+10) ;
    if (pos().y() > 700) {
        scene()->removeItem(this);
        delete this ;
    }
}
