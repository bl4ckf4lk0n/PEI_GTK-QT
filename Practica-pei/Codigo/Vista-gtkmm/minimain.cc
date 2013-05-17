#include <gtkmm.h>
int main (int argc, char **argv){
	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv,"org.gtkmm.examples.base");
    Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file("plantilla.glade");
    Glib::RefPtr<Gtk::Builder> builder_registro = Gtk::Builder::create_from_file("formulario_registro.glade");
    Gtk::Window* pWindow = 0;
  	builder->get_widget("window1", pWindow);
  	Gtk::Alignment* pPag1 = 0;
  	builder->get_widget("pag1", pPag1);

  	Gtk::Widget* subventana = 0;
  	builder_registro->get_widget("box1", subventana);
  	pPag1->add(*subventana);

  	return app->run(*pWindow);
}