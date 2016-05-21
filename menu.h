#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include "uwpbutton.h"
#include <QEvent>
#include <QDebug>

namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = 0);
    ~Menu();
    void timerEvent(QTimerEvent *event);

signals:
    void changed(const QString & name);

private slots:
    void rxClicked()
    {
        if (timerId == 0)
            timerId = startTimer(10);
        if (menu->isChecked())
        {
            bExpand = true;
            increment = 15;
        }
        else
        {
            bExpand = false;
            increment = -15;
        }
    }
    void checkChecked(const QString & name);
    void OOO(const QString & name) {
        //qDebug() << name;
        emit changed(name);
    }

private:
    Ui::Menu *ui;
    UWPButton *menu;
    UWPButton *main;
    UWPButton *list;
    UWPButton *graph;
    bool bExpand;
    int timerId = 0;
    int increment;
};

#endif // MENU_H
