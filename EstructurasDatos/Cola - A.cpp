#include <cstdlib>
#include <iostream>
#include "Cola.h"


main (){
	cola cla;
	
	cla.InsCola('a'); //Insertamos a la cola
	cla.InsCola('b'); //Insertamos a la cola
	cla.AtenderCola(); //Elimina siempre el primer elemento, ya que el primero en entrar es el primero en salir
	cla.ImprimirCola();
}
