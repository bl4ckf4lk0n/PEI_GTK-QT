#ifndef GTKMM_PLANTILLA_H
#define GTKMM_PLANTILLA_H

#include <gtkmm.h>
#include "../Modelo/modelo.h"

class Plantilla : public Gtk::Window
{
public:
  Plantilla(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade);
  ~Plantilla(){};
  modelo mod;

protected:
  //Signal handlers:
  void on_button_quit_tab(Gtk::Widget*);
  void addTab();
  void quit();
  void abrir();
  void guardar();
  void guardarComo();
  void buscar();
  void exportar();
  void nuevoRegistro();

  Glib::RefPtr<Gtk::Builder> builder;
 private:
 	Gtk::Notebook* pPestanas;
};

#endif //GTKMM_PLANTILLA_H