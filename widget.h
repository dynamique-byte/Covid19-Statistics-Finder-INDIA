    #ifndef WIDGET_H
    #define WIDGET_H
    #include <QWidget>
    #include <QList>
    #include <QMessageBox>
    #include "covid.h"
    #include "covidcontroller.h"
    namespace Ui {
       class Widget;
    }
    class Widget : public QWidget
    {
       Q_OBJECT
       public:
          explicit Widget(QWidget *parent = 0);
          ~Widget();
       private:
          Ui::Widget *ui;
          Covid currentCovid;
          CovidController *covidController;
          QList<Covid> list;
          int totalRecord;
          int currentIndex;
          void populateRecord();
          void populateUI();
       signals:
       private slots:
          void browseButtonClicked();
          void addNewButtonClicked();
          void updateButtonClicked();
          void deleteButtonClicked();
          void findButtonClicked();
          void prevButtonClicked();
          void nextButtonClicked();
    };
    #endif   // WIDGET_H
