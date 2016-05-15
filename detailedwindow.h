#ifndef DETAILEDWINDOW_H
#define DETAILEDWINDOW_H

#include <QWidget>

namespace Ui {
class detailedwindow;
}

class detailedwindow : public QWidget
{
    Q_OBJECT

public:
    explicit detailedwindow(QWidget *parent = 0);
    ~detailedwindow();

private:
    Ui::detailedwindow *ui;
};

#endif // DETAILEDWINDOW_H
