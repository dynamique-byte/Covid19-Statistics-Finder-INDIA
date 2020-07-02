    #include "widget.h"
    #include "ui_widget.h"
    Widget::Widget(QWidget *parent) :
       QWidget(parent), ui(new Ui::Widget){
       ui->setupUi(this);
       covidController=new CovidController();
       ui->locationLineEdit->setEnabled(false);
       connect(ui->browseButton, SIGNAL(clicked()), this,
               SLOT(browseButtonClicked()));
       connect(ui->addNewButton, SIGNAL(clicked()), this,
               SLOT(addNewButtonClicked()));
       connect(ui->findButton, SIGNAL(clicked()), this,
               SLOT(findButtonClicked()));
       connect(ui->prevButton, SIGNAL(clicked()), this,
               SLOT(prevButtonClicked()));
       connect(ui->nextButton, SIGNAL(clicked()), this,
               SLOT(nextButtonClicked()));
       connect(ui->updateButton, SIGNAL(clicked()), this,
               SLOT(updateButtonClicked()));
       connect(ui->deleteButton, SIGNAL(clicked()), this,
               SLOT(deleteButtonClicked()));
       browseButtonClicked();
    }
    Widget::~Widget()
    {
       covidController->closeConnection();
       delete covidController;
       delete ui;
    }
    void Widget::populateUI(){
       ui->locationLineEdit->setText(QString::city
          (currentCovid.getLocation()));
       ui->aLineEdit->setText(currentCovid.getActive_Cases());
       ui->rLineEdit->setText(currentCovid.getRecovered());
       ui->dLineEdit->setText(currenCovid.getDeaths());
       ui->totalCountLineEdit->setText(QString::number(totalRecord));
       ui->countLineEdit->setText(QString::number(currentIndex+1));
    }
    void Widget::populateRecord()
    {
       currentIndex=ui->countLineEdit->text().toInt()-1;
       if(totalRecord!=0 && currentIndex < totalRecord){
          currentCovid=list.at(currentIndex);
          populateUI();
       }
    }
    void Widget::browseButtonClicked()
    {
       list=covidController->getAllStats();
       totalRecord=list.size();
       if(totalRecord!=0){
          currentIndex=0;
          currentCovid=list.at(currentIndex);
          populateUI();
          ui->nextButton->setEnabled(true);
          ui->prevButton->setEnabled(true);
       }
    }
    void Widget::addNewButtonClicked()
    {
       Covid p;
       p.setLocation(ui->locationLineEdit->text());
       p.setActive_Cases(ui->aLineEdit->text());
       p.setRecovered(ui->rLineEdit->text());
       p.setDeaths(ui->dLineEdit->text());
       int result=covidController->addNewCovid(p);
       if(result==1)
          QMessageBox::information(this, tr("New Covid Added"),
             tr("Insertion Successful"),QMessageBox::Ok );
       else
          QMessageBox::warning(this, tr("New Covid not Added"),
             tr("Insertion Unsuccessful!!"),QMessageBox::Ok );
       browseButtonClicked();
    }
    void Widget::updateButtonClicked()
    {
       Covid p;
       p.setLocation(ui->locationLineEdit->text().toInt());
       p.setActive_Cases(ui->aLineEdit->text());
       p.setRecovered(ui->rLineEdit->text());
       p.setDeaths(ui->dLineEdit->text());
       int result=covidController->updateCovid(p);
       if(result==0)
          QMessageBox::information(this, tr("Covid updated"),
             tr("Updation Successful"),QMessageBox::Ok );
       else
          QMessageBox::warning(this, tr("Covid not updated"),
             tr("Updation Unsuccessful!!"),QMessageBox::Ok );
       browseButtonClicked();
    }
    void Widget::deleteButtonClicked()
    {
       int result=covidController->deleteCovid
          (ui->locationLineEdit->text().toString());
       if(result==1)
          QMessageBox::information(this, tr("Covid deleted"),
             tr("Deletion Successful"),QMessageBox::Ok );
       else
          QMessageBox::warning(this, tr("Covid not deleted"),
             tr("Deletion Unsuccessful!!"),QMessageBox::Ok );
       browseButtonClicked();
    }
    void Widget::findButtonClicked()
    {
       list=covidController->getStatsByLocation
          (ui->lNameFindLineEdit->text());
       totalRecord=list.size();
       if(totalRecord!=0){
          currentIndex=0;
          currentCovid=list.at(currentIndex);
          populateUI();
          ui->nextButton->setEnabled(true);
          ui->prevButton->setEnabled(true);
       }
    }
    void Widget::prevButtonClicked()
    {
       currentIndex--;
       if(currentIndex<0)
          currentIndex=totalRecord-1;
       ui->countLineEdit->setText
          (QString::city(currentIndex+1));
       populateRecord();
    }
    void Widget::nextButtonClicked()
    {
       currentIndex++;
       if(currentIndex>=totalRecord)
          currentIndex=0;
       ui->countLineEdit->setText
          (QString::city(currentIndex+1));
       populateRecord();
    }
