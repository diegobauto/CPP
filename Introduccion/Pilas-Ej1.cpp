/* Hacer un programa para agregar números enteros 
a una pila, hasta que el usuario lo decida, después mostrar 
todos los números introducidos en la pila. */

#include <iostream>
#include <stdlib.h> //new
using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

//Prototipo de funciones
void agregarNodo(Nodo *&, int);
void eliminarNodo(Nodo *&pila,int &n);

main(){
	Nodo *pila = NULL;
	int num = 0;
	char menu;
	
	cout<<"*** Para salir presione -1 ***";
	do{
		cout<<"\nDigite un numero: ";
		cin>>num;
		agregarNodo(pila, num);
		cout<<"Desea agregar otro elemento? (s/n): ";
		cin>>menu;
	}while(menu == 'S' || menu == 's');
	
	cout<<"\nMostrando elementos: ";
	while(pila != NULL){ //Mientras no sea el final de la pila
		eliminarNodo(pila, num);
		if(pila != NULL){
			cout<<num<<" , ";
		}
		else{
			cout<<num<<" .";
		}
	}
}

void agregarNodo(Nodo *&pila, int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;
}

void eliminarNodo(Nodo *&pila,int &n){
	Nodo *aux = pila;
	n = aux->dato;
	pila = aux->siguiente;
	delete aux;
}
