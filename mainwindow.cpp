#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    //ui->TIMER->display(tomatoTime);

    ui->playButton->setIcon(QIcon(":/start"));


    isStart = false;

    m_BStop=false;
    m_nPause=0;
    myTimer=new QTimer(this);
    connect(myTimer,SIGNAL(timeout()),this,SLOT(ShowTimer()));
    connect(ui->playButton,SIGNAL(clicked()),this,SLOT(on_StartLCDBtn_clicked()));

    bar = new CRoundProcesseBar(this);
    bar->setGeometry(65+25,40,bar->width(),bar->height());
    bar->m_clockValue = tomatoTime;

    qDebug() << bar->x() << bar->y();

    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);

    setMouseTracking(true);

    ui->playButton->setIcon(playPix);
    ui->playButton->setStyleSheet("background-color:transparent;");
    FDialog = new FinishDialog;

    connect(FDialog,&FinishDialog::Ok,this,&MainWindow::receiveOk);

    play = new UWPButton(this);
    play->setIconSize(QSize(60, 60));
    play->SetButtonIcons(QIcon(":/play_r"), QIcon(":/play_h"), QIcon(":/play_p"));
    play->setStyleSheet("background-color:transparent;");
    play->setGeometry(268, 450, 60, 60);
    play->res = 1;
    play->name = "play";
    play->setCheckable(true);
    connect(play,SIGNAL(clicked()),this,SLOT(on_StartLCDBtn_clicked()));

    /*int width = this->width();

    QToolButton *minButton = new QToolButton(this);
    QToolButton *closeButton= new QToolButton(this);

    QPixmap minPix  = style()->standardPixmap(QStyle::SP_TitleBarMinButton);
    QPixmap closePix = style()->standardPixmap(QStyle::SP_TitleBarCloseButton);

    minButton->setIcon(minPix);
    closeButton->setIcon(closePix);

    minButton->setGeometry(width-46,5,20,20);
    closeButton->setGeometry(width-25,5,20,20);


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
    animation->start();*/

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QBitmap bitmap(this->size());
    bitmap.fill();
    QPainter painter(&bitmap);
    QPixmap pixmap(":/stop");
    painter.drawPixmap(this->rect(), pixmap);
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::on_StartBtn_clicked()
{
    //bool ok = true;
    int num = 100000;
    int begin=m_nPause;
    //bar->setRange(0,num);
    for(int i = begin; i <= num; i++)
    {
        if(!m_BStop)
        {
            //bar->setValue(i);
            m_nPause=i;
        }else
        {
            //bar->setValue(i);
            m_BStop=true;
        }
    }
}

void MainWindow::on_StartLCDBtn_clicked()
{
    ui->playButton->setIcon(stopPix);
    isStart = !isStart;
    if(!isStart)
    if (QMessageBox::Yes == QMessageBox::question(this,
                                                  tr("Question"),
                                                  tr("Do you want to stop?"),
                                                  QMessageBox::Yes | QMessageBox::No,
                                                  QMessageBox::Yes))
    {
        play->setChecked(false);
        ui->playButton->setIcon(playPix);
        //QMessageBox::information(this, tr("Hmmm..."), tr("I'm glad to hear that!"));
    }
    else
    {
        play->setChecked(true);
        ui->playButton->setIcon(stopPix);
        //QMessageBox::information(this, tr("Hmmm..."), tr("I'm sorry!"));
        isStart = !isStart;
        myTimer->start();
        return;
    }
    CurDate=QDateTime::currentDateTime();
    myTimer->start(1);
}

void MainWindow::ShowTimer()
{
    int timeTotal = 1500;
    QString ss;
    int wyy0 = timeTotal*1000 - CurDate.msecsTo(QDateTime::currentDateTime());
    int wyy = wyy0/1000;
    if(isStart)
    {
        QString min;
        min.setNum(wyy / 60);
        QString sec;
        sec.setNum(wyy % 60);

        QString zero = "0";
        if(min.size() == 1)
            min = zero + min;
        if(sec.size() == 1)
            sec = zero + sec;
        QString sum = min + ":" + sec;

        ss.setNum(wyy0/(timeTotal/100)/10);
        bar->setScanValue(ss);
        bar->m_clockValue = sum;
        //qDebug() << wyy0 << " " << min << " " << sec << " " << sum << "/n";
        //ui->TIMER->display(sum);
    }
    else
    {
        on_StopLCDBtn_clicked();
    }
    if(ss == "0")
    {
        FDialog = new FinishDialog;
        on_StopLCDBtn_clicked();
        isStart = !isStart;
        ui->playButton->setIcon(playPix);
        //FDialog = new FinishDialog;
        FDialog->show();

    }
}

void MainWindow::on_StopLCDBtn_clicked()
{
    myTimer->stop();
}

void MainWindow::showFDialog()
{
    FDialog->show();
}

/*void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        mouse_press = true;
        move_point = event->pos();;
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(mouse_press)
    {
        QPoint move_pos = event->globalPos();
        this->move(move_pos - move_point);
    }
}
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    mouse_press = false;
}*/

bool MainWindow::closeWidget()
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
