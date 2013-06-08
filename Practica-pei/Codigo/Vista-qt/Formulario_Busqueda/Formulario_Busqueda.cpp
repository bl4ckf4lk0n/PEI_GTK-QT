#include <QtGui>

#include "Formulario_Busqueda.h"

Formulario_Busqueda::Formulario_Busqueda(QMainWindow* parent,QTabWidget* tab,modelo* m,int pos)
{
	this->parent = parent;
	ui.setupUi(this);
	this->model = m;
	this->pestanya = pos;
	this->tab = tab;
}

void Formulario_Busqueda::on_Btn_Buscar_clicked()
{
	bool exacta = !ui.CB_TipoBusqueda->currentIndex();
	bool And = !ui.CB_TipoBusqueda_2->currentIndex();

	string nom = ui.LE_Nombre->text().toStdString();
	string dir = ui.LE_Direccion->text().toStdString();
	string pob = ui.LE_Poblacion->text().toStdString();
	string cod = ui.LE_CodPostal->text().toStdString();
	string tel = ui.LE_Telefono->text().toStdString();
	string email = ui.LE_Email->text().toStdString();


	int pos = model->Buscar(this->pestanya,exacta,And,nom,dir,cod,tel,pob,email);
	if(pos != -1)
	{
		this->NuevaPestanya("Busqueda "+tab->tabText(this->pestanya),pos,false);
		this->hide();
	}
	else
	{
		QMessageBox alerta(this);
	    alerta.addButton("Cerrar",QMessageBox::RejectRole);
	    alerta.setIcon(QMessageBox::Information);
	    alerta.setText("No se han encontrado coincidencias");
	    alerta.exec();
	}


}

void Formulario_Busqueda::NuevaPestanya(QString nomPestanya,int pos,bool nuevo)
{
    tab->setUpdatesEnabled(false);

    Formulario_Registro* form = new Formulario_Registro(tab,model,nuevo);

    tab->addTab(form,nomPestanya);  
    
    tab->setUpdatesEnabled(true);  
}

void Formulario_Busqueda::closeEvent(QCloseEvent *event)
{
	QMessageBox confirmacion(this);
    confirmacion.addButton("Sí",QMessageBox::ApplyRole);
    confirmacion.addButton("No",QMessageBox::NoRole);
    confirmacion.setIcon(QMessageBox::Question);
    confirmacion.setText("¿Cerrar la ventana de búsqueda?");
    int ret = confirmacion.exec();	

    if(ret == 0)
    {
    	event->accept();
    }
    else
    {
    	event->ignore();
    }
}