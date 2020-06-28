#include "tower.h"

Tower::Tower(QPoint pos, QString pixFileName):QObject(0),pixmap(pixFileName){
    _pos=pos;
    m_attackRange=100;
    currentHP=60;
}

void Tower::draw(QPainter *painter){
    painter->drawPixmap(_pos,pixmap);
    painter->setPen(Qt::white);
    painter->drawEllipse(QPoint(_pos.x()+15,_pos.y()+15), m_attackRange, m_attackRange);
}

QPoint Tower::getpos(){
    return _pos;
}

void Tower::getattack(){
    currentHP-=2;
}

int Tower::getHP(){
    return currentHP;
}
