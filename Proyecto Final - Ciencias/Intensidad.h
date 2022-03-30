#ifndef INTENSIDAD_H
#define INTENSIDAD_H

#include "estructura.h"

template <class T>
class Intensidad{
  nodo<T> *dos, *tres, *cuatro, *cinco, *seis;
  int tam_dos, tam_tres, tam_cuatro, tam_cinco, tam_seis;

  public: Intensidad(){
    tam_dos=0, tam_tres=0, tam_cuatro=0, tam_cinco=0, tam_seis=0;
    dos=NULL, tres=NULL, cuatro=NULL, cinco=NULL, seis=NULL;
  }

  void insertar(T nueva_info);
  T obtener(int intensidad, int posicion);
  int tam(int intensidad);
  void validarInsercion(nodo<T> *&cab, nodo<T> *nuevo);
  T validarObtener(nodo<T> *&cab, int pos);
};

template<class T>
void Intensidad<T>::validarInsercion(nodo<T> *&cab, nodo<T> *nuevo){
  if(cab == NULL){
    cab = nuevo;
  } else{
    nodo<T> *aux = cab;
    while(aux->sigInt != NULL){
      aux = aux->sigInt;
    }
    aux->sigInt=nuevo;
  }
}

template<class T>
void Intensidad<T>::insertar(T nueva_info) {
  nodo<T> *nuevo_nodo = new nodo<T>;
  nuevo_nodo->info = nueva_info;
  nuevo_nodo->sigInt = NULL;

  if(nueva_info.intensidad == 2){
    validarInsercion(dos, nuevo_nodo);
    tam_dos++;
  }else if(nueva_info.intensidad == 3){
    validarInsercion(tres, nuevo_nodo);
    tam_tres++;
  }else if(nueva_info.intensidad == 4){
    validarInsercion(cuatro, nuevo_nodo);
    tam_cuatro++;
  }else if(nueva_info.intensidad == 5){
    validarInsercion(cinco, nuevo_nodo);
    tam_cinco++;
  }else if(nueva_info.intensidad == 6){
    validarInsercion(seis, nuevo_nodo);
    tam_seis++;
  }
}

template<class T>
T Intensidad<T>::validarObtener(nodo<T> *&cab, int pos){
  nodo <T> *aux = cab;
  int posAux = 0;
  while(posAux<pos){
    aux = aux->sigInt;
    posAux++;
  }
  return aux->info;
}

template<class T>
T Intensidad<T>::obtener(int intensidad, int posicion){
  if(intensidad == 2){
    return validarObtener(dos,posicion);
  }else if(intensidad == 3){
    return validarObtener(tres,posicion);
  }else if(intensidad == 4){
    return validarObtener(cuatro,posicion);
  }else if(intensidad == 5){
    return validarObtener(cinco,posicion);
  }else if(intensidad == 6){
    return validarObtener(seis,posicion);
  }
}

template<class T>
int Intensidad<T>::tam(int intensidad) {
  if(intensidad == 2){
    return tam_dos;
  }else if(intensidad == 3){
    return tam_tres;
  }else if(intensidad == 4){
    return tam_cuatro;
  }else if(intensidad == 5){
    return tam_cinco;
  }else if(intensidad == 6){
    return tam_seis;
  } 
}

#endif