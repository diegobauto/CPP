/*Arbol Ordenado Binario*/

#include <iostream>
using namespace std;
#include "Monticulo.h"

main(){
	monticulo L(10);
	L.insertar(180);
	L.insertar(170);
	L.insertar(160);
	L.insertar(140);
	L.insertar(130);
	L.insertar(120);
	L.insertar(150);
	L.insertar(110);
	L.atender();
	L.imprimirArreglo();
	L.insertar(135);
	L.imprimirArreglo();
	L.atender();
	L.insertar(200);
	L.imprimirArreglo();

	/*monticulo L(7);
	L.insertar(100);
	L.insertar(90);
	L.insertar(80);
	L.insertar(110);
	L.insertar(95);
	L.insertar(120);
	L.insertar(130);
	L.imprimirArreglo();
	L.atender();L.imprimirArreglo();
	L.atender();L.imprimirArreglo();
	L.atender();L.imprimirArreglo();*/
}
