#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QPoint>
#include <QPixmap>
#include <QString>
#include <QPainter>
#include <QTime>
#include <QTimer>
#include <QPropertyAnimation>

class Enemy : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QPoint _cpos READ get_cpos WRITE set_cpos)
public:
    Enemy();
    Enemy(QPoint spos,QPoint epos, QString pixFileName);
    void drawe(QPainter *painter);
    void alive();
    QPoint get_cpos();
    void set_cpos(QPoint pos);
private:
    QPoint _spos;
    QPoint _epos;
    QPoint _cpos;
    QPixmap pixmap;
    QTimer *life;
    int speed;

signals:

public slots:
    void emove();
};

#endif // ENEMY_H
