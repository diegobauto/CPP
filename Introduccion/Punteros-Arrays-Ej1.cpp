/* Rellenar un array de 10 n�meros, posteriormente utilizando punteros 
indicar cuales son n�meros pares y su posici�n en memoria */

#include <iostream>
using namespace std;

main(){
	int numeros[] = {1,2,3,4,5,6,7,8,9,10};
	int *puntero;
	
	puntero = numeros; //Posicion de memoria de la primera posicion del arreglo 
	
	for(int i=0; i<10; i++){
		if (*puntero % 2 == 0){
			cout<<*puntero<<" es par - Direccion: "<<puntero<<endl;
		}
		puntero++;
	}
	
}
