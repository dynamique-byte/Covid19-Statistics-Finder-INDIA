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
    ui->label_3->setVisible(false);
    ui->label->setText("Covid19 Statistic");
    if(!connOpen())
    {
        ui->label_3->setText("Sorry! Server is Down :(");

    }
    else{
        ui->label3->setVisible(false);
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
        {ui->label->setText("Covid19 Statistic");
             while(qry.next())
             {
                 count++;
             }
             if(count==1){

                   QSqlQueryModel * modal=new QSqlQueryModel();

                           qry.exec();
                           modal->setQuery(qry);
                           ui->loc_text->setVisible(false);
                           ui->label_2->setVisible(false);
                           ui->pushButton->hide();
                           ui->label3->setVisible(true);
                           ui->label3->setModel(modal);
                           connClose();

             }


        }
        else{
            ui->label3->setVisible(true);
             ui->label_3->setText("Sorry! No such location exixt in database :(");
        }

}
