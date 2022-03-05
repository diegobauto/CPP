#include <iostream>
using namespace std;

/*int *CrearArregloEnteros();
int *CrearArregloEnteros(int);*/

int *CrearArregloEnteros(int tam=5){
	int *ar;
	ar = new int[tam];
	return ar;
}


main(){
	int *ar1, *ar2, tam = 3;
	ar1 = CrearArregloEnteros();
	ar2 = CrearArregloEnteros(tam);
	
	for(int i=0; i<5; i++){
		*(ar1+i) = i*2;
		cout<<*(ar1+i);
	}
	
	cout<<endl;
	for(int i=0; i<4; i++){
		ar2[i] = i*3;
		cout<<*(ar2+i);
	}
}

/*int *CrearArregloEnteros(){
	int *ar;
	ar=new int[5];
	return ar;
}

int *CrearArregloEnteros(int tam){
	int *ar;
	ar = new int[tam];
	return ar;
}*/
