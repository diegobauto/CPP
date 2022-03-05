// Punteros a estructuras

#include <iostream>
using namespace std;

//Estructura de Persona
struct Persona{
	char nombre[30];
	int edad;
} persona, *puntero = &persona;

//Prototipo de Funcion
void pedirDatos(); 
void mostrarDatos(Persona *);

main(){
	//LLamo a las funciones
	pedirDatos();
	mostrarDatos(puntero);
}

//Funcion para pedir los datos
void pedirDatos(){
	cout<<"Digite su nombre: ";
	cin.getline(puntero->nombre, 30, '\n');
	cout<<"Digite su edad: ";
	cin>>puntero->edad;
}

//Funcion para mostrar los datos
void mostrarDatos(Persona *puntero_persona){
	cout<<"Nombre: "<<puntero_persona->nombre<<" - Edad: "<<puntero_persona->edad;
}
