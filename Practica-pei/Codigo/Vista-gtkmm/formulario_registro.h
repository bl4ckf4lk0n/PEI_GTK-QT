#ifndef GTKMM_FORM_REGISTRO_H
#define GTKMM_FORM_REGISTRO_H

#include <gtkmm.h>
#include <iostream>
#include "../Modelo/modelo.h"

using namespace std;

class FormularioRegistro : public Gtk::Box
{
public:
  FormularioRegistro(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade);
  ~FormularioRegistro(){};
  void setModelo(modelo* _mod){mod = _mod;}
  void MostrarPersona();
  
  
  void MostrarPersonaVacia();

protected:
  //Signal handlers:
	void on_btn_adelante_clicked();
	void on_btn_atras_clicked();
	void on_btn_ModRegistro_clicked();
  void on_btn_BorrarRegistro_clicked();
  void on_tb_changed();

	void MostrarPersona(persona p);
  	Glib::RefPtr<Gtk::Builder> builder;
 private:
 	modelo* mod;
 	int index;
  Gtk::Dialog* dialogo_confirmacion;
  bool modificado;
  Gtk::Entry *tb_nombre,* tb_dir,* tb_poblacion,* tb_codigopostal,* tb_telefono,* tb_correo;
};

#endif //GTKMM_FORM_REGISTRO_H