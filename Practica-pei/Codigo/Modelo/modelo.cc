#include "modelo.h"

modelo::modelo()
{
	numPersonas = 0;
	numVistas = 0;
}

modelo::modelo(std::vector<persona> listaPersonas/*, std::vector<vista> listaVistas*/)
{
	this->listaPersonas = listaPersonas;
	//this->listaVistas = listaVistas;
	numPersonas = listaPersonas.size();
	//numVistas = listaVistas.size();
}

modelo::modelo(const modelo& mod)
{
	this->listaPersonas = mod.listaPersonas;
	//this->listaVistas = mod.listaVistas;
	this->numPersonas = mod.numPersonas;
	this->numVistas = mod.numVistas;
}

modelo::~modelo()
{
	this->numPersonas=0;
	this->numVistas=0;
}

modelo& modelo::operator=(const modelo& mod)
{
	if(this != &mod)
	{
		this->listaPersonas = mod.listaPersonas;
		//this->listaVistas = mod.listaVistas;
		this->numPersonas = mod.numPersonas;
		this->numVistas = mod.numVistas;
	}


	return *this;
}

/*void modelo::ActualizarVistas()
{
	for (vista v : this->listaVistas ) 
	{
	    //Actualizar vista
	}
}*/

void modelo::GuardarEnFichero(string file)
{
	//Guardar lista de personas en un fichero mediante la clase gestorFicheros.
	gestorFicheros fichero;
	fichero.add(file);
	fichero.escribirVectorPersonas(0,this->listaPersonas);
}

void modelo::Buscar()
{
	for (persona p : this->listaPersonas ) 
	{
	    //Comparar
	}
}

void modelo::BorrarPersona(int id)
{
	//int cont = 0;
	/*for (persona p : this->listaPersonas ) 
	{
	    if(p.getID() == id)
	    {
	    	break;
	    }
	    cont++;
	}*/

	listaPersonas.erase(listaPersonas.begin() + id);
	this->numPersonas--;
}

void modelo::InsertarPersona(persona p)
{
	listaPersonas.push_back(p);
	this->numPersonas++;
}

void modelo::LeerFichero(string file)
{
	gestorFicheros fichero;
	fichero.add(file);
	this->listaPersonas = fichero.getPersonas(0);
	this->numPersonas = this->listaPersonas.size();
}

persona modelo::MostrarPersona(int num)
{

	if(num < this->numPersonas)
	{
		return listaPersonas[num];
	}
	else
	{
		//Lanzar excepción
		return listaPersonas[0];
	}
}

persona* modelo::ObtenerReferenciaPersona(int num)
{

	if(num < this->numPersonas)
	{
		return &listaPersonas[num];
	}
	else
	{
		//Lanzar excepción
		return &listaPersonas[0];
	}
}