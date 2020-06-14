#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include "tower.h"
#include "mybutton.h"
#include "enemy.h"
#include "tower2.h"
#include <QList>
#include <QTime>
#include <QTimer>
#include <QObject>
#include <QString>
#include <choosebutton.h>

class Enemy;
class GameWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit GameWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    void set_tower(int i);
    void set_tower2(int i);
    void showtext(QPainter *painter);
private:
    QList<Tower *>tower_list;
    QList<Tower2 *>tower2_list;
    QList<ChooseButton *>button_list;
    QList<Enemy *>enemy_list;
    QTimer *timer;
    static int count;
    int life;
    int money;

signals:

public slots:
    void set_enemy();
    void updatescene();
};

#endif // GAMEWINDOW_H
