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

void ordenshell (int a[], int N){
	int i,j,h;
	int v;
	for(h=1; h<=N/9; h=3*h+1);
	for(; h>0; h/=3){
    	for(i=h; i<N; i+=1){
			v=a[i];
			j=i;
        	while(j>=h && a[j-h]>v){
				a[j] = a[j-h]; 
				j-=h;
			}
			a[j]=v;
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
	ordenshell(a,N);
	cout <<"--------------------> Tiempo: " <<GetCounter() <<" seg <--------------------" <<"\n";
	
	imprimirArreglo(a, N);
	cout<<endl;
}
 
main(){
	for(int N=20; N<=500; N+=20){
		llenarArreglo(N);
	}
}
