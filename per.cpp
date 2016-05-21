#include "per.h"
#include "database.h"
CPersonGroupMan::CPersonGroupMan(QWidget *parent) :
    QDialog(parent)
{
    QSqlError error = Init();
    if(error.type() != QSqlError::NoError)
    {
        QMessageBox::critical(this, tr("初始化数据库失败"), error.text(), QMessageBox::Cancel);
    }
}
