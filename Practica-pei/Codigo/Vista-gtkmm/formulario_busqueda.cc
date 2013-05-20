#include "formulario_busqueda.h"
FormularioBusqueda::FormularioBusqueda(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade)
: Gtk::Box(cobject),
  builder(refGlade)
{
	Gtk::Widget* subventana = 0;
      builder->get_widget("contenedor_principal", subventana);
}