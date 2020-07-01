#include "covid_mainwin.h"
#include "ui_covid_mainwin.h"

covid_mainwin::covid_mainwin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::covid_mainwin)
{
    ui->setupUi(this);
}

covid_mainwin::~covid_mainwin()
{
    delete ui;
}
