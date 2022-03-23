#include <iostream>
using namespace std;
#include "Multilista.h"

struct Horario{
	string dia;
	string hora;
};

struct Asignatura{
	string nombre;
	int tipo;
	Lista<Horario> horarios;
};

struct Carrera{
	string carrera;
	int codigo;
	Lista<Asignatura> asignaturas;
};

struct Facultad{
	string nombre;
	string direccion;
	Lista<Carrera> carreras;
};

struct Universidad{
	string nombre;
	long int telefono;
	Lista<Facultad> facultades;
};

main(){
	int df, dc, da, dias, longitud, longitud1, longitud2, longitud3;
	
	Horario auxH;
	Asignatura auxA;
	Carrera auxC;
	Facultad auxF;
	Universidad auxU;
	Lista<Universidad> U;	
	
	cout<<"Digite el nombre de la Universidad:";
	cin>>auxU.nombre;
	cout<<"Digite el telefono de la Universidad:";
	cin>>auxU.telefono;
	cout<<endl;
	
	cout<<"Cuantas facultades tiene la universidad?: ";
	cin>>df;
	cout<<endl;
	
	for(int i=0; i<df; i++){
		cout<<"Digite el nombre de la facultad #"<<(i+1)<<": ";
		cin>>auxF.nombre;
		cout<<"Digite la direccion de la facultad:";
		cin>>auxF.direccion;
		cout<<endl;
		
		cout<<"Cuantas carreras tiene la facultad de "<<auxF.nombre<<"?: ";
		cin>>dc;
		cout<<endl;
		
		for(int i=0; i<dc; i++){
			cout<<"Digite el nombre de la carrera #"<<(i+1)<<": ";
			cin>>auxC.carrera;
			cout<<"Digite el codigo de la carrera:";
			cin>>auxC.codigo;
			cout<<endl;
			
			cout<<"Cuantas asignaturas tiene la carrera "<<auxC.carrera<<"?: ";
			cin>>da;
			cout<<endl;
			
			for(int i=0; i<da; i++){
				cout<<"Digite el nombre de la asignatura #"<<(i+1)<<": ";
				cin>>auxA.nombre ;
				cout<<"Digite el tipo de la asignatura:";
				cout<<"\n1) Basica \n2) Nucleo \n3) Profundizacion\n";
				cin>>auxA.tipo;
				cout<<endl;
				
				cout<<"Cuantos dias a la semana tiene "<<auxA.nombre<<"?: ";
				cin>>dias;
				cout<<endl;
				
				for(int i=0; i<dias; i++){
					cout<<"Digite el dia:";
					cin>>auxH.dia;
					cout<<"Digite la hora:";
					cin>>auxH.hora;
					cout<<endl;
					
					auxA.horarios.insertar_pos(auxH);
				}
				auxC.asignaturas.insertar_pos(auxA);
			}
			auxF.carreras.insertar_pos(auxC);
		}
		auxU.facultades.insertar_pos(auxF);
	}
	U.insertar_pos(auxU);
	
	
	cout<<"----------------------------------"<<endl;
	auxU = U.obtener_dato(0);
	cout<<"\t Universidad: "<<auxU.nombre<<" - Tel: "<<auxU.telefono<<endl;	
	
	int aux=0, aux2=0, aux3=0;
	longitud = auxU.facultades.Tam_lista();
	for(int i=0; i<longitud; i++){
		auxF = auxU.facultades.obtener_dato(i);
		cout<<endl<<"Facultad: "<<auxF.nombre<<" - Dir: "<<auxF.direccion<<endl;
	
		longitud1 = auxF.carreras.Tam_lista();
		for(int i=aux; i<longitud1; i++){
			auxC = auxF.carreras.obtener_dato(i);
			cout<<"\tCarrera: "<<auxC.carrera<<" - Cod: "<<auxC.codigo<<endl;
			aux = longitud1;
			
			longitud2 = auxC.asignaturas.Tam_lista();
			for(int i=aux2; i<longitud2; i++){
				auxA = auxC.asignaturas.obtener_dato(i);
				cout<<"\t\t"<<auxA.nombre<<" - Tipo: "<<auxA.tipo<<endl;
				aux2 = longitud2;
				
				longitud3 = auxA.horarios.Tam_lista();
				for(int i=aux3; i<longitud3; i++){
					auxH = auxA.horarios.obtener_dato(i);
					cout<<"\t\t\t"<<auxH.dia<<" de "<<auxH.hora<<endl;
					aux3 = longitud3;
				}
			}
		}
	}
}
