#include "health.h"
#include "game.h"

#include <QString>
#include <QFont>
#include <QGraphicsView>

extern Game * game;

Health::Health(QGraphicsItem *parent) : QGraphicsTextItem(parent){
    health = 3 ;
    setPlainText (QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::red) ;
    setFont(QFont("times" ,16));
}

void Health::decrease()
{
    health--;
    if(gameOver())
        game->close();
    else
        setPlainText (QString("Health: ") + QString::number(health));
}

int Health::getHealth()
{
    return health ;
}

bool Health::gameOver()
{
    return health < 1;
}
