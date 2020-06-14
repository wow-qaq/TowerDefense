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

class GameWindow;
class Enemy : public QObject
{
    Q_OBJECT
public:
    Enemy();
    Enemy(QPoint spos,QPoint epos,GameWindow *game, QString pixFileName);
    ~Enemy();
    void drawe(QPainter *painter);
    QPoint get_cpos();
    void set_cpos(QPoint pos);
    void emove();
    void getDamage(int damage);
    void getRemoved();
    void getAttacked(Tower * attacker);
    void gotLostSight(Tower * attacker);
    QPoint pos() const;
public slots:
    void doActive();
private:
    QPoint _spos;
    QPoint _epos;
    QPoint _cpos;
    QPixmap pixmap;
    double speed;
    bool _active;
    int _maxHp;
    int _currentHp;
    GameWindow * _game;
    QList<Tower*> _attacklist;
    static const QSize _fixedSize;

signals:

public slots:
};

#endif // ENEMY_H
