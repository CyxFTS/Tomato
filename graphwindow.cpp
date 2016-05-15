#include "graphwindow.h"
#include "ui_graphwindow.h"

graphwindow::graphwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::graphwindow)
{
    ui->setupUi(this);
}

graphwindow::~graphwindow()
{
    delete ui;
}
