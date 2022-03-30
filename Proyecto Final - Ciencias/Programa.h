#ifndef PROGRAMA_H
#define PROGRAMA_H

#include "estructura.h"

template <class T>
class Programa{
  nodo<T> *sistemas, *electronica, *industrial, *electrica, *catastral;
  int tam_sistemas, tam_electronica, tam_industrial, tam_electrica, tam_catastral;

  public: Programa(){
    tam_sistemas=0, tam_electronica=0, tam_industrial=0, tam_electrica=0, tam_catastral=0;
    sistemas=NULL, electronica=NULL, industrial=NULL, electrica=NULL, catastral=NULL;
  }

  string upper(string s);
  void insertar(T nueva_info);
  T obtener(string programa, int posicion);
  int tam(string programa);
  void validarInsercion(nodo<T> *&cab, nodo<T> *nuevo);
  T validarObtener(nodo<T> *&cab, int pos);
};


template<class T>
string Programa<T>::upper(string s){
  for(int i=0; i<s.length(); i++){
    s[i] = toupper(s[i]);
  }
  return s;
}

template<class T>
void Programa<T>::validarInsercion(nodo<T> *&cab, nodo<T> *nuevo){
  if(cab == NULL){
    cab = nuevo;
  } else{
    nodo<T> *aux = cab;
    while(aux->sigProg != NULL){
      aux = aux->sigProg;
    }
    aux->sigProg=nuevo;
  }
}

template<class T>
void Programa<T>::insertar(T nueva_info) {
  nodo<T> *nuevo_nodo = new nodo<T>;
  nuevo_nodo->info = nueva_info;
  nuevo_nodo->sigProg = NULL;
  if(upper(nueva_info.programa) == "SISTEMAS"){
    validarInsercion(sistemas, nuevo_nodo);
    tam_sistemas++;
  }else if(upper(nueva_info.programa) == "ELECTRONICA"){
    validarInsercion(electronica, nuevo_nodo);
    tam_electronica++;
  }else if(upper(nueva_info.programa) == "INDUSTRIAL"){
    validarInsercion(industrial, nuevo_nodo);
    tam_industrial++;
  }else if(upper(nueva_info.programa) == "ELECTRICA"){
    validarInsercion(electrica, nuevo_nodo);
    tam_electrica++;
  }else if(upper(nueva_info.programa) == "CATASTRAL"){
    validarInsercion(catastral, nuevo_nodo);
    tam_catastral++;
  }
}

template<class T>
T Programa<T>::validarObtener(nodo<T> *&cab, int pos){
  nodo <T> *aux = cab;
  int posAux = 0;
  while(posAux<pos){
    aux = aux->sigProg;
    posAux++;
  }
  return aux->info;
}

template<class T>
T Programa<T>::obtener(string programa, int posicion){
  if(upper(programa) == "SISTEMAS"){
    return validarObtener(sistemas,posicion);
  }else if(upper(programa) == "ELECTRONICA"){
    return validarObtener(electronica,posicion);
  }else if(upper(programa) == "INDUSTRIAL"){
    return validarObtener(industrial,posicion);
  }else if(upper(programa) == "ELECTRICA"){
    return validarObtener(electrica,posicion);
  }else if(upper(programa) == "CATASTRAL"){
    return validarObtener(catastral,posicion);
  }
}

template<class T>
int Programa<T>::tam(string programa) {
  if(upper(programa) == "SISTEMAS"){
    return tam_sistemas;
  }else if(upper(programa) == "ELECTRONICA"){
    return tam_electronica;
  }else if(upper(programa) == "INDUSTRIAL"){
    return tam_industrial;
  }else if(upper(programa) == "ELECTRICA"){  
    return tam_electrica;
  }else if(upper(programa) == "CATASTRAL"){
    return tam_catastral;
  } 
}

#endif