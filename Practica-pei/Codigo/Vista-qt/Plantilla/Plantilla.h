#ifndef PLANTILLA_SRC_H
#define PLANTILLA_SRC_H

#include <iostream>
#include <QFileDialog>
#include <QTabWidget>
#include "ui_Plantilla.h"
#include "../../Modelo/modelo.h"
#include "../Formulario_Registro/Formulario_Registro.h"
#include "../NuevoRegistro/NuevoRegistro.h"
#include "../Formulario_Busqueda/Formulario_Busqueda.h"
#include "../Acerca_de/Acerca_de.h"
using namespace std;

class Plantilla : public QMainWindow
{
 Q_OBJECT

public:
 Plantilla(QMainWindow *parent = 0);

private slots:
	/*Slot que permite abrir un nuevo archivo*/
	void on_actionAbrir_triggered();

	/*Slot que nos permite crear un nuevo registro en la pestaña seleccionada actualmente.
	  Si no hay pestañas seleccionadas no hace nada.*/
	void on_actionNuevo_registro_triggered();

	/*Slot que nos permite guardar los cambios realizados en los registros de una pestaña.
	  Si el archivo no se ha guardado anteriormente en el disco realiza la misma función que GuardarComo...*/
	void on_actionGuardar_triggered();

	/*Slot que nos permite guardar en disco los cambios realizados sobre los registros de una pestaña*/
	void on_actionGuardar_como_triggered();

	/*Cierra una pestaña del widget de pestañas, eliminando tambien el vector de personas correspondiente en el modelo*/
	void on_tabWidget_tabCloseRequested(int index);

	/*Crea una nueva pestaña con un registro vacio, de manera que podamos crear de cero un nuevo archivo*/
	void on_actionNuevo_archivo_triggered();

	/*Abre el dialogo de búsqueda para la pestaña actual*/
	void on_actionBuscar_triggered();

	/*Abre el dialogo de Acerca de*/
	void on_actionAcerca_triggered();

	/*Permite exportar los registros de una pestaña en formato CSV*/
	void on_actionExportar_triggered();


private:
 Ui::App_Main ui;
 modelo model;
 /*Muestra un selector de archivos con el que abrir un archivo y mostrar los datos
   en el programa.*/
 QString AbrirArchivo();

 /*Añade una nueva pestaña al widget QTabWidget y crea un nuevo widget Formulario_Registro que es
   añadido a la pestaña*/
 void NuevaPestanya(QString nomPestanya,int pos,bool nuevo);
};

#endif