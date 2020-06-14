#ifndef TOWER2_H
#define TOWER2_H

#include <QObject>
#include <QPoint>
#include <QPixmap>
#include <QString>
#include <QPainter>

class Tower2 : public QObject
{
    Q_OBJECT
public:
    Tower2(QPoint pos, QString pixFileName);
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

#endif // TOWER2_H
