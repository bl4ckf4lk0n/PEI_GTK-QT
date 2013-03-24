#include <iostream>
#include <string>
#include "../Modelo/modelo.h"
#include "../Persona/persona.h"
using namespace std;


int MostrarMenu();
void EjecutarFuncion(int,modelo&);
void MostrarRegistros(modelo&);

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
		case 2: break;
		case 3: break;
		case 4: break;
		case 5: break;

		default: cout<<"Opcion incorrecta"<<endl;

	}
}

void MostrarRegistros(modelo& model)
{
	int num = 0;
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