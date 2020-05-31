#include "gamewindow.h"

int GameWindow::count=0;

GameWindow::GameWindow(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(800,600);
    for(int i=0;i<4;i++){
        MyButton *setTower = new MyButton(":/res/images/TowerPlace.png");
        setTower->setParent(this);
        setTower->move(100+200*i,200);
        connect(setTower,&MyButton::clicked,this,[=](){
            emit set_tower(i);
        });
        button_list.push_back(setTower);
    }
    MyButton *begin = new MyButton(":/res/images/begin.jfif");
    begin->setParent(this);
    begin->move(300,100);
    connect(begin,&MyButton::clicked,this,[=](){
        timer = new QTimer(this);
//        emit set_enemy();
        connect(timer,SIGNAL(timeout()),this,SLOT(updatescene()));
        timer->start(50);
        timer->setInterval(100);
    });
}

void GameWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pixmap(":/res/images/map.jfif");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
    foreach (Tower *tower, tower_list) {
       tower->draw(&painter);
    }
    foreach (Enemy *enemy, enemy_list) {
        enemy->drawe(&painter);
    }
}

void GameWindow::set_tower(int i){
    Tower *new_tower = new Tower(QPoint(100+200*i,250),":/res/images/Tower.png");
    tower_list.push_back(new_tower);
    update();
}

void GameWindow::set_enemy(){
    Enemy *new_enemy = new Enemy(QPoint(0,300),QPoint(800,300),":/res/images/Enemy.png");
    enemy_list.push_back(new_enemy);
    new_enemy->emove();
    update();
}

void GameWindow::updatescene(){
    if(count<5){
        this->set_enemy();
        count++;
    }
    update();
}
