#ifndef GESTOR_FICHEROS
#define GESTOR_FICHEROS

#include <iostream>
#include <fstream>
#include <vector>

#include "fileException.h"
#include "persona.h"

using namespace std;

class gestorFicheros
{
public:
	gestorFicheros(){}
	~gestorFicheros(){}

	int add(string file);
	int newFile(string file);
	void removeFile(int pos);
	vector<string> getFicheros();
	void modificarFichero(string file,int pos);
	int obtenerPosicion(string file);
	void exportarCSV(string file,vector<persona> nuevasPersonas);


	vector<persona> getPersonas(int indiceFichero);

	void escribirVectorPersonas(int indiceFichero, vector<persona> nuevasPersonas);
	int anyadirAvector(string file);
private:
	vector<string> files;
	void escribirPersona(ofstream & salida, persona nuevaPersona);
};
#endif