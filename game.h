#ifndef GAME_H
#define GAME_H

#include "mainwindow.h"
#include "player.h"
#include "score.h"
#include "health.h"

#include <QGraphicsScene>
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsTextItem>

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;
    Player * player;
    Score * score ;
    Health * health;
};

#endif // GAME_H
