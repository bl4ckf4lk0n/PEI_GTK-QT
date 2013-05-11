#include <QtGui>

#include "NuevoRegistro.h"

NuevoRegistro::NuevoRegistro(QMainWindow* parent,modelo* m,int pos)
{
	this->parent = parent;
	ui.setupUi(this);
	this->model = m;
	this->pestanya = pos;
}

void NuevoRegistro::on_Btn_GuardarRegistro_clicked()
{
	persona p;
	
	p.setNombre(ui.LE_NombreNew->text().toStdString());
	p.setDireccion(ui.LE_DireccionNew->text().toStdString());
	p.setPoblacion(ui.LE_PoblacionNew->text().toStdString());
	p.setCodPostal(ui.LE_CodPostalNew->text().toStdString());
	p.setTelefono(ui.LE_TelefonoNew->text().toStdString());
	p.setEmail(ui.LE_EmailNew->text().toStdString());

	model->InsertarPersona(this->pestanya,p);

	this->close();
}