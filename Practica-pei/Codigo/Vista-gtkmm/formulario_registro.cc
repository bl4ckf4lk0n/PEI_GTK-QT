#include "formulario_registro.h"
FormularioRegistro::FormularioRegistro(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade)
: Gtk::Box(cobject),
  builder(refGlade)
{
		Gtk::Widget* subventana = 0;
		builder->get_widget("contenedor_principal", subventana);
		index = 0;
		Gtk::Button* bt_adelante,* bt_atras,* bt_modificar;
		builder->get_widget("bt_adelante",bt_adelante);
		builder->get_widget("bt_atras",bt_atras);
		builder->get_widget("ModificarRegistro",bt_modificar);
		bt_adelante->signal_clicked().connect(sigc::mem_fun(this,&FormularioRegistro::on_btn_adelante_clicked));
		bt_atras->signal_clicked().connect(sigc::mem_fun(this,&FormularioRegistro::on_btn_atras_clicked));
		bt_modificar->signal_clicked().connect(sigc::mem_fun(this,&FormularioRegistro::on_btn_ModRegistro_clicked));

}

void FormularioRegistro::MostrarPersona(persona pers){
	Gtk::Entry* tb_nombre;
	builder->get_widget("tb_nombre",tb_nombre);
	tb_nombre->set_text(pers.getNombre());
}

void FormularioRegistro::on_btn_adelante_clicked(){
	Gtk::SpinButton* sp_adelante;
	builder->get_widget("sp_adelante",sp_adelante);
	int valor = sp_adelante->get_value();

	if(index + valor < mod->getNumPersonas(static_cast<Gtk::Notebook*>(get_parent())->get_current_page())){
		index += valor;
	}else{
		cerr<<"Error en el valor"<<endl;
	}

	persona personaFinal = mod->MostrarPersona(static_cast<Gtk::Notebook*>(get_parent())->get_current_page(),index);
	MostrarPersona(personaFinal);
}
void FormularioRegistro::on_btn_atras_clicked(){
	Gtk::SpinButton* sp_atras;
	builder->get_widget("sp_atras",sp_atras);
	int valor = sp_atras->get_value();

	if(index - valor >= 0){
		index -= valor;
	}else{
		cerr<<"Error en el valor"<<endl;
	}

	persona personaFinal = mod->MostrarPersona(static_cast<Gtk::Notebook*>(get_parent())->get_current_page(),index);
	MostrarPersona(personaFinal);
}

void FormularioRegistro::on_btn_ModRegistro_clicked(){
	persona* p = this->mod->ObtenerReferenciaPersona(static_cast<Gtk::Notebook*>(get_parent())->get_current_page(),this->index);
	Gtk::Entry* tb_nombre;
	builder->get_widget("tb_nombre",tb_nombre);
	p->setNombre(tb_nombre->get_text());

	Gtk::Entry* tb_dir;
	builder->get_widget("tb_direccion",tb_dir);
	p->setDireccion(tb_dir->get_text());

	Gtk::Entry* tb_poblacion;
	builder->get_widget("tb_poblacion",tb_poblacion);
	p->setPoblacion(tb_poblacion->get_text());

	Gtk::Entry* tb_codigopostal;
	builder->get_widget("tb_codigopostal",tb_codigopostal);
	p->setCodPostal(tb_codigopostal->get_text());

	Gtk::Entry* tb_telefono;
	builder->get_widget("tb_telefono",tb_telefono);
	p->setTelefono(tb_telefono->get_text());

	Gtk::Entry* tb_correo;
	builder->get_widget("tb_correo",tb_correo);
	p->setEmail(tb_correo->get_text());
}