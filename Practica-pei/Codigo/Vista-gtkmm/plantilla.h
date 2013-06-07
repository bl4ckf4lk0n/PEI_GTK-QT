#ifndef GTKMM_PLANTILLA_H
#define GTKMM_PLANTILLA_H

#include <gtkmm.h>
#include <iostream>
#include "../Modelo/modelo.h"
#include "formulario_registro.h"
#include "nuevo.h"
#include "formulario_busqueda.h"


class Plantilla : public Gtk::Window
{
public:
  Plantilla(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade);
  ~Plantilla(){};
  modelo mod;

protected:
  //Signal handlers:
  void on_button_quit_tab(Gtk::Widget*);
  void addTabNuevo();
  void addTab(string);
  void quit();
  void abrir();
  void guardar();
  void guardarComo();
  void buscar();
  void exportar();
  void nuevoRegistro();
  void getArchivo();
  void acercaDe();

  Glib::RefPtr<Gtk::Builder> builder;
 private:
 	Gtk::Notebook* pPestanas;
  Gtk::FileChooserDialog* dialogo;
  Gtk::Dialog* dialogo_acercaDe;
  Gtk::Dialog* dialogo_confirmacion;
};

#endif //GTKMM_PLANTILLA_H
