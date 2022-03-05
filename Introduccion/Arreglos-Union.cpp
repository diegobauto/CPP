#include <iostream>
using namespace std;

main(){
	char letras1[] = {'a', 'b', 'c', '-'};
	char letras2[] = {'d', 'e', 'f', 'g', 'h'};
	
	int tamL1 = sizeof(letras1)/sizeof(letras1[0]);
	int tamL2 = sizeof(letras2)/sizeof(letras2[0]);
	
	int tam = tamL1+tamL2;
	char vector[tam];
	
	for(int i=0; i<tamL1; i++){
		vector[i] = letras1[i];
	}
	
	for(int i=tamL1; i<tam; i++){
		vector[i] = letras2[i-tamL1];
	}
	
	for(int i=0; i<tam; i++){
		cout<<vector[i];
	}
}
