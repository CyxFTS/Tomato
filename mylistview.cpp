#include "mylistview.h"
#include "checkboxdelegate.h"
#include <QDebug>
MyListView::MyListView(QWidget *parent)
    :QWidget(parent)
{

    /*model = new QStandardItemModel();
    QStandardItem *Item = new QStandardItem();
    Item->setCheckable(true);
    Item->setText("Input the task");
    Item->setEditable(false);
    model->setItem( rowCnt++, Item );*/

    listView = new QListView(this);
    /*listView->setModel(model);

    listView->setAcceptDrops(true);
    listView->setDragEnabled(true);
    listView->setDragDropMode(QAbstractItemView::InternalMove);
    listView->setDragDropOverwriteMode(false);*/

    QVBoxLayout *btnLayout = new QVBoxLayout;
    insertBtn = new QPushButton(tr("+"), this);
    insertBtn->setFixedSize(30, 30);
    qDebug()<<insertBtn->size();
    connect(insertBtn, SIGNAL(clicked()), this, SLOT(insertData()));
    delBtn = new QPushButton(tr("-"), this);
    delBtn->setFixedSize(30, 30);
    connect(delBtn, SIGNAL(clicked()), this, SLOT(deleteData()));
    QSpacerItem* vSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
    btnLayout->addWidget(insertBtn);
    btnLayout->addWidget(delBtn);
    btnLayout->addSpacerItem(vSpacer);

    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(listView);
    mainLayout->addLayout(btnLayout);
    setLayout(mainLayout);

    db2 = QSqlDatabase::addDatabase("QSQLITE");
    db2.setDatabaseName("target.db");
    if(!db2.open())
    {
        //错误处理
        //return db.lastError();
    }

    QSqlQuery query2;
    query2.prepare(create_sql);
    if(!query2.exec())
    {
        qDebug()<<query2.lastError();
    }
    else
    {
        qDebug()<<"table created!";
    }

    dmodel = new QSqlTableModel(listView);
    dmodel->setTable("task");
    dmodel->select();

    /*QList<QStandardItem*> itemlist;

    for (int i = 0; i < dmodel->rowCount(); ++i) {
        QSqlRecord record = dmodel->record(i);
        QString name = record.value("name").toString();
        Item->setCheckable( true );
        Item->setText(name);

        //Item2->setDragEnabled(true);
        Item->setEditable(false);

        model->setItem( model->rowCount(), Item );
        qDebug()<<name;
    }*/
    rowCnt = dmodel->index(dmodel->rowCount()-1, 0, QModelIndex()).data().toInt();
    qDebug()<< rowCnt <<"hello";

    listView->setModel(dmodel);
    listView->setModelColumn(1);
    db2.close();
}

MyListView::~MyListView()
{

}

void MyListView::hideButtons()
{
    insertBtn->hide();
    delBtn->hide();
}

void MyListView::insertData()
{
    bool isOK;
    QString text = QInputDialog::getText(this, "Insert",
                                         "Please input new target:",
                                         QLineEdit::Normal,
                                         "New target",
                                         &isOK);
    if (isOK) {
        /*QStandardItem *Item2 = new QStandardItem();
        Item2->setCheckable( true );
        Item2->setText(text);

        //Item2->setDragEnabled(true);
        Item2->setEditable(false);

        model->setItem( model->rowCount(), Item2 );*/
        qDebug() <<"wa";
        if(QSqlDatabase::contains("qt_sql_default_connection"))
            db2 = QSqlDatabase::database("qt_sql_default_connection");
        else
            db2 = QSqlDatabase::addDatabase("QSQLITE");
        db2.setDatabaseName("target.db");
        if(!db2.open())
        {
            //错误处理
            //return db.lastError();
        }
        //qDebug() <<db2.lastError();
        QSqlQuery query2;
        //query2.prepare(create_sql);
        if(!query2.exec(create_sql))
        {
            qDebug()<<query2.lastError();
        }
        else
        {
            qDebug()<<"table created!";
        }
        rowCnt = dmodel->index(dmodel->rowCount()-1, 0, QModelIndex()).data().toInt();
        AddRecord(query2, rowCnt+1, text, QDateTime().currentDateTime());
        rowCnt = dmodel->index(dmodel->rowCount()-1, 0, QModelIndex()).data().toInt();
        qDebug()<< rowCnt <<"hello";


        //同步更新listView
        //dmodel->setTable("task");
        dmodel->select();
        listView->setModel(dmodel);
        listView->setModelColumn(1);

        db2.close();

    }

}


void MyListView::deleteData()
{
    /*if (model->rowCount() > 1) {
        model->removeRows(listView->currentIndex().row(), 1);
        rowCnt--;
    }*/
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db2 = QSqlDatabase::database("qt_sql_default_connection");
    else
        db2 = QSqlDatabase::addDatabase("QSQLITE");
    db2.setDatabaseName("target.db");
    if(!db2.open())
    {
        //错误处理
        qDebug()<<db2.lastError();
    }

    QSqlQuery query2;
    query2.prepare(create_sql);
    if(!query2.exec())
    {
        qDebug()<<query2.lastError();
    }
    else
    {
        qDebug()<<"table created!";
    }

    //AddRecord(query2, dmodel->rowCount(), text, QDateTime().currentDateTime());

    QModelIndex index = dmodel->index(listView->currentIndex().row(), 0, QModelIndex());
    //qDebug()<<index.data().toInt();
    DeleteRecord(query2,index.data().toInt());
    //同步更新listView
    //dmodel->setTable("task");
    dmodel->select();
    listView->setModel(dmodel);
    listView->setModelColumn(1);
    listView->setAlternatingRowColors(true);
    db2.close();
}

/*void MyListView::showData()
{
    QStringList data = model->stringList();
    QString str;
    foreach(QString s, data) {
        str += s + "\n";
    }
    QMessageBox::information(this, "Data", str);
}*/
