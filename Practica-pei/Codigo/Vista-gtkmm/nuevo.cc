#include "nuevo.h"
FormularioNuevo::FormularioNuevo(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade)
: Gtk::Window(cobject),
  builder(refGlade)
{
}