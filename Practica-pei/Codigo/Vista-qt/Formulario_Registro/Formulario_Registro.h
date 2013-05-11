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
	void on_Btn_Adelante_clicked();
	void on_Btn_Atras_clicked();
	void on_Btn_ModRegistro_clicked();
	void on_Btn_BorrarRegistro_clicked();

private:
 Ui::Form_registro ui;
 QTabWidget* parent;
 modelo* model;
 int index;
};

#endif