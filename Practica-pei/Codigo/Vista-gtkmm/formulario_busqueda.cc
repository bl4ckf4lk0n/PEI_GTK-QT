#include "formulario_busqueda.h"
FormularioBusqueda::FormularioBusqueda(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade)
: Gtk::Dialog(cobject),
  builder(refGlade)
{
	Gtk::Button* bt_Buscar = 0;
	builder->get_widget("bt_Buscar", bt_Buscar);
	bt_Buscar->signal_clicked().connect(sigc::mem_fun(this,&FormularioBusqueda::on_btn_Buscar_click));
}

void FormularioBusqueda::on_btn_Buscar_click(){
	Gtk::Entry* tb_nombre;
	builder->get_widget("tb_nombre",tb_nombre);
	nombre = tb_nombre->get_text();

	Gtk::Entry* tb_direccion;
	builder->get_widget("tb_direccion",tb_direccion);
	direccion = tb_direccion->get_text();

	Gtk::Entry* tb_poblacion;
	builder->get_widget("tb_poblacion",tb_poblacion);
	poblacion = tb_poblacion->get_text();

	Gtk::Entry* tb_codigopostal;
	builder->get_widget("tb_codigopostal",tb_codigopostal);
	codigopostal = tb_codigopostal->get_text();

	Gtk::Entry* tb_telefono;
	builder->get_widget("tb_telefono",tb_telefono);
	telefono = tb_telefono->get_text();

	Gtk::Entry* tb_correo;
	builder->get_widget("tb_correo",tb_correo);
	correo = tb_correo->get_text();

	Gtk::ComboBox* cb_tipoBusqueda;
	builder->get_widget("cb_tipoBusqueda",cb_tipoBusqueda);
	int select = cb_tipoBusqueda->get_active_row_number();
	busquedaExacta = (select == 0);

	Gtk::ComboBox* cb_conector;
	builder->get_widget("cb_conector",cb_conector);
	select = cb_conector->get_active_row_number();
	busquedaAnd = (select == 0);

	response(Gtk::RESPONSE_OK);
}