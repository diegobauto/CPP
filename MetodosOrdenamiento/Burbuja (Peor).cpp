#include<iostream>
#include <windows.h>
using namespace std;

//empienzan funciones para calcular tiempo
double PCFreq = 0.0;
__int64 CounterStart = 0;

void StartCounter()
{
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
    cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double(li.QuadPart);

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}
double GetCounter()
{
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

void burbuja(int a[], int N){
	int i,j;
	for(i=N; i>=1; i--){
		for(j=0; j<i; j++){
			if(a[j-1]> a[j]){
				intercambio(a, j-1, j);
			}
		}
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
	burbuja(a,N);
	cout <<"---------------------> Tiempo: " <<GetCounter() <<" seg <---------------------" <<"\n";

	imprimirArreglo(a, N);
	cout<<endl;
}
 
main(){
	for(int N=10; N<=500; N+=10){
		llenarArreglo(N);
	}
}
