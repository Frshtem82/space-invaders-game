#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include "enemy2.h"

#include <QGraphicsScene>
#include <QKeyEvent>

Player::Player(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    QPixmap oPixmap(":/shooter.png");
    setPixmap(oPixmap.scaled(QSize(100 , 100) , Qt::KeepAspectRatio));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left) {
        if (pos().x() > 0)
            setPos(x()-20,y());
    }
    else if(event->key() == Qt::Key_Right) {
        if (pos().x() + 100 < 1000)
            setPos(x()+20,y());
    }
    else if (event->key()== Qt::Key_Space) {
        Bullet * bullet = new Bullet() ;
        bullet->setPos(x()+35 , y()) ;
        scene()->addItem(bullet);

//        if (bulletSound->state() == QMediaPlayer::PlayingState) {
//            bulletSound->setPosition(0);
//        }
//        else if ()
//            bulletSound->play(bulletSound->state() == QMediaPlayer::StoppedState) {
//                bulletSound->play();
//            }

    }
}

void Player::spawn() {
    Enemy * enemy1 = new Enemy();
    scene()->addItem(enemy1);

    Enemy2 * enemy2 = new Enemy2();
    scene()->addItem(enemy2);
}
