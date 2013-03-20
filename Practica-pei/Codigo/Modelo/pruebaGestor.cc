#include "gestorFicheros.h"
#include "../Persona/persona.h"

int main(){
	try{
		gestorFicheros g;
		g.add("ErrorPruebaPersonas.txt");
		g.add("pruebaPersonas.txt");
		std::vector<persona> v = g.getPersonas(0);
		g.newFile("pruebaPersonas2.txt");
		

		v = g.getPersonas(1);
		persona nueva("hola", "micasa", "españa", "ñá", "123456789", "");
		//g.anyadirPersona(0,nueva);
		g.escribirVectorPersonas(2,v);
		v[1].setNombre("Pepito");
		g.escribirVectorPersonas(2,v);
		
	}catch(fileException e){
		cerr<<e.what()<<endl;
		return -1;
	}
	return 0;
}