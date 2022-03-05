/* Rellenar un arreglo con n números, 
posteriormente utilizando punteros determinar 
el menor elemento del vector */

#include <iostream>
using namespace std;

main(){
	
	int n=0, numero, *puntero;
	
	cout<<"Digite el tamaño del array: ";
	cin>>n;
	
	int numeros[n]; //Declaro el array
	
	//Entrada de datos
	for(int i=0; i<n; i++){
		cout<<"["<<i+1<<"]: ";
		cin>>numero;
		numeros[i] = numero;
	}
	
	puntero = numeros; //Tomo la direccion del primer numero del arreglo
	
	int menor = *puntero; //Tomo el primero valor del arreglo como el menor
	for(int i=0; i<n; i++){
		if(*puntero < menor){ //Recorro y evaluo cual es el menor de todos
			menor = *puntero;
		}
		puntero++;
	}
	cout<<menor;
}
