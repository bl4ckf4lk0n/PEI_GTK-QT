#include "gestorFicheros.h"
#include "../Persona/persona.h"

int main(){
	try{
		gestorFicheros g;
		g.add("pruebaPersonas.txt");
		g.newFile("pruebaPersonas2.txt");
		std::vector<persona> v = g.getPersonas(0);
		persona nueva("hola", "micasa", "españa", "ñá", "123456789", "");
		//g.anyadirPersona(0,nueva);
		g.escribirVectorPersonas(1,v);
		v[0].setNombre("Pepito");
		g.escribirVectorPersonas(1,v);
	}catch(fileException e){
		cerr<<e.what()<<endl;
		return -1;
	}
	return 0;
}