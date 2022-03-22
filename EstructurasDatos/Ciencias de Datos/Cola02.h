#include <cstdlib>
#include <iostream>
#ifndef COLAOPTIMIZADA_H     
#define COLAOPTIMIZADA_H 

using namespace std;

struct nodo{
	int dato;
    nodo *sig;
};

class Cola{
	nodo *cab, *z, *fin;
	int tam;
	
    public: Cola(){
		cab = new nodo;
		cab->dato = -1;
		z = new nodo;
		z->dato = -1;
		cab->sig = z;
		z->sig = z;
		fin = cab;
		tam = 0;
	}
	
    void set(int info);
    char get();
    bool cola_vacia();
};

void Cola::set(int info){
    nodo *nuevo = new nodo;
    nuevo->dato = info;
    nuevo->sig = fin->sig;
    fin->sig = nuevo;
    fin = nuevo;
    tam++;
}

char Cola::get(){
	int x;
    nodo *aux = cab->sig; 
    x = aux->dato;
    cab->sig = aux->sig; 
    delete aux;
    tam--;
    return x;
}

bool Cola::cola_vacia(){
	return (cab->sig == z);
}

#endif
