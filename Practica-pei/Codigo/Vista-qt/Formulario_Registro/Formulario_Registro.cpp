#include <QtGui>

#include "Formulario_Registro.h"

Formulario_Registro::Formulario_Registro(QTabWidget *parent,modelo* m,bool nuevo)
{
 	this->parent = parent;
	ui.setupUi(this);
	this->model = m;
	this->index = 0;
	val_SB_Adelante_Anterior = 1;
	val_SB_Atras_Anterior = 0;
	if(!nuevo)
	{
			this->MostrarPersona(this->model->MostrarPersona(m->getNumFicheros()-1,0));
			ui.SB_Adelante->setMaximum(100);
			ui.SB_Adelante->setMinimum(0);
			ui.SB_Adelante->setValue(0);

			ui.SB_Atras->setMaximum(100);
			ui.SB_Atras->setMinimum(0);
			ui.SB_Atras->setValue(0);
	}
	else
	{
		string titulo = "Registro " +  boost::lexical_cast<string>( index );
	 	QString aux(titulo.c_str());
	 	ui.GB_Registro->setTitle(aux);
	 	persona p;
	 	this->model->InsertarPersona(this->model->getNumFicheros()-1,p);

 		ui.SB_Adelante->setMaximum(100);
		ui.SB_Adelante->setMinimum(0);
		ui.SB_Adelante->setValue(0);

		ui.SB_Atras->setMaximum(100);
		ui.SB_Atras->setMinimum(0);
		ui.SB_Atras->setValue(0);
	}


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
	int incremento = ui.SB_Adelante->value();
	if(this->index+incremento < this->model->getNumPersonas(this->parent->currentIndex()))
	{
		this->index+=incremento;
		this->MostrarPersona(this->model->MostrarPersona(this->parent->currentIndex(),this->index));

		if(this->index+ui.SB_Adelante->value() >= this->model->getNumPersonas(this->parent->currentIndex()))
		{
			//cout<<this->model->getNumPersonas(this->parent->currentIndex()) - this->index - 1<<endl;
			ui.SB_Adelante->setValue(this->model->getNumPersonas(this->parent->currentIndex()) - this->index - 1);
		}

	}
}

void Formulario_Registro::on_Btn_Atras_clicked()
{
	int decremento = ui.SB_Atras->value();
	if(this->index-decremento >= 0)
	{
		this->index-=decremento;
		this->MostrarPersona(this->model->MostrarPersona(this->parent->currentIndex(),this->index));


		if(this->index-ui.SB_Atras->value() < 0)
		{
			ui.SB_Atras->setValue(this->index);
		}

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


		if(this->index+ui.SB_Adelante->value() >= this->model->getNumPersonas(this->parent->currentIndex()))
		{
			//cout<<this->model->getNumPersonas(this->parent->currentIndex()) - this->index - 1<<endl;
			ui.SB_Adelante->setValue(this->model->getNumPersonas(this->parent->currentIndex()) - this->index - 1);
		}

		if(this->index-ui.SB_Atras->value()<0)
		{
			ui.SB_Atras->setValue(this->index);
		}

	}
	else
	{
		persona p;
	 	this->model->InsertarPersona(this->parent->currentIndex(),p);
		this->MostrarPersona(this->model->MostrarPersona(this->parent->currentIndex(),this->index));
	}


}

void Formulario_Registro::on_SB_Adelante_valueChanged(int val)
{

	if(this->index+val < this->model->getNumPersonas(this->parent->currentIndex()))
	{
		val_SB_Adelante_Anterior = val;
	}
	else
	{
		ui.SB_Adelante->setValue(this->val_SB_Adelante_Anterior);
	}
}

void Formulario_Registro::on_SB_Atras_valueChanged(int val)
{

	if(this->index-val >= 0)
	{
		val_SB_Atras_Anterior = val;
	}
	else
	{
		ui.SB_Atras->setValue(this->val_SB_Atras_Anterior);
	}
}