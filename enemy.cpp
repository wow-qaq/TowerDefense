#include "enemy.h"

static const int HP_BAR = 20;
const QSize Enemy::_fixedSize(50,40);
Enemy::Enemy(){}

Enemy::Enemy(QPoint spos, QPoint epos, GameWindow *game, QString pixFileName):
    QObject(0),
    _spos(spos),
    _epos(epos),
    pixmap(pixFileName),
    _active(true),
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

void Enemy::doActive(){
    _active=true;
}

void Enemy::emove(){
    QVector2D enemy(_epos - _spos);
    enemy.normalize();
    _cpos=_cpos+enemy.toPoint()*speed;
}

void Enemy::drawe(QPainter *painter){
    if(!_active)
        return;
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

QPoint Enemy::get_cpos(){
    return this->_cpos;
}

void Enemy::set_cpos(QPoint pos){
    this->_cpos=pos;
}

void Enemy::getDamage(int damage){
    _currentHp-=damage;
    if(_currentHp<=0){
        getRemoved();
    }
}

void Enemy::getRemoved(){
    if(_attacklist.empty()){
        return;
    }
//    foreach(Tower * tower, _attacklist)
//        tower->targetKilled();
//    _game->goldNum+=100;
//    _game->removeEnemy(this);
}

void Enemy::getAttacked(Tower *attacker){
    _attacklist.push_back(attacker);
}

void Enemy::gotLostSight(Tower *attacker){
    _attacklist.removeOne(attacker);
}
