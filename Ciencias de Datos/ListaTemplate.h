#ifndef LISTA_H
#define LISTA_H

#include <iostream>
using namespace std;

template <class T>
struct nodo{
	T info;
	nodo<T> *sig;
};

template <class T>
class Lista {
	nodo<T> *cab;
	int tam;
	
	public: Lista(){
		cab = NULL;
		tam = 0;
	};
	
	bool lista_vacia();
	int Tam_lista();
	void insertar_pos(T infonva, int pos);
	bool eliminar(int pos);
	T obtener_dato(int pos);
};

template <class T>
bool Lista <T>::lista_vacia(){
	return (cab == NULL)? true : false;
}

template <class T >
int Lista<T>::Tam_lista(){
	return tam;
}

template <class T>
void Lista <T>::insertar_pos(T infonva, int pos){
	nodo<T> *nuevo_nodo = new nodo<T>();
	nuevo_nodo->info = infonva;
	nuevo_nodo->sig = NULL;
	
	if(lista_vacia()){
		//meter al inicio si no hay nada
		cab = nuevo_nodo;
	}else if(pos>tam){
		//meter al final
		nodo<T> *puntero = cab;
		while( puntero->sig != NULL){
			puntero = puntero->sig;
		}
		puntero->sig = nuevo_nodo;
	}else if(pos>0 && pos<(tam+1)){
		//meter en medio
		nodo<T> *ade, *atr;
		ade = cab;
		for(int i=0; i<pos; i++){
			atr = ade;
			ade = ade->sig;
		}
		atr->sig = nuevo_nodo;
		nuevo_nodo->sig = ade;
	}
	tam++;
}

template <class T>
bool Lista <T>::eliminar(int pos){
	if(pos<tam){
		if (cab){
			if(pos == 0){
				nodo<T> *del = cab;
				cab = cab->sig;
				delete(del);
			}
			else if(pos < tam){
				nodo<T> *puntero = cab;
				int cont = 0;
				while (cont < (pos-1)) {
					puntero = puntero->sig;
					cont++;
				}
				nodo<T> *del = puntero->sig;
				puntero->sig = del->sig;
				delete(del);
			}
			tam--;
		}
	}
	else{
		return false;
	}
	return true;
}

template <class T>
T Lista <T>::obtener_dato(int pos){
	nodo<T> *puntero = cab;
	int cont = 0;
	while (puntero!=NULL && cont<pos){
		puntero = puntero->sig;
		cont++;
	}
	return puntero->info;
}

#endif
