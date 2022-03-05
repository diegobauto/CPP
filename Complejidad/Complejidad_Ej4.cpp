#include <cstdlib>
#include <iostream>

using namespace std;

struct nodo {
	int x,y;
    nodo *sig;
};

int main(int argc, char** argv) {
	
	nodo **arr, *Aux;
	int N, tam, j, i;
	
	int contador = sizeof(arr) + sizeof(Aux) + sizeof(N) + sizeof(tam)+ sizeof(j) + sizeof(i);
	
	cout<<"Escriba el valor de N ";  		//1
	cin>>N; 						 		//1
	cout<<"Escriba el valor de tam ";		//1
	cin>>tam;						 		//1
	
	arr= new nodo *[N]; 					//1
	
	for(i=0; i<N; i++){
		arr[i]=NULL;						//N
		contador += sizeof(arr[i]);	
	}
	
	for(i=0; i<N; i++){
		for(j=1; j<=tam; j++){
			Aux=new nodo; 					//N*tam
			contador += sizeof(*Aux);	
			Aux->x=j;						//N*tam
			Aux->y=N+j*i;					//N*tam
			Aux->sig = arr[i];				//N*tam
			arr[i]= Aux; 					//N*tam
		}	
	}
	
	cout<<"CONTADOR : "<<contador<<endl;
			
	for(i=0; i<N; i++){
		Aux = arr[i]; 						//N
		cout<<"lista "<<i;					//N
		cout<<endl;							//N
 		
		while(Aux!=NULL){
			cout<<Aux->x<<" "<<Aux->y<<cout<<endl;		//N^2						//N^2
			Aux=Aux->sig; 								//N^2
		}
		
		for(Aux=arr[i]->sig; Aux!=NULL; Aux=Aux->sig) {
			delete arr[i];					//N(N-1)
			arr[i]=Aux; 					//N(N-1)
		}
		delete arr[i];						//N
	}
	delete []arr; 							//1
	
	system("PAUSE");						//1
    return EXIT_SUCCESS;					//1
}

//f(N) = 3N*tam+N+6
//t(N) = 5(N*tam) + 5N + 3(N^2) + 2(N(N-1)) + 8 
//		 5(N*tam) + 5N + 3N^2 + 2(N^2-N) + 8
//		 5(N*tam) + 5N + 3N^2 + 2N^2 - 2N + 8 
//		 5(N*tam) + 5N^2 + 3N + 8

