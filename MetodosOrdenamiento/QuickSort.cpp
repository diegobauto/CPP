#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

intercambio(int a[], int min, int i){
	int aux = a[i];
	a[i] = a[min];
	a[min] = aux;
}

void ordenrapido(int a[], int izq, int der){
	int i, j; 
	int v;
	if(der> izq){
		v= a[der]; i=izq-1; j=der;
		for(;;){
			while (a[++i]<v);
			while (a[--j] >v);
			if(i>=j) break;
			intercambio(a,i,j);
		}
		intercambio(a, i, der);
		ordenrapido(a, izq, i-1);
		ordenrapido(a, i+1, der);
	}
}

void imprimirArreglo(int a[], int N){
	for(int i=0; i<N; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

bool verificar(int alt, int arr[], int N){	
	for(int i=0; i<N; i++){
		if(arr[i] == alt){
			return true;
		}
	}
	return false;
}

void llenarArreglo(int N){
	int a[N];
	
	int n1 = 0;
	int menores[N];
	int n2 = 0;
	int mayores[N];
	srand(time(NULL));
	
	for(int i=0; i<N; i++){
		mayores[i] = 0;
		menores[i] = 0;
	}
	
	for(int i=0; i<N; i++){
		if(i<N/2-1){
			do
            	n1 = 1 + rand() % (N/2 - 1);
			while(verificar(n1, menores, N/2-1));
			menores[i] = n1;
			a[i] = menores[i];
		}
		else if(i>=N/2-1 and i<N-1){ 
    		do
            	n2 =  N/2+1 + rand() % (N + 1 - (N/2+1));	
			while(verificar(n2, mayores, N));
			mayores[i] = n2;
			a[i] = mayores[i];
		}
	}
	a[N-1] = N/2;
	
	cout<<endl;
	imprimirArreglo(a, N);
	ordenrapido(a, 0, N-1);
	imprimirArreglo(a, N);
	cout<<endl;
}
 
main(){
	for(int N=10; N<=500; N+=10){
		llenarArreglo(N);
	}
}
