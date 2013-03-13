#include "gestorFicheros.h"

void gestorFicheros::add(string file){
	files.push_back(file);
}

int/*vector<persona>*/ gestorFicheros::getPersonas(int indiceFichero){


	cout<<endl<<"HAY QUE CAMBIAR EL TIPO DEVUELTO A PERSONA EN VEZ DE A INT"<<endl<<endl;


	ifstream origen;
	origen.open(files.at(indiceFichero).c_str());

	if(origen.is_open()){
		cout<<"Bien!"<<endl;
		// Parsear el fichero buscando personas
		origen.close();
	}else{
		cerr<<"Ha ocurrido un error al abrir el registro de personas"<<endl; // TODO: Deberíamos lanzar una excepción?
	}	
	return 0;
}
