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
	fichero.escribirVectorPersonas(pos,this->listaPersonas[pos]);
}

void modelo::GuardarComo(string fich, int pos)
{
	//Guardar lista de personas en un fichero mediante la clase gestorFicheros.
	int f = fichero.newFile(fich);
	fichero.escribirVectorPersonas(f,this->listaPersonas[pos]);
	fichero.modificarFichero(fich,pos);
}

void modelo::Buscar()
{
	/*for (persona p : this->listaPersonas ) 
	{
	    //Comparar
	}*/
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
	this->listaPersonas.push_back(fichero.getPersonas(pos));
}

void modelo::EliminarFichero(int pos)
{
	listaPersonas.erase(listaPersonas.begin()+pos);
	fichero.removeFile(pos);
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