#include "winwindow.h"

WinWindow::WinWindow(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(800,600);
}

void WinWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pixmap(":/res/images/Defeat.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
}
