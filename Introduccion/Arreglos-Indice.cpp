#include <iostream>

using namespace std;

main(){
	int tam, num;
	
	cout<<"Digite el numero de elementos del arreglo: ";
	cin>>tam;
	
	int numeros[tam];
	
	for(int i=0; i<tam; i++){
		cout<<"Digite un numero: ";
		cin>>num;
		numeros[i] = num;
	}
	
	for(int i=0; i<tam; i++){
		cout<<"["<<i<<"] -> "<<numeros[i]<<endl;
	}
}
