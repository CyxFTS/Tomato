#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}
