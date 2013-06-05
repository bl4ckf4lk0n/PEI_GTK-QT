#ifndef GTKMM_FORM_REGISTRO_H
#define GTKMM_FORM_REGISTRO_H

#include <gtkmm.h>
#include "../Modelo/modelo.h"


class FormularioRegistro : public Gtk::Box
{
public:
  FormularioRegistro(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade);
  ~FormularioRegistro(){};
  void setModelo(modelo* _mod){mod = _mod;}
  void MostrarPersona(persona p);

protected:
  //Signal handlers:


	
  	Glib::RefPtr<Gtk::Builder> builder;
 private:
 	modelo* mod;
 	int index;
};

#endif //GTKMM_FORM_REGISTRO_H