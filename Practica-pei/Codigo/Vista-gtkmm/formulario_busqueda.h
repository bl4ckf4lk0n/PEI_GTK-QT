#ifndef GTKMM_FORM_BUSQUEDA_H
#define GTKMM_FORM_BUSQUEDA_H

#include <gtkmm.h>


class FormularioBusqueda : public Gtk::Box
{
public:
  FormularioBusqueda(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade);
  ~FormularioBusqueda(){};

protected:
  //Signal handlers:

  Glib::RefPtr<Gtk::Builder> builder;
};

#endif //GTKMM_FORM_BUSQUEDA_H