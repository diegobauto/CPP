#include <iostream>
#include "ArbolBinLista.h"
using namespace std;

main(){ ARBOL a; NODO *p;  int i;
	cout<<"Numero a insertar? (fin =999): ";
	cin>>i;
	while(i!=999){
		if (a.ins_arbol(i)==-1) cout<<"Ya existe"<<endl;
		cout<<"Numero a insertar? (fin =999): ";
		cin>>i;
	}
	
	cout<<"Número a retirar (fin=999)"<<endl;
	cin>>i;
		
	while(i!=999){
		if (a.retira_arbol(i)==-1)cout<<"No existe"<<endl;
		cout<<"Número a retirar (fin=999)"<<endl;
		cin>>i;
	}
	a.inorden(a.raiz_arbol()); cout<<"___________"<<endl;
	//getch();
	a.preorden(a.raiz_arbol()); cout<<"__________"<<endl;
	//getch();
	a.posorden(a.raiz_arbol()); cout<<"__________"<<endl;
	//getch();
}


