#include <iostream>
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

void merge(int a[], int first, int middle, int last){
    int b[last];
    int i, j, k;
    k = 0;
    i = first;
    j = middle + 1;
    while(i <= middle && j <= last){
        if(a[i] < a[j]){
            b[k++] = a[i++]; 
        }
        else{
            b[k++] = a[j++];
        }
    }
  
    while(i <= middle){
        b[k++] = a[i++];
    }
  
    while(j <= last){
        b[k++] = a[j++];
    }
  
    for(i=last; i >= first; i--){
        a[i] = b[--k];
    } 
}

void mergeSort(int a[], int first, int last){
    int middle;
    if(first < last){
        middle = (first + last) / 2;
        mergeSort(a, first, middle);
        mergeSort(a, middle+1, last);
        merge(a, first, middle, last);
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
	mergeSort(a, 0, N-1);
	cout <<"--------------------> Tiempo: " <<GetCounter() <<" seg <--------------------" <<"\n";
	
	imprimirArreglo(a, N);
	cout<<endl;
}

int main(){	
 	for(int N=10; N<=500; N+=10){
		llenarArreglo(N);
	}
 	
    return 0;
}
