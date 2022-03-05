//Correspondencia entre Arrays y Punteros

#include <iostream>
using namespace std;

main(){
	
	int numeros[] = {5,6,7,8,9};
	int *dir_numeros;
	
	dir_numeros = numeros; //Solo guarda la direccion del primer elemento del arreglo
	
	for(int i=0; i<5; i++){
		//cout<<"Numero: "<<*dir_numeros++<<endl;
		//cout<<"Posicion: "<<dir_numeros++<<endl;
		
		//Si los pongo juntos no me toca sumar doble vez ya que lo que hace es recorrer
		//Y recorreria dos veces extendiendome de la longitud del arreglo
		cout<<"Numero: "<<*dir_numeros<<" - Posicion: "<<dir_numeros<<endl;
		dir_numeros++; //El ++ Lo puedo poner por fuera o adentro del cout
	}
	
	
}
