/* Colas: 
El primer elemento en entrar es el primero en salir
El ultimo elemento es el ultimo en salir
Si agrego un elemento será al final de la cola
Si elimino un elemento será al inicio de la cola
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

struct NodoCola{
	int dato;
	NodoCola *siguiente;
};

//Prototipos de función
void insertarCola(NodoCola *&, NodoCola *&, int);
bool cola_vacia(NodoCola *);

main(){
	NodoCola *frente = NULL;
	NodoCola *fin = NULL;
	
	int dato;
	cout<<"Digite un numero: ";
	cin>>dato;
	insertarCola(frente, fin, dato);
	
	cout<<"Digite un numero: ";
	cin>>dato;
	insertarCola(frente, fin, dato);
	
	cout<<"Digite un numero: ";
	cin>>dato;
	insertarCola(frente, fin, dato);
}

//Función para insertar elementos a una cola
void insertarCola(NodoCola *&frente, NodoCola *&fin, int n){
	NodoCola *nuevo_nodo = new NodoCola();
	
	nuevo_nodo -> dato = n;
	nuevo_nodo -> siguiente = NULL;
	
	if(cola_vacia(frente)){
		frente = nuevo_nodo;
	}
	else{
		fin -> siguiente = nuevo_nodo;
	}
	
	fin = nuevo_nodo;
	cout<<"\tElemento "<<n<<" insertado correctamente\n";
}

//Funcion para determinar si la cola esta vacia o no
bool cola_vacia(NodoCola *frente){
	return (frente == NULL)? true : false;
}
