#include <iostream>
using namespace std;
 
struct Estud{
	string nombre;
	long long int codigo;
}; 

struct nodo{
	Estud dato;
	nodo *sig;
};

class ListaOR {
	nodo *cab;
	int tam;
	
	public: ListaOR(){
		cab = NULL;
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
	nodo *nuevo_estudiante = new nodo();
	nuevo_estudiante->dato = info;
	nuevo_estudiante->sig = NULL;
	int n = 0;
	
	if (Lista_vacia()){
		cab = nuevo_estudiante;
	}
	else{
		nodo *ant, *aux = cab;
		while (aux!=NULL && (aux->dato).codigo < info.codigo){
			n++;
			ant = aux;
			aux = aux->sig;
			cout<<"h";
		}
		
		if (n == 0){
			nuevo_estudiante->sig = aux;
			cab = nuevo_estudiante;
		}else if(aux == NULL){
			ant->sig = nuevo_estudiante;
		}else{
			nuevo_estudiante->sig = aux;
			ant->sig = nuevo_estudiante;
		}
	}
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
	return "BUSCAR: Codigo no encontrado";
}

void ListaOR::Eliminar(long long int cod){
	nodo *ant, *aux = cab;
	int n = 0;
	
	while(aux != NULL && (aux->dato).codigo != cod) {
		n++;
		ant = aux;
		aux = aux->sig;
	}
	
	if(n == 0){
		cab = aux->sig;
		delete aux;
	}else{
		nodo *puntero = ant->sig;
		ant->sig = puntero->sig;
		delete puntero;
	}
	tam--;
}

//Realizar pruebas
void ListaOR::imprimir(){
	cout<<endl<<"********* Imprimiendo ********"<<endl;
	nodo *aux = cab;
	while(aux != NULL){
		cout<<(aux->dato).nombre<<" - "<<(aux->dato).codigo<<endl;
		aux = aux->sig;
	}
	cout<<endl<<"********* *********** ********"<<endl;
}
