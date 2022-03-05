/* Transmision de Direcciones
 
 Ej: Intercambiar el valor de dos variables */

#include<iostream>
using namespace std;

void intercambio(float *, float *); //Prototipo de función

main(){
	float num1 = 10.5, num2 = 5.5;
	
	cout<<"Numero 1: "<<num1<<endl;
	cout<<"Numero 2: "<<num2<<endl;
	
	intercambio(&num1, &num2);
	
	cout<<"\nNumero 1: "<<num1<<endl;
	cout<<"Numero 2: "<<num2<<endl;
} 

void intercambio(float *n1, float *n2){
	float aux;
	aux = *n1;
	*n1 = *n2;
	*n2 = aux;
}

