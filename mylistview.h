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

class MyListView : public QWidget
{
    Q_OBJECT

public:
    explicit MyListView();
    ~MyListView();

private slots:
    void insertData();

    void deleteData();

    void showData();

private:

    QStringListModel * model;
    QListView * listView;
};

#endif // MYLISTVIEW_H
