#ifndef GTKMM_FORM_NUEVO_H
#define GTKMM_FORM_NUEVO_H

#include <gtkmm.h>
#include "../Modelo/persona.h"

class FormularioNuevo : public Gtk::Dialog
{
public:
  FormularioNuevo(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade);
  ~FormularioNuevo(){};
  persona getNuevaPersona(){
  	return nuevaPersona;
  }

protected:
  //Signal handlers:
	void on_btn_Guardar();

  Glib::RefPtr<Gtk::Builder> builder;
private:
	persona nuevaPersona;
};

#endif //GTKMM_FORM_NUEVO_H