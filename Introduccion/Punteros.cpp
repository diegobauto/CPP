/*Punteros - Declaración de Punteros

&n = La direccion donde esta almacenada n
*n = El valor de la variable n

*/

#include <iostream>

using namespace std;

main(){
	
	int numero=20, *puntero; //Debe ser entero para guardar un entero
	
	puntero = &numero; //Direccion en donde esta almacenada
	
	cout<<"Valor del numero: "<< *puntero <<endl;
	cout<<"Valor del numero: "<< numero <<endl;
	
	cout<<"Direccion del numero: "<< puntero <<endl;
	cout<<"Direccion del numero: "<< &numero <<endl;
}
