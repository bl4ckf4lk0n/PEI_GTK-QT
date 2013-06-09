#include "gestorFicheros.h"
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/regex.hpp>
#include <boost/regex.hpp>
#include <boost/lexical_cast.hpp>


int gestorFicheros::add(string file) {
	ifstream origen;
	origen.open(file.c_str());
	if(origen.is_open()){
		files.push_back(file);
		origen.close();
		return files.size()-1;
	}else{
		throw fileException("Ha ocurrido un error al abrir el registro de personas");
	}
	return -1;
}

int gestorFicheros::anyadirAvector(string file)
{
	files.push_back(file);
	return files.size() - 1;
}

int gestorFicheros::newFile(string file){
	ifstream origen;
	origen.open(file.c_str());
	if(!origen.is_open()){
		
		ofstream nuevo;
		nuevo.open(file.c_str());
		if(nuevo.is_open()){
			nuevo.close();
			files.push_back(file);
			return files.size()-1;
		}else{
			throw fileException("Ha ocurrido un error al crear el nuevo fichero.");
		}
	}else{
		origen.close();
		throw fileException("No se puede crear el fichero " + file + ". Ya existe un fichero con ese nombre.");
		
	}
	return -1;
}

vector<persona> gestorFicheros::getPersonas(int indiceFichero){
	ifstream origen;
	origen.open(files.at(indiceFichero).c_str());

	std::vector<persona> retorno;

	if(origen.is_open()){
		if(origen.peek() == std::ifstream::traits_type::eof()){
			throw fileException("Archivo vacío");
		}
		string linea;
		bool correcto = false;
		while (getline(origen, linea))
		{
			boost::trim_left(linea);
			if(linea != ""){
				try{
					string nombre, direccion,poblacion,cod_postal,email;
					string telefono;
					boost::regex regEx;
					regEx= "^NOMBRE";

					//linea ahora contiene el nombre
					if(!boost::regex_search(linea,regEx))
						throw fileException("Archivo con formato incorrecto");
					boost::algorithm::erase_regex(linea,regEx);
					boost::trim_left(linea);
					nombre = linea;

					getline(origen, linea);
					//linea ahora contiene la dirección
					regEx= "^DIRECCION";
					if(!boost::regex_search(linea,regEx))
						throw fileException("Archivo con formato incorrecto");
					boost::algorithm::erase_regex(linea,regEx);
					boost::trim_left(linea);
					direccion = linea;

					getline(origen, linea);
					//linea ahora contiene la población
					regEx= "^POBLACION";
					if(!boost::regex_search(linea,regEx))
						throw fileException("Archivo con formato incorrecto");
					boost::algorithm::erase_regex(linea,regEx);
					boost::trim_left(linea);
					poblacion = linea;

					getline(origen, linea);
					//linea ahora contiene el cpostal
					regEx= "^CPOSTAL";
					if(!boost::regex_search(linea,regEx))
						throw fileException("Archivo con formato incorrecto");
					boost::algorithm::erase_regex(linea,regEx);
					boost::trim_left(linea);
					cod_postal = linea;

					getline(origen, linea);
					//linea ahora contiene el teléfono
					regEx= "^TELEFONO";
					if(!boost::regex_search(linea,regEx))
						throw fileException("Archivo con formato incorrecto");
					boost::algorithm::erase_regex(linea,regEx);
					boost::trim_left(linea);
					telefono = linea;

					getline(origen, linea);
					//linea ahora contiene el email
					regEx= "^EMAIL";
					if(!boost::regex_search(linea,regEx))
						throw fileException("Archivo con formato incorrecto");
					boost::algorithm::erase_regex(linea,regEx);
					boost::trim_left(linea);
					email = linea;

					persona nueva(nombre,direccion,poblacion,cod_postal,telefono,email);
					retorno.push_back(nueva);
					correcto = true;
				}catch(ios_base::failure ex){
					throw fileException("Archivo con formato incorrecto");
				}
			}
		}
		if(!correcto){
			throw fileException("Archivo con formato incorrecto");
		}
		origen.close();
	}else{
		throw fileException("Ha ocurrido un error al abrir el registro de personas");
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
		for(unsigned int i = 0; i < nuevasPersonas.size(); i++){
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
		throw fileException("Ha ocurrido un error al abrir el registro de personas");
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

void gestorFicheros::removeFile(int pos)
{
	files.erase(files.begin()+pos);
}

void gestorFicheros::modificarFichero(string file,int pos)
{
	files[pos] = file;
}

int gestorFicheros::obtenerPosicion(string file)
{
	for(unsigned int i = 0; i<files.size(); i++ )
	{
		if(files[i] == file)
		{
			return i;
		}
	}
	return -1;
}

void gestorFicheros::exportarCSV(string file,vector<persona> nuevasPersonas)
{
	ofstream salida;
	salida.open(file.c_str());

	if(salida.is_open()){
		salida<<"NOMBRE,DIRECCION,POBLACION,CPOSTAL,TELEFONO,EMAIL"<<endl;

		for(unsigned int i = 0; i < nuevasPersonas.size(); i++){

			salida	<<"\"" <<nuevasPersonas[i].getNombre()<<"\""
					<<",\""<<nuevasPersonas[i].getDireccion()<<"\""
					<<",\""<<nuevasPersonas[i].getPoblacion()<<"\""
					<<",\""<<nuevasPersonas[i].getCodPostal()<<"\""
					<<",\""<<nuevasPersonas[i].getTelefono()<<"\""
					<<",\""<<nuevasPersonas[i].getEmail()<<"\""<<endl;
		}

		salida.close();
	}
}