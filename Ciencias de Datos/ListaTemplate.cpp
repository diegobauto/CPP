#include <iostream>
using namespace std;
#include "Lista.h"

struct persona{
	char nombre[20];
	int edad;
} 
persona1 = {"Diego", 18}, 
persona2 = {"Steven", 18}, 
persona3 = {"Mafe", 18}, 
persona4 = {"Ana", 18};

main(){
	Lista <int> Lenteros;
	Lista <char> Lchar;
	Lista <persona> Lestructura;
	
	//Para los enteros
	int cont=0;
	Lenteros.insertar_pos(8,3);
	Lenteros.insertar_pos(6,2);
	Lenteros.insertar_pos(5,1);
	Lenteros.insertar_pos(12,3);
	while(cont<Lenteros.Tam_lista()){
		cout<<Lenteros.obtener_dato(cont);
		cont++;
	}
	while(cont<Lenteros.Tam_lista()){
		cout<<Lenteros.obtener_dato(cont);
		cont++;
	}
	
	cont=Lenteros.Tam_lista()-1;
	while (Lenteros.Tam_lista() != 0){
		Lenteros.eliminar(cont);
		cont--;
	};
	
	cout<<endl;
	//Para los char
	Lchar.insertar_pos('*',3);
	Lchar.insertar_pos('#',2);
	Lchar.insertar_pos('?',1);
	Lchar.insertar_pos('@',3);
	cont=0;
	while(cont<Lchar.Tam_lista()){
		cout<<Lchar.obtener_dato(cont);
		cont++;
	}
	cont=Lchar.Tam_lista()-1;
	while (Lchar.Tam_lista() != 0){
		Lchar.eliminar(cont);
		cont--;
	};
	
	//Para la estructura
	Lestructura.insertar_pos(persona1,3);
	Lestructura.insertar_pos(persona2,2);
	Lestructura.insertar_pos(persona3,1);
	Lestructura.insertar_pos(persona4,3);
	cont=0;
	while(cont<Lestructura.Tam_lista()){
		cout<<endl<<Lestructura.obtener_dato(cont).nombre<<" - ";
		cout<<Lestructura.obtener_dato(cont).edad;
		cont++;
	}
	cont=Lestructura.Tam_lista()-1;
	while (Lestructura.Tam_lista() != 0){
		Lestructura.eliminar(cont);
		cont--;
	};
}
