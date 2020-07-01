    #include "covid.h"
    Covid::Covid(){
       Location="";
       Active_Cases=0;
       Recovered=0;
       Deaths=0;
    }
    Person::Person(const QString &location,const int a,const int r,const int d){
       Location=location;
       Active_Cases=a;
       Recovered=r;
       Deaths=d;
    }
    QString Covid::getLocation(){
       return Location;
    }
    void Covid::setLocation(const QString &location){
       Location=location;
    }
    int Covid::getActive_Cases(){
       return Active_Cases;
    }
    void Covid::setActive_Cases(const int a){
       Active_Cases=a;
    }
    int Covid::getRecovered(){
       return Recovered;
    }
    void Covid::setRecovered(const int r){
       Recovered=r;
    }
    int Covid::getDeaths(){
       return Deaths;
    }
    void Covid::setActive_Cases(const int d){
       Deaths=d;
    }
