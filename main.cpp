#include "round.h"
#include "mainwindow.h"
#include "detailedwindow.h"
#include <QApplication>
#include <QHBoxLayout>
#include <QtSql>
#include "finishdialog.h"
#include "uwpbutton.h"
#include "menu.h"
#include "graphwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*QPropertyAnimation *animation2 = new QPropertyAnimation(background0, "windowOpacity");
    animation2->setDuration(1000);
    animation2->setStartValue(1);
    animation2->setEndValue(0);
    animation2->start();*/

    /*

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("grade.db");
    if(!db.open())
    {
        //错误处理
        //return db.lastError();
    }


    QSqlQuery query;
    query.exec("select name from task where time between '20:52:00' and '20:54:00'");
    while(query.next())
    {
        QString name = query.value(0).toString();
        qDebug()<<QString("name:%1").arg(name);
    }
    qDebug()<<query.lastError();
    /*if(!query.exec())
    {
        qDebug()<<query.lastError();
    }
    else
    {
        qDebug()<<"succeed!";
    }/*

    AddRecord(query, 2, "i.data().toString()", QDateTime().currentDateTime());

    Refresh_w(query);

    ReadRecord(query);
*/
    /*QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("grade.db");
        if(!db.open())
        {
            //错误处理
            //return db.lastError();
        }


    QSqlQuery query;

    AddRecord_g(query, QDate().currentDate(), "bad", QTime().fromString("14:00:05"));
    AddRecord_g(query, QDate().currentDate(), "good", QTime().fromString("00:00:05"));
    AddRecord_g(query, QDate().currentDate(), "bad", QTime().fromString("02:00:05"));
    /*graphwindow w;
    w.show();*/
    detailedwindow w;
    w.show();

    /*QLabel *background0 = new QLabel();
    background0->setPixmap(QPixmap(":/180"));
    background0->setGeometry(0, 0, 400, 500);
    background0->setScaledContents(true);
    background0->setStyleSheet("background-color:transparent;");
    background0->setWindowFlags(Qt::FramelessWindowHint);

    QPropertyAnimation *animation = new QPropertyAnimation(background0, "windowOpacity");
    animation->setDuration(5200);
    animation->setStartValue(0);
    animation->setEndValue(0);
    animation->setKeyValueAt(0.2,1);
    animation->setKeyValueAt(0.8,1);
    animation->start();
    QObject::connect(animation, SIGNAL(finished()), background0, SLOT(close()));
    background0->show();
    background0->move((QApplication::desktop()->width() - w.width())/2,(QApplication::desktop()->height() - w.height())/2);
    w.move((QApplication::desktop()->width() - w.width())/2,(QApplication::desktop()->height() - w.height())/2);
    //background0->close();*/



    return a.exec();
}
