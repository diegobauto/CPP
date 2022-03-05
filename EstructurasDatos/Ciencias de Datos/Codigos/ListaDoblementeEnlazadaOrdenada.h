#include <iostream>
using namespace std;
 
struct Estud{
	string nombre;
	long long int codigo;
}; 

struct nodo{
	nodo *atr;
	Estud dato;
	nodo *sig;
};

class ListaOR {
	nodo *cab;
	int tam;
	
	public: ListaOR(){
		cab = new nodo();
		(cab->dato).nombre = "Cabecero";
		(cab->dato).codigo = 0;
		cab->sig = cab;
		cab->atr = cab;
		tam = 0;
	};
	
	bool Lista_vacia();
	int Tam_Lista();
	void ins_Lista(Estud info);
	string Buscar_dato(long long int cod);
	void Eliminar(long long int cod);
	void imprimir();
};

bool ListaOR::Lista_vacia(){
	return (cab == NULL)? true : false;
}

int ListaOR::Tam_Lista(){
	return tam;
}

void ListaOR::ins_Lista(Estud info){
	nodo *nuevo = new nodo();
	nuevo->dato = info;
	nodo *aux = cab;
	int cont = 0;
	
	if(tam == 0){
		cab = nuevo;
		nuevo->sig = nuevo;
		nuevo->atr = nuevo;
	}else{
		while(cont<tam){
			if(info.codigo < (aux->dato).codigo)break;
			aux = aux->sig;
			cont++;
		}
		aux->atr->sig = nuevo;
		nuevo->atr = aux->atr;
		aux->atr = nuevo;
		nuevo->sig = aux;
	}
	if (info.codigo < (cab->dato).codigo)cab = nuevo;
	tam++;
}

string ListaOR::Buscar_dato(long long int cod){
	nodo *aux = cab;
	while(aux != NULL){
		if ((aux->dato).codigo == cod){
			return (aux->dato).nombre;
		}
		aux = aux->sig;
	}
	return " - VACIO - ";
}

void ListaOR::Eliminar(long long int cod){
	if(tam==1){
		tam=0;
		return;	
	}
	nodo *aux = cab;
	for(int i=0; i<tam; i++){
		if((aux->dato).codigo == cod){
			aux->atr->sig = aux->sig;
			aux->sig->atr = aux->atr;
			delete aux;
			tam--;
			break;	
		}
		aux = aux->sig;
	}
	if((cab->dato).codigo == cod) cab=cab->sig;
}

//Realizar pruebas
void ListaOR::imprimir(){
	cout<<endl<<endl<<"********* Imprimiendo ********"<<endl;
	nodo *aux = cab;
	int p = 0;
	while(aux != NULL && p<tam){
		cout<<"Ant: "<<((aux->atr)->dato).nombre<<"     [";
		cout<<(aux->dato).nombre<<" - "<<(aux->dato).codigo<<"]";
		cout<<"     Sig: "<<((aux->sig)->dato).nombre<<endl;
		aux = aux->sig;
		p++;
	}
	cout<<"*******************************"<<endl<<endl;
}
