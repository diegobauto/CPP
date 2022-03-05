/* Pedir su nombre al usuario y devolver el número de vocales que hay. 
NOTA: Recuerda que debes utilizar punteros */

#include <iostream>
#include <string.h>
using namespace std;

int contarVocales(char *);

char nombre[30];

main(){
	cout<<"Digite su nombre: ";
	cin.getline(nombre,30,'\n');
	strupr(nombre); //Pasando el nombre a mayuscula
	cout<<"Numero de vocales es: "<<contarVocales(nombre);
}

int contarVocales(char *nombre){
	int cont = 0;
	
	while(*nombre) {
		switch(*nombre) {
			case 'A':
			case 'E':
			case 'I':
			case 'O':
			case 'U': cont++;
		}
		nombre++;
	}
	return cont;
}
