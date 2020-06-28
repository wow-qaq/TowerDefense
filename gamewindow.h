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
#include "choosebutton.h"
#include "lvtower.h"
#include "winwindow.h"
#include <QtMultimedia>

class Enemy;
class GameWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit GameWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    void set_tower(int i);
    void set_tower2(int i);
    void removetower(Tower *tower);
    void removetower2(Tower2 *tower2);
    void showtext(QPainter *painter);
    void lifeloss();
    void removeEnemy(Enemy *enemy);
    void levelup(int i);
    friend class Enemy;
private:
    QList<Tower *>tower_list;
    QList<Tower2 *>tower2_list;
    QList<LvTower *>lvtower_list;
    QList<ChooseButton *>button_list;
    QList<Enemy *>enemy_list;
    QList<Enemy *>enemy2_list;
    QTimer *timer;
    static int count;
    int life;
    int money;
    QMediaPlayer *music;

signals:

public slots:
    void set_enemy();
    void set_enemy2();
    void set_enemy3();
    void updatescene();
};

#endif // GAMEWINDOW_H
