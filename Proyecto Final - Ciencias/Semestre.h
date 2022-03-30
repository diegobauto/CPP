#ifndef SEMESTRE_H
#define SEMESTRE_H

#include "estructura.h"

template <class T>
class Semestre{
  nodo<T> *uno, *dos, *tres, *cuatro, *cinco, *seis, *siete, *ocho, *nueve, *diez;
  int tam_uno, tam_dos, tam_tres, tam_cuatro, tam_cinco, tam_seis, tam_siete, tam_ocho, tam_nueve, tam_diez;

  public: Semestre(){
    tam_uno=0, tam_dos=0, tam_tres=0, tam_cuatro=0, tam_cinco= 0, tam_seis=0, tam_siete=0, tam_ocho=0, tam_nueve=0, tam_diez=0;
    uno=NULL, dos=NULL, tres=NULL, cuatro=NULL;
  }

  void insertar(T nueva_info);
  T obtener(int semestre, int posicion);
  int tam(int semestre);
  void validarInsercion(nodo<T> *&cab, nodo<T> *nuevo);
  T validarObtener(nodo<T> *&cab, int pos);
};

template<class T>
void Semestre<T>::validarInsercion(nodo<T> *&cab, nodo<T> *nuevo){
  if(cab == NULL){
    cab = nuevo;
  } else{
    nodo<T> *aux = cab;
    while(aux->sigSem != NULL){
      aux = aux->sigSem;
    }
    aux->sigSem=nuevo;
  }
}

template<class T>
void Semestre<T>::insertar(T nueva_info) {
  nodo<T> *nuevo_nodo = new nodo<T>;
  nuevo_nodo->info = nueva_info;
  nuevo_nodo->sigSem = NULL;
  if(nueva_info.semestre == 1){
    validarInsercion(uno, nuevo_nodo);
    tam_uno++;
  }else if(nueva_info.semestre == 2){
    validarInsercion(dos, nuevo_nodo);
    tam_dos++;
  }else if(nueva_info.semestre == 3){
    validarInsercion(tres, nuevo_nodo);
    tam_tres++;
  }else if(nueva_info.semestre == 4){
    validarInsercion(cuatro, nuevo_nodo);
    tam_cuatro++;
  }else if(nueva_info.semestre == 5){
    validarInsercion(cinco, nuevo_nodo);
    tam_cinco++;
  }else if(nueva_info.semestre == 6){
    validarInsercion(seis, nuevo_nodo);
    tam_seis++;
  }else if(nueva_info.semestre == 7){
    validarInsercion(siete, nuevo_nodo);
    tam_siete++;
  }else if(nueva_info.semestre == 8){
    validarInsercion(ocho, nuevo_nodo);
    tam_ocho++;
  }else if(nueva_info.semestre == 9){
    validarInsercion(nueve, nuevo_nodo);
    tam_nueve++;
  }else if(nueva_info.semestre == 10){
    validarInsercion(diez, nuevo_nodo);
    tam_diez++;
  }
}

template<class T>
T Semestre<T>::validarObtener(nodo<T> *&cab, int pos){
  nodo <T> *aux = cab;
  int posAux = 0;
  while(posAux<pos){
    aux = aux->sigSem;
    posAux++;
  }
  return aux->info;
}

template<class T>
T Semestre<T>::obtener(int semestre, int posicion){
  if(semestre == 1){
    return validarObtener(uno,posicion);
  }else if(semestre == 2){
    return validarObtener(dos,posicion);
  }else if(semestre == 3){
    return validarObtener(tres,posicion);
  }else if(semestre == 4){
    return validarObtener(cuatro,posicion);
  }else if(semestre == 5){
    return validarObtener(cinco,posicion);
  }else if(semestre == 6){
    return validarObtener(seis,posicion);
  }else if(semestre == 7){
    return validarObtener(siete,posicion);
  }else if(semestre == 8){
    return validarObtener(ocho,posicion);
  }else if(semestre == 9){
    return validarObtener(nueve,posicion);
  }else if(semestre == 10){
    return validarObtener(diez,posicion);
  }
}

template<class T>
int Semestre<T>::tam(int semestre) {
  if(semestre == 1){
    return tam_uno;
  }else if(semestre == 2){
    return tam_dos;
  }else if(semestre == 3){
    return tam_tres;
  }else if(semestre == 4){
    return tam_cuatro;
  }else if(semestre == 5){
    return tam_cinco;
  }else if(semestre == 6){
    return tam_seis;
  }else if(semestre == 7){
    return tam_siete;
  }else if(semestre == 8){
    return tam_ocho;
  }else if(semestre == 9){
    return tam_nueve;
  }else if(semestre == 10){
    return tam_diez;
  }
}

#endif