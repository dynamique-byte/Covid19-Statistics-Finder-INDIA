#ifndef COVID_MAIN_H
#define COVID_MAIN_H
#include<QString>
#include <QMainWindow>
#include<QtSql>
#include<QSqlDatabase>
#include<QMessageBox>
namespace Ui {
class covid_main;
}

class covid_main : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase db;
    void connClose(){
        db.close();
        db.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen()
    {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("gey");
        if(!db.open())
        {
            qDebug()<<("Failed to open the database");
            return false;
        }
        else{
             qDebug()<<("Connected....");
             return true;
        }

    }

public:
    explicit covid_main(QWidget *parent = 0);
    ~covid_main();\


private slots:

void on_pushButton_clicked();


private:
    Ui::covid_main *ui;
};

#endif // COVID_MAIN_H
