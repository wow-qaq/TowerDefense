#ifndef CHOOSEBUTTON_H
#define CHOOSEBUTTON_H

#include <QWidget>
#include <QObject>
#include <QPixmap>
#include <QPushButton>
#include <QAction>

class ChooseButton : public QPushButton
{
    Q_OBJECT
public:
    ChooseButton(QString filename);
private:
    QPixmap(pixmap);

signals:
    void choosetower();
    void choosetower2();
    void removetower();
    void removetower2();
    void levelup();
public slots:
};

#endif // CHOOSEBUTTON_H
