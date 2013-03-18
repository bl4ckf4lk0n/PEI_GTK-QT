#include "gestorFicheros.h"
#include "../Persona/persona.h"

int main(){
	gestorFicheros g;
	g.add("pruebaPersonas.txt");
	g.getPersonas(0);
	persona nueva("hola", "micasa", "españa", "ñá", "123456789", "");
	g.anyadirPersona(0,nueva);

	return 0;
}