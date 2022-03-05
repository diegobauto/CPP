#include <iostream>

using namespace std;

main(){
	int mayor = 0;
	int numeros[] = {7,2,3,9,2,15,1,3};
	
	
	for(int i=0; i<sizeof(numeros)/sizeof(numeros[0]); i++){
		if(numeros[i] > mayor){
			mayor = numeros[i];
		}
	}	
	
	cout<<"El mayor de los numeros es: "<<mayor;
}
