#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include "database.h"
#include <qcustomplot.h>
#include <QVector>
#include "tempcolor.h"

namespace Ui {
class graphwindow;
}

class graphwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit graphwindow(QWidget *parent = 0);
    void showCalendar();
    void showCalendar_2();
    void countTime();
    void drawBar();
    ~graphwindow();

private:
    Ui::graphwindow *ui;
    QString now;

    void selectDate(const QString&a, const QString&b);
    QCPBars* bars;
    QCPBars* bars2;

protected:
    bool eventFilter(QObject *obj, QEvent *ev);
private slots:
    void getData();
    void confirmDate();
};




#endif // GRAPHWINDOW_H
