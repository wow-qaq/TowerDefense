#ifndef WINWINDOW_H
#define WINWINDOW_H

#include <QMainWindow>
#include <QPainter>

class WinWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit WinWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);

signals:

public slots:
};

#endif // WINWINDOW_H
