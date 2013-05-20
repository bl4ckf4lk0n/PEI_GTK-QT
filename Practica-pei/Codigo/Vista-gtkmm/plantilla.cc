#include "plantilla.h"
#include "formulario_registro.h"
#include <iostream>

Plantilla::Plantilla(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade)
: Gtk::Window(cobject),
  builder(refGlade)
{
	Glib::RefPtr<Gtk::Builder> builder_tab_con_boton = Gtk::Builder::create_from_file("tab_con_boton.glade");
	Glib::RefPtr<Gtk::Builder> builder_registro = Gtk::Builder::create_from_file("formulario_registro.glade");

	FormularioRegistro* subventana = 0;
	Gtk::Box* tabBoton = 0;
	Gtk::MenuItem* menu = 0;

	builder->get_widget("Archivo", menu);
  	builder->get_widget("grupo_pestanas", pPestanas);
  	builder_registro->get_widget_derived("contenedor_principal", subventana);
	builder_tab_con_boton->get_widget("contenedor", tabBoton);

	std::vector<Gtk::Widget*> tabBoton_hijos = tabBoton->get_children();
	Gtk::Label* nombre_pestana = dynamic_cast<Gtk::Label*>(tabBoton_hijos[0]);
	nombre_pestana->set_text("archivo");

	Gtk::Button* boton_pestana = dynamic_cast<Gtk::Button*>(tabBoton_hijos[1]);
	boton_pestana->signal_clicked().connect(sigc::bind<Gtk::Widget*>(sigc::mem_fun(this,&Plantilla::on_button_quit_tab),subventana));

  	pPestanas->append_page(*subventana, *tabBoton);

  	std::vector<Gtk::Widget*> menu_hijos = menu->get_submenu()->get_children();
  	dynamic_cast<Gtk::MenuItem*>(menu_hijos[0])->signal_activate().connect(sigc::mem_fun(this,&Plantilla::addTab));
  	dynamic_cast<Gtk::MenuItem*>(menu_hijos[1])->signal_activate().connect(sigc::mem_fun(this,&Plantilla::abrir));
  	dynamic_cast<Gtk::MenuItem*>(menu_hijos[2])->signal_activate().connect(sigc::mem_fun(this,&Plantilla::guardar));
  	dynamic_cast<Gtk::MenuItem*>(menu_hijos[3])->signal_activate().connect(sigc::mem_fun(this,&Plantilla::guardarComo));
  	dynamic_cast<Gtk::MenuItem*>(menu_hijos[4])->signal_activate().connect(sigc::mem_fun(this,&Plantilla::buscar));
  	dynamic_cast<Gtk::MenuItem*>(menu_hijos[5])->signal_activate().connect(sigc::mem_fun(this,&Plantilla::exportar));
  	dynamic_cast<Gtk::MenuItem*>(menu_hijos[7])->signal_activate().connect(sigc::mem_fun(this,&Plantilla::quit));

  	builder->get_widget("Registro", menu);
  	menu_hijos = menu->get_submenu()->get_children();
  	dynamic_cast<Gtk::MenuItem*>(menu_hijos[0])->signal_activate().connect(sigc::mem_fun(this,&Plantilla::addTab));
}

void Plantilla::addTab(){
	Glib::RefPtr<Gtk::Builder> builder_registro = Gtk::Builder::create_from_file("formulario_registro.glade");
	Glib::RefPtr<Gtk::Builder> builder_tab_con_boton = Gtk::Builder::create_from_file("tab_con_boton.glade");
	
	FormularioRegistro* subventana = 0;
	Gtk::Box* tabBoton = 0;
  	
  	builder_tab_con_boton->get_widget("contenedor", tabBoton);  	
  	builder_registro->get_widget_derived("contenedor_principal", subventana);
  	builder_tab_con_boton->get_widget("contenedor", tabBoton);

	std::vector<Gtk::Widget*> tabBoton_hijos = tabBoton->get_children();
	Gtk::Label* nombre_pestana = dynamic_cast<Gtk::Label*>(tabBoton_hijos[0]);
	nombre_pestana->set_text("archivo");

	Gtk::Button* boton_pestana = dynamic_cast<Gtk::Button*>(tabBoton_hijos[1]);
	boton_pestana->signal_clicked().connect(sigc::bind<Gtk::Widget*>(sigc::mem_fun(this,&Plantilla::on_button_quit_tab),subventana));

  	pPestanas->append_page(*subventana, *tabBoton);
}

void Plantilla::on_button_quit_tab(Gtk::Widget* hijo)
{
  int numpage = pPestanas->page_num(*hijo);
  	if(numpage != -1){
    	pPestanas->remove_page(numpage);
	}else{
    	std::cout<<"Ha ocurrido un error, numpage es : "<<numpage<<std::endl;
  	}
}

void Plantilla::abrir(){
	std::cout<<"Función Abrir..."<<std::endl;
}

void Plantilla::guardar(){
	std::cout<<"Función Guardar..."<<std::endl;
}

void Plantilla::guardarComo(){
	std::cout<<"Función guardar como..."<<std::endl;
}

void Plantilla::buscar(){
	std::cout<<"Función buscar..."<<std::endl;
}

void Plantilla::exportar(){
	std::cout<<"Función Exportar..."<<std::endl;
}

void Plantilla::nuevoRegistro(){
	std::cout<<"Función nuevoRegistro, debe abrir un diálogo para crear uno nuevo, y luego guardarlo en el archivo actual ..."<<std::endl;
}

void Plantilla::quit(){
 	hide();
 }
