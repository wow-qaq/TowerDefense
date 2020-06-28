#include "lvtower.h"

LvTower::LvTower(QPoint pos, QString pixFileName):Tower(pos,pixFileName){
    _pos=pos;
    pixmap=pixFileName;
    m_attackRange=100;
}
