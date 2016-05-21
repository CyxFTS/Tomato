#ifndef DETAILEDWINDOW_H
#define DETAILEDWINDOW_H

#include <QWidget>
#include "mylistview.h"
#include "mainwindow.h"
#include <QSql>
#include <QSqlRelationalTableModel>
#include <QSqlRelationalDelegate>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QHeaderView>
#include <QLabel>
#include <QToolButton>
#include <QPoint>
#include <QMouseEvent>
#include "database.h"
#include "finishdialog.h"
#include <QMenu>
#include "menu.h"
#include "graphwindow.h"

namespace Ui {
class detailedwindow;
}

class detailedwindow : public QWidget
{
    Q_OBJECT

public:
    explicit detailedwindow(QWidget *parent = 0);
    void timerEvent(QTimerEvent *event)
    {
        if (event->timerId() == timerId)
        {
            int x = geometry().x();
            int y = geometry().y();
            int w = geometry().width();
            int h = geometry().height();
            setGeometry(x, y, w + increment, h);
            if (bExpand)
            {
                if (w > 1080)
                {
                    killTimer(timerId);
                    timerId = 0;
                }
            }
            else
            {
                if (w < 570)
                {
                    killTimer(timerId);
                    timerId = 0;
                }
            }
        }
    }
    ~detailedwindow();


private slots:
    bool closeWidget();
    //鼠标按下事件
    void mousePressEvent(QMouseEvent *event);
    //鼠标释放事件
    void mouseReleaseEvent(QMouseEvent *event);
    //鼠标移动事件
    void mouseMoveEvent(QMouseEvent *event);
    //缩放点击
    void rxClicked()
    {
        if (timerId == 0)
            timerId = startTimer(10);
        if (ppbExpandCollapse->isChecked())
        {
            bExpand = true;
            //ppbExpandCollapse->setIcon(colPix);
            increment = 10;
            //setSizeIncrement(0, 10);
        }
        else
        {
            bExpand = false;
            //ppbExpandCollapse->setIcon(expandPix);
            increment = -10;
        }
    }
    void refreshFinished();
    void receiveRefresh(const QString & name);
    void PPP(const QString & name);
    void switchWeek();

private:
    Menu *menu;
    QPushButton *ppbExpandCollapse;
    QSqlDatabase db;
    bool bExpand;
    int timerId;
    int increment;
    Ui::detailedwindow *ui;
    MyListView * taskList;
    QSqlTableModel *model;
    QSqlTableModel *modelw;
    QPoint move_point; //移动的距离
    bool mouse_press = false; //鼠标按下
    QPixmap expandPix  = style()->standardPixmap(QStyle::SP_ToolBarHorizontalExtensionButton);
    QPixmap colPix  = style()->standardPixmap(QStyle::SP_ArrowLeft);
    MainWindow *window;
    UWPButton *minButton;
    UWPButton *closeButton;
    UWPButton *weekButton;
    graphwindow *graph;

};

#endif // DETAILEDWINDOW_H
