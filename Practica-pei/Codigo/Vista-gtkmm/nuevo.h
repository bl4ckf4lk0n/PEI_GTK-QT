#ifndef GTKMM_FORM_NUEVO_H
#define GTKMM_FORM_NUEVO_H

#include <gtkmm.h>


class FormularioNuevo : public Gtk::Window
{
public:
  FormularioNuevo(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade);
  ~FormularioNuevo(){};

protected:
  //Signal handlers:

  Glib::RefPtr<Gtk::Builder> builder;
};

#endif //GTKMM_FORM_NUEVO_H