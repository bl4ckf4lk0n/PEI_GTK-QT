#include "plantilla.h"


Plantilla::Plantilla(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade)
: Gtk::Window(cobject),
  builder(refGlade)
{
	Glib::RefPtr<Gtk::Builder> builder_tab_con_boton = Gtk::Builder::create_from_file("tab_con_boton.glade");
	builder->get_widget("grupo_pestanas", pPestanas);
	Gtk::MenuItem* menu = 0;
	builder->get_widget("Archivo", menu);
  	vector<Gtk::Widget*> menu_hijos = menu->get_submenu()->get_children();
  	static_cast<Gtk::MenuItem*>(menu_hijos[0])->signal_activate().connect(sigc::mem_fun(this,&Plantilla::addTabNuevo));
  	static_cast<Gtk::MenuItem*>(menu_hijos[1])->signal_activate().connect(sigc::mem_fun(this,&Plantilla::abrir));
  	static_cast<Gtk::MenuItem*>(menu_hijos[2])->signal_activate().connect(sigc::mem_fun(this,&Plantilla::guardar));
  	static_cast<Gtk::MenuItem*>(menu_hijos[3])->signal_activate().connect(sigc::mem_fun(this,&Plantilla::guardarComo));
  	static_cast<Gtk::MenuItem*>(menu_hijos[4])->signal_activate().connect(sigc::mem_fun(this,&Plantilla::buscar));
  	static_cast<Gtk::MenuItem*>(menu_hijos[5])->signal_activate().connect(sigc::mem_fun(this,&Plantilla::exportar));
  	static_cast<Gtk::MenuItem*>(menu_hijos[7])->signal_activate().connect(sigc::mem_fun(this,&Plantilla::quit));

  	builder->get_widget("Registro", menu);
  	menu_hijos = menu->get_submenu()->get_children();
  	static_cast<Gtk::MenuItem*>(menu_hijos[0])->signal_activate().connect(sigc::mem_fun(this,&Plantilla::nuevoRegistro));

  	builder->get_widget("Ayuda", menu);
  	menu_hijos = menu->get_submenu()->get_children();
  	static_cast<Gtk::MenuItem*>(menu_hijos[0])->signal_activate().connect(sigc::mem_fun(this,&Plantilla::acercaDe));

  	Glib::RefPtr<Gtk::Builder> builder_acerca_de = Gtk::Builder::create_from_file("Acerca_de.glade");
	builder_acerca_de->get_widget("AcercaDe",dialogo_acercaDe);
	dialogo_acercaDe->add_button(Gtk::Stock::OK, Gtk::RESPONSE_OK);

	Glib::RefPtr<Gtk::Builder> builder_confirmacion = Gtk::Builder::create_from_file("estas_seguro.glade");
	builder_confirmacion->get_widget("estasSeguro",dialogo_confirmacion);
	dialogo_confirmacion->add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
	dialogo_confirmacion->add_button(Gtk::Stock::OK, Gtk::RESPONSE_OK);

	builder->get_widget("fileChooser",dialogo);
	dialogo->add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
	dialogo->add_button("Seleccionar", Gtk::RESPONSE_OK);

	abrir();
	/*if(pPestanas->get_n_pages() == 0){
		menu_hijos[0]->set_sensitive(false);
	}*/
}

void Plantilla::addTabNuevo(){
	mod.NuevoArchivo();
	string aux = "";
	addTab(aux);
	persona p;
	mod.InsertarPersona(pPestanas->get_current_page(),p);
}

void Plantilla::addTab(string nombre){
	Glib::RefPtr<Gtk::Builder> builder_registro = Gtk::Builder::create_from_file("formulario_registro.glade");
	Glib::RefPtr<Gtk::Builder> builder_tab_con_boton = Gtk::Builder::create_from_file("tab_con_boton.glade");
	
	FormularioRegistro* subventana = 0;
	Gtk::Box* tabBoton = 0;
  	
  	builder_tab_con_boton->get_widget("contenedor", tabBoton);  	
  	builder_registro->get_widget_derived("contenedor_principal", subventana);
  	subventana->setModelo(&mod);
  	builder_tab_con_boton->get_widget("contenedor", tabBoton);

	vector<Gtk::Widget*> tabBoton_hijos = tabBoton->get_children();
	Gtk::Label* nombre_pestana = static_cast<Gtk::Label*>(tabBoton_hijos[0]);
	nombre_pestana->set_line_wrap(false);
	if(nombre == ""){
		nombre_pestana->set_text("*archivo nuevo");
	}else{
		nombre_pestana->set_text(nombre);
	}

	Gtk::Button* boton_pestana = static_cast<Gtk::Button*>(tabBoton_hijos[1]);
	boton_pestana->signal_clicked().connect(sigc::bind<Gtk::Widget*>(sigc::mem_fun(this,&Plantilla::on_button_quit_tab),subventana));

  	pPestanas->append_page(*subventana, *tabBoton);
  	pPestanas->set_current_page(pPestanas->get_n_pages()-1);

  	if(nombre != ""){
  		subventana->MostrarPersona();
  	}
}

void Plantilla::on_button_quit_tab(Gtk::Widget* hijo)
{
	int continuar = dialogo_confirmacion->run();
	dialogo_confirmacion->hide();
	if(continuar == Gtk::RESPONSE_OK){
	  	int numpage = pPestanas->page_num(*hijo);
	  	if(numpage != -1){
	    	pPestanas->remove_page(numpage);
	    	mod.EliminarFichero(numpage);
		}else{
	    	cout<<"Ha ocurrido un error, numpage es : "<<numpage<<endl;
	  	}
  	}
}

void Plantilla::abrir(){
	cout<<"Función Abrir..."<<endl;
	dialogo->set_action(Gtk::FILE_CHOOSER_ACTION_OPEN);
	dialogo->set_modal(true);
	int result = dialogo->run();
	string archivo = "";
	switch(result)
	{
	case(Gtk::RESPONSE_OK):
		{
			archivo = dialogo->get_filename();
		  	cout << "archivo selecccionado: " << archivo << endl;
		  	mod.LeerFichero(archivo);
		  	addTab(archivo);
		  	break;
		}
	case(Gtk::RESPONSE_CANCEL):
		{
		  cout << "Apertura cancelada" << endl;
		  break;
		}
	default:
		{
		  cout << "Ha ocurrido algo extraño" << endl;
		  break;
		}
	}
	dialogo->hide();
}

void Plantilla::getArchivo(){
	string archivo = dialogo->get_filename();
	cout<<"El archivo es:"<<archivo<<endl;
	dialogo->hide();
}

void Plantilla::guardar(){
	cout<<"Función Guardar..."<<endl;
	if(mod.ObtenerRuta(pPestanas->get_current_page()) != "")
    {
        cout<<mod.ObtenerRuta(pPestanas->get_current_page())<<endl;
        mod.GuardarEnFichero(pPestanas->get_current_page());
    }
    else
    {
        guardarComo();
    }
}

void Plantilla::guardarComo(){
	cout<<"Función guardar como..."<<endl;
	dialogo->set_action(Gtk::FILE_CHOOSER_ACTION_SAVE);
	dialogo->set_modal(true);
	int result = dialogo->run();
	string archivo = "";
	if(result == Gtk::RESPONSE_OK){
			archivo = dialogo->get_filename();
		  	cout << "archivo selecccionado: " << archivo << endl;
		  	mod.GuardarComo(archivo,pPestanas->get_current_page());

		  	// cambiamos el nombre de la pestaña al nombre del archivo
  			static_cast<Gtk::Label*>(static_cast<Gtk::Box*>(pPestanas->get_tab_label(*(pPestanas->get_children()[0])))->get_children()[0])->set_text(archivo);
		}
	
	
	dialogo->hide();
}

void Plantilla::buscar(){
	cout<<"Función buscar..."<<endl;
	if(pPestanas->get_n_pages() > 0){
		Glib::RefPtr<Gtk::Builder> builder_busqueda = Gtk::Builder::create_from_file("formulario_busqueda.glade");
		FormularioBusqueda* dialog = 0;
		builder_busqueda->get_widget_derived("ventana_busqueda",dialog);
		dialog->add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
		
		int result = 0;
		int continuar = 0;
		while(result != Gtk::RESPONSE_OK && continuar != Gtk::RESPONSE_OK){
			result = dialog->run();
			if(result == Gtk::RESPONSE_OK){
				int buscar = mod.Buscar(pPestanas->get_current_page(),dialog->getExacta(), dialog->getAnd(), dialog->getNombre(),dialog->getDireccion(),dialog->getCodigoPostal(),dialog->getTelefono(), dialog->getPoblacion(),dialog->getCorreo());
				if(buscar > 0)
					addTab("Resultados de búsqueda");
				else
					cout<<"Error en la búsqueda"<<endl;
			}else{
				continuar = dialogo_confirmacion->run();
				dialogo_confirmacion->hide();
			}
		}
		dialog->hide();
			
	}
}

void Plantilla::exportar(){
	cout<<"Función Exportar..."<<endl;
	dialogo->set_action(Gtk::FILE_CHOOSER_ACTION_SAVE);
	dialogo->set_modal(true);
	int result = dialogo->run();
	string archivo = "";
	if(result == Gtk::RESPONSE_OK){
		archivo = dialogo->get_filename();
	  	cout << "archivo selecccionado: " << archivo << endl;
	  	mod.ExportarCSV(archivo,pPestanas->get_current_page());
	}
	dialogo->hide();
}

void Plantilla::nuevoRegistro(){
	if(pPestanas->get_n_pages() > 0){
		cout<<"Función nuevoRegistro, debe abrir un diálogo para crear uno nuevo, y luego guardarlo en el archivo actual ..."<<endl;
		Glib::RefPtr<Gtk::Builder> builder_nuevo = Gtk::Builder::create_from_file("nuevo.glade");
		FormularioNuevo* dialog = 0;
		builder_nuevo->get_widget_derived("ventana_nuevo",dialog);
		dialog->add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
		
		int result = 0;
		int continuar = 0;
		while(result != Gtk::RESPONSE_OK && continuar != Gtk::RESPONSE_OK){
			result = dialog->run();
			if(result == Gtk::RESPONSE_OK){
				mod.InsertarPersona(pPestanas->get_current_page(), dialog->getNuevaPersona());
			}else{
				continuar = dialogo_confirmacion->run();
				dialogo_confirmacion->hide();
			}
		}
		dialog->hide();
	}
}

void Plantilla::acercaDe(){
	dialogo_acercaDe->run();
	dialogo_acercaDe->hide();
}

void Plantilla::quit(){
 	hide();
 }
