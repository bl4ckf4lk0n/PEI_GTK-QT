#include <QtGui>

#include "Formulario_Registro.h"

Formulario_Registro::Formulario_Registro(QTabWidget *parent,modelo* m)
{
 	this->parent = parent;
	ui.setupUi(this);
	this->model = m;
	this->index = 0;
	this->MostrarPersona(this->model->MostrarPersona(m->getNumFicheros()-1,0));

}

void Formulario_Registro::MostrarPersona(persona p)
{
	 //Rellenar QWidget con los datos del registro de persona pasado por parametro.
	 QString aux(p.getNombre().c_str());
	 ui.LE_Nombre->setText(aux);

	 aux = p.getDireccion().c_str();
	 ui.LE_Direccion->setText(aux);

	 aux = p.getPoblacion().c_str();;
	 ui.LE_Poblacion->setText(aux);

	 aux = p.getCodPostal().c_str();
	 ui.LE_CodPostal->setText(aux);

	 aux = p.getTelefono().c_str();
	 ui.LE_Telefono->setText(aux);

	 aux = p.getEmail().c_str();
	 ui.LE_Email->setText(aux);
  
  	 string titulo = "Registro " +  boost::lexical_cast<string>( index );
	 aux = titulo.c_str();
	 ui.GB_Registro->setTitle(aux);
}

void Formulario_Registro::on_Btn_Adelante_clicked()
{
	if(this->index+1 < this->model->getNumPersonas(this->parent->currentIndex()))
	{
		this->index++;
		this->MostrarPersona(this->model->MostrarPersona(this->parent->currentIndex(),this->index));
	}
}

void Formulario_Registro::on_Btn_Atras_clicked()
{
	if(this->index-1 >= 0)
	{
		this->index--;
		this->MostrarPersona(this->model->MostrarPersona(this->parent->currentIndex(),this->index));
	}
}

void Formulario_Registro::on_Btn_ModRegistro_clicked()
{
	persona* p = this->model->ObtenerReferenciaPersona(this->parent->currentIndex(),this->index);
	
	p->setNombre(ui.LE_Nombre->text().toStdString());
	p->setDireccion(ui.LE_Direccion->text().toStdString());
	p->setPoblacion(ui.LE_Poblacion->text().toStdString());
	p->setCodPostal(ui.LE_CodPostal->text().toStdString());
	p->setTelefono(ui.LE_Telefono->text().toStdString());
	p->setEmail(ui.LE_Email->text().toStdString());
}

void Formulario_Registro::on_Btn_BorrarRegistro_clicked()
{
	this->model->BorrarPersona(this->parent->currentIndex(),this->index);
	if(this->model->getNumPersonas(this->parent->currentIndex()) > 0)
	{
		if(this->model->getNumPersonas(this->parent->currentIndex()) <= this->index)
		{
			this->index--;
		}		
		this->MostrarPersona(this->model->MostrarPersona(this->parent->currentIndex(),this->index));
	}
	else
	{
		this->close();
	}


}