    #ifndef COVID_H
    #define COVID_H
    #include <QString>
    using namespace std;
    class Covid
    {
       private:
          QString Location;
          int Active_Cases;
          int Recovered;
          int Deaths;
          
       public:
          Covid();
          Covid(const QString&, const int, const int, const int);
          QString getLocation();
          void setLocation(const QString&);
          int getActive_Cases();
          void setActive_Cases(const int);
          int getRecovered();
          void setRecovered(const int);
          int getDeaths();
          void setDeaths(const int);
          
    };
    #endif   // COVID_H
