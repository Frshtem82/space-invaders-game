#ifndef HEALTH_H
#define HEALTH_H

#include <QWidget>
#include <QGraphicsTextItem>

class Health : public QGraphicsTextItem
{
public:
    Health(QGraphicsItem * parent=0);
    void decrease() ;
    int getHealth() ;
private :
    int health;
    bool gameOver() ;
};

#endif // HEALTH_H
