#include <QtGui>

#include "Plantilla.h"

Plantilla::Plantilla(QMainWindow *parent)
{
    ui.setupUi(this);
    ui.tabWidget->setUpdatesEnabled(false);


    QString filename = AbrirArchivo();

    //Resetear QTabWidget
    ui.tabWidget->clear();

    if(filename != "")
    {
        QStringList list = filename.split('/');

        this->NuevaPestanya(list[list.count()-1],model.getNumFicheros()-1,false);       
    }


}

void Plantilla::on_actionAbrir_triggered()
{
    QString filename = AbrirArchivo();

    if(filename != "")
    {
        QStringList list = filename.split('/');

        this->NuevaPestanya(list[list.count()-1],model.getNumFicheros()-1,false);       
    }

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
    	return "";
    }
}

void Plantilla::NuevaPestanya(QString nomPestanya,int pos,bool nuevo)
{
    ui.tabWidget->setUpdatesEnabled(false);

    Formulario_Registro* form = new Formulario_Registro(ui.tabWidget,&model,nuevo);

    ui.tabWidget->addTab(form,nomPestanya);  
    
    ui.tabWidget->setUpdatesEnabled(true);  
}

void Plantilla::on_actionNuevo_registro_triggered()
{
    if(this->ui.tabWidget->currentIndex() != -1)
    {
        NuevoRegistro* nuevo = new NuevoRegistro(this,&model,ui.tabWidget->currentIndex());
        nuevo->exec();

        Formulario_Registro* form = (Formulario_Registro*) this->ui.tabWidget->widget(ui.tabWidget->currentIndex());

        if(!form->isVisible())
        {
            form->MostrarPersona(this->model.MostrarPersona(ui.tabWidget->currentIndex(),0));
            form->show();
        }
    }
    
}

void Plantilla::on_actionGuardar_triggered()
{
    if(this->ui.tabWidget->currentIndex() != -1)
    {
        if(model.ObtenerRuta(this->ui.tabWidget->currentIndex()) != "")
        {
            cout<<model.ObtenerRuta(this->ui.tabWidget->currentIndex())<<endl;
            model.GuardarEnFichero(this->ui.tabWidget->currentIndex());
        }
        else
        {
            this->on_actionGuardar_como_triggered();
        }

    }
}

void Plantilla::on_actionGuardar_como_triggered()
{
    if(this->ui.tabWidget->currentIndex() != -1)
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

}

void Plantilla::on_actionNuevo_archivo_triggered()
{
    model.NuevoArchivo();

    this->NuevaPestanya("Nuevo archivo",model.getNumFicheros()-1,true);   

}


void Plantilla::on_actionBuscar_triggered()
{
    if(this->ui.tabWidget->currentIndex() != -1)
    {
        Formulario_Busqueda* buscar = new Formulario_Busqueda(this,ui.tabWidget,&model,ui.tabWidget->currentIndex());
        buscar->exec();
    }
}

void Plantilla::on_actionAcerca_triggered()
{
    Acerca_de* acerca = new Acerca_de(this);
    acerca->exec();
}