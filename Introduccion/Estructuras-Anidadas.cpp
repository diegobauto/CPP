#include <iostream>
using namespace std;

struct info_direccion {
	char direccion[20];
	char ciudad[20];
	char provincia[20];
};

struct empleado{
	char nombre[20];
	struct info_direccion dir_empleado;
	double salario;
}empleados[2];

main(){
	
	for(int i=0; i<2; i++){
		fflush(stdin); //Vaciar el buffer y permitir digitar los valores
		cout<<"Empleado #"<<i+1<<endl;
		cout<<"Digite nombre: ";
		cin>>empleados[i].nombre;
		cout<<"Digite direccion: ";
		cin>>empleados[i].dir_empleado.direccion;
		cout<<"Digite ciudad: ";
		cin>>empleados[i].dir_empleado.ciudad;
		cout<<"Digite provincia: ";
		cin>>empleados[i].dir_empleado.provincia;
		cout<<"Digite salario: ";
		cin>>empleados[i].salario;
		cout<<"\n";
	}
	
	for(int i=0; i<2; i++){
		cout<<endl<<empleados[i].nombre<<endl;	
		cout<<empleados[i].dir_empleado.direccion<<endl;
		cout<<empleados[i].dir_empleado.ciudad<<endl;
		cout<<empleados[i].dir_empleado.provincia<<endl;
		cout<<empleados[i].salario<<endl;
	}
}
