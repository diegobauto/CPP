/* Comprobar si un número es par o impar, y señalar la 
posición de memoria donde se está guardando el número. 
Con punteros */

#include <iostream>
using namespace std;

main(){
	int numero = 0;
	int *puntero;
	
	cout<<"Digite un numero: ";
	cin>>numero;
	puntero = &numero; //Guardando la posicion de memoria
	
	if(*puntero%2==0){
		cout<<*puntero<<" es par y esta en la direccion: "<<puntero;
	}
	else{
		cout<<*puntero<<" es impar y esta en la direccion: "<<puntero;
	}
}
