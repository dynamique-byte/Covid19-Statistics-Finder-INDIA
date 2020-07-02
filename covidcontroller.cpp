    #include "covidcontroller.h"
    CovidController::CovidController()
    {
       try{
          driver=get_driver_instance();
          connection=driver->connect("localhost",
                            "root", "*******");
          connection->setAutoCommit(0);
          connection->setSchema("covid_stats");
       }catch(SQLException &ex){
          cout<<"Exception occurred"<<ex.getErrorCode()<<endl;
       }
    }
    QList<Person> PersonController::getAllStats(){
       QList<Covid> list;
       PreparedStatement *pstmt=connection->prepareStatement
          ("SELECT * FROM covid_data");
       ResultSet *resultSet=NULL;
       try{
          resultSet=pstmt->executeQuery();
          while(resultSet->next()){
             Covid p;
             p.setLocation(QString::fromStdString(resultSet->getString
                ("location")));
             p.setActive_Cases(resultSet->getInt("a"));
             p.setRecovered(resultSet->getInt("r"));
             p.setDeaths(resultSet->getInt("d"));
             list.append(p);
          }
       }catch(SQLException &ex){
          cout<<"Exception occurred"<<ex.getErrorCode()<<endl;
       }
       resultSet->close();
       pstmt->close();
       delete pstmt;
       delete resultSet;
       return list;
    }
    QList<Covid> CovidController::geStatsByLocation(const QString &location){
       QList<Covid> list;
       ResultSet *resultSet=NULL;
       PreparedStatement *pstmt=connection->prepareStatement
          ("SELECT * FROM covid_data WHERE Location = ");
       try{
          pstmt->setString(1,lname.toStdString());
          resultSet=pstmt->executeQuery();
          while(resultSet->next()){
             Covid p;
             p.setLocation(QString::fromStdString(resultSet->getString
                ("location")));
             p.setActive_Cases(resultSet->getInt("a"));
             p.setRecovered(resultSet->getInt("r"));
             p.setDeaths(resultSet->getInt("d"));
             list.append(p);
          }
       }catch(SQLException &ex){
          cout<<"Exception occurred"<<ex.getErrorCode()<<endl;
       }
       resultSet->close();
       pstmt->close();
       delete pstmt;
       delete resultSet;
       return list;
    }
    int CovidController::addNewCovid(Covid &p){
       int result=0;
       PreparedStatement *pstmt=connection->prepareStatement
          ("INSERT INTO covid_data ( Location, Active_Cases, Recovered,
            Deaths )
          VALUES (?,?,?,?)");
       try{
          pstmt->setString(1,p.getLocation().toStdString());
          pstmt->setInt(2,p.getActive_Cases());
          pstmt->setInt(3,p.getRecovered());
          pstmt->setInt(4,p.getDeaths());
          result=pstmt->executeUpdate();
          connection->commit();
       }catch(SQLException &ex){
          cout<<"Exception occurred"<<ex.getErrorCode()<<endl;
       }
       pstmt->close();
       delete pstmt;
       return result;
    }
    int CovidController::updateCovid(Covid &p){
       int result=0;
       PreparedStatement *pstmt=connection->prepareStatement
          ("UPDATE covid_data SET Location=?, Active_Cases=?, Recovered=?,
           Deaths=? WHERE Location=?");
       try{
         pstmt->setString(1,p.getLocation().toStdString());
          pstmt->setInt(2,p.getActive_Cases());
          pstmt->setInt(3,p.getRecovered());
          pstmt->setInt(4,p.getDeaths());
          result=pstmt->executeUpdate();
          connection->commit();
       }catch(SQLException &ex){
          cout<<"Exception occurred"<<ex.getErrorCode()<<endl;
       }
       pstmt->close();
       delete pstmt;
       return result;
    }
    int CovidController::deleteCovid(String Location){
       int result=0;
       PreparedStatement *pstmt=connection->prepareStatement
          ("DELETE FROM covid_data WHERE Location=?");
       try{
          pstmt->setString(1,p.getLocation().toStdString());
          result=pstmt->executeUpdate();
          connection->commit();
       }catch(SQLException &ex){
          cout<<"Exception occurred"<<ex.getErrorCode()<<endl;
       }
       pstmt->close();
       delete pstmt;
       return result;
    }
    void CovidController::closeConnection()
    {
       connection->close();
    }
    CovidController::~CovidController(){
       delete connection;
        // delete driver;
    }
