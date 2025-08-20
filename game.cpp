#include "game.h"
#include "enemy.h"
#include "score.h"

#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
//#include <QMediaPlayer>
#include <QImage>
#include <QBrush>

Game::Game(QWidget *parent)
{

    QGraphicsScene * scene = new QGraphicsScene() ;
    scene->setSceneRect(0,0,1000,700);
    setBackgroundBrush(QBrush(QImage(":/s.jpg")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1000,700);

    Player * player = new Player();
    player->setPos(500,600);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player) ;

    score = new Score() ;
    scene->addItem((score));

    health = new Health ;
    health->setPos(health->x()+200,health->y());
    scene->addItem(health) ;

    QTimer * timer = new QTimer() ;
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));

    timer->start(2000);

    //    QMediaPlayer * music = new QMediaPlayer();
    //    music->setMedia(QUrl("qrc:/sounds/14.happy-3538.mp3"));
    //    music->play() ;
    show();
}
