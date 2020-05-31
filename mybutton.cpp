#include "mybutton.h"
#include <QPixmap>

MyButton::MyButton(QString pix):QPushButton(0){
    QPixmap pixmap(pix);
    this->setFixedSize(pixmap.width(),pixmap.height());
    this->setStyleSheet("QPushBUtton{border:Opx;}");
    this->setIcon(pixmap);
    this->setIconSize(QSize(pixmap.width(),pixmap.height()));
}
