#ifndef FORMREG_H
#define FORMREG_H

#include <boost/lexical_cast.hpp>
#include "ui_FormularioRegistro.h"
#include "../../Modelo/modelo.h"
#include "../../Modelo/persona.h"


class Formulario_Registro : public QWidget
{
 Q_OBJECT

public:
 Formulario_Registro(QTabWidget *parent,modelo* m,bool nuevo);
 void MostrarPersona(persona p);

private slots:
	/*Permite avanzar tantos registros como indica el SpinBox de avance. Si se diera el caso de que
	  avanza mas registros de los habidos, no hace nada*/
	void on_Btn_Adelante_clicked();

	/*Permite retroceder tantos registros como indica el SpinBox de retroceso. Si se diera el caso de que
	  retrocede mas registros a partir del primero, no hace nada*/
	void on_Btn_Atras_clicked();

	/*Modifica el registro con los datos especificados por el usuario, en el modelo*/
	void on_Btn_ModRegistro_clicked();

	/*Elimina un registro tanto de la pestaña correspondiente como del vector correspondiente en el modelo*/
	void on_Btn_BorrarRegistro_clicked();

	/*Comprueba si el valor del SpinBox de avance no se sale del rango*/
	void on_SB_Adelante_valueChanged(int val);

	/*Comprueba si el valor del SpinBox de retroceso no se sale del rango*/
	void on_SB_Atras_valueChanged(int val);

private:
 Ui::Form_registro ui;
 QTabWidget* parent;
 modelo* model;
 int index;
 int val_SB_Adelante_Anterior;
 int val_SB_Atras_Anterior;
};

#endif