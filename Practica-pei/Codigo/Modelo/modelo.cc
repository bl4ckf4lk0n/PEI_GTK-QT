#include "modelo.h"

modelo::modelo()
{}

modelo::modelo(std::vector<persona> listaPersonas, std::vector<vista> listaVistas)
{
	this->listaPersonas = listaPersonas;
	this->listaVistas = listaVistas;
}

modelo::modelo(const modelo& mod)
{
	this->listaPersonas = mod.listaPersonas;
	this->listaVistas = mod.listaVistas;
}

modelo::~modelo()
{}

modelo& modelo::operator=(const modelo& mod)
{
	if(this != &mod)
	{
		this->listaPersonas = mod.listaPersonas;
		this->listaVistas = mod.listaVistas;
	}


	return *this;
}

void modelo::ActualizarVistas()
{
	for (vista v : this->listaVistas ) 
	{
	    //Actualizar vista
	}
}

void modelo::GuardarEnFichero()
{
	//Guardar lista de personas en un fichero mediante la clase gestorFicheros.
}

void Buscar()
{
	for (persona p : this->listaPersonas ) 
	{
	    //Comparar
	}
}