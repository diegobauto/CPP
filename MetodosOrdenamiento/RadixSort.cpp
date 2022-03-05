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

int maxValor(int arr[], int n){
	int max = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

void intercambio(int arr[], int n, int digito){
	
}

void radixSort(int arr[], int n){
	int m = maxValor(arr, n);

	for (int digito=1; m/digito>0; digito*=10)
		int fin[n];
		int i, con[10] = { 0 };
		
		for (i=0; i<n; i++)
			con[(arr[i] / digito) % 10]++;
	
		for (i=1; i<10; i++)
			con[i] += con[i - 1];
	
		for (i=n-1; i >=0; i--) {
			fin[con[(arr[i] / digito) % 10] - 1] = arr[i];
			con[(arr[i] / digito) % 10]--;
		}
	
		for (i=0; i<n; i++)
			arr[i] = fin[i];
}

void imprimirArreglo(int a[], int N){
	for(int i=0; i<N; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void llenarArreglo(int N){
	int arr[N];
	for(int i=0; i<N; i++){
		arr[i] = N-i;
	}
	imprimirArreglo(arr, N);
	
	StartCounter(); //Calculamos tiempo
	radixSort(arr, N);
	cout <<"--------------------> Tiempo: " <<GetCounter() <<" seg <--------------------" <<"\n";
	
	imprimirArreglo(arr, N);
	cout<<endl;
}

int main(){
	for(int N=10; N<=500; N+=10){
		llenarArreglo(N);
	}
	return 0;
}
