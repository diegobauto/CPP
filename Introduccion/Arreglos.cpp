#include <iostream>

using namespace std;

main(){
	int numeros[] = {7,2,3,4,2};
	for(int i=0; i<sizeof(numeros)/sizeof(numeros[0]); i++){
		cout<<numeros[i];
	}	
	
	char vocales[] = {'a', 'e', 'i', 'o', 'u'};
	for(int i=0; i<sizeof(vocales)/sizeof(vocales[0]); i++){
		cout<<vocales[i];
	}
}
