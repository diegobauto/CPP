/*Asignacion Dinamica de Arreglos

new: Reserva el número de bytes solicitado por la declaración
delete: Libera un bloque de bytes reservado con anterioridad

Ejemplo: Pedir al usuario n calificaciones y almacenarlos
en un areglo dinamico

*/

#include <iostream>
#include <stdlib.h> //Funciona new y delete
using namespace std;

//Prototipo de Funcion
void pedirNotas();
void mostrarNotas();

int nCal, *puntero;

main(){
	pedirNotas();
	mostrarNotas();
	
	delete[] puntero;
}

void pedirNotas(){
	cout<<"Digite el numero de calificaciones: ";
	cin>>nCal;
	
	puntero = new int[nCal];
	
	for(int i=0; i<nCal; i++){
		cout<<"NOTA ["<<i+1<<"]: ";
		cin>>puntero[i];
	}
}

void mostrarNotas(){
	cout<<"\nNotas: "<<endl;
	for(int i=0; i<nCal; i++){
		cout<<puntero[i]<<endl;
	}
}
