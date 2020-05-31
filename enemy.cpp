#include "enemy.h"

Enemy::Enemy(){}

Enemy::Enemy(QPoint spos, QPoint epos, QString pixFileName):QObject(0),pixmap(pixFileName){
    _spos=spos;
    _epos=epos;
    _cpos=spos;
    speed=1000;
}

void Enemy::emove(){
    QPropertyAnimation * animation = new QPropertyAnimation(this, "_cpos");
    animation->setDuration(2000);
    animation->setStartValue(_spos);
    animation->setEndValue(_epos);
    animation->start();
}

void Enemy::drawe(QPainter *painter){
    painter->drawPixmap(_cpos,pixmap);
}

QPoint Enemy::get_cpos(){
    return this->_cpos;
}

void Enemy::set_cpos(QPoint pos){
    this->_cpos=pos;
}
