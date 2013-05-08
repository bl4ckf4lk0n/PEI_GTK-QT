#ifndef _MODELO_H
#define _MODELO_H

#include <iostream>
#include <string>
#include <vector>
#include "persona.h"
#include "gestorFicheros.h"
using namespace std;


class modelo
{
public:

	//Funciones canónicas
	modelo();
	modelo(const modelo&);
	~modelo();
	modelo& operator=(const modelo&);

	//Get
	std::vector<persona> getListaPersonas(int pos){return this->listaPersonas[pos];}
	int getNumPersonas(int pos){return this->listaPersonas[pos].size();}
	int getNumFicheros(){return listaPersonas.size();}

	//Funciones usuario
	void GuardarEnFichero(int pos);
	void GuardarComo(string fich, int pos);
	void Buscar(/*Datos de busqueda (Por definir)*/);
	void BorrarPersona(int pos,int id);
	void InsertarPersona(int pos, persona p);
	void LeerFichero(string file);
	void EliminarFichero(int pos);
	persona MostrarPersona(int pos,int num);
	persona* ObtenerReferenciaPersona(int pos,int num);

private:
	std::vector<std::vector<persona>> listaPersonas;
	gestorFicheros fichero;
};



#endif