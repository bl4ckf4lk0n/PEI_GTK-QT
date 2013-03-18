#ifndef GESTOR_FICHEROS
#define GESTOR_FICHEROS

#include <iostream>
#include <fstream>
#include <vector>


#include "../Persona/persona.h"

using namespace std;

class gestorFicheros
{
private:
	vector<string> files;

public:
	gestorFicheros(){}
	~gestorFicheros(){}

	void add(string file);
	vector<string> getFicheros();


	vector<persona> getPersonas(int indiceFichero);

	//void escribirPersona(int indiceFichero, persona nuevaPersona);

	/* data */
};
#endif