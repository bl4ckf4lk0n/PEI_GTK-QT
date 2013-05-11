#include <libglademm/xml.h>
#include <gtkmm.h>
int main (int argc, char **argv){
	Gtk::Main kit(argc, argv);
//Load the Glade file and instiate its widgets:
	Glib::RefPtr<Gnome::Glade::Xml> refXml;
	try
	{
		refXml = Gnome::Glade::Xml::create("prueba.glade");
	}
	catch(const Gnome::Glade::XmlError& ex)
	{}
}