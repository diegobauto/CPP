#include <iostream>
#include "ColaOptimizada.h"
using namespace std;

main (){
	Cola claop;
	
	claop.set(1); //Insertamos a la cola
	claop.set(2); //Insertamos a la cola
	int var = claop.get(); //Elimina siempre el primer elemento, ya que el primero en entrar es el primero en salir
	cout<<var;
}
