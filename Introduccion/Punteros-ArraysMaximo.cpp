#include <iostream>
using namespace std;

/* Hallar el maximo elemento de un arreglo */

void hallarMaximo(int *);

main() {	
	int numeros[] = {8,9,1,5,15,4,2};
	int *puntero;
	
	puntero = numeros;
	hallarMaximo(puntero);
			
}

void hallarMaximo(int *puntero){
	int mayor = 0;
	for(int i=0; i<7; i++){
		if(*puntero > mayor){
			mayor = *puntero;
		}
		puntero++;
	}
	cout<<mayor;
}
