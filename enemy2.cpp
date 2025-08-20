#include "enemy2.h"
#include "game.h"
#include "bulletofenemy.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>

extern Game * game ;

Enemy2::Enemy2() : QObject() , QGraphicsPixmapItem()
{
    int random_number = rand() % 900 ;
    setPos(random_number , 0);

    QPixmap oPixmap2(":/enemyy.png");
    setPixmap(oPixmap2.scaled(QSize(100 , 100) , Qt::KeepAspectRatio));

    setTransformOriginPoint(50,50);
    setRotation(180);

    QTimer * firetimer = new QTimer() ;
    connect(firetimer,SIGNAL(timeout()) , this , SLOT(shoot()));
    firetimer->start(2000);

    QTimer * movetimer = new QTimer() ;
    connect(movetimer,SIGNAL(timeout()) , this , SLOT(move()));
    movetimer->start(200);
}

void Enemy2::move()
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
void Enemy2::shoot()
{
    QTimer * timer = new QTimer() ;
    connect(timer,SIGNAL(timeout()) , this , SLOT(move()));

    timer->start(100);

    Bullet2 * bullet = new Bullet2() ;
    bullet->setPos(x()+35 , y()) ;
    scene()->addItem(bullet);
}
