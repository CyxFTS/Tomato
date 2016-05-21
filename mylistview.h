#ifndef MYLISTVIEW_H
#define MYLISTVIEW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QListView>
#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QInputDialog>
#include <QLineEdit>
#include <QMessageBox>
#include <QStandardItemModel>
#include <database.h>

class MyListView : public QWidget
{
    Q_OBJECT

public:
    explicit MyListView(QWidget *parent = 0);
    void hideButtons();
    ~MyListView();


private slots:
    void insertData();

    void deleteData();

    //void showData();

private:
    QSqlDatabase db2;
    QListView * listView;
    QStandardItemModel * model;
    QSqlTableModel *dmodel;
    unsigned rowCnt = 0;
    QPushButton *insertBtn;
    QPushButton *delBtn;
};

#endif // MYLISTVIEW_H
