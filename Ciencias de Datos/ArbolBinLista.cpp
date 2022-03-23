#include <iostream>
#include "ArbolBinLista.h"
using namespace std;

main(){ 

	ARBOL a; NODO *p;  int i;
	a.ins_arbol(100);
	a.ins_arbol(80);
	a.ins_arbol(89);
	a.ins_arbol(85);
	a.ins_arbol(150);
	a.ins_arbol(120);
	a.ins_arbol(155);
	a.ins_arbol(160);
	a.ins_arbol(154);
	a.nose();
	
	
	/*cout<<"Numero a insertar? (fin =999): ";
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
	}*/
	//a.inorden(a.raiz_arbol()); cout<<"___________"<<endl;
	//getch();
	//a.preorden(a.raiz_arbol()); cout<<"__________"<<endl;
	//getch();
	//a.posorden(a.raiz_arbol()); cout<<"__________"<<endl;
	//getch();
}


