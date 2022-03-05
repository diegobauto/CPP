#include <iostream>
using namespace std;

struct nodo{
	int izq;
	int value;
	int der;
}*arr[0];

class ArbolBin {
	int tam;
	public: ArbolBin(int dim){
		int i;
		tam = dim+1;
		arr[tam];
		for(i; i<tam; i++){
			nodo *aux = new nodo();	
			aux->der = i+1;
			arr[i]=aux;
		}
		arr[i-1]->der = 0;
	};
	
	bool Lista_llena();
	void insertar(int info);
	nodo *Buscar(nodo *aux, int info);
	void eliminar(int info);
	void imprimir();
	void inorden();
	void preorden();
	void posorden();
	void niveles();
};

bool ArbolBin::Lista_llena(){
	return (arr[0]->der == 0)? true : false;
}


nodo *ArbolBin::Buscar(nodo *aux, int info){
	if(info>=aux->value && aux->der == 0){
		return aux;
	}
	else if(info<=aux->value && aux->izq == 0){
		return aux;
	}
	else{
		if(info>aux->value){
			aux = arr[aux->der];
		}else{
			aux = arr[aux->izq];
		}
		Buscar(aux, info);
	}
}

void ArbolBin::insertar(int info){
	int x;
	if(arr[0]->der==1){
		arr[0]->izq = arr[0]->der;
		arr[arr[0]->der]->value = info;
		x = arr[0]->der;
		arr[0]->der = arr[arr[0]->der]->der;
		arr[x]->der=0;
		arr[x]->izq=0;
	}else{
		int y = 0;
		nodo *aux = arr[arr[0]->izq];
		nodo *dato = Buscar(aux, info);
		
		arr[arr[0]->der]->value = info; 
		y = arr[arr[0]->der]->der;
		arr[arr[0]->der]->der=0;
		arr[arr[0]->der]->izq=0;
		if(info > dato->value){
			dato->der = arr[0]->der;
		}else{
			dato->izq = arr[0]->der;
		}
		arr[0]->der = y;
	}
}

void ArbolBin::eliminar(int info){
	int i=0;
	while(arr[i]->value != info){
		i++;
	}
	int pos = i;
	
	i=0;
	char dir;
	while( true ){
		if(arr[i]->der == pos){
			dir = 'd';
			break;
		}else if(arr[i]->izq == pos){
			dir = 'i';
			break;
		}
		i++;
	}
	cout<<"Padre: "<<i<<"- "<<dir;
	nodo *aux = arr[arr[pos]->der];
	if(arr[pos]->izq != 0 && arr[pos]->der != 0){
		
		while(aux->izq != 0){
			aux = arr[aux->izq];
		}
		cout<<endl<<"izqu: "<<aux->value;
		arr[pos]->value = aux->value;
		
		arr[0]->der = arr[pos]->der;
		aux->value = 0;
		aux->der = 0;
		arr[pos]->der = 0;
	}
	else if(arr[pos]->izq != 0){
		arr[0]->der = pos;
		arr[pos]->value = aux->value;
		aux->value = 0;
		arr[i]->izq = arr[pos]->izq;
		arr[pos]->izq = 0;
	}else if(arr[pos]->der != 0){
		arr[0]->der = pos;
		arr[pos]->value = aux->value;
		aux->value = 0;
		arr[0]->der = arr[pos]->der;
		arr[pos]->der = 0;
	}else{
		arr[pos]->value = 0;
		arr[0]->der = pos;
	}
}

void ArbolBin::imprimir(){
	for(int i=0; i<tam; i++){
		cout<<endl<<i<<":\t"<<arr[i]->izq<<"<- ["<<arr[i]->value<<"] ->"<<arr[i]->der<<endl;
	}
	cout<<endl<<"---------------------------------------"<<endl;
}

void ArbolBin::inorden(){
	
}
