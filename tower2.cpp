#include "tower2.h"

Tower2::Tower2(QPoint pos, QString pixFileName):QObject(0),pixmap(pixFileName){
    _pos=pos;
    m_attackRange=100;
    m_damage=10;
    m_fireRate=5;
}

void Tower2::draw(QPainter *painter){
    painter->drawPixmap(_pos,pixmap);
    painter->setPen(Qt::white);
    painter->drawEllipse(QPoint(_pos.x()+15,_pos.y()+15), m_attackRange, m_attackRange);
}
