#ifndef GTKMM_FORM_REGISTRO_H
#define GTKMM_FORM_REGISTRO_H

#include <gtkmm.h>


class FormularioRegistro : public Gtk::Box
{
public:
  FormularioRegistro(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade);
  ~FormularioRegistro(){};

protected:
  //Signal handlers:

  Glib::RefPtr<Gtk::Builder> builder;
};

#endif //GTKMM_FORM_REGISTRO_H