#ifndef FORM_H
#define FORM_H

#include <QWidget>


class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();

private:
    Form *ui;
};

#endif // FORM_H
