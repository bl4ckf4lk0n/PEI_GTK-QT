#ifndef FORMNUEVOREGISTRO_H
#define FORMNUEVOREGISTRO_H

#include <QMainWindow>
#include "ui_NuevoRegistro.h"
#include "../../Modelo/modelo.h"


class NuevoRegistro : public QDialog
{
 Q_OBJECT

public:
 NuevoRegistro(QMainWindow* parent,modelo* m,int pos);

private slots:

 /*Guarda un nuevo registro en la pestaña correspondiente, añadiendola al vector de personas correspondiente del modelo*/
 void on_Btn_GuardarRegistro_clicked();

 void closeEvent(QCloseEvent *event);

private:
 Ui::Dialog_NuevoRegistro ui;
 QMainWindow* parent;
 modelo* model;
 int pestanya;
};

#endif