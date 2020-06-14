#include "gamewindow.h"
#include "QDebug"

int GameWindow::count=0;

GameWindow::GameWindow(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(800,600);
    life=10;
    money=100;
    for(int i=0;i<4;i++){
        ChooseButton *setTower = new ChooseButton(":/res/images/TowerPlace.png");
        setTower->setParent(this);
        setTower->move(100+200*i,200);
        connect(setTower,&ChooseButton::choosetower,this,[=](){
            emit set_tower(i);
        });
        connect(setTower,&ChooseButton::choosetower2,this,[=](){
            emit set_tower2(i);
        });
        button_list.push_back(setTower);
    }
    MyButton *begin = new MyButton(":/res/images/begin.jfif");
    begin->setParent(this);
    begin->move(300,100);
    connect(begin,&MyButton::clicked,this,[=](){
        timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(updatescene()));
        timer->start(50);
        timer->setInterval(500);
    });
}

void GameWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    showtext(&painter);
    QPixmap pixmap(":/res/images/map.jfif");
    painter.drawPixmap(75,0,this->width(),this->height(),pixmap);
    foreach (Tower *tower, tower_list) {
       tower->draw(&painter);
    }
    foreach (Enemy *enemy, enemy_list) {
        enemy->drawe(&painter);
    }
    foreach (Tower2 *tower2, tower2_list) {
       tower2->draw(&painter);
    }
}

void GameWindow::set_tower(int i){
    Tower *new_tower = new Tower(QPoint(100+200*i,250),":/res/images/Tower.png");
    tower_list.push_back(new_tower);
    update();
}

void GameWindow::set_tower2(int i){
    Tower2 *new_tower = new Tower2(QPoint(100+200*i,250),":/res/images/Tower.png");
    tower2_list.push_back(new_tower);
    update();
}

void GameWindow::set_enemy(){
    Enemy *new_enemy = new Enemy(QPoint(75,325),QPoint(800,325),this,":/res/images/Enemy.png");
    enemy_list.push_back(new_enemy);
    update();
}

void GameWindow::updatescene(){
    if(count<5){
        this->set_enemy();
        count++;
    }
    foreach (Enemy* enemy, enemy_list) {
        enemy->emove();
    }
    update();
}

void GameWindow::showtext(QPainter *painter){
    painter->save();
    painter->setPen(Qt::red);
    painter->drawText(QRect(0,0,75,50),QString("life:%1 money:%2").arg(life).arg(money));
    painter->restore();
}
