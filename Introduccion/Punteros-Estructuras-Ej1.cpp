/* Hacer una estructura llamada alumno, en la cual se tendrán 
los siguientes Campos: Nombre, edad, promedio, 
pedir datos al usuario para 3 alumnos, 
comprobar cuál de los 3 tiene el mejor promedio y 
posteriormente imprimir los datos del alumno.
NOTA: Usar punteros a estructura */

#include <iostream>
using namespace std;

struct Alumno{
	char nombre[30];
	int edad;
	float promedio;
} alumnos[3], *puntero = alumnos;

//Prototipo de Funcion
void pedirDatos();
void calcularMayorPromedio(Alumno *);
void imprimir(Alumno *);


main(){
	pedirDatos();	
	imprimir(puntero);
	calcularMayorPromedio(puntero);
}

void pedirDatos(){
	for(int i=0; i<3; i++){
		cout<<puntero;
		cout<<"\nDigite su nombre: ";
		cin.getline((puntero+i)->nombre, 30, '\n');
		cout<<"Digite su edad: ";
		cin>>(puntero+i)->edad;
		cout<<"Digite su promedio: ";
		cin>>(puntero+i)->promedio;
		cout<<endl;
		
		cin.ignore(); //Limpiar el Buffer
	}
}

void calcularMayorPromedio(Alumno *puntero){
	int mayor = 0;
	int pos = 0;
	for(int i=0; i<3; i++){
		if((puntero+i)->promedio > mayor){
			mayor = (puntero+i)->promedio;
			pos = i;
		}
	}
	cout<<"\nEl mayor promedio es: \nAlumno["<<pos+1<<"]: "<<(puntero+pos)->nombre<<" con "<<(puntero+pos)->promedio;
}

void imprimir(Alumno *puntero){
	for(int i=0; i<3; i++){
		cout<<"\nAlumno ["<<i+1<<"]: ";
		cout<<"\nNombre: "<<(puntero+i)->nombre<<endl;
		cout<<"Edad: "<<(puntero+i)->edad<<endl;
		cout<<"Promedio: "<<(puntero+i)->promedio<<endl;
	}
	
}
