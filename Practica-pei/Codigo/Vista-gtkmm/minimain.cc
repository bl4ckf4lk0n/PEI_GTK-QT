#include <gtkmm.h>
#include <iostream>

void on_button_clicked(Gtk::Widget* hijo) {
  Gtk::Notebook* padre = dynamic_cast<Gtk::Notebook*>(hijo->get_parent());
  int numpage = padre->page_num(*hijo);
  if(numpage != -1)
    padre->remove_page(numpage);
  else{
    std::cout<<"Ha ocurrido un error, numpage es : "<<numpage<<std::endl;
  }

}


int main (int argc, char **argv){
	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv,"org.gtkmm.examples.base");
    Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file("plantilla.glade");
    Glib::RefPtr<Gtk::Builder> builder_registro;
    Gtk::Window* pWindow = 0;
  	builder->get_widget("window1", pWindow);
  	/*Gtk::Alignment* pPag1 = 0;
  	builder->get_widget("pag1", pPag1);*/
  	Gtk::Notebook* pPestanas = 0;
  	builder->get_widget("notebook1", pPestanas);
  	

    for (int i = 0; i < 10; ++i)
    {
      // tienes que recrear el formulario si quieres que aparezca varias veces. Si no intenta asignar dos padres distintos a un mismo widget
      builder_registro = Gtk::Builder::create_from_file("formulario_registro.glade");
      Gtk::Widget* subventana = 0;
      builder_registro->get_widget("contenedor_principal", subventana);

      Glib::RefPtr<Gtk::Builder> builder_tab_con_boton = Gtk::Builder::create_from_file("tab_con_boton.glade");
      Gtk::Box* tabBoton = 0;
      builder_tab_con_boton->get_widget("contenedor", tabBoton);
      std::vector<Gtk::Widget*> tabBoton_hijos = tabBoton->get_children();
      Gtk::Label* nombre_pestana = dynamic_cast<Gtk::Label*>(tabBoton_hijos[0]);
      nombre_pestana->set_text("archivo");

      Gtk::Button* boton_pestana = dynamic_cast<Gtk::Button*>(tabBoton_hijos[1]);
      boton_pestana->signal_clicked().connect(sigc::bind<Gtk::Widget*>(sigc::ptr_fun(&on_button_clicked),subventana));

      pPestanas->append_page(*subventana, *tabBoton);
    }

  	return app->run(*pWindow);
}