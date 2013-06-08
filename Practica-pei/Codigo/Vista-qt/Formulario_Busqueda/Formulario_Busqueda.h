#ifndef BUSQUEDA_SRC_H
#define BUSQUEDA_SRC_H

#include <QMainWindow>
#include <QMessageBox>
#include "ui_Formulario_Busqueda.h"
#include "../../Modelo/modelo.h"
#include "../../Modelo/persona.h"
#include "../Formulario_Registro/Formulario_Registro.h"

using namespace std;

class Formulario_Busqueda : public QDialog
{
 Q_OBJECT

public:
 Formulario_Busqueda(QMainWindow* parent,QTabWidget* tab,modelo* m,int pos);

private slots:
 /*Realiza una llamada al metodo de buscar del modelo pasandoles todos los datos para la búsqueda*/
 void on_Btn_Buscar_clicked();
 void closeEvent(QCloseEvent *event);

private:
 Ui::Dialog_Busqueda ui;
 QMainWindow* parent;
 QTabWidget* tab;
 modelo* model;
 int pestanya;

 /*Abre una nueva pestaña con los resultados de la búsqueda*/
 void NuevaPestanya(QString nomPestanya,int pos,bool nuevo);
};


#endif