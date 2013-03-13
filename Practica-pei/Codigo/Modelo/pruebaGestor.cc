#include "gestorFicheros.h"

int main(){
	gestorFicheros g;
	g.add("pruebaPersonas.txt");
	g.getPersonas(0);

	return 0;
}