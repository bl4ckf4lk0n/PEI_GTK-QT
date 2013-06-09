#include "formulario_registro.h"
FormularioRegistro::FormularioRegistro(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade)
: Gtk::Box(cobject),
  builder(refGlade)
{
	index = 0;
	modificado = false;

	Gtk::Widget* subventana = 0;
	builder->get_widget("contenedor_principal", subventana);

	Gtk::Button* bt_adelante,* bt_atras,* bt_modificar,* bt_borrar;
	builder->get_widget("bt_adelante",bt_adelante);
	builder->get_widget("bt_atras",bt_atras);
	builder->get_widget("ModificarRegistro",bt_modificar);
	builder->get_widget("BorrarRegistro",bt_borrar);

	bt_adelante->signal_clicked().connect(sigc::mem_fun(this,&FormularioRegistro::on_btn_adelante_clicked));
	bt_atras->signal_clicked().connect(sigc::mem_fun(this,&FormularioRegistro::on_btn_atras_clicked));
	bt_modificar->signal_clicked().connect(sigc::mem_fun(this,&FormularioRegistro::on_btn_ModRegistro_clicked));
	bt_borrar->signal_clicked().connect(sigc::mem_fun(this,&FormularioRegistro::on_btn_BorrarRegistro_clicked));

	builder->get_widget("tb_nombre",tb_nombre);
	builder->get_widget("tb_direccion",tb_dir);
	builder->get_widget("tb_poblacion",tb_poblacion);
	builder->get_widget("tb_codigopostal",tb_codigopostal);
	builder->get_widget("tb_telefono",tb_telefono);
	builder->get_widget("tb_correo",tb_correo);

	tb_nombre->signal_changed().connect(sigc::mem_fun(this,&FormularioRegistro::on_tb_changed));
	tb_dir->signal_changed().connect(sigc::mem_fun(this,&FormularioRegistro::on_tb_changed));
	tb_poblacion->signal_changed().connect(sigc::mem_fun(this,&FormularioRegistro::on_tb_changed));
	tb_codigopostal->signal_changed().connect(sigc::mem_fun(this,&FormularioRegistro::on_tb_changed));
	tb_telefono->signal_changed().connect(sigc::mem_fun(this,&FormularioRegistro::on_tb_changed));
	tb_correo->signal_changed().connect(sigc::mem_fun(this,&FormularioRegistro::on_tb_changed));

	builder->get_widget("sp_adelante",sp_adelante);
	builder->get_widget("sp_atras",sp_atras);

	sp_adelante->signal_changed().connect(sigc::mem_fun(this,&FormularioRegistro::on_sp_adelante_changed));
	sp_atras->signal_changed().connect(sigc::mem_fun(this,&FormularioRegistro::on_sp_atras_changed));


	Glib::RefPtr<Gtk::Builder> builder_confirmacion = Gtk::Builder::create_from_file("estas_seguro.glade");
	builder_confirmacion->get_widget("estasSeguro",dialogo_confirmacion);
	dialogo_confirmacion->add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
	dialogo_confirmacion->add_button(Gtk::Stock::OK, Gtk::RESPONSE_OK);
}

void FormularioRegistro::MostrarPersonaVacia(){
	if(index < 0){
		persona p;
		mod->InsertarPersona(static_cast<Gtk::Notebook*>(get_parent())->get_current_page(),p);
		index = 0;
	}	

	tb_nombre->set_text("");	
	tb_dir->set_text("");	
	tb_poblacion->set_text("");	
	tb_codigopostal->set_text("");	
	tb_telefono->set_text("");	
	tb_correo->set_text("");
}

void FormularioRegistro::MostrarPersona(persona pers){	
	tb_nombre->set_text(pers.getNombre());
	tb_dir->set_text(pers.getDireccion());
	tb_poblacion->set_text(pers.getPoblacion());
	tb_codigopostal->set_text(pers.getCodPostal());
	tb_telefono->set_text(pers.getTelefono());
	tb_correo->set_text(pers.getEmail());
}

void FormularioRegistro::on_btn_adelante_clicked(){
	int continuar = Gtk::RESPONSE_OK;
	if(modificado){
		continuar = dialogo_confirmacion->run();
		dialogo_confirmacion->hide();
	}
	if(continuar == Gtk::RESPONSE_OK){
		int valor = sp_adelante->get_value();

		if(index + valor < mod->getNumPersonas(static_cast<Gtk::Notebook*>(get_parent())->get_current_page())){
			index += valor;
		}else{
			cerr<<"[I] Valor fuera del listado de registros. Ignorando"<<endl;
		}
		MostrarPersona();
		ActualizarLabelRegistro();
	}
}
void FormularioRegistro::on_btn_atras_clicked(){
	int continuar = Gtk::RESPONSE_OK;
	if(modificado){
		continuar = dialogo_confirmacion->run();
		dialogo_confirmacion->hide();
	}
	if(continuar == Gtk::RESPONSE_OK){
		int valor = sp_atras->get_value();

		if(index - valor >= 0){
			index -= valor;
		}else{
			cerr<<"[I] Valor fuera del listado de registros. Ignorando"<<endl;
		}
		MostrarPersona();

		ActualizarLabelRegistro();

	}
}
void FormularioRegistro::ActualizarLabelRegistro(){
	Gtk::Label* nombreRegistro = 0;
	builder->get_widget("lb_numRegistro", nombreRegistro);
	string nombre = nombreRegistro->get_text();
	vector<string> aux;
	boost::algorithm::split(aux,nombre,boost::is_any_of(" "));
	nombre = aux[0] + " " + boost::lexical_cast<string,int>(index);
	nombreRegistro->set_text(nombre);
}


void FormularioRegistro::on_btn_ModRegistro_clicked(){
	persona* p = this->mod->ObtenerReferenciaPersona(static_cast<Gtk::Notebook*>(get_parent())->get_current_page(),this->index);	

	p->setNombre(tb_nombre->get_text());
	p->setDireccion(tb_dir->get_text());
	p->setPoblacion(tb_poblacion->get_text());
	p->setCodPostal(tb_codigopostal->get_text());
	p->setTelefono(tb_telefono->get_text());
	p->setEmail(tb_correo->get_text());

	modificado = false;
}

void FormularioRegistro::on_btn_BorrarRegistro_clicked(){
	int continuar = Gtk::RESPONSE_OK;
	//if(modificado){
		continuar = dialogo_confirmacion->run();
		dialogo_confirmacion->hide();
	//}
	if(continuar == Gtk::RESPONSE_OK){
		if(mod->getNumPersonas(static_cast<Gtk::Notebook*>(get_parent())->get_current_page()) > 0){
			mod->BorrarPersona(static_cast<Gtk::Notebook*>(get_parent())->get_current_page(),index);
			if(index == mod->getNumPersonas(static_cast<Gtk::Notebook*>(get_parent())->get_current_page()))
				index--;
			if(index != -1)
				MostrarPersona();
			else{
				MostrarPersonaVacia();
			}

		}
	}
}

void FormularioRegistro::MostrarPersona(){
	if(mod->getNumPersonas(static_cast<Gtk::Notebook*>(get_parent())->get_current_page()) > 0){
		persona personaFinal = mod->MostrarPersona(static_cast<Gtk::Notebook*>(get_parent())->get_current_page(),index);
		MostrarPersona(personaFinal);
	}else{
		MostrarPersonaVacia();
	}
	sp_adelante->get_adjustment()->set_upper(mod->getNumPersonas(static_cast<Gtk::Notebook*>(get_parent())->get_current_page())-index-1);
	sp_atras->get_adjustment()->set_upper(index);
	modificado = false;
}

void FormularioRegistro::on_tb_changed(){
	modificado = true;
}

void FormularioRegistro::on_sp_adelante_changed(){
	int valor = sp_adelante->get_value();
	int valorMaximo = mod->getNumPersonas(static_cast<Gtk::Notebook*>(get_parent())->get_current_page());
	if(index + valor >= valorMaximo){
		sp_adelante->set_value(valorMaximo - index-1);
	}
}

void FormularioRegistro::on_sp_atras_changed(){
	int valor = sp_atras->get_value();
	if( index - valor < 0){
		sp_atras->set_value(index);
	}
}