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
	/*Obtiene el vector de personas especificado por 'pos'*/
	std::vector<persona> getListaPersonas(int pos){return this->listaPersonas[pos];}

	/*Obtiene el numero de personas del vector correspondiente, especificado por 'pos'*/
	int getNumPersonas(int pos){return this->listaPersonas[pos].size();}

	/*Obtiene el numero de ficheros abiertos en la ejecución del programa*/
	int getNumFicheros(){return listaPersonas.size();}

	//Funciones usuario
	/*Realiza una llamada al gestor de ficheros para grabar las modificaciones realizadas en el7
	  fichero correspondiente*/
	void GuardarEnFichero(int pos);
	
	/*Guarda los datos de una pestaña en un nuevo fichero especificado por el usuario*/
	void GuardarComo(string fich, int pos);

	/*Añade un nuevo vector de personas vacio al modelo*/
	int NuevoArchivo();

	/*Realiza un filtrado de registros a partir de los datos especificados por el usuario*/
	int Buscar(int pos,bool exacta, bool And, string nom,string dir,string codpostal,string tel, string pob,string email);
	
	/*Borra una persona del vector de personas correspondiente*/
	void BorrarPersona(int pos,int id);

	/*Inserta una persona en el vector de personas especificado*/
	void InsertarPersona(int pos, persona p);

	/*Realiza una lectura, mediante el metodo del gestor de ficheros, de un fichero*/
	void LeerFichero(string file);

	/*Elimina un vector de personas de la ejecución del programa*/
	void EliminarFichero(int pos);

	/*Devuelve los datos de un registro, especificado por el usuario*/
	persona MostrarPersona(int pos,int num);

	/*Devuelve una referencia a una persona*/
	persona* ObtenerReferenciaPersona(int pos,int num);

	/*Obtiene la ruta del archivo especificado*/
	string ObtenerRuta(int pos);

	/*Llama al metodo del gestor de ficheros para realizar la exportación en CVS*/
	void ExportarCSV(string fich,int pos);

private:
	std::vector<std::vector<persona>> listaPersonas;
	std::vector<string> listaRutas;
	gestorFicheros fichero;
};



#endif