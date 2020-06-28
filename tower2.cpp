#include "tower2.h"

Tower2::Tower2(QPoint pos, QString pixFileName):Tower(pos,pixFileName){
    _pos2=pos;
    pixmap=pixFileName;
    m_attackRange=100;
    currentHP=50;
}

QPoint Tower2::getpos2(){
    return _pos2;
}
