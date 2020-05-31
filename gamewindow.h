#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include "tower.h"
#include "mybutton.h"
#include "enemy.h"
#include <QList>
#include <QTime>
#include <QTimer>
#include <QObject>

class GameWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit GameWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    void set_tower(int i);

private:
    QList<Tower *>tower_list;
    QList<MyButton *>button_list;
    QList<Enemy *>enemy_list;
    QTimer *timer;
    static int count;

signals:

public slots:
    void set_enemy();
    void updatescene();
};

#endif // GAMEWINDOW_H
