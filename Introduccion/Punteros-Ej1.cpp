/* Comprobar si un n�mero es par o impar, y se�alar la 
posici�n de memoria donde se est� guardando el n�mero. 
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
