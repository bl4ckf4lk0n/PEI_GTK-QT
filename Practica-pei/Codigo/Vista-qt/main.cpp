 #include <QApplication>

 #include "Plantilla.h"

 int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
     Plantilla p;
     p.show();
     return app.exec();
 }