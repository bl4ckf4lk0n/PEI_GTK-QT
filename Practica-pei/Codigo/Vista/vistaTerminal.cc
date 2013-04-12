#include <iostream>
#include <string>
#include "../Modelo/modelo.h"
#include "../Modelo/persona.h"
using namespace std;


int MostrarMenu();
void EjecutarFuncion(int,modelo&);
void MostrarRegistros(modelo&);
void AnyadirRegistro(modelo&);
void BorrarRegistro(modelo&);
void GuardarEnFichero(modelo&);

int main()
{

	modelo model;
	string rutaFichero="";

	cout<<"Introduce ruta del fichero de información"<<endl;
	cin>>rutaFichero;

	model.LeerFichero(rutaFichero);

	int opcion = 0;
	do
	{
		opcion = MostrarMenu();
		EjecutarFuncion(opcion,model);	
	}while(opcion != 5);



	return 0;
}

int MostrarMenu()
{
	int opcion;

	cout<<"1-Ver registros"<<endl;
	cout<<"2-Añadir nuevo registro"<<endl;
	cout<<"3-Borrar nuevo registro"<<endl;
	cout<<"4-Guardar fichero"<<endl;
	cout<<"5-Salir"<<endl;
	cout<<"Opcion: ";

	cin>>opcion;

	cout<<endl;
	return opcion;
}

void EjecutarFuncion(int opcion,modelo& model)
{
	switch(opcion)
	{
		case 1: MostrarRegistros(model); break;
		case 2: AnyadirRegistro(model);break;
		case 3: BorrarRegistro(model);break;
		case 4: GuardarEnFichero(model);break;
		case 5: break;

		default: cout<<"Opcion incorrecta"<<endl;

	}
}

void MostrarRegistros(modelo& model)
{
	int num = 0;
	cin.ignore(256, '\n');
	cout<<"Hay " << model.getNumPersonas() << " registros en total. Selecciona uno: "<<endl;
	cin>>num;
	persona p = model.MostrarPersona(num);

	//Englobar en un try-catch

	cout<<"Nombre: " + p.getNombre()<<endl;
	cout<<"Dirección: " + p.getDireccion()<<endl;
	cout<<"Población: " + p.getPoblacion()<<endl;
	cout<<"Código postal: " + p.getCodPostal()<<endl;
	cout<<"Telefono: " + p.getTelefono()<<endl;
	cout<<"Correo electrónico: " + p.getEmail()<<endl;
} 

void AnyadirRegistro(modelo& model)
{
	string nombre= "";
	string direccion= "";
	string poblacion= "";
	string cod_postal= "";
	string telefono= "";
	string email= "";

	cin.ignore(256, '\n'); 
	cout<<"Nombre: ";
	getline(cin,nombre);
	cout<<endl;
	cout<<"Dirección: ";
	getline(cin,direccion);
	cout<<endl;
	cout<<"Población: ";
	getline(cin,poblacion);
	cout<<endl;
	cout<<"Código postal: ";
	getline(cin,cod_postal);
	cout<<endl;
	cout<<"Telefono: ";
	getline(cin,telefono);
	cout<<endl;
	cout<<"Correo electrónico: ";
	getline(cin,email);
	cout<<endl;

	persona p (nombre,direccion,poblacion,cod_postal,telefono,email);
	model.InsertarPersona(p); 
}

void BorrarRegistro(modelo& model)
{
	char respuesta=' ';
	int num = -1;
	cin.ignore(256, '\n'); 
	cout<<"Hay " << model.getNumPersonas() << " registros en total. Selecciona uno: "<<endl;
	cin>>num;

	//Cazar excepcion antes de borrar
	persona p = model.MostrarPersona(num);

	cout<<"¿Borrar el siguiente registro?:"<<endl;
	cout<<endl;
	cout<<"Nombre: " + p.getNombre()<<endl;
	cout<<"Dirección: " + p.getDireccion()<<endl;
	cout<<"Población: " + p.getPoblacion()<<endl;
	cout<<"Código postal: " + p.getCodPostal()<<endl;
	cout<<"Telefono: " + p.getTelefono()<<endl;
	cout<<"Correo electrónico: " + p.getEmail()<<endl;
	cout<<endl;


	bool respuestaCorrecta = false;
	do
	{
		cout<<"S/N: ";
		cin>>respuesta;

		if(respuesta == 'S' || respuesta == 's')
		{
			model.BorrarPersona(num);
			respuestaCorrecta = true;
		}
		else if(respuesta == 'N' || respuesta == 'n')
		{
			respuestaCorrecta = true;
		}
		else
		{
			respuestaCorrecta = false;
		}
	}while(!respuestaCorrecta);

}

void GuardarEnFichero(modelo& model)
{
	string ruta ="";

	cin.ignore(256, '\n'); 
	cout<<"Ruta del fichero: ";
	getline(cin,ruta);

	model.GuardarEnFichero(ruta);
}