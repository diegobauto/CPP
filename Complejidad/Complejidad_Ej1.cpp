#include<iostream>
using namespace std;

main(){
	int N, i, j, *a;
	cin>>N; 				//1
	
	for(i=0; i<N; i++){
		a = new int[N]; 	//N
		for(j=0; j<N; j++){
			a[j]=j*i; 		//N^2
			cout<<a[j]; 	//N^2
		}
		delete []a; 		//N
	}
}

//f(N) = N+4
//t(N) = 2N^2+2N+1
