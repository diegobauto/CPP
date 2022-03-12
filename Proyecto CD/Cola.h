#include <cstdlib>
#include <iostream>
#ifndef COLA_H     
#define COLA_H 

using namespace std;

template <class T>
struct nodoC{
	T dato;
    nodoC<T> *sig;
};

template <class T>
class Cola{
	nodoC<T> *cab,*fin;
    public: Cola(){
		cab=fin=NULL;
	}
	
    void InsCola(T i);
    T AtenderCola();
    void ImprimirCola();
    bool ColaVacia();
    ~Cola();
};

template <class T>
void Cola <T>::InsCola(T i){
    nodoC<T> *nuevo;
    nuevo= new nodoC<T>;
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

template <class T>
T Cola <T>::AtenderCola(){
	T x;
    nodoC<T> *aux = cab; 
    cab=aux->sig;
    x=aux->dato;
    delete aux;
    return x;
}

template <class T>
void Cola <T>::ImprimirCola(){
	nodoC<T> *aux;
	aux=cab;
	while(aux!=NULL){
		cout<<aux->dato<<" ";
		aux=aux->sig;
	}    
}

template <class T>
bool Cola <T>::ColaVacia(){
	return (cab==NULL);
}

template <class T>
Cola <T>::~Cola(){
	nodoC<T> *aux;
	while(cab!=NULL){
		aux= cab;
		cab=aux->sig;
		delete aux;
	}
	delete cab;
}

#endif
