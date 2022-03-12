#include <iostream>
using namespace std;
#include "Multilista.h"
#include "Cola.h"

/*struct Programa{
	
};*/

struct Vacuna{
	string fecha;
	string tipo;
};

struct Profesor{
	int codigo;
	string nombre;
	string email;
	//Cola<Programa> programas;
	Cola<Vacuna> vacunas; 
};

struct Estud{
	long long int codigo;
	string nombre;
	int edad;
	string email;
	string programa;
	string tipo;
	int semetre;
	Cola<Vacuna> vacunas; 
};

struct Horario{
	string dia;
	int hora_inicio;
	int hora_final;
	string salon;
};

struct Grupo{
	int id;
	string nom_profesor;
	int max_estud;
	Lista<Horario> horario;
	int aforo;  
};

struct Asignatura{
	string programa;
	int codigo;
	string nombre;
	int creditos;
	int intensidad;
	bool dicta_prox;
	string tipo;
	int semestre;
};

void funEstudiante(){
	cout<<"1.Adicionar grupo\n2.Retirar grupo\n3.Cambiar grupo"<<endl<<"Opcion: ";
}

void funFuncionario(){
	int op2;
	
	cout<<"1.Agregar asignatura\n2.Agregar grupo\n3.Agregar profesor\n4.Agregar estudiante"<<endl<<"Opcion: ";
	cin>>op2;
	
	switch(op2){
		case 1:
			Asignatura auxA;
		case 2:
			
		case 3:
			
		case 4:
			
		default:
			cout<<"Opcion erronea"
		
	}

}


void funSistema(){
	cout<<"---- Sistema.exe ---";
}



main(){
	int op1;
	
	cout<<"1.Estudiante\n2.Funcionario\n3.Sistema"<<endl<<"Opcion: ";
	cin>>op;
	
	if(op == 1){
		funEstudiante();
	}else if(op == 2){
		funFuncionario();
	}else if(op == 3){
		funSistema();
	}
}
