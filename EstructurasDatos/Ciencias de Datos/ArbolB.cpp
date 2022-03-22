#include <iostream>
#include "ArbolB.h"

main(){
	ArbolB B(2);
	
	B.insertar(10, "Juan");
	B.insertar(20, "Maria");
	B.insertar(30, "Pedro");
	B.imprimir();
	
	cout<<B.buscar(20);
}
