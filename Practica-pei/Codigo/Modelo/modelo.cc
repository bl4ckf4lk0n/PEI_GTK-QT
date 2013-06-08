#include "modelo.h"

modelo::modelo()
{
}


modelo::modelo(const modelo& mod)
{
	this->listaPersonas = mod.listaPersonas;
}

modelo::~modelo()
{
}

modelo& modelo::operator=(const modelo& mod)
{
	if(this != &mod)
	{
		this->listaPersonas = mod.listaPersonas;
	}


	return *this;
}


void modelo::GuardarEnFichero(int pos)
{
	//Guardar lista de personas en un fichero mediante la clase gestorFicheros.
	if(listaRutas[pos] != "")
	{
		int ruta = fichero.obtenerPosicion(listaRutas[pos]);
		fichero.escribirVectorPersonas(ruta,this->listaPersonas[pos]);		
	}
}

void modelo::GuardarComo(string fich, int pos)
{
	//Guardar lista de personas en un fichero mediante la clase gestorFicheros.
	try{
		int f = fichero.newFile(fich);
		fichero.escribirVectorPersonas(f,this->listaPersonas[pos]);
		fichero.modificarFichero(fich,pos);
		this->listaRutas[pos] = fich;
		fichero.removeFile(f);
	}catch(fileException& e){
		/*cerr<<e.what()<<endl;
		cerr<<"0"<<endl;
		if(listaRutas[pos] == "")
		{
			pos = fichero.add(fich);
		}
		fichero.modificarFichero(fich,pos);
		cerr<<"1"<<endl;
		fichero.escribirVectorPersonas(pos,this->listaPersonas[pos]);
		cerr<<"2"<<endl;
		this->listaRutas[pos] = fich;
		cerr<<"Se ha modificado el fichero que ya existia"<<endl;*/
		fichero.modificarFichero(fich,pos);
		fichero.escribirVectorPersonas(pos,this->listaPersonas[pos]);
		this->listaRutas[pos] = fich;
	}
}

int modelo::NuevoArchivo()
{
	std::vector<persona> nuevaLista;
	listaPersonas.push_back(nuevaLista);
	listaRutas.push_back("");
	fichero.anyadirAvector("");

	return listaPersonas.size() - 1;
}

/*
	Devuelve un vector de personas filtrado por los campos especificados
*/
int modelo::Buscar(int pos,bool exacta, bool And, string nom,string dir,string codpostal,string tel, string pob,string email)
{
	std::vector<persona> resultados;

	bool insertar = true;
	for (persona p : this->listaPersonas[pos] )
	{
		insertar = true;
		//Busqueda anidada con AND
	    if(And)
	    {
	    	//Coincidencia exacta
	    	if(exacta)
	    	{
	    		if(nom != "")
	    		{
	    			if(p.getNombre() != nom)
	    			{
	    				insertar = false;
	    				continue;
	    			}
	    		}

	    		if(dir != "")
	    		{
	    			if(p.getDireccion() != dir)
	    			{
	    				insertar = false;
	    				continue;
	    			}
	    		}

	    		if(codpostal != "")
	    		{
	    			if(p.getCodPostal() != codpostal)
	    			{
	    				insertar = false;
	    				continue;
	    			}
	    		}

	    		if(tel != "")
	    		{
	    			if(p.getTelefono() != tel)
	    			{
	    				insertar = false;
	    				continue;
	    			}
	    		}

	    		if(pob != "")
	    		{
	    			if(p.getPoblacion() != pob)
	    			{
	    				insertar = false;
	    				continue;
	    			}
	    		}

	    		if(email != "")
	    		{
	    			if(p.getEmail() != email)
	    			{
	    				insertar = false;
	    				continue;
	    			}
	    		}

	    		if(insertar)
	    		{
	    			resultados.push_back(p);
	    		}
	    	}
	    	else //Busqueda con subcadenas
	    	{

	    		if(nom != "")
	    		{
	    			if(p.getNombre().find(nom) == string::npos)
	    			{
	    				insertar = false;
	    				continue;
	    			}
	    		}

	    		if(dir != "")
	    		{

	    			if(p.getDireccion().find(dir) == string::npos)
	    			{
	    				insertar = false;
	    				continue;
	    			}
	    		}

	    		if(codpostal != "")
	    		{
	    			if(p.getCodPostal().find(codpostal) == string::npos)
	    			{
	    				insertar = false;
	    				continue;
	    			}
	    		}

	    		if(tel != "")
	    		{

	    			if(p.getTelefono().find(tel) == string::npos)
	    			{
	    				insertar = false;
	    				continue;
	    			}
	    		}

	    		if(pob != "")
	    		{

	    			if(p.getPoblacion().find(pob) == string::npos)
	    			{
	    				insertar = false;
	    				continue;
	    			}
	    		}

	    		if(email != "")
	    		{
	    			if(p.getEmail().find(email) == string::npos)
	    			{
	    				insertar = false;
	    				continue;
	    			}
	    		}

	    		if(insertar)
	    		{
	    			resultados.push_back(p);
	    		}	    		
	    	}
	    }
	    else //Busqueda anidada con OR
	    {
	    	//Coincidencia exacta
	    	if(exacta)
	    	{
				if(nom != "")
	    		{
	    			if(p.getNombre() == nom)
	    			{
	    				resultados.push_back(p);
	    				continue;
	    			}
	    		}

	    		if(dir != "")
	    		{
	    			if(p.getDireccion() == dir)
	    			{
	    				resultados.push_back(p);
	    				continue;
	    			}
	    		}

	    		if(codpostal != "")
	    		{
	    			if(p.getCodPostal() == codpostal)
	    			{
	    				resultados.push_back(p);
	    				continue;
	    			}
	    		}

	    		if(tel != "")
	    		{
	    			if(p.getTelefono() == tel)
	    			{
	    				resultados.push_back(p);
	    				continue;
	    			}
	    		}

	    		if(pob != "")
	    		{
	    			if(p.getPoblacion() == pob)
	    			{
	    				resultados.push_back(p);
	    				continue;
	    			}
	    		}

	    		if(email != "")
	    		{
	    			if(p.getEmail() == email)
	    			{
	    				resultados.push_back(p);
	    				continue;
	    			}
	    		}
	    	}
	    	else //Busqueda con subcadena
	    	{
				if(nom != "")
	    		{
	    			if(p.getNombre().find(nom) != string::npos)
	    			{
	    				resultados.push_back(p);
	    				continue;
	    			}
	    		}

	    		if(dir != "")
	    		{
	    			if(p.getDireccion().find(dir) != string::npos)
	    			{
	    				resultados.push_back(p);
	    				continue;
	    			}
	    		}

	    		if(codpostal != "")
	    		{
	    			if(p.getCodPostal().find(codpostal) != string::npos)
	    			{
	    				resultados.push_back(p);
	    				continue;
	    			}
	    		}

	    		if(tel != "")
	    		{
	    			if(p.getTelefono().find(tel) != string::npos)
	    			{
	    				resultados.push_back(p);
	    				continue;
	    			}
	    		}

	    		if(pob != "")
	    		{
	    			if(p.getPoblacion().find(pob) != string::npos)
	    			{
	    				resultados.push_back(p);
	    				continue;
	    			}
	    		}

	    		if(email != "")
	    		{
	    			if(p.getEmail().find(email) != string::npos)
	    			{
	    				resultados.push_back(p);
	    				continue;
	    			}
	    		}
	    	}
	    }
	}

	if(resultados.size() > 0)
	{
		this->listaPersonas.push_back(resultados);
		this->listaRutas.push_back("");
		return listaPersonas.size()-1;
	}
	else
	{
		return -1;
	}
	
}

void modelo::BorrarPersona(int pos,int id)
{
	listaPersonas[pos].erase(listaPersonas[pos].begin() + id);
}

void modelo::InsertarPersona(int pos,persona p)
{
	listaPersonas[pos].push_back(p);
}


void modelo::LeerFichero(string file)
{
	int pos = this->fichero.add(file);
	try
	{
		this->listaPersonas.push_back(fichero.getPersonas(pos));
	}
	catch(fileException fexc)
	{
		throw fexc;
	}
	
	this->listaRutas.push_back(file);
}

void modelo::EliminarFichero(int pos)
{
	/*if(listaRutas[pos] != "")
	{
		int ruta = fichero.obtenerPosicion(listaRutas[pos]);
		fichero.removeFile(ruta);		
	}*/
	fichero.removeFile(pos);
	listaPersonas.erase(listaPersonas.begin()+pos);
	listaRutas.erase(listaRutas.begin()+pos);
}

persona modelo::MostrarPersona(int pos,int num)
{

	if(num < this->getNumPersonas(pos))
	{
		return listaPersonas[pos][num];
	}
	else
	{
		//Lanzar excepción
		return listaPersonas[pos][0];
	}
}

persona* modelo::ObtenerReferenciaPersona(int pos,int num)
{
	if(num < this->getNumPersonas(pos))
	{	
		return &listaPersonas[pos][num];
	}
	else
	{
		//Lanzar excepción
		return &listaPersonas[pos][0];
	}
}

string modelo::ObtenerRuta(int pos)
{
	return listaRutas[pos];
}

void modelo::ExportarCSV(string fich, int pos)
{
	fichero.exportarCSV(fich,this->listaPersonas[pos]);
}