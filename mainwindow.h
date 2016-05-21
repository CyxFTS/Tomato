#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDateTime>
#include <QTimer>
#include <QTime>
#include <QPixmap>
#include <QIcon>
#include <QDebug>
#include <QMessageBox>
#include <QProgressDialog>
#include <QToolButton>
#include <QLabel>
#include <QBitmap>
#include <QPropertyAnimation>
#include <round.h>
#include <QStyle>
#include "finishdialog.h"
#include "customshadoweffect.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showFDialog();
    void send()
    {
        emit refresh("hello");
        qDebug() <<"lolo01";
    }

signals:
    void refresh(const QString &name);

protected:
    void changeEvent(QEvent *e);

    /*void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);*/

private slots:
    void on_StopLCDBtn_clicked();
    void on_StartLCDBtn_clicked();
    void on_StartBtn_clicked();
    void ShowTimer();
    void paintEvent(QPaintEvent *);
    bool closeWidget();
    void receiveOk(const QString & name)
    {
        qDebug() << "Receives Newspaper: " << name;
        emit refresh(name);
        qDebug() <<"lolo01";
    }

private:
    FinishDialog *FDialog;
    CRoundProcesseBar *bar;
    Ui::MainWindow *ui;
    bool m_BStop;
    bool isStart;
    QString tomatoTime = "25:00";
    //QDialog *FDialog;
    QPixmap playPix = style()->standardPixmap(QStyle::SP_MediaPlay);
    QPixmap stopPix = style()->standardPixmap(QStyle::SP_MediaStop);

    int m_nPause;
    QTimer *myTimer;
    QDateTime CurDate;
    QPoint move_point; //移动的距离
    bool mouse_press = false; //鼠标按下
    UWPButton *play;

};

#endif // MAINWINDOW_H
