#include "gestorFicheros.h"
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/regex.hpp>
#include <boost/lexical_cast.hpp>

void gestorFicheros::add(string file){
	files.push_back(file);
}

vector<persona> gestorFicheros::getPersonas(int indiceFichero){
	ifstream origen;
	origen.open(files.at(indiceFichero).c_str());

	std::vector<persona> retorno;

	if(origen.is_open()){
		string linea;
		while (getline(origen, linea))
		{
			boost::trim_left(linea);
			if(linea != ""){
				try{
					string nombre, direccion,poblacion,cod_postal,email;
					string telefono;
					boost::regex regEx;
					regEx= "^[A-Z]+";

					//linea ahora contiene el nombre
					boost::algorithm::erase_regex(linea,regEx);
					boost::trim_left(linea);
					nombre = linea;

					getline(origen, linea);
					//linea ahora contiene la dirección
					boost::algorithm::erase_regex(linea,regEx);
					boost::trim_left(linea);
					direccion = linea;

					getline(origen, linea);
					//linea ahora contiene la población
					boost::algorithm::erase_regex(linea,regEx);
					boost::trim_left(linea);
					poblacion = linea;

					getline(origen, linea);
					//linea ahora contiene el cpostal
					boost::algorithm::erase_regex(linea,regEx);
					boost::trim_left(linea);
					cod_postal = linea;

					getline(origen, linea);
					//linea ahora contiene el teléfono
					boost::algorithm::erase_regex(linea,regEx);
					boost::trim_left(linea);
					/*cout<< "El telefono es: -" + linea + "-"<<endl;
					telefono = boost::lexical_cast<int,string>(linea.data());*/
					telefono = linea;

					getline(origen, linea);
					//linea ahora contiene el email
					boost::algorithm::erase_regex(linea,regEx);
					boost::trim_left(linea);
					email = linea;

					persona nueva(nombre,direccion,poblacion,cod_postal,telefono,email);
					retorno.push_back(nueva);
					cout<<endl<<"Nueva persona:"<<endl<<nombre<<endl<<direccion<<endl<<poblacion<<endl<<cod_postal<<endl<<telefono<<endl<<email<<endl;

				}catch(ios_base::failure ex){
					cerr<<"[E] Archivo con formato incorrecto"<<endl; // TODO: Deberíamos lanzar una excepción?
				}
			}
		}
		origen.close();
	}else{
		cerr<<"[E] Ha ocurrido un error al abrir el registro de personas"<<endl; // TODO: Deberíamos lanzar una excepción?
	}	
	return retorno;
}

vector<string> gestorFicheros::getFicheros(){
	return files;
}

