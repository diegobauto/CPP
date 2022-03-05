/* Pilas:
El primer elemento en entrar es el ultimo en salir
El ultimo elemento en entrar es el primero en salir
Si quiero agrear un elemento debe ser al inicio de la pila
Si quiero eliminar un elemento debe ser al inicio de la pila
*/

#include <iostream>
#include <stdlib.h> //new
using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

//Prototipo de funciones
void agregarNodo(Nodo *&, int); 
void eliminarNodo(Nodo *&, int &);

main(){
	Nodo *pila = NULL;
	int num;
	
	cout<<"Digite un numero: ";
	cin>>num;
	agregarNodo(pila, num);
	
	cout<<"Digite un numero: ";
	cin>>num;
	agregarNodo(pila, num);
	
	cout<<"\nSacando elementos: ";
	while(pila != NULL){ //Mientras no sea el final de la pila
		eliminarNodo(pila, num);
		if(pila != NULL){
			cout<<num<<",";
		}
		else{
			cout<<num<<".";
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
