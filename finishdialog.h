#ifndef FINISHDIALOG_H
#define FINISHDIALOG_H

#include <QDialog>
#include "mylistview.h"
#include <QDebug>
#include <QSqlError>
#include <QDateTime>
#include <QMouseEvent>
#include <QPoint>
#include <QPixmap>
#include <QGraphicsDropShadowEffect>
#include <QBoxLayout>
#include "customshadoweffect.h"
#include "uwpbutton.h"
#include "timeeditdelegate.h"

/*QString create_sql = "create table task (id int primary key, name varchar(30), time nvarchar(20))";
QString select_max_sql = "select max(id) from task";
QString insert_sql = "insert into task values (?, ?, ?)";
QString update_sql = "update task set name = :name where id = :id";
QString select_sql = "select id, name from task";
QString select_all_sql = "select * from task";
QString delete_sql = "delete from task where id = ?";
QString clear_sql = "delete from task";*/

namespace Ui {
class FinishDialog;
}

class FinishDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FinishDialog(QWidget *parent = 0);
    ~FinishDialog();
    UWPButton * button;
    void send();


signals:
    void Ok(const QString &name);

private slots:
    //鼠标按下事件
    void mousePressEvent(QMouseEvent *event);
    //鼠标释放事件
    void mouseReleaseEvent(QMouseEvent *event);
    //鼠标移动事件
    void mouseMoveEvent(QMouseEvent *event);
    //void paintEvent(QPaintEvent *event);

    void check();

private:
    int taskCnt;
    QSqlTableModel *model;
    Ui::FinishDialog *ui;
    MyListView* myList;
    QPoint move_point; //移动的距离
    bool mouse_press = false; //鼠标按下
};

#endif // FINISHDIALOG_H
