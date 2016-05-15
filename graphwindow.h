#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QWidget>

namespace Ui {
class graphwindow;
}

class graphwindow : public QWidget
{
    Q_OBJECT

public:
    explicit graphwindow(QWidget *parent = 0);
    ~graphwindow();

private:
    Ui::graphwindow *ui;
};

#endif // GRAPHWINDOW_H
