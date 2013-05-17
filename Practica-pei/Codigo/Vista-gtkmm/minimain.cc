#include <gtkmm.h>
int main (int argc, char **argv){
	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv,"org.gtkmm.examples.base");
    Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file("plantilla.glade");
    Glib::RefPtr<Gtk::Builder> builder_registro = Gtk::Builder::create_from_file("formulario_registro.glade");
    Gtk::Window* pWindow = 0;
  	builder->get_widget("window1", pWindow);
  	/*Gtk::Alignment* pPag1 = 0;
  	builder->get_widget("pag1", pPag1);*/
  	Gtk::Notebook* pPestanas = 0;
  	builder->get_widget("notebook1", pPestanas);
  	

  	Gtk::Widget* subventana = 0;
  	builder_registro->get_widget("contenedor_principal", subventana);

  	// tienes que recrear el formulario si quieres que aparezca varias veces. Si no intenta asignar dos padres distintos a un mismo widget
  	builder_registro = Gtk::Builder::create_from_file("formulario_registro.glade");
  	Gtk::Widget* subventana2 = 0;
  	builder_registro->get_widget("contenedor_principal", subventana2);
  	//pPag1->add(*subventana);

  	Gtk::Label* nombre_pestana = new Gtk::Label();
  	nombre_pestana->set_text("prueba");
  	pPestanas->append_page(*subventana, *nombre_pestana);
  	Gtk::Label* nombre_pestana2 = new Gtk::Label();
  	nombre_pestana2->set_text("prueba2");
  	pPestanas->append_page(*subventana2, *nombre_pestana2);
  	delete nombre_pestana;
  	delete nombre_pestana2;

  	return app->run(*pWindow);
}