#include "gamewindow.h"
#include "QDebug"

int GameWindow::count=0;

GameWindow::GameWindow(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(800,600);
    life=5;
    money=300;
    for(int i=0;i<4;i++){
        ChooseButton *chooseTower = new ChooseButton(":/res/images/TowerPlace.png");
        chooseTower->setParent(this);
        chooseTower->move(100+200*i,200);
        connect(chooseTower,&ChooseButton::choosetower,this,[=](){
            if(money>=100){
                emit set_tower(i);
            }
        });
        connect(chooseTower,&ChooseButton::choosetower2,this,[=](){
            if(money>=100){
                emit set_tower2(i);
            }
        });
        connect(chooseTower,&ChooseButton::levelup,this,[=](){
            emit levelup(i);
        });
        connect(chooseTower,&ChooseButton::removetower,this,[=](){
            emit removetower(tower_list[0]);
        });
        connect(chooseTower,&ChooseButton::removetower2,this,[=](){
            emit removetower2(tower2_list[0]);
        });
        button_list.push_back(chooseTower);
    }
    MyButton *begin = new MyButton(":/res/images/begin.jfif");
    begin->setParent(this);
    begin->move(350,100);
    connect(begin,&MyButton::clicked,this,[=](){
        timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(updatescene()));
        timer->start(50);
        timer->setInterval(500);
    });
    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/res/music/back.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    music = new QMediaPlayer(this);
    music->setPlaylist(playlist);
    music->setVolume(25);
    music->play();
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
    foreach (Enemy *enemy2, enemy2_list) {
        enemy2->drawe(&painter);
    }
    foreach (Tower2 *tower2, tower2_list) {
        tower2->draw(&painter);
    }
    foreach (LvTower *lvtower, lvtower_list){
        lvtower->draw(&painter);
    }
}

void GameWindow::set_tower(int i){
    Tower *new_tower = new Tower(QPoint(100+200*i,250),":/res/images/Tower.png");
    tower_list.push_back(new_tower);
    money-=100;
    update();
}

void GameWindow::set_tower2(int i){
    Tower2 *new_tower = new Tower2(QPoint(100+200*i,250),":/res/images/Blue.png");
    tower2_list.push_back(new_tower);
    money-=100;
    update();
}

void GameWindow::set_enemy(){
    Enemy *new_enemy = new Enemy(QPoint(75,325),QPoint(800,325),this,":/res/images/Enemy.png");
    enemy_list.push_back(new_enemy);
    update();
}

void GameWindow::set_enemy2(){
    Enemy *new_enemy2 = new Enemy(QPoint(75,325),QPoint(800,325),this,":/res/images/Enemy2.jpg");
    new_enemy2->change();
    enemy_list.push_back(new_enemy2);
    update();
}

void GameWindow::updatescene(){
    if(count<15){
        this->set_enemy();
        count++;
    }
    else if(count>=15&&count<=25){
        this->set_enemy2();
        count++;
    }
    foreach (Enemy* enemy, enemy_list) {
        enemy->emove();
        enemy->attack();
    }
    for(int k=0;k<tower_list.size();k++){
        if(tower_list[k]->getHP()<=0)
            removetower(tower_list[k]);
    }
    for(int k=0;k<tower2_list.size();k++){
        if(tower2_list[k]->getHP()<=0)
            removetower(tower2_list[k]);
    }
    if(life==0){
        WinWindow *window = new WinWindow;
        this->close();
        window->show();
    }
    update();
}

void GameWindow::showtext(QPainter *painter){
    painter->save();
    painter->setPen(Qt::red);
    painter->drawText(QRect(0,0,75,50),QString("life:%1 money:%2").arg(life).arg(money));
    painter->restore();
}

void GameWindow::removeEnemy(Enemy *enemy){
    enemy_list.removeOne(enemy);
}

void GameWindow::removetower(Tower *tower){
    tower_list.removeOne(tower);
}

void GameWindow::removetower2(Tower2 *tower2){
    tower2_list.removeOne(tower2);
}

void GameWindow::levelup(int i){
    LvTower *new_tower = new LvTower(QPoint(100+200*i,250),":/res/images/Tower3.png");
    lvtower_list.push_back(new_tower);
    money-=100;
    update();
}
