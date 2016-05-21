#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QDialog>
#include <QMessageBox>

static QString create_sql = "create table task (id int primary key, name varchar(30), time datetime)";
static QString create_sql_w = "create table task_w (id int primary key, name varchar(30), time datetime(%Y.%m.%d %H:%M))";
static QString select_max_sql = "select max(id) from task";
static QString insert_sql = "insert into task values (?, ?, ?)";
static QString insert_sql_g = "insert into task values (?, ?, ?)";
static QString update_sql = "update task set name = :name where id = :id";
static QString select_sql = "select * from task where strftime('%Y', time) = '2016'";
static QString select_all_sql = "select * from task";
static QString select_month = "select * ";
static QString copy = "INSERT INTO week(id, name, time) SELECT * FROM task where time between datetime('now','start of month','+1 second') and datetime('now','start of month','+1 month','-1 second')";
static QString delete_sql = "delete from task where id = ?";
static QString clear_sql = "delete from week";
static QString select_sql_00 = "select name from task where time between '00:00:00' and '00:59:59'";
static QString select_sql_01 = "select name from task where time between '01:00:00' and '01:59:59'";
static QString select_sql_02 = "select name from task where time between '02:00:00' and '02:59:59'";
static QString select_sql_03 = "select name from task where time between '03:00:00' and '03:59:59'";
static QString select_sql_04 = "select name from task where time between '04:00:00' and '04:59:59'";
static QString select_sql_05 = "select name from task where time between '05:00:00' and '05:59:59'";
static QString select_sql_06 = "select name from task where time between '06:00:00' and '06:59:59'";
static QString select_sql_07 = "select name from task where time between '07:00:00' and '07:59:59'";
static QString select_sql_08 = "select name from task where time between '08:00:00' and '08:59:59'";
static QString select_sql_09 = "select name from task where time between '09:00:00' and '09:59:59'";
static QString select_sql_10 = "select name from task where time between '10:00:00' and '10:59:59'";
static QString select_sql_11 = "select name from task where time between '11:00:00' and '11:59:59'";
static QString select_sql_12 = "select name from task where time between '12:00:00' and '12:59:59'";
static QString select_sql_13 = "select name from task where time between '13:00:00' and '13:59:59'";
static QString select_sql_14 = "select name from task where time between '14:00:00' and '14:59:59'";
static QString select_sql_15 = "select name from task where time between '15:00:00' and '15:59:59'";
static QString select_sql_16 = "select name from task where time between '16:00:00' and '16:59:59'";
static QString select_sql_17 = "select name from task where time between '17:00:00' and '17:59:59'";
static QString select_sql_18 = "select name from task where time between '18:00:00' and '18:59:59'";
static QString select_sql_19 = "select name from task where time between '19:00:00' and '19:59:59'";
static QString select_sql_20 = "select name from task where time between '20:00:00' and '20:59:59'";
static QString select_sql_21 = "select name from task where time between '21:00:00' and '21:59:59'";
static QString select_sql_22 = "select name from task where time between '22:00:00' and '22:59:59'";
static QString select_sql_23 = "select name from task where time between '23:00:00' and '23:59:59'";


static QVariant AddRecord(QSqlQuery &query, const int ID, const QString &name, const QDateTime datetime)
{    
    QString str = datetime.toString("yyyy-MM-dd hh:mm");
    QDateTime datetime2 = QDateTime().fromString(str,"yyyy-MM-dd hh:mm");
    qDebug()<<datetime2;
    query.prepare(insert_sql);
    query.addBindValue(ID);
    query.addBindValue(name);
    query.addBindValue(datetime2);
    if(!query.exec())
    {
        qDebug()<<query.lastError();
    }
    else
    {
        qDebug()<<"inserted!";
    }

    return query.lastInsertId();
}

static QVariant AddRecord_g(QSqlQuery &query, const QDate &date, const QString &grade, const QTime &time)
{
    query.prepare(insert_sql_g);
    query.addBindValue(date);
    query.addBindValue(grade);
    query.addBindValue(time);
    if(!query.exec())
    {
        qDebug()<<query.lastError();
    }
    else
    {
        qDebug()<<"inserted!"<<time;
    }

    return query.lastInsertId();
}

static QVariant Refresh_w(QSqlQuery &query)
{
    query.exec(clear_sql);
    query.prepare(copy);
    if(!query.exec())
    {
        qDebug()<<query.lastError();
    }
    else
    {
        qDebug()<<"inserted!";
    }

    return query.lastInsertId();
}

static QVariant ReadAllRecord(QSqlQuery &query)
{
    query.prepare(select_all_sql);
    if(!query.exec())
    {
        qDebug()<<query.lastError();
    }
    else
    {
        while(query.next())
        {
            QString id = query.value(0).toString();
            QString name = query.value(1).toString();
            QString age = query.value(2).toString();

            qDebug()<<QString("id:%1    name:%2    time:%3").arg(id).arg(name).arg(age);
        }
    }
    return query.lastInsertId();
}

static QVariant ReadRecord(QSqlQuery &query)
{
    query.prepare(select_sql);
    if(!query.exec())
    {
        qDebug()<<query.lastError();
    }
    else
    {
        while(query.next())
        {
            int id = query.value(0).toInt();
            QString name = query.value(1).toString();
            QDateTime age = query.value(2).toDateTime();
            qDebug()<<age;
            //qDebug()<<QString("id:%1    name:%2    time:%3").arg(id).arg(name).arg(age);
        }
    }
    return query.lastInsertId();
}

static QVariant DeleteRecord(QSqlQuery &query,const int ID)
{
    query.prepare(delete_sql);
    query.addBindValue(ID);

    if(!query.exec())
    {
        qDebug()<<query.lastError();
    }
    else
    {
        qDebug()<<"deleted!";
    }

    return query.lastInsertId();
}


#endif // DATABASE_H
