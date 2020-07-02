#include "covid_mainwin.h"
#include "ui_covid_mainwin.h"
#include "covid_main.h"
covid_mainwin::covid_mainwin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::covid_mainwin)
{
    ui->setupUi(this);
    covid_main conn;
    if(!conn.connOpen())
    {
        ui->label2->setText("Not Connected");

    }
}

covid_mainwin::~covid_mainwin()
{
    delete ui;
}

void covid_mainwin::on_showdata_clicked()
{


}
