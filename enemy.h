#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QPoint>
#include <QPixmap>
#include <QString>
#include <QPainter>
#include <QTime>
#include <QTimer>
#include <QVector2D>
#include "gamewindow.h"
#include "choosebutton.h"
#include "tower.h"
#include "tower2.h"
#include "lvtower.h"

class GameWindow;
class Tower;
class Enemy : public QObject
{
    Q_OBJECT
public:
    Enemy();
    Enemy(QPoint spos,QPoint epos,GameWindow *game, QString pixFileName);
    ~Enemy();
    void drawe(QPainter *painter);
    void emove();
    void getDamage(int damage);
    void getLower();
    void getRemoved();
    void change();
    void attack();
    double getDistance(QPoint cpos, QList<Tower*>towerlist);
    double getDistance(QPoint cpos, QList<Tower2*>tower2list);
    double getDistance(QPoint cpos, QList<LvTower*>lvtowerlist);
    QPoint pos() const;
private:
    QPoint _spos;
    QPoint _epos;
    QPoint _cpos;
    QPixmap pixmap;
    double speed;
    int _maxHp;
    int _currentHp;
    GameWindow * _game;
    static const QSize _fixedSize;

signals:

public slots:
};

#endif // ENEMY_H
