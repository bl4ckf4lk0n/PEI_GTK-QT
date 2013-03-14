#include "persona.h"

persona::persona(string nombre, string direccion, string poblacion, string cod_postal, int telefono, string email)
{
	this->nombre = nombre;
	this->direccion = direccion;
	this->poblacion = poblacion;
	this->cod_postal = cod_postal;
	this->telefono = telefono;
	this->email = email;
}

persona::persona(const persona& mod)
{
	this->nombre = mod.nombre;
	this->direccion = mod.direccion;
	this->poblacion = mod.poblacion;
	this->cod_postal = mod.cod_postal;
	this->telefono = mod.telefono;
	this->email = mod.email;
}

persona::~persona()
{
	this->nombre = "";
	this->direccion = "";
	this->poblacion = "";
	this->cod_postal = "";
	this->telefono = -1;
	this->email = "";	
}

persona& persona::operator=(const persona& mod)
{
	if(this != &mod)
	{
		this->nombre = mod.nombre;
		this->direccion = mod.direccion;
		this->poblacion = mod.poblacion;
		this->cod_postal = mod.cod_postal;
		this->telefono = mod.telefono;
		this->email = mod.email;	
	}


	return *this;
}