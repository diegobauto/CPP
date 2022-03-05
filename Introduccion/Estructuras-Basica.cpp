#include <iostream>
using namespace std;

struct Persona {
	char nombre[20];
	int edad;
};

main(){
	Persona persona1 = {"Diego", 21};
	Persona persona2 = {"Juan", 5};
	cout<<persona2.nombre;
	cout<<persona1.edad;
}
