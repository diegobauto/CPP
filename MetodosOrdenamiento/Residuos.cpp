#include<iostream>
#include <windows.h>
using namespace std;


//empienzan funciones para calcular tiempo
double PCFreq = 0.0;
__int64 CounterStart = 0;
void StartCounter(){
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
    cout << "QueryPerformanceFrequency failed!\n";
    PCFreq = double(li.QuadPart);
    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}
double GetCounter(){
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}
//Terminan funciones


intercambio(int a[], int min, int i){
	int aux = a[i];
	a[i] = a[min];
	a[min] = aux;
}


unsigned bits(int x, int k, int j){ 
	return (x>>k)&~(~0<<j);
}


void cambioresiduos(int a[], int izq, int der, int b){ 
	int i,j; int t;
	if(der>izq && b>0){
		i=izq; j=der;
		while(j!=i){
			while(!bits(a[i],b,1) && i<j) i++;
			while( bits(a[j],b,1) && j>i) j--;
			intercambio(a, i, j);
		}
		if(!bits(a[i],b,1)) j++;
		cambioresiduos(a, izq, j-1, b-1);
		cambioresiduos(a, j, der, b-1);
	}
}


void imprimirArreglo(int a[], int N){
	for(int i=0; i<N; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}


void llenarArreglo(int N){
	int a[N];
	for(int i=0; i<N; i++){
		a[i] = N-i;
	}
	imprimirArreglo(a, N);
	
	StartCounter(); //Calculamos tiempo
	cambioresiduos(a, 0, N-1, 10);
	cout <<"---------------------> Tiempo: " <<GetCounter() <<" seg <---------------------" <<"\n";
	
	imprimirArreglo(a, N);
	cout<<endl;
}


main(){
	for(int N=10; N<=500; N+=10){
		llenarArreglo(N);
	}
}
