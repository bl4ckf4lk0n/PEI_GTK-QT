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

    this->NuevaPestanya(list[list.count()-1],model.getNumFicheros()-1);

}

void Plantilla::on_actionAbrir_triggered()
{
    QString filename = AbrirArchivo();

    QStringList list = filename.split('/');

    this->NuevaPestanya(list[list.count()-1],model.getNumFicheros()-1);
}

void Plantilla::on_tabWidget_tabCloseRequested(int index)
{
    model.EliminarFichero(index);
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
      model.LeerFichero(filename.toStdString());
      return filename;
    }
    else
    {
    	return NULL;
    }
}

void Plantilla::NuevaPestanya(QString nomPestanya,int pos)
{

    Formulario_Registro* form = new Formulario_Registro(ui.tabWidget,&model);

    ui.tabWidget->addTab(form,nomPestanya);
    ui.tabWidget->setUpdatesEnabled(true);
}

void Plantilla::on_actionNuevo_registro_triggered()
{
    NuevoRegistro* nuevo = new NuevoRegistro(this,&model,ui.tabWidget->currentIndex());
    nuevo->exec();
}

void Plantilla::on_actionGuardar_triggered()
{
    model.GuardarEnFichero(this->ui.tabWidget->currentIndex());
}

void Plantilla::on_actionGuardar_como_triggered()
{
    QString filename = QFileDialog::getSaveFileName( 
    this, 
    tr("Guardar como..."), 
    QDir::currentPath(), 
    tr("Document files (*.txt);;All files (*.*)") );

    if( !filename.isNull() )
    {
      model.GuardarComo(filename.toStdString(),this->ui.tabWidget->currentIndex());
      QStringList list = filename.split('/');
      ui.tabWidget->setTabText(this->ui.tabWidget->currentIndex(),list[list.count()-1]);
    }
}