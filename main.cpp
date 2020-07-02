    #include "widget.h"
    #include <QApplication>
    #include <QStyleFactory>
    using namespace std;
    int main(int argc, char *argv[])
    {
       QApplication a(argc, argv);
       QApplication::setStyle
          (QStyleFactory::create("fusion"));
       Widget w;
       w.show();
       return a.exec();
    }
