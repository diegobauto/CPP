#ifndef INTERNA_H
#define INTERNA_H

#include <cstdlib>
#include <iostream>
using namespace std;

template <class T>
struct nodoL{
  nodoL<T> *sig;
  T info;
};

template <class T>
class Interna{
  nodoL<T> *cab;
  int tam;

	public: Interna(){
    cab = NULL;
    tam=0;
  }

  void insertar(T nueva_info);
  T obtener(int posicion);
  int tamLista();
  int obtenerPosicion(string cod);
  void editar(T nueva_info, int posicion);
  bool encontrar(string cod);
};

template<class T>
void Interna<T>::insertar(T nueva_info) {
  nodoL<T> *nuevo_nodo = new nodoL<T>();
  nuevo_nodo->info = nueva_info;
  nuevo_nodo->sig = NULL;
  if(cab == NULL){
    cab = nuevo_nodo;
  } else{
    nodoL<T> *aux = cab;
    while(aux->sig != NULL){
      aux = aux->sig;
    }
    aux->sig = nuevo_nodo;
  }
  tam++;
}

template<class T>
T Interna<T>::obtener(int posicion) {
  nodoL <T> *aux = cab;
  int pos = 0;
  while(pos < posicion){
    aux = aux->sig;
    pos++;
  }
  return aux->info;
}

template<class T>
int Interna<T>::obtenerPosicion(string cod) {
  nodoL <T> *aux;
  aux = cab;
  int pos = 0;
  while(aux!=NULL){
    if(aux->info == cod){
      return pos;
    }
    aux = aux->sig;
    pos++;
  }
  return -1;
}

template<class T>
void Interna<T>::editar(T nueva_info, int posicion) {
  nodoL <T> *aux = cab;
  int pos = 0;
  while(pos<posicion && aux!=NULL){
    aux = aux->sig;
    pos++;
  }
  aux->info = nueva_info;
}

template<class T>
bool Interna<T>::encontrar(string cod) {
  nodoL <T> *aux;
  aux = cab;
  while(aux!=NULL){
    if(aux->info == cod){
      return true;
    }
    aux = aux->sig;
  }
  return false;
}

template<class T>
int Interna<T>::tamLista() {
  nodoL<T> *aux = cab;
  int p=0;
  while(aux!=NULL){
    aux=aux->sig;
    p++;
  }
  return p;
}

#endif