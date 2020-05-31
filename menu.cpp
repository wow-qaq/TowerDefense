#include "menu.h"

Menu::Menu(QWidget *parent):QMainWindow(parent)
{
    this->setFixedSize(800,600);
    MyButton *first = new MyButton(":/res/images/first.png");
    first->setParent(this);
    first->move(300,100);
    MyButton *second = new MyButton(":/res/images/second.png");
    second->setParent(this);
    second->move(400,100);
    connect(first, &MyButton::clicked, this, &Menu::choose);
    connect(second, &MyButton::clicked, this, &Menu::choose);
}

void Menu::choose()
{
    GameWindow * game  = new GameWindow();
    this->close();
    game->show();
}
