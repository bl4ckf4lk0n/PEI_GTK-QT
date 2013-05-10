#ifndef _MODELO_H
#define _MODELO_H

#include <iostream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/regex.hpp>
#include <boost/regex.hpp>
#include <boost/lexical_cast.hpp>
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
	int NuevoArchivo(string fich);
	int Buscar(int pos,int exacta, int And, string nom,string dir,string codpostal,string tel, string pob,string email);
	void BorrarPersona(int pos,int id);
	void InsertarPersona(int pos, persona p);
	void LeerFichero(string file);
	void EliminarFichero(int pos);
	persona MostrarPersona(int pos,int num);
	persona* ObtenerReferenciaPersona(int pos,int num);

private:
	std::vector<std::vector<persona>> listaPersonas;
	std::vector<string> listaRutas;
	gestorFicheros fichero;
};



#endif