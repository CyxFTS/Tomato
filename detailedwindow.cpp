#include "detailedwindow.h"
#include "ui_detailedwindow.h"


detailedwindow::detailedwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::detailedwindow)
{
    setWindowIcon(QIcon(":/start"));

    QLabel *background = new QLabel(this);
    background->setPixmap(QPixmap(":/title2"));
    background->setGeometry(0, 0, 550, 530);
    background->setScaledContents(true);

    ui->setupUi(this);
    window = new MainWindow(this);

    timerId = 0;
    bExpand = true;

    ppbExpandCollapse = new QPushButton(this);

    ppbExpandCollapse->setCheckable(true);
    ppbExpandCollapse->setIcon(QIcon(":/expand"));
    ppbExpandCollapse->setIconSize(QSize(25,25));
    ppbExpandCollapse->setStyleSheet("background-color:transparent;");
    connect(ppbExpandCollapse, SIGNAL(clicked()), this, SLOT(rxClicked()));

    setAttribute(Qt::WA_TranslucentBackground, true);
        setWindowFlags(Qt::Window | Qt::FramelessWindowHint
                       | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint
                       | Qt::WindowMaximizeButtonHint);


    db = QSqlDatabase::addDatabase("QSQLITE");
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


    //插入数据
    //AddRecord(query, 4, "shihhsh", QDateTime());

    //查询所有数据
    //ReadAllRecord(query);

    /*qDebug() << "sasas";

    query.exec("SELECT * FROM table");
    while(query.next())
    {
        qDebug() << query.value(0).toInt() << query.value(1).toString();
    }*/

    model = new QSqlTableModel(ui->tableView);
    model->setTable("task");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Name"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Time"));
    model->select();
    ui->tableView->setModel(model);
    //ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setColumnWidth(0, 50);
    ui->tableView->setColumnWidth(1, 300-48-42);
    ui->tableView->setColumnWidth(2, 170);
    ui->tableView->setItemDelegateForColumn(2, new TimeEditDelegate("yyyy-MM-dd ddd hh:mm"));


    modelw = new QSqlTableModel(ui->tableView);
    modelw->setTable("week");
    modelw->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    modelw->setHeaderData(1,Qt::Horizontal,QObject::tr("Name"));
    modelw->setHeaderData(2,Qt::Horizontal,QObject::tr("Time"));
    modelw->select();
    ui->tableView_2->setModel(modelw);
    //ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_2->setColumnWidth(0, 50);
    ui->tableView_2->setColumnWidth(1, 300-48-42);
    ui->tableView_2->setColumnWidth(2, 170);
    ui->tableView_2->setItemDelegateForColumn(2, new TimeEditDelegate("yyyy-MM-dd ddd hh:mm"));
    db.close();

    taskList = new MyListView(this);

    taskList->setGeometry(550,50,550-300,327-83);

    //无边框处理
    setWindowFlags(Qt::FramelessWindowHint);

    setMouseTracking(true);

    int width = window->width();

    minButton = new UWPButton(this);
    closeButton= new UWPButton(this);

    minButton->setIconSize(QSize(48, 31));
    closeButton->setIconSize(QSize(48, 31));

    minButton->res = 1;
    closeButton->res = 1;

    minButton->SetButtonIcons(QIcon(":/min_r"), QIcon(":/min_h"), QIcon(":/min_p"));
    closeButton->SetButtonIcons(QIcon(":/close_r"), QIcon(":/close_h"), QIcon(":/close_p"));

    ppbExpandCollapse->setGeometry(width-20-8,this->height()/2-5,25,25);
    minButton->setGeometry(width-48*2-2,1,48,31);
    closeButton->setGeometry(width-48-2,1,48,31);

    minButton->setToolTip(tr("minimize"));
    closeButton->setToolTip(tr("close"));

    minButton->setStyleSheet("background-color:transparent;");
    closeButton->setStyleSheet("background-color:transparent;");

    connect(minButton,SIGNAL(clicked()),this,SLOT(showMinimized()));
    //connect(closeButton,SIGNAL(clicked()),this,SLOT(close()));
    connect(closeButton,SIGNAL(clicked()),this,SLOT(closeWidget()));

    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(1000);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->start();

    this->resize(window->width(), window->height());
    db.close();
    //window->showFDialog();
    connect(window, &MainWindow::refresh,
                         this, &detailedwindow::receiveRefresh);
    //window->send();
    QPalette sample_palette;
    sample_palette.setColor(QPalette::Window, Qt::white);

    ui->label->setAutoFillBackground(true);
    ui->label->setPalette(sample_palette);

    ui->label_2->setStyleSheet("color:#ffffff;");

    menu = new Menu(this);
    menu->setGeometry(1, 31, menu->width(), menu->height());
    connect(menu,&Menu::changed,this,&detailedwindow::PPP);

    ui->tableView->hide();
    ui->tableView_2->hide();

    weekButton = new UWPButton(this);
    weekButton->setIconSize(QSize(48, 48));
    weekButton->res = 1;
    weekButton->SetButtonIcons(QIcon(":/week"), QIcon(":/week"), QIcon(":/week"));
    weekButton->setGeometry(width-48-15,45,48,48);
    weekButton->setToolTip(tr("month"));
    weekButton->setStyleSheet("background-color:transparent;");

    weekButton->hide();
    connect(weekButton, SIGNAL(clicked()), this, SLOT(switchWeek()));
    graph = new graphwindow(this);
    graph->setGeometry(63,45,graph->width(), graph->height());
    graph->hide();
}

detailedwindow::~detailedwindow()
{
    delete ui;
}

void detailedwindow::mousePressEvent(QMouseEvent *event)
{
 if(event->button() == Qt::LeftButton)
 {
      mouse_press = true;
      //鼠标相对于窗体的位置（或者使用event->globalPos() - this->pos()）
      move_point = event->pos();;
 }
}
void detailedwindow::mouseMoveEvent(QMouseEvent *event)
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
void detailedwindow::mouseReleaseEvent(QMouseEvent *event)
{
    //设置鼠标为未被按下
    mouse_press = false;
}

bool detailedwindow::closeWidget()
{
   //界面动画，改变透明度的方式消失1 - 0渐变
   QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
   animation->setDuration(1000);
   animation->setStartValue(1);
   animation->setEndValue(0);
   animation->start();
   connect(animation, SIGNAL(finished()), this, SLOT(close()));

   return true;
}

void detailedwindow::receiveRefresh(const QString & name)
{
    qDebug() << "Receives Newspaper: " << name;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("finished.db");
    if(!db.open())
    {
        //错误处理
        //return db.lastError();
    }
    qDebug()<<db.lastError();
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
    model->select();
    ui->tableView->setModel(model);
    db.close();
}

void detailedwindow::PPP(const QString & name) {
    qDebug() << name;
    if(name == "main")
    {
        window->show();
        ui->tableView->hide();
        ui->tableView_2->hide();
        weekButton->hide();
        graph->hide();
        ppbExpandCollapse->show();
    }
    if(name == "list")
    {
        window->hide();
        ui->tableView->show();
        ui->tableView_2->hide();
        weekButton->show();
        graph->hide();
        receiveRefresh("");
        ppbExpandCollapse->show();
    }
    if(name == "graph")
    {
        window->hide();
        ui->tableView->hide();
        ui->tableView_2->hide();
        weekButton->hide();
        graph->drawBar();
        graph->show();
        ppbExpandCollapse->hide();
    }
}

void detailedwindow::switchWeek() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("finished.db");
        if(!db.open())
        {
            //错误处理
            //return db.lastError();
        }


        QSqlQuery query;
    Refresh_w(query);
    if(ui->tableView_2->isHidden()){
        ui->tableView_2->show();
        ui->tableView->hide();
    }
    else {
        ui->tableView->show();
        ui->tableView_2->hide();
    }
    modelw->select();
    ui->tableView_2->setModel(modelw);
    db.close();
}

void detailedwindow::refreshFinished()
{
    qDebug()<<"25653wsss";
    /*db.setDatabaseName("finished.db");
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
    model->select();
    ui->tableView->setModel(model);
    db.close();*/
}
