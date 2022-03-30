#ifndef CREDITOS_H
#define CREDITOS_H

#include "estructura.h"

template <class T>
class Creditos{
  nodo<T> *uno, *dos, *tres, *cuatro;
  int tam_uno, tam_dos, tam_tres, tam_cuatro;

  public: Creditos(){
    tam_uno=0, tam_dos=0, tam_tres=0, tam_cuatro=0;
    uno=NULL, dos=NULL, tres=NULL, cuatro=NULL;
  }

  void insertar(T nueva_info);
  T obtener(int creditos, int posicion);
  int tam(int creditos);
  void validarInsercion(nodo<T> *&cab, nodo<T> *nuevo);
  T validarObtener(nodo<T> *&cab, int pos);
};

template<class T>
void Creditos<T>::validarInsercion(nodo<T> *&cab, nodo<T> *nuevo){
  if(cab == NULL){
    cab = nuevo;
  } else{
    nodo<T> *aux = cab;
    while(aux->sigCre != NULL){
      aux = aux->sigCre;
    }
    aux->sigCre=nuevo;
  }
}

template<class T>
void Creditos<T>::insertar(T nueva_info) {
  nodo<T> *nuevo_nodo = new nodo<T>;
  nuevo_nodo->info = nueva_info;
  nuevo_nodo->sigCre = NULL;

  if(nueva_info.creditos == 1){
    validarInsercion(uno, nuevo_nodo);
    tam_uno++;
  }else if(nueva_info.creditos == 2){
    validarInsercion(dos, nuevo_nodo);
    tam_dos++;
  }else if(nueva_info.creditos == 3){
    validarInsercion(tres, nuevo_nodo);
    tam_tres++;
  }else if(nueva_info.creditos == 4){
    validarInsercion(cuatro, nuevo_nodo);
    tam_cuatro++;
  }
}

template<class T>
T Creditos<T>::validarObtener(nodo<T> *&cab, int pos){
  nodo <T> *aux = cab;
  int posAux = 0;
  while(posAux<pos){
    aux = aux->sigCre;
    posAux++;
  }
  return aux->info;
}

template<class T>
T Creditos<T>::obtener(int creditos, int posicion){
  if(creditos == 1){
    return validarObtener(uno,posicion);
  }else if(creditos == 2){
    return validarObtener(dos,posicion);
  }else if(creditos == 3){
    return validarObtener(tres,posicion);
  }else if(creditos == 4){
    return validarObtener(cuatro,posicion);
  }
}

template<class T>
int Creditos<T>::tam(int creditos) {
  if(creditos == 1){
    return tam_uno;
  }else if(creditos == 2){
    return tam_dos;
  }else if(creditos == 3){
    return tam_tres;
  }else if(creditos == 4){
    return tam_cuatro;
  }
}

#endif