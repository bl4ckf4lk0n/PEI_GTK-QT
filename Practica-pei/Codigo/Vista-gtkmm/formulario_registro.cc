#include "formulario_registro.h"
FormularioRegistro::FormularioRegistro(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade)
: Gtk::Box(cobject),
  builder(refGlade)
{
	Gtk::Widget* subventana = 0;
      builder->get_widget("contenedor_principal", subventana);
}