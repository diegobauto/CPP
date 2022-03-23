//Arbol Ordenado Binario

#include <iostream>
using namespace std;
#include "ArbolBin.h"

int main(){
	ArbolBin L(6);

	L.insertar(100);
	L.insertar(160);
	L.insertar(80);
	L.insertar(110);
	L.insertar(95);
	L.insertar(120);
	L.imprimir();
	L.eliminar(160);
	L.imprimir();
	/*L.insertar(100);
	L.insertar(90);
	L.insertar(80);
	L.insertar(110);
	L.insertar(95);
	L.insertar(120);
	L.imprimir();
	L.eliminar(90);
	L.imprimir();*/
	return 0;
}
