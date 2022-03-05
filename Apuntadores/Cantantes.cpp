#include <cstdlib>
#include <iostream>

using namespace std;
char *Mus[]={"Andr?s Calamaro", "Charly Garc?a", "Gustavo Cerati", "Joaquin Sabina", "Fito Paez"};
char **ApMus[5]={Mus+3, Mus+2, Mus+4, Mus, Mus+1}; 
char ***AppMus[3]={ApMus+4, ApMus+2, ApMus}; 		
char ****Fin= AppMus+1;

int main(int argc, char *argv[]){
	cout<<**(*Fin-1)+6<<endl; // o Cerati
	cout<<*(*(*(Fin-1)-1)+1)+8<<endl; //arc?a
	++*(*(AppMus+1)-1);  //Mus+3, Mus+3, Mus+4, Mus, Mus+1
	cout<<**(*Fin-1)+8<<endl; //Sabina
	cout<<(*++*--*Fin+2)<<endl; //to Paez
	cout<<*(**Fin-4)+9<<endl; //lamaro
	
	system("PAUSE");
	return EXIT_SUCCESS;
}
