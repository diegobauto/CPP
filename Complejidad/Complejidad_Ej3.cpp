#include<iostream>
using namespace std;

main(){
	
	struct nodo {
		int x, y;
		nodo *sig;
	};

	int N, i, j; 
	nodo *cab = NULL, *Aux; 	//1
	cin>>N; 					//1
	
	for(i=0; i<N; i++){
		Aux = new nodo; 		//N
		Aux ->x = i;			//N
		Aux ->y = N-i;			//N
		Aux ->sig = cab;		//N
		cab = Aux;				//N
	}
	
	Aux = cab; 					//1
	
	while(Aux!=NULL){
		cout<< Aux->x<< Aux->y; //N
		cout<<endl; 			//N
		Aux = Aux->sig;			//N
	} 
	
	for(Aux=cab->sig; Aux!=NULL; Aux=Aux->sig){
		delete cab; 			//N-1
		cab = Aux;				//N-1
	}
}

//f(N) = 3N + 5 
//t(N) = 8N + 2(N-1) + 3 
//	   = 8N + 2N - 2 + 3
//	   = 10N + 1
