#ifndef ARBOLB_H
#define ARBOLB_H

#include <iostream>
using namespace std;

struct nodo{
	int *claves;
	nodo **hijos;
	int Nclaves;
	bool hoja;
	string dato;
};

class ArbolB {
	nodo *raiz;
	int d;
	
	public: ArbolB(int ord){
		d = ord;
		raiz = crear_nodo();
		raiz->Nclaves = 0;
		raiz->hoja = true;
	}
	
	nodo *crear_nodo();
	nodo *get_raiz ();
	int  dividir_nodo(nodo *actual, nodo **hermano);
	void insertar(int clave, string dato);
	nodo *buscar_nodo(int clave, nodo *Actual, nodo **padre);
	int InsertarNodoNormal(int clave, nodo *Actual, string dato);
	void InsertarNodoLleno(int clave, nodo *Actual, nodo *padre, string dato);
	nodo *buscar_padre (int clave, nodo *Actual, nodo *padre);
	bool borrar(int clave);
	nodo *Unir_nodos(nodo* hizq, nodo*hDer, nodo*padre);
	string buscar(int clave);
	void imprimir();
};

nodo *ArbolB::crear_nodo(){
	nodo *nuevo = new nodo();
	nuevo->dato = "";
	nuevo -> claves= new int[2*d-1];
	nuevo->hijos = new nodo* [2*d];
	nuevo->Nclaves=0;
	nuevo->hoja=true;
	return nuevo;
}

nodo *ArbolB::get_raiz (){
	return raiz;
}

void ArbolB::insertar (int clave, string dato){
	nodo *padre = NULL, *Actual=raiz;
	Actual = buscar_nodo( clave, Actual, &padre);
	if (Actual->Nclaves<2*d-1) InsertarNodoNormal(clave, Actual, dato);
	else InsertarNodoLleno(clave, Actual, padre, dato);
}

nodo *ArbolB:: buscar_nodo(int clave, nodo *Actual, nodo **padre){
	int i=0;
	while((i < Actual ->Nclaves) && clave > Actual->claves[i]) i++;
	if (Actual->hoja){
		if (Actual==raiz)
			*padre=NULL;
			return Actual;
	} 	
	else{
		*padre= Actual;
		Actual= Actual ->hijos[i];
		return buscar_nodo(clave, Actual, padre);
	}
}

string ArbolB::buscar(int clave){
	nodo *padre = NULL, *Actual=raiz;
	Actual = buscar_nodo( clave, Actual, &padre);
	return Actual->dato;
}

int ArbolB::InsertarNodoNormal(int clave, nodo *Actual, string dato){
	cout<<"INSERTAR NODO NORMAL"<<endl;
	int i, j;
	i=Actual->Nclaves;
	while((i-1)>=0 && clave< Actual->claves[i-1]){
		Actual->claves[i]=Actual->claves[i-1];
		if (!Actual->hoja) //si el nodo no es una hoja
			Actual->hijos[i+1]=Actual->hijos[i];
			i++;
	}
	Actual->claves[i]=clave;
	Actual->dato = dato;
	(Actual->Nclaves)++;
	return i;
}

void ArbolB::InsertarNodoLleno( int clave, nodo *Actual, nodo *padre, string dato){
	cout<<"INSERTAR NODO LLENO"<<endl;
	int pos, sube;
	nodo *nuevo = crear_nodo();
	nodo *nivelad = NULL;
	
	sube = dividir_nodo(Actual, &nuevo);
	
	if(clave < sube){
		Actual->claves[d-1]=clave;
		(Actual->Nclaves)++;	
	}else{
		nuevo->claves[d-1] = clave;
		(nuevo->Nclaves)++;
	}
	if(Actual != raiz && padre->Nclaves< 2*d-1){
		pos= InsertarNodoNormal(sube, padre, dato);
		padre->hijos[pos]=Actual;
		padre->hijos[pos+1]=nuevo;
	}else{
		if (Actual==raiz){
			nivelad = crear_nodo();
			nivelad->hoja = false;
			nivelad->Nclaves=1;
			nivelad->hijos[0]= Actual;
			nivelad->hijos[1]= nuevo;
		}else{
			nivelad=buscar_padre(padre->claves[0], padre, nivelad);
			InsertarNodoLleno(padre->claves[d-1], padre, nivelad, dato);
		}
	}	
}

int ArbolB::dividir_nodo(nodo *actual, nodo **hermano){
	int i;
	nodo *nuevo=crear_nodo();
	nuevo->hoja=actual->hoja;
	for(i=0; i<d-1; i++)
		nuevo->claves[i]=actual->claves[i+d];
	if(!actual->hoja)
		for (i=0; i<d; i++)
			nuevo->hijos[i]=actual->hijos[i+d];
	nuevo->Nclaves=actual->Nclaves=d-1;
	imprimir();
	return nuevo->claves[d-1];
}

nodo *ArbolB::buscar_padre (int clave, nodo *Actual, nodo *padre){
	int i=0;
	if(clave == Actual->claves[0])
		return padre;
	else{
		while(i < Actual->Nclaves && clave > Actual->claves[i]) i++;
		padre=Actual;
		Actual= Actual -> hijos[i];
		return buscar_padre(clave, Actual, padre);
	}
}

void ArbolB::imprimir(){
	for(int i=0; i<get_raiz()->Nclaves; i++){
		cout<<*get_raiz()->claves++<<" ";
	}
}

#endif
