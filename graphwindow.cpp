#include "graphwindow.h"
#include "ui_graphwindow.h"

static QVector<double> ratio(24);
static QVector<int> good(24);
static QVector<int> normal(24);
static QVector<int> cnt(24);

graphwindow::graphwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::graphwindow)
{
    ui->setupUi(this);
    ui->comboBox->installEventFilter(this);
    ui->comboBox_2->setCurrentText(QDate().currentDate().addYears(-10).toString("yyyy/MM/dd"));
    ui->comboBox->setCurrentText(QDate().currentDate().toString("yyyy/MM/dd"));
    ui->comboBox_2->installEventFilter(this);
    ui->calendarWidget->hide();
    connect(ui->calendarWidget,SIGNAL(clicked(QDate)),this,SLOT(getData()));
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("grade.db");
    if(!db.open())
    {
        //错误处理
        //return db.lastError();
    }

    ratio = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    good = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    cnt = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    normal = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    QSqlQuery query;
    query.exec(select_sql_00);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[0];
        if(query.value(0).toString() == "normal")
            ++normal[0];
        ++cnt[0];
        //qDebug()<<QString("name:%1").arg(name);
    }
    query.exec(select_sql_01);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[1];
        if(query.value(0).toString() == "normal")
            ++normal[1];
        ++cnt[1];
        //qDebug()<<QString("name:%1").arg(name);
    }
    query.exec(select_sql_02);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[2];
        if(query.value(0).toString() == "normal")
            ++normal[2];
        ++cnt[2];
        //qDebug()<<QString("name:%1").arg(name);
    }
    query.exec(select_sql_03);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[3];
        if(query.value(0).toString() == "normal")
            ++normal[3];
        ++cnt[3];
        //qDebug()<<QString("name:%1").arg(name);
    }
    query.exec(select_sql_04);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[4];
        if(query.value(0).toString() == "normal")
            ++normal[4];
        ++cnt[4];
        //qDebug()<<QString("name:%1").arg(name);
    }
    query.exec(select_sql_05);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[5];
        if(query.value(0).toString() == "normal")
            ++normal[5];
        ++cnt[5];
        //qDebug()<<QString("name:%1").arg(name);
    }
    query.exec(select_sql_06);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[6];
        if(query.value(0).toString() == "normal")
            ++normal[6];
        ++cnt[6];
        //qDebug()<<QString("name:%1").arg(name);
    }
    query.exec(select_sql_07);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[7];
        if(query.value(0).toString() == "normal")
            ++normal[7];
        ++cnt[7];
        //qDebug()<<QString("name:%1").arg(name);
    }
    query.exec(select_sql_08);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[8];
        if(query.value(0).toString() == "normal")
            ++normal[8];
        ++cnt[8];
        //qDebug()<<QString("name:%1").arg(name);
    }
    query.exec(select_sql_09);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[9];
        if(query.value(0).toString() == "normal")
            ++normal[9];
        ++cnt[9];
        //qDebug()<<QString("name:%1").arg(name);
    }
    query.exec(select_sql_10);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[10];
        if(query.value(0).toString() == "normal")
            ++normal[10];
        ++cnt[10];
        //qDebug()<<QString("name:%1").arg(name);
    }
    query.exec(select_sql_11);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[11];
        if(query.value(0).toString() == "normal")
            ++normal[11];
        ++cnt[11];
        //qDebug()<<QString("name:%1").arg(name);
    }
    query.exec(select_sql_12);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[12];
        if(query.value(0).toString() == "normal")
            ++normal[12];
        ++cnt[12];
        //qDebug()<<QString("name:%1").arg(name);
    }
    query.exec(select_sql_13);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[13];
        if(query.value(0).toString() == "normal")
            ++normal[13];
        ++cnt[13];
        //qDebug()<<QString("name:%1").arg(name);
    }
    query.exec(select_sql_14);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[14];
        if(query.value(0).toString() == "normal")
            ++normal[14];
        ++cnt[14];
        //qDebug()<<QString("name:%1").arg(name);
    }
    query.exec(select_sql_15);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[15];
        if(query.value(0).toString() == "normal")
            ++normal[15];
        ++cnt[15];
        //qDebug()<<QString("name:%1").arg(name);
    }
    query.exec(select_sql_16);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[16];
        if(query.value(0).toString() == "normal")
            ++normal[16];
        ++cnt[16];
        //qDebug()<<QString("name:%1").arg(name);
    }
    query.exec(select_sql_17);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[17];
        if(query.value(0).toString() == "normal")
            ++normal[17];
        ++cnt[17];
        //qDebug()<<QString("name:%1").arg(name);
    }
    query.exec(select_sql_18);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[18];
        if(query.value(0).toString() == "normal")
            ++normal[18];
        ++cnt[18];
        //qDebug()<<QString("name:%1").arg(name);
    }
    query.exec(select_sql_19);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[19];
        if(query.value(0).toString() == "normal")
            ++normal[19];
        ++cnt[19];
        //qDebug()<<QString("name:%1").arg(name);
    }
    query.exec(select_sql_20);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[20];
        if(query.value(0).toString() == "normal")
            ++normal[20];
        ++cnt[20];
        //qDebug()<<QString("name:%1").arg(name);
    }
    query.exec(select_sql_21);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[21];
        if(query.value(0).toString() == "normal")
            ++normal[21];
        ++cnt[21];
        //qDebug()<<QString("name:%1").arg(name);
    }
    query.exec(select_sql_22);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[22];
        if(query.value(0).toString() == "normal")
            ++normal[22];
        ++cnt[22];
        //qDebug()<<QString("name:%1").arg(name);
    }
    query.exec(select_sql_23);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[23];
        if(query.value(0).toString() == "normal")
            ++normal[23];
        ++cnt[23];
        //qDebug()<<QString("name:%1").arg(name);
    }
    db.close();

    for(int i = 0; i < 24; ++i){
        if(cnt[i] != 0)
            ratio[i] = (double(good[i]) + double(normal[i])/2) / cnt[i];
        //qDebug() << ratio[i];
    }

    drawBar();
    setWindowFlags(Qt::FramelessWindowHint);

    setMouseTracking(true);
    setAttribute(Qt::WA_TranslucentBackground, true);

    QObject::connect(ui->pushButton, &QPushButton::clicked, this, &graphwindow::confirmDate);

    QToolButton *prev = ui->calendarWidget->findChild<QToolButton*>(QLatin1String("qt_calendar_prevmonth"));
    QToolButton *next = ui->calendarWidget->findChild<QToolButton*>(QLatin1String("qt_calendar_nextmonth"));
    prev->setIcon(QIcon(":/prev"));
    next->setIcon(QIcon(":/next"));
}

graphwindow::~graphwindow()
{
    delete ui;
}


bool graphwindow::eventFilter(QObject *obj, QEvent *event)

{
    if (obj == ui->comboBox) {
        if (event->type() == QEvent::MouseButtonRelease) {
            showCalendar();
            return true;
        }
        else
            return false;
    }
    else if (obj == ui->comboBox_2) {
        if (event->type() == QEvent::MouseButtonRelease) {
            showCalendar_2();
            return true;
        }
        else
            return false;
    }
    else {
        return QMainWindow::eventFilter(obj, event);
    }
}
void graphwindow::showCalendar()
{
    ui->calendarWidget->show();
    now = "1";
}
void graphwindow::getData()
{
    QDate data = ui->calendarWidget->selectedDate();
    QString dtstr=data.toString("yyyy/MM/dd");
    if(now == "1")
        ui->comboBox->setCurrentText(dtstr);
    if(now == "2")
        ui->comboBox_2->setCurrentText(dtstr);
    ui->calendarWidget->hide();
}

void graphwindow::showCalendar_2()
{
    ui->calendarWidget->show();
    now = "2";
}
/*
void graphwindow::countTime()
{
    QVector<double> ratio(24);
    QVector<int> good(24);
    QVector<int> cnt(24);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("grade.db");
    if(!db.open())
    {
        //错误处理
        //return db.lastError();
    }

    QSqlQuery query;
    query.exec(select_sql_00);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[0];
        ++cnt[0];
        //qDebug()<<QString("name:%1").arg(name);
    }
    query.exec(select_sql_01);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[1];
        ++cnt[1];
        //qDebug()<<QString("name:%1").arg(name);
    }
    query.exec(select_sql_02);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[2];
        ++cnt[2];
        //qDebug()<<QString("name:%1").arg(name);
    }
    query.exec(select_sql_03);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[3];
        ++cnt[3];
        //qDebug()<<QString("name:%1").arg(name);
    }
    query.exec(select_sql_04);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[4];
        ++cnt[4];
        //qDebug()<<QString("name:%1").arg(name);
    }
    query.exec(select_sql_05);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[5];
        ++cnt[5];
        //qDebug()<<QString("name:%1").arg(name);
    }
    query.exec(select_sql_06);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[6];
        ++cnt[6];
        //qDebug()<<QString("name:%1").arg(name);
    }
    query.exec(select_sql_07);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[7];
        ++cnt[7];
        //qDebug()<<QString("name:%1").arg(name);
    }
    query.exec(select_sql_08);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[8];
        ++cnt[8];
        //qDebug()<<QString("name:%1").arg(name);
    }
    query.exec(select_sql_09);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[9];
        ++cnt[9];
        //qDebug()<<QString("name:%1").arg(name);
    }
    query.exec(select_sql_10);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[10];
        ++cnt[10];
        //qDebug()<<QString("name:%1").arg(name);
    }
    query.exec(select_sql_11);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[11];
        ++cnt[11];
        //qDebug()<<QString("name:%1").arg(name);
    }
    query.exec(select_sql_12);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[12];
        ++cnt[12];
        //qDebug()<<QString("name:%1").arg(name);
    }
    query.exec(select_sql_13);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[13];
        ++cnt[13];
        //qDebug()<<QString("name:%1").arg(name);
    }
    query.exec(select_sql_14);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[14];
        ++cnt[14];
        //qDebug()<<QString("name:%1").arg(name);
    }
    query.exec(select_sql_15);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[15];
        ++cnt[15];
        //qDebug()<<QString("name:%1").arg(name);
    }
    query.exec(select_sql_16);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[16];
        ++cnt[16];
        //qDebug()<<QString("name:%1").arg(name);
    }
    query.exec(select_sql_17);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[17];
        ++cnt[17];
        //qDebug()<<QString("name:%1").arg(name);
    }
    query.exec(select_sql_18);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[18];
        ++cnt[18];
        //qDebug()<<QString("name:%1").arg(name);
    }
    query.exec(select_sql_19);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[19];
        ++cnt[19];
        //qDebug()<<QString("name:%1").arg(name);
    }
    query.exec(select_sql_20);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[20];
        ++cnt[20];
        //qDebug()<<QString("name:%1").arg(name);
    }
    query.exec(select_sql_21);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[21];
        ++cnt[21];
        //qDebug()<<QString("name:%1").arg(name);
    }
    query.exec(select_sql_22);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[22];
        ++cnt[22];
        //qDebug()<<QString("name:%1").arg(name);
    }
    query.exec(select_sql_23);
    while(query.next())
    {
        //QString name = query.value(0).toString();
        if(query.value(0).toString() == "good")
            ++good[23];
        ++cnt[23];
        //qDebug()<<QString("name:%1").arg(name);
    }

    db.close();
}
*/
void graphwindow::selectDate(const QString& a, const QString& b)
{
    ratio = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    good = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    normal = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    cnt = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    QDate beg, end;
    beg = QDate().fromString(a,"yyyy/MM/dd");
    end = QDate().fromString(b,"yyyy/MM/dd");

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("grade.db");
    if(!db.open())
    {
        //错误处理
        //return db.lastError();
    }

    QSqlQuery query;

    query.prepare("select * from task where date Between :beg and :end ");
    query.bindValue(":beg", end);
    query.bindValue(":end", beg);
    QList<QVariant> list = query.boundValues().values();
          //for (int i = 0; i < list.size(); ++i)
              //qDebug() << i << ": " << list.at(i).toString().toUtf8().data();
    //query.prepare("select * from task where date Between :beg and :end ");
    if(!query.exec())
    {
        qDebug() << query.lastError();
    }
    else
    {
        qDebug() << "date selected!";
        while(query.next())
        {
            qDebug()<<query.value(1).toString()<<query.value(2).toString();
            for(int i = 0; i < 24; ++i) {
                QString hour = QString::number(i);
                if(i < 10)
                    hour = "0"+hour;
                QString time1 = hour + ":00:00.000";
                QString time2 = hour + ":59:59.999";
                if(query.value(2).toString()>=time1&&query.value(2).toString()<=time2) {
                    if(query.value(1).toString() == "good")
                        ++good[i];
                    if(query.value(1).toString() == "normal")
                        ++normal[i];
                    ++cnt[i];
                }
            }
        }
    }

    for(int i = 0; i < 24; ++i){
        if(cnt[i] != 0)
            ratio[i] = (double(good[i]) + double(normal[i])/2) / cnt[i];
        //qDebug() << ratio[i];
    }

    db.close();

    drawBar();

}

void graphwindow::drawBar()
{
    ui->widget->removePlottable(bars);
    ui->widget_2->removePlottable(bars2);
    QVector<QString> labels(12);
    QVector<double> values(12);

    for(int i=0;i<12;++i)
        labels[i]=QString::number(i);
    for(int i=0;i<12;++i) {
        values[i] = ratio[i];
        //qDebug() <<"h"<< values[i];
    }
    bars=new QCPBars(this->ui->widget->xAxis,this->ui->widget->yAxis);
    bars->setPen(red700);
    bars->setBrush(red500);
    QVector<double> index(12);
    for(int i=0;i<12;++i)
        index[i]=i;
    bars->setData(index,values);
    this->ui->widget->xAxis->setAutoTicks(false);
    this->ui->widget->xAxis->setAutoTickLabels(false);
    this->ui->widget->xAxis->setAutoTickStep(false);
    this->ui->widget->addPlottable(bars);
    this->ui->widget->rescaleAxes();
    double wid=this->ui->widget->xAxis->range().upper-this->ui->widget->xAxis->range().lower;
    double cl=bars->width()+(1.0*wid-bars->width()*5)/32;
    QVector<double> coor;
    for(int i=0;i<12;++i)
        coor.append(this->ui->widget->xAxis->range().lower+i*cl+bars->width()/2);
    this->ui->widget->xAxis->setTickVector(coor);
    this->ui->widget->xAxis->setTickVectorLabels(labels);
    this->ui->widget->yAxis->setRange(0,1.0);
    this->ui->widget->replot();

    for(int i=0;i<12;++i)
        labels[i]=QString::number(i+12);
    for(int i=0;i<12;++i)
        values[i] = ratio[i+12];
    bars2=new QCPBars(this->ui->widget_2->xAxis,this->ui->widget_2->yAxis);
    bars2->setPen(red700);
    bars2->setBrush(red500);

    for(int i=0;i<12;++i)
        index[i]=i+12;
    bars2->setData(index,values);
    this->ui->widget_2->xAxis->setAutoTicks(false);
    this->ui->widget_2->xAxis->setAutoTickLabels(false);
    this->ui->widget_2->xAxis->setAutoTickStep(false);
    this->ui->widget_2->addPlottable(bars2);
    this->ui->widget_2->rescaleAxes();

    QVector<double> coor2;
    for(int i=0;i<12;++i)
        coor2.append(this->ui->widget_2->xAxis->range().lower+i*cl+bars2->width()/2);
    this->ui->widget_2->xAxis->setTickVector(coor2);
    this->ui->widget_2->xAxis->setTickVectorLabels(labels);
    this->ui->widget_2->yAxis->setRange(0,1.0);

    this->ui->widget_2->replot();
}

void graphwindow::confirmDate()
{
    selectDate(ui->comboBox->currentText(), ui->comboBox_2->currentText());
    //qDebug()<<ui->comboBox->currentText()<<ui->comboBox_2->currentText();
}
