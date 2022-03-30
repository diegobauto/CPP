#ifndef LISTA_H
#define LISTA_H

#include "estructura.h"

template <class T>
class Lista{
  nodo<T> *cab;
  int tam;

	public: Lista(){
    cab = NULL;
    tam=0;
  }

  void insertar(T nueva_info);
  T obtener(int posicion);
  int tamLista();
  void editar(T nueva_info, int posicion);
};

template<class T>
void Lista<T>::insertar(T nueva_info) {
  nodo<T> *nuevo_nodo = new nodo<T>;
  nuevo_nodo->info = nueva_info;
  nuevo_nodo->sig = NULL;
  if(cab == NULL){
    cab = nuevo_nodo;
  } else{
    nodo<T> *aux = cab;
    while(aux->sig != NULL){
      aux = aux->sig;
    }
    aux->sig = nuevo_nodo;
  }
  tam++;
}

template<class T>
T Lista<T>::obtener(int posicion) {
  nodo <T> *aux = cab;
  int pos = 0;
  while(pos < posicion){
    aux = aux->sig;
    pos++;
  }
  return aux->info;
}

template<class T>
void Lista<T>::editar(T nueva_info, int posicion) {
  nodo <T> *aux = cab;
  int pos = 0;
  while(pos<posicion && aux!=NULL){
    aux = aux->sig;
    pos++;
  }
  aux->info = nueva_info;
}

template<class T>
int Lista<T>::tamLista() {
  return tam;
}

#endif