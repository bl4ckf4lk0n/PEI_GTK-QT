#ifndef GESTOR_FICHEROS
#define GESTOR_FICHEROS

#include <iostream>
#include <fstream>
#include <vector>

#include "fileException.h"
#include "../Persona/persona.h"

using namespace std;

class gestorFicheros
{
private:
	vector<string> files;
	void escribirPersona(ofstream & salida, persona nuevaPersona);

public:
	gestorFicheros(){}
	~gestorFicheros(){}

	int add(string file) ;
	int newFile(string file);
	vector<string> getFicheros();


	vector<persona> getPersonas(int indiceFichero);

	void escribirVectorPersonas(int indiceFichero, vector<persona> nuevasPersonas);
	void anyadirPersona(int indiceFichero, persona nuevaPersona);

	/* data */
};
#endif