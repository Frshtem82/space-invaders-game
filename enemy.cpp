#include "enemy.h"
#include "game.h"
#include "bullet.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>

extern Game * game ;

Enemy::Enemy() : QObject() , QGraphicsPixmapItem()
{
    int random_number = rand() % 900 ;
    setPos(random_number , 0);

    QPixmap oPixmap1(":/enemyy2.png");
    setPixmap(oPixmap1.scaled(QSize(100 , 100) , Qt::KeepAspectRatio));

    setTransformOriginPoint(50,50);
    setRotation(180);

    QTimer * timer = new QTimer() ;
    connect(timer,SIGNAL(timeout()) , this , SLOT(move()));

    timer->start(70);
}

void Enemy::move()
{
    setPos(x(),y()+5) ;
    QList<QGraphicsItem *> colliding_items1 = collidingItems();
    for (int i=0 , n = colliding_items1.size() ; i < n ; i++) {
        if (typeid(*(colliding_items1[i])) == typeid(Player))
            game->close();
    }
    if (pos().y() > 600) {
    game->health->decrease();
    scene()->removeItem(this);
    delete this ;
    }
}
