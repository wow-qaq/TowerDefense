#ifndef TOWER_H
#define TOWER_H

#include <QObject>
#include <QPoint>
#include <QPixmap>
#include <QString>
#include <QPainter>

class Tower : public QObject
{
    Q_OBJECT
public:
    Tower(QPoint pos, QString pixFileName);
    void draw(QPainter *painter);
private:
    QPoint _pos;
    QPixmap pixmap;
    int m_attackRange;
    int m_damage;
    int m_fireRate;

signals:

public slots:
};

#endif // TOWER_H
