#include <cstdlib>
#include <iostream>
#ifndef COLA1_H     
#define COLA1_H 

using namespace std;

struct nodoC{
	int dato;
    nodoC *sig;
};

class cola{
	nodoC *cab,*fin;
    public: cola(){
		cab=fin=NULL;
	}
	
    void InsCola(int i);
    int AtenderCola();
    void ImprimirCola();
    bool ColaVacia();
    ~cola();
};

void cola::InsCola(int i){
    nodoC *nuevo;
    nuevo= new nodoC;
    nuevo->dato=i;
    nuevo->sig= NULL;
    if(cab==NULL){
		cab=nuevo;
	}
    else{
		fin->sig = nuevo;
	}
    fin=nuevo;
}

int cola::AtenderCola(){
	int x;
    nodoC *aux = cab; 
    cab=aux->sig;
    x=aux->dato;
    delete aux;
    return x;
}

void cola::ImprimirCola(){
	nodoC *aux;
	aux=cab;
	while(aux!=NULL){
		cout<<aux->dato<<" ";
		aux=aux->sig;
	}    
}

bool cola::ColaVacia(){
	return (cab==NULL);
}

cola::~cola(){
	nodoC *aux;
	while(cab!=NULL){
		aux= cab;
		cab=aux->sig;
		delete aux;
	}
	delete cab;
}

#endif
