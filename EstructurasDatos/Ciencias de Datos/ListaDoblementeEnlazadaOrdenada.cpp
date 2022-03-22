/*Lista doblemente enlazada ordenada*/

#include <iostream>
using namespace std;
#include "DoblementeEnlazadaOrdenada.h"

main(){
	ListaOR L;
	Estud Aux;
	char res='s', Borra;
	long long int cod;
	
	//insercion
	cout<<endl<<"----INSERTAR----"<<endl;
	while(res == 's'){
		cout<<"Ingrese el codigo del estudiante: ";
		cin>>Aux.codigo;
		cout<<"Ingrese el nombre del estudiante: ";
		cin>>Aux.nombre;
		L.ins_Lista(Aux);
		
		L.imprimir(); //imprimir lista
		
		cout<<"Desea ingresar otro estudiante? (s/n): ";
		cin>>res;
	}
	
	//busqueda
	cout<<endl<<"----BUSCAR----"<<endl;
	res = 's';
	while(res == 's'){
		cout<<"Ingrese el código del estudiante que desea buscar: ";
		cin>>cod;
		cout<<"El nombre del estudiante con código "<<cod<<" es "<<L.Buscar_dato(cod)<<endl;
		cout<<"Desea buscar otro estudiante? (s/n): ";
		cin>>res;
	}
	
	//borrado
	cout<<endl<<"----BORRAR----"<<endl;
	res = 's';
	while(res == 's'){
		cout<<"Ingrese el codigo del estudiante que desea borrar: ";
		cin>>cod;
		cout<<"El nombre del estudiante con codigo "<<cod<<" es "<<L.Buscar_dato(cod)<<endl;
		cout<<"Esta seguro de borrarlo? (s/n): ";
		cin>>Borra;
		if (Borra == 's'){
			L.Eliminar(cod);
		}
		L.imprimir(); //imprimir lista
		
		cout<<"Desea borrar otro estudiante? (s/n): ";
		cin>>res;
	}
}

