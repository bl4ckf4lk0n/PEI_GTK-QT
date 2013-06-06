#include "nuevo.h"
FormularioNuevo::FormularioNuevo(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade)
: Gtk::Dialog(cobject),
  builder(refGlade)
{
	Gtk::Button* bt_guardar = 0;
	builder->get_widget("bt_guardar", bt_guardar);
	bt_guardar->signal_clicked().connect(sigc::mem_fun(this,&FormularioNuevo::on_btn_Guardar));
}

void FormularioNuevo::on_btn_Guardar(){
	Gtk::Entry* tb_nombre;
	builder->get_widget("tb_nombre",tb_nombre);
	nuevaPersona.setNombre(tb_nombre->get_text());

	Gtk::Entry* tb_dir;
	builder->get_widget("tb_dir",tb_dir);
	nuevaPersona.setDireccion(tb_dir->get_text());

	Gtk::Entry* tb_poblacion;
	builder->get_widget("tb_poblacion",tb_poblacion);
	nuevaPersona.setPoblacion(tb_poblacion->get_text());

	Gtk::Entry* tb_codigopostal;
	builder->get_widget("tb_codigopostal",tb_codigopostal);
	nuevaPersona.setCodPostal(tb_codigopostal->get_text());

	Gtk::Entry* tb_telefono;
	builder->get_widget("tb_telefono",tb_telefono);
	nuevaPersona.setTelefono(tb_telefono->get_text());

	Gtk::Entry* tb_correo;
	builder->get_widget("tb_correo",tb_correo);
	nuevaPersona.setEmail(tb_correo->get_text());

	response(Gtk::RESPONSE_OK);
}