#ifndef LVTOWER_H
#define LVTOWER_H

#include <QObject>
#include <QPoint>
#include <QPixmap>
#include <QString>
#include <QPainter>
#include "tower.h"

class LvTower : public Tower
{
public:
    LvTower(QPoint pos, QString pixFileName);
private:
    QPoint _pos;
    QPixmap pixmap;
    int m_attackRange;

signals:

public slots:
};

#endif // LVTOWER_H
