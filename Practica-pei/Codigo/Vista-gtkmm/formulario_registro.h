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
  void MostrarPersona(persona p);

protected:
  //Signal handlers:
	void on_btn_adelante_clicked();
	void on_btn_atras_clicked();
	void on_btn_ModRegistro_clicked();

	
  	Glib::RefPtr<Gtk::Builder> builder;
 private:
 	modelo* mod;
 	int index;
};

#endif //GTKMM_FORM_REGISTRO_H