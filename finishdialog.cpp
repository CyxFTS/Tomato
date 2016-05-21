#include "finishdialog.h"
#include "ui_finishdialog.h"

#include <QSqlTableModel>
#include <QSqlQuery>
#include <QDebug>

FinishDialog::FinishDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FinishDialog)
{
    /*QLabel *background = new QLabel(this);
    background->setPixmap(QPixmap(":/dialog"));
    //background->setGeometry(0, 0, 550, 530);
    background->setScaledContents(true);*/

    ui->setupUi(this);
    button = new UWPButton(this);
    button->setIconSize(QSize(120, 32));
    button->SetButtonIcons(QIcon(":/normal"), QIcon(":/hover"), QIcon(":/pressed"));
    button->setStyleSheet("background-color:transparent;");
    button->setGeometry(30,283,120,32);
    connect(button,SIGNAL(clicked()),this,SLOT(check()));


    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("target.db");
    if(!db.open())
    {
        //错误处理
        //return db.lastError();
    }

    QSqlQuery query;
    query.prepare(create_sql);
    if(!query.exec())
    {
        qDebug()<<query.lastError();
    }
    else
    {
        qDebug()<<"table created!";
    }


    //插入数据
    //AddRecord(query, 0, "shihhsh", QDateTime().currentDateTime());

    //查询所有数据
    //ReadAllRecord(query);

    model = new QSqlTableModel(ui->tableView);
    model->setTable("task");
    model->select();

    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();

    //ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setColumnWidth(0, 30);
    ui->tableView->setColumnWidth(1, 232);
    ui->tableView->setColumnWidth(2, 168);
    ui->tableView->setItemDelegateForColumn(2, new TimeEditDelegate("yyyy-MM-dd hh:mm"));

    //无边框处理
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);

    setMouseTracking(true);

    setAttribute(Qt::WA_TranslucentBackground);
    CustomShadowEffect *bodyShadow = new CustomShadowEffect();
    bodyShadow->setBlurRadius(20.0);
    bodyShadow->setDistance(10.0);
    bodyShadow->setColor(QColor(0, 0, 0, 30));
    setGraphicsEffect(bodyShadow);

    db.close();
    connect(button,&UWPButton::clicked,this,&FinishDialog::close);

    connect(button,&UWPButton::clicked,this,&FinishDialog::send);
    connect(button,&UWPButton::clicked,this,&FinishDialog::close);

}

FinishDialog::~FinishDialog()
{
    delete ui;
}

void FinishDialog::mousePressEvent(QMouseEvent *event)
{
 if(event->button() == Qt::LeftButton)
 {
      mouse_press = true;
      //鼠标相对于窗体的位置（或者使用event->globalPos() - this->pos()）
      move_point = event->pos();;
 }
}
void FinishDialog::mouseMoveEvent(QMouseEvent *event)
{
    //若鼠标左键被按下
    if(mouse_press)
    {
        //鼠标相对于屏幕的位置
        QPoint move_pos = event->globalPos();

       //移动主窗体位置
       this->move(move_pos - move_point);
    }
}
void FinishDialog::mouseReleaseEvent(QMouseEvent *event)
{
    //设置鼠标为未被按下
    mouse_press = false;
}

void FinishDialog::check()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("finished.db");
    if(!db.open())
    {
        //错误处理
        //return db.lastError();
    }

    QSqlQuery query;
    query.prepare(create_sql);
    if(!query.exec())
    {
        qDebug()<<query.lastError();
    }
    else
    {
        qDebug()<<"table created!";
    }

    QSqlTableModel *model2;
    model2 = new QSqlTableModel;
    model2->setTable("task");
    model2->select();

    QItemSelectionModel *selections = ui->tableView->selectionModel();
    QModelIndexList selected = selections->selectedIndexes();
    //QString str=model->data(model->index(10,2)).toString();

    int row = model2->rowCount();

    //批量添加进数据库
    //qDebug()<<QDateTime().currentDateTime();
    /*qDebug() << selected[2].data().toString();
    qDebug()<<str;*/
    int cnt = 0;
    for(auto i : selected) {
        qDebug() << i;
        if(cnt % 3 == 1){
            AddRecord(query, row+1, i.data().toString(), QDateTime().currentDateTime());
            ++row;
        }
        ++cnt;

    }

    db.close();

}

void FinishDialog::send()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("grade.db");
    if(!db.open())
    {
        //错误处理
        //return db.lastError();
    }

    qDebug()<<"hi";
    QSqlQuery query;

    if(ui->radioButton->isChecked()) {
        AddRecord_g(query, QDate().currentDate(), "good", QTime().currentTime());
        emit Ok("good");
    }
    if(ui->radioButton_2->isChecked()) {
        AddRecord_g(query, QDate().currentDate(), "normal", QTime().currentTime());
        emit Ok("normal");
    }
    if(ui->radioButton_3->isChecked()) {
        AddRecord_g(query, QDate().currentDate(), "bad", QTime().currentTime());
        emit Ok("bad");
    }
    //ReadAllRecord(query);
    db.close();
    //qDebug() <<"lolo00"<<QTime().currentTime();

}

/*void FinishDialog::paintEvent(QPaintEvent *event)
{
    QPainterPath path;
    path.setFillRule(Qt::WindingFill);
    path.addRect(10, 10, this->width()-20, this->height()-20);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.fillPath(path, QBrush(Qt::white));

    QColor color(0, 0, 0, 50);
    for(int i=0; i<10; i++)
    {
        QPainterPath path;
        path.setFillRule(Qt::WindingFill);
        path.addRect(10-i, 10-i, this->width()-(10-i)*2, this->height()-(10-i)*2);
        color.setAlpha(150 - qSqrt(i)*50);
        painter.setPen(color);
        painter.drawPath(path);
    }
}*/

