#ifndef GTKMM_FORM_BUSQUEDA_H
#define GTKMM_FORM_BUSQUEDA_H

#include <gtkmm.h>

using std::string;

class FormularioBusqueda : public Gtk::Dialog
{
public:
  FormularioBusqueda(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade);
  ~FormularioBusqueda(){};
  string getNombre(){return nombre;}
  string getCodigoPostal(){return codigopostal;}
  string getDireccion(){return direccion;}
  string getTelefono(){return telefono;}
  string getPoblacion(){return poblacion;}
  string getCorreo(){return correo;}
  bool getExacta(){return busquedaExacta;}
  bool getAnd(){return busquedaAnd;}

protected:
  //Signal handlers:
	void on_btn_Buscar_click();

  Glib::RefPtr<Gtk::Builder> builder;
private:
	string nombre, codigopostal,direccion, telefono, poblacion, correo;
	bool busquedaExacta, busquedaAnd;
};

#endif //GTKMM_FORM_BUSQUEDA_H