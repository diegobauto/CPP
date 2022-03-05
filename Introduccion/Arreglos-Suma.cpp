#include <iostream>

using namespace std;

main(){
	int numeros[] = {1,2,3,4,5,6,7,8,9};
	int aux = 0;
	
	for(int i=0; i<sizeof(numeros)/sizeof(numeros[0]); i++){
		aux+=numeros[i];
	}
	cout<<aux;
}
