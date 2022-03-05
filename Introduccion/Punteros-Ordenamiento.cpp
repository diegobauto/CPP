/* Pedir al usuario N números, almacenarlos en un arreglo dinámico
posteriormente ordenar los números en orden ascendente y mostrarlos en pantalla. 
NOTA: Utilizar cualquier método de ordenamiento. */

#include <iostream>
#include <stdlib.h> //new y delete
using namespace std;

//Prototipo de las funciones
void pedirDatos();
void imprimir();
void ordenar(); //Puntero con la primera posicion del arrelgo, tamaño

int n=0, *puntero;

main(){
	pedirDatos();
	imprimir();
	ordenar();
	imprimir();
	
	delete[] puntero;
}

void pedirDatos(){
	cout<<"Digite el numero de elementos: ";
	cin>>n;
	
	puntero = new int[n]; //Reserva memoria dinamica con n elemetos
	
	for(int i=0; i<n; i++){
		cout<<"["<<i+1<<"]: ";
		cin>>*(puntero+i); //*(puntero+i) = puntero[i] 
	}
}

void imprimir(){
	cout<<"\nDatos: ";
	for(int i=0; i<n; i++){
		cout<<puntero[i];
	}
}

void ordenar(){
	int aux;
	
	//Ordenar el arraglo, metodo burbuja
	for(int i=0; i<n; i++){
		for(int j=0; j<n-1; j++){
			if(*(puntero+j) > *(puntero+j+1)){
				aux = *(puntero+j);
				*(puntero+j) = *(puntero+j+1);
				*(puntero+j+1) = aux;
			}
		}
	}
}


