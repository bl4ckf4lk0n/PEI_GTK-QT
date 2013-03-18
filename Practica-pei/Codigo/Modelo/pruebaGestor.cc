#include "gestorFicheros.h"
#include "../Persona/persona.h"

int main(){
	gestorFicheros g;
	g.add("pruebaPersonas.txt");
	g.add("pruebaPersonas2.txt");
	std::vector<persona> v = g.getPersonas(0);
	persona nueva("hola", "micasa", "españa", "ñá", "123456789", "");
	//g.anyadirPersona(0,nueva);
	g.escribirVectorPersonas(1,v);
	v[0].setNombre("Pepito");
	g.escribirVectorPersonas(1,v);

	return 0;
}