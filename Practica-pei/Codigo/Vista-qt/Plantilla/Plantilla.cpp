#include <QtGui>

#include "Plantilla.h"

Plantilla::Plantilla(QMainWindow *parent)
{
ui.setupUi(this);
ui.tabWidget->setUpdatesEnabled(false);


QString filename = AbrirArchivo();

QStringList list = filename.split('/');

//Resetear QTabWidget
ui.tabWidget->clear();

this->NuevaPestanya(list[list.count()-1],this->models.size()-1);

}

void Plantilla::on_actionAbrir_triggered()
{
QString filename = AbrirArchivo();

QStringList list = filename.split('/');

this->NuevaPestanya(list[list.count()-1],this->models.size()-1);
}

void Plantilla::on_tabWidget_tabCloseRequested(int index)
{
    ui.tabWidget->removeTab(index);
}

QString Plantilla::AbrirArchivo()
{
    QString filename = QFileDialog::getOpenFileName( 
    this, 
    tr("Abrir archivo"), 
    QDir::currentPath(), 
    tr("Document files (*.txt);;All files (*.*)") );

    if( !filename.isNull() )
    {
      modelo model;
      model.LeerFichero(filename.toStdString());
      this->models.push_back(model);
      return filename;
    }
    else
    {
    	return NULL;
    }
}

void Plantilla::NuevaPestanya(QString nomPestanya,int modelo)
{

    //Añadir QWidget Formulario_Registro con el 1º registro del modelo leido
    Formulario_Registro* form = new Formulario_Registro(this,models[modelo]);

    ui.tabWidget->addTab(form,nomPestanya);
    ui.tabWidget->setUpdatesEnabled(true);
}