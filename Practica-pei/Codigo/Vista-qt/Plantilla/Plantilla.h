 #ifndef PLANTILLA_SRC_H
 #define PLANTILLA_SRC_H

#include <iostream>
 #include <QFileDialog>
 #include <QTabWidget>
 #include "ui_Plantilla.h"
 #include "../../Modelo/modelo.h"
 #include "../Formulario_Registro/Formulario_Registro.h"
 using namespace std;

 class Plantilla : public QMainWindow
 {
     Q_OBJECT

 public:
     Plantilla(QMainWindow *parent = 0);

 private slots:
 	void on_actionAbrir_triggered();
 	void on_tabWidget_tabCloseRequested(int index);

 private:
     Ui::App_Main ui;
     std::vector<modelo> models;
     QString AbrirArchivo();
     void NuevaPestanya(QString nomPestanya,int modelo);
 };

 #endif