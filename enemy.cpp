#include "enemy.h"

static const int HP_BAR = 20;
const QSize Enemy::_fixedSize(50,40);
Enemy::Enemy(){}

Enemy::Enemy(QPoint spos, QPoint epos, GameWindow *game, QString pixFileName):
    QObject(0),
    _spos(spos),
    _epos(epos),
    pixmap(pixFileName),
    _maxHp(30),
    _currentHp(30),
    _game(game)
{
    _cpos=spos;
    speed=25.0;
}

Enemy::~Enemy(){
    _game=NULL;
}

void Enemy::emove(){
    if(_cpos==_epos)
        _game->life--;
    if(getDistance(_cpos,_game->lvtower_list)<=100){
        getDamage(6);
    }
    if(getDistance(_cpos,_game->tower_list)<=100){
        getDamage(3);
    }
    if(getDistance(_cpos,_game->tower2_list)<=100)
        getLower();
    QVector2D enemy(_epos - _spos);
    enemy.normalize();
    _cpos=_cpos+enemy.toPoint()*speed;
}

void Enemy::drawe(QPainter *painter){
    painter->save();
    QPoint healthBarPoint = _cpos+QPoint(-HP_BAR/2-5,-_fixedSize.height());
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::red);
    QRect healthBarRect(healthBarPoint,QSize(HP_BAR,2));
    painter->drawRect(healthBarRect);
    painter->setBrush(Qt::green);
    QRect healBarLiveRect(healthBarPoint,QSize((double)_currentHp/_maxHp*HP_BAR,2));
    painter->drawRect(healBarLiveRect);
    QPoint toSub(-_fixedSize.width()/2,-_fixedSize.height()/2);
    painter->translate(_cpos);
    painter->drawPixmap(toSub, pixmap);
    painter->restore();
}

void Enemy::getDamage(int damage){
    if(_currentHp>0)
        _currentHp-=damage;
    else
        getRemoved();
}

void Enemy::getLower(){
    speed=15;
    _currentHp-=1;
}

void Enemy::getRemoved(){
    _game->money+=50;
    _game->removeEnemy(this);
}

void Enemy::attack(){
    if(getDistance(_cpos,_game->tower_list)<=75)
        _game->tower_list[0]->getattack();
    if(getDistance(_cpos,_game->tower2_list)<=75)
        _game->tower2_list[0]->getattack();
}

double Enemy::getDistance(QPoint cpos, QList<Tower*>towerlist){
    double distance[4]={1000,1000,1000,1000},dx[4]={1000,1000,1000,1000},dy[4]={1000,1000,1000,1000};
    int i,min=1000;
    for(i=0;i!=towerlist.size();i++){
        dx[i]=cpos.x()-towerlist[i]->getpos().x();
        dy[i]=cpos.y()-towerlist[i]->getpos().y();
        distance[i]=sqrt(dx[i]*dx[i]+dy[i]*dy[i]);
    }
    for(i=0;i<4;i++){
        if(distance[i]<min)
            min=distance[i];
    }
    return min;
}

double Enemy::getDistance(QPoint cpos, QList<Tower2*>tower2list){
    double distance[4]={1000,1000,1000,1000},dx[4]={1000,1000,1000,1000},dy[4]={1000,1000,1000,1000};
    int i=0,min=1000;
    for(i=0;i!=tower2list.size();i++){
        dx[i]=cpos.x()-tower2list[i]->getpos2().x();
        dy[i]=cpos.y()-tower2list[i]->getpos2().y();
        distance[i]=sqrt(dx[i]*dx[i]+dy[i]*dy[i]);
    }
    for(i=0;i<4;i++){
        if(distance[i]<min)
            min=distance[i];
    }
    return min;
}

double Enemy::getDistance(QPoint cpos, QList<LvTower*>lvtowerlist){
    double distance[4]={1000,1000,1000,1000},dx[4]={1000,1000,1000,1000},dy[4]={1000,1000,1000,1000};
    int i=0,min=1000;
    for(i=0;i!=lvtowerlist.size();i++){
        dx[i]=cpos.x()-lvtowerlist[i]->getpos().x();
        dy[i]=cpos.y()-lvtowerlist[i]->getpos().y();
        distance[i]=sqrt(dx[i]*dx[i]+dy[i]*dy[i]);
    }
    for(i=0;i<4;i++){
        if(distance[i]<min)
            min=distance[i];
    }
    return min;
}

void Enemy::change(int addHP, int addSpeed){
    _maxHp=_maxHp+addHP;
    _currentHp=_maxHp;
    speed=speed+addSpeed;
}
