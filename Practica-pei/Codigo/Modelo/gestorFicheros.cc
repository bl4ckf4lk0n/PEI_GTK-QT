#include "gestorFicheros.h"
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/regex.hpp>
#include <boost/lexical_cast.hpp>

void gestorFicheros::add(string file){
	ifstream origen;
	origen.open(file.c_str());
	if(origen.is_open()){
		files.push_back(file);
		origen.close();
	}else{
		cerr<<"[E] Ha ocurrido un error al abrir el registro de personas"<<endl; // TODO: Deberíamos lanzar una excepción?
	}
	
}

void gestorFicheros::newFile(string file){
	ifstream origen;
	origen.open(file.c_str());
	if(!origen.is_open()){
		files.push_back(file);
		ofstream nuevo;
		nuevo.open(file.c_str());
		if(nuevo.is_open()){
			nuevo.close();
		}else{
			cerr<<"[E] Ha ocurrido un error al crear el fichero nuevo."<<endl; // TODO: Deberíamos lanzar una excepción?
		}
	}else{
		cerr<<"[E] No se puede crear el fichero " + file + ". Ya existe un fichero con ese nombre."<<endl; // TODO: Deberíamos lanzar una excepción?
		origen.close();
	}
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

void gestorFicheros::escribirVectorPersonas(int indiceFichero, vector<persona> nuevasPersonas){
	ofstream salida;
	salida.open(files.at(indiceFichero).c_str());

	if(salida.is_open()){
		for(int i = 0; i < nuevasPersonas.size(); i++){
			escribirPersona(salida, nuevasPersonas.at(i));
		}

		salida.close();
	}
}

void gestorFicheros::anyadirPersona(int indiceFichero, persona nuevaPersona){
	ofstream salida;
	salida.open(files.at(indiceFichero).c_str(),ios::app);

	if(salida.is_open()){
		escribirPersona(salida, nuevaPersona);
		salida.close();
	}else{
		cerr<<"[E] Ha ocurrido un error al abrir el registro de personas"<<endl; // TODO: Deberíamos lanzar una excepción?
	}	
}

void gestorFicheros::escribirPersona(ofstream& salida, persona nuevaPersona){
	salida<<endl
			<<"NOMBRE "<<nuevaPersona.getNombre()<<endl
			<<"DIRECCION "<<nuevaPersona.getDireccion()<<endl
			<<"POBLACION "<<nuevaPersona.getPoblacion()<<endl
			<<"CPOSTAL "<<nuevaPersona.getCodPostal()<<endl
			<<"TELEFONO "<<nuevaPersona.getTelefono()<<endl
			<<"EMAIL "<<nuevaPersona.getEmail()<<endl;
}