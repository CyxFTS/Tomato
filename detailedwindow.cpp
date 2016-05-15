#include "detailedwindow.h"
#include "ui_detailedwindow.h"

detailedwindow::detailedwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::detailedwindow)
{
    ui->setupUi(this);
}

detailedwindow::~detailedwindow()
{
    delete ui;
}
