#include "choosebutton.h"

ChooseButton::ChooseButton(QString filename) : QPushButton(0),pixmap(filename)
{
    this->setFixedSize(pixmap.width(),pixmap.height());
    this->setStyleSheet("QPushBUtton{border:Opx;}");
    this->setIcon(pixmap);
    this->setIconSize(QSize(pixmap.size()));
    this->setContextMenuPolicy(Qt::ActionsContextMenu);
    QAction *action1 = new QAction(this);
    action1->setText("攻击塔");
    this->addAction(action1);
    QAction *action2 = new QAction(this);
    action2->setText("减速塔");
    this->addAction(action2);
    QAction *action3 = new QAction(this);
    action3->setText("升级");
    this->addAction(action3);
    QAction *action4 = new QAction(this);
    action4->setText("拆除攻击塔");
    this->addAction(action4);
    QAction *action5 = new QAction(this);
    action5->setText("拆除减速塔");
    this->addAction(action5);
    connect(action1,QAction::triggered,this,[=](){
        emit choosetower();
    });
    connect(action2,QAction::triggered,this,[=](){
        emit choosetower2();
    });
    connect(action3,QAction::triggered,this,[=](){
        emit levelup();
    });
    connect(action4,QAction::triggered,this,[=](){
        emit removetower();
    });
    connect(action5,QAction::triggered,this,[=](){
        emit removetower2();
    });
}
