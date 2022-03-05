#include<iostream>
using namespace std;

main(){
	int N, i, j, **a;
	int contador = 0;
	cin>>N; 							//1
	a = new int *[N]; 					//1
		
	for(i=0; i<N; i++){
		a[i] = new int [N]; 			//N
		for(j=0; j<N; j++){
			a[i][j] = j*i; 				//N^2
			contador += sizeof(a[i][j]);
		}	
		contador += sizeof(a[i]);	
	}
	
	cout<<contador+sizeof(i)+sizeof(j)+sizeof(N)+sizeof(a)<<endl;

	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			cout<<a[i][j]; 				//N^2
		}	
		delete a[i]; 					//N
	}
	delete []a; 						//1
}

//f(N) = N^2+N+4
//t(N) = 2N^2+2N+3
