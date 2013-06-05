#include "formulario_registro.h"
FormularioRegistro::FormularioRegistro(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade)
: Gtk::Box(cobject),
  builder(refGlade)
{
		Gtk::Widget* subventana = 0;
		builder->get_widget("contenedor_principal", subventana);
		index = 0;
}

void FormularioRegistro::MostrarPersona(persona pers){
	Gtk::Entry* tb_nombre;
	builder->get_widget("tb_nombre",tb_nombre);
	tb_nombre->set_text("AAA");
}
