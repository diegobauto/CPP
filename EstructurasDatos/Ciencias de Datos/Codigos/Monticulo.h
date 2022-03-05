#include <iostream>
using namespace std;

class monticulo {
	int *arr, tam, PosAct;
	int a[0];
	
	public: monticulo(int dim){
		tam = dim+1;
		a[dim+1];
		for(int i=0; i<tam; i++){
			a[i] = 0;	
		}
		arr = a;
	};
	
	bool monticulo_lleno();
	bool insertar(int num);
	int atender();
	void imprimirArreglo();
	int mayor(int h1, int h2, int aux);
};

bool monticulo::monticulo_lleno(){
	return (PosAct == tam-1)? true:false;
}

bool monticulo::insertar(int num){
	
	if(PosAct == 0){
		PosAct++;
		arr[1] = num;
	}else if(!monticulo_lleno()){
		PosAct++;
		int k = PosAct/2;
		int aux, aux2 = PosAct;	
		
		if(arr[k] > num){
			arr[PosAct] = num;
		}
		
		while (k >= 1){
			if(arr[k] < num){
				aux = arr[k];
				arr[k] = num; 
				arr[aux2] = aux;
			}	
			aux2 = k;
			k = k/2;
		}
	}
}

int monticulo::mayor(int h1, int h2, int aux){
	if(arr[h1]>arr[h2]){
		if(arr[h1]>arr[aux]){
			return h1;
		}else{
			return aux;
		}
	}else{
		if(arr[h2]>arr[aux]){
			return h2;
		}else{
			return aux;
		}
	}
}

int monticulo::atender(){
	int pos = 1;
	int aux = tam-1;
	int h1 = 2*pos;
	int h2 = 2*pos+1;
	
	while (h1 <= tam-1 || h2 <= tam-1){
		int max = mayor(h1,h2,aux);
		arr[pos] = arr[max];
		arr[max] = 0;
		pos = max;
		h1 = 2*pos;
		h2 = 2*pos+1;
	}
	arr[pos] = arr[aux];
	arr[tam-1] = 0;
	PosAct--;
}

void monticulo::imprimirArreglo(){
	for(int i=1; i<=PosAct; i++){
		cout<<"["<<arr[i]<<"] ";
	}
	cout<<endl;
}
