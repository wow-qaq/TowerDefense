#ifndef TOWER2_H
#define TOWER2_H

#include <QObject>
#include <QPoint>
#include <QPixmap>
#include <QString>
#include <QPainter>
#include "tower.h"

class Tower2 : public Tower
{
public:
    Tower2(QPoint pos, QString pixFileName);
    QPoint getpos2();
private:
    QPoint _pos2;
    QPixmap pixmap;
    int m_attackRange;
    int currentHP;
signals:

public slots:
};

#endif // TOWER2_H
