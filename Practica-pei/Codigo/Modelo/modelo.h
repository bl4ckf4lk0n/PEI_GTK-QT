#ifndef _MODELO_H
#define _MODELO_H

#include <iostream>
#include <string>
#include <vector>
#include "../Persona/persona.h"
#include "gestorFicheros.h"
using namespace std;

/*class vista
{
public:
	vista();
	~vista();

};*/


class modelo
{
public:

	//Funciones canónicas
	modelo();
	modelo(std::vector<persona>/*,std::vector<vista>*/);
	modelo(const modelo&);
	~modelo();
	modelo& operator=(const modelo&);

	//Get
	std::vector<persona> getListaPersonas(){return this->listaPersonas;}
	//std::vector<vista> getListaVistas(){return this->listaVistas;}
	int getNumPersonas(){return this->numPersonas;}
	int getNumVistas(){return this->numVistas;}

	//Set
	void setListaPersonas(std::vector<persona> v){this->listaPersonas = v;}
	//void setListaVistas(std::vector<vista> v){this->listaVistas = v;}
	void setNumPersonas(int numPersonas){this->numPersonas = numPersonas;}
	void setNumVistas(int numVistas){this->numVistas = numVistas;}

	//Funciones usuario
	//void ActualizarVistas();
	void GuardarEnFichero();
	void Buscar(/*Datos de busqueda (Por definir)*/);
	void BorrarPersona(int);
	void InsertarPersona(persona);
	void LeerFichero(string file);
	persona MostrarPersona(int num);

private:
	std::vector<persona> listaPersonas;
	//std::vector<vista>	listaVistas;
	int numPersonas;
	int numVistas;
};



#endif