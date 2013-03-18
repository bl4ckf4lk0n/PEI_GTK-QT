#ifndef _PERSONA_H
#define _PERSONA_H

#include <iostream>
#include <string>
using namespace std;

class persona
{
public:

	//Funciones canónicas
	persona(){}
	persona(string nombre, string direccion, string poblacion, string cod_postal, string telefono, string email);
	persona(const persona&);
	~persona();
	persona& operator=(const persona&);

	//Get
	int getID(){return id;}
	string getNombre(){return nombre;}
	string getDireccion(){return direccion;}
	string getPoblacion(){return poblacion;}
	string getCodPostal(){return cod_postal;}
	string getTelefono(){return telefono;}
	string getEmail(){return email;}

	//Set
	void setID(int id){this->id = id;}
	void setNombre(string nombre){this->nombre = nombre;}
	void setDireccion(string direccion){this->direccion = direccion;}
	void setPoblacion(string poblacion){this->poblacion = poblacion;}
	void setCodPostal(string cod_postal){this->cod_postal = cod_postal;}
	void setTelefono(string telefono){this->telefono = telefono;}
	void setEmail(string email){this->email = email;}

private:
	int id;
	string nombre;
	string direccion;
	string poblacion;
	string cod_postal;
	string telefono;
	string email;
};



#endif