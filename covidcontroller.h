    #ifndef COVIDCONTROLLER_H
    #define COVIDCONTROLLER_H
    #include <QList>
    #include <QString>
    #include <cppconn/connection.h>
    #include <cppconn/prepared_statement.h>
    #include <cppconn/driver.h>
    #include <cppconn/exception.h>
    #include <cppconn/resultset.h>
    #include "covid.h"
    using namespace std;
    using namespace sql;
    class CovidController
    {
       private:
          Driver *driver;
          Connection *connection;
       public:
          CovidController();
          QList<Person> getAllStats();
          QList<Person> getStatsByLocation(const
             QString& );
          int addNewCovid(Covid&);
          int updateCovid(Covid&);
          int deleteCovid(int);
          void closeConnection();
          ~CovidController();
    };
    #endif   // COVIDCONTROLLER_H
