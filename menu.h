#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QPainter>
#include <QPixmap>
#include "mybutton.h"
#include <gamewindow.h>

class Menu : public QMainWindow
{
    Q_OBJECT
public:
    explicit Menu(QWidget *parent = nullptr);
    void choose();

signals:

public slots:

};

#endif // MENU_H
