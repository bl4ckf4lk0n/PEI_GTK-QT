#include "plantilla.h"
#include "formulario_registro.h"
#include <iostream>

Plantilla::Plantilla(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade)
: Gtk::Window(cobject),
  builder(refGlade)
{
	Glib::RefPtr<Gtk::Builder> builder_tab_con_boton = Gtk::Builder::create_from_file("tab_con_boton.glade");
	/*Glib::RefPtr<Gtk::Builder> builder_registro = Gtk::Builder::create_from_file("formulario_registro.glade");

	FormularioRegistro* subventana = 0;
	Gtk::Box* tabBoton = 0;
	

	
  	
  	builder_registro->get_widget_derived("contenedor_principal", subventana);
	builder_tab_con_boton->get_widget("contenedor", tabBoton);

	vector<Gtk::Widget*> tabBoton_hijos = tabBoton->get_children();
	Gtk::Label* nombre_pestana = static_cast<Gtk::Label*>(tabBoton_hijos[0]);
	nombre_pestana->set_text("*archivo nuevo");

	Gtk::Button* boton_pestana = static_cast<Gtk::Button*>(tabBoton_hijos[1]);
	boton_pestana->signal_clicked().connect(sigc::bind<Gtk::Widget*>(sigc::mem_fun(this,&Plantilla::on_button_quit_tab),subventana));

  	pPestanas->append_page(*subventana, *tabBoton);*/
	builder->get_widget("grupo_pestanas", pPestanas);
	Gtk::MenuItem* menu = 0;
	builder->get_widget("Archivo", menu);
  	vector<Gtk::Widget*> menu_hijos = menu->get_submenu()->get_children();
  	static_cast<Gtk::MenuItem*>(menu_hijos[0])->signal_activate().connect(sigc::mem_fun(this,&Plantilla::addTabNuevo));
  	static_cast<Gtk::MenuItem*>(menu_hijos[1])->signal_activate().connect(sigc::mem_fun(this,&Plantilla::abrir));
  	static_cast<Gtk::MenuItem*>(menu_hijos[2])->signal_activate().connect(sigc::mem_fun(this,&Plantilla::guardar));
  	static_cast<Gtk::MenuItem*>(menu_hijos[3])->signal_activate().connect(sigc::mem_fun(this,&Plantilla::guardarComo));
  	static_cast<Gtk::MenuItem*>(menu_hijos[4])->signal_activate().connect(sigc::mem_fun(this,&Plantilla::buscar));
  	static_cast<Gtk::MenuItem*>(menu_hijos[5])->signal_activate().connect(sigc::mem_fun(this,&Plantilla::exportar));
  	static_cast<Gtk::MenuItem*>(menu_hijos[7])->signal_activate().connect(sigc::mem_fun(this,&Plantilla::quit));

  	builder->get_widget("Registro", menu);
  	menu_hijos = menu->get_submenu()->get_children();
  	//static_cast<Gtk::MenuItem*>(menu_hijos[0])->signal_activate().connect(sigc::mem_fun(this,&Plantilla::addTabNuevo));

	builder->get_widget("fileChooser",dialogo);
	dialogo->add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
	dialogo->add_button("Seleccionar", Gtk::RESPONSE_OK);

	abrir();
}

void Plantilla::addTabNuevo(){
	mod.NuevoArchivo();
	string aux = "";
	addTab(aux);
}

void Plantilla::addTab(string nombre){
	Glib::RefPtr<Gtk::Builder> builder_registro = Gtk::Builder::create_from_file("formulario_registro.glade");
	Glib::RefPtr<Gtk::Builder> builder_tab_con_boton = Gtk::Builder::create_from_file("tab_con_boton.glade");
	
	FormularioRegistro* subventana = 0;
	Gtk::Box* tabBoton = 0;
  	
  	builder_tab_con_boton->get_widget("contenedor", tabBoton);  	
  	builder_registro->get_widget_derived("contenedor_principal", subventana);
  	subventana->setModelo(&mod);
  	builder_tab_con_boton->get_widget("contenedor", tabBoton);

	vector<Gtk::Widget*> tabBoton_hijos = tabBoton->get_children();
	Gtk::Label* nombre_pestana = static_cast<Gtk::Label*>(tabBoton_hijos[0]);
	nombre_pestana->set_line_wrap(false);
	if(nombre == ""){
		nombre_pestana->set_text("*archivo nuevo");
	}else{
		nombre_pestana->set_text(nombre);
	}

	Gtk::Button* boton_pestana = static_cast<Gtk::Button*>(tabBoton_hijos[1]);
	boton_pestana->signal_clicked().connect(sigc::bind<Gtk::Widget*>(sigc::mem_fun(this,&Plantilla::on_button_quit_tab),subventana));

  	pPestanas->append_page(*subventana, *tabBoton);
  	pPestanas->set_current_page(pPestanas->get_n_pages()-1);

  	if(nombre != ""){
  		subventana->MostrarPersona(mod.MostrarPersona(pPestanas->get_current_page(),0));
  	}
}

void Plantilla::on_button_quit_tab(Gtk::Widget* hijo)
{
  int numpage = pPestanas->page_num(*hijo);
  	if(numpage != -1){
    	pPestanas->remove_page(numpage);
    	mod.EliminarFichero(numpage);
	}else{
    	cout<<"Ha ocurrido un error, numpage es : "<<numpage<<endl;
  	}
}

void Plantilla::abrir(){
	cout<<"Función Abrir..."<<endl;
	dialogo->set_modal(true);
	int result = dialogo->run();
	string archivo = "";
	switch(result)
	{
	case(Gtk::RESPONSE_OK):
		{
			archivo = dialogo->get_filename();
		  	cout << "archivo selecccionado: " << archivo << endl;
		  	mod.LeerFichero(archivo);
		  	addTab(archivo);
		  	break;
		}
	case(Gtk::RESPONSE_CANCEL):
		{
		  cout << "Apertura cancelada" << endl;
		  break;
		}
	default:
		{
		  cout << "Ha ocurrido algo extraño" << endl;
		  break;
		}
	}
	dialogo->hide();
}

void Plantilla::getArchivo(){
	string archivo = dialogo->get_filename();
	cout<<"El archivo es:"<<archivo<<endl;
	dialogo->hide();
}

void Plantilla::guardar(){
	cout<<"Función Guardar..."<<endl;
}

void Plantilla::guardarComo(){
	cout<<"Función guardar como..."<<endl;
}

void Plantilla::buscar(){
	cout<<"Función buscar..."<<endl;
}

void Plantilla::exportar(){
	cout<<"Función Exportar..."<<endl;
}

void Plantilla::nuevoRegistro(){
	cout<<"Función nuevoRegistro, debe abrir un diálogo para crear uno nuevo, y luego guardarlo en el archivo actual ..."<<endl;
}

void Plantilla::quit(){
 	hide();
 }
