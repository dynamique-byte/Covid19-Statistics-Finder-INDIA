#include "covid_main.h"
#include "ui_covid_main.h"
#include<iostream>
#include<stdio.h>
#include <cppconn/connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <QString>
#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include "covid_mainwin.h"
covid_main::covid_main(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::covid_main)
{
    ui->setupUi(this);

    if(!connOpen())
    {
        ui->label->setText("Not Connected");

    }
    else{
        ui->label->setText(" Connected");
    }

}

covid_main::~covid_main()
{
    delete ui;
}
void covid_main::on_pushButton_clicked()
{

        QString Loc;
         int count=0;
        Loc=ui->loc_text->text();
        if(!connOpen())
        {
                qDebug()<<("Failed to open the database");
                return;

        }
          connOpen();
          QSqlQuery qry;
          qry.prepare("select * from h where Location='"+Loc+"';");
        if(qry.exec())
        {
             while(qry.next())
             {
                 count++;
             }
             if(count==1){
                   ui->label->setText("");
                   connClose();
                   this->hide();
                   covid_mainwin covid_mainwin;
                   covid_mainwin.setModal(true);
                   covid_mainwin.exec();

             }
             else{
                  ui->label->setText("No Such Location Exist in Record");
             }

        }

}
