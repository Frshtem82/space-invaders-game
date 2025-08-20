#ifndef BULLETOFENEMY_H
#define BULLETOFENEMY_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Bullet2 : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet2(QGraphicsItem  * parent=0);
public slots:
    void move();
};

#endif // BULLETOFENEMY_H
