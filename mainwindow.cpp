#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QPushButton>
#include <QDebug>
#include "mybutton.h"
#include "gamewindow.h"
#include "menu.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setFixedSize(800,600);
    ui->setupUi(this);
    MyButton *btn = new MyButton(":/res/images/Begin Button.jfif");
    btn->setParent(this);
    btn->move(200,200);
    Menu *menu = new Menu;
    connect(btn,&MyButton::clicked,this,[=](){
        this->close();
        menu->show();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pixmap(":/res/images/Welcome.jfif");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
}
