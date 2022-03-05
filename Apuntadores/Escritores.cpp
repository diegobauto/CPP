#include <cstdlib>
#include <iostream>

using namespace std;

char *Esc[]={"Pablo Neruda", "Juan Rulfo", "Ernesto S?bato", "Alfonsina Storni"};
char **ApEsc[4]={Esc+1, Esc, Esc+3, Esc+2};
char ***apfin=ApEsc+1;

int main(int argc, char *argv[]){
	
	cout<<(**(ApEsc+2)+3)<<endl; //onsina Storni
	cout<<(*(*ApEsc+1)+8)<<endl; //S?bato
	cout<<(*--*(ApEsc)+4)<<endl; //o Neruda
	cout<<(*++apfin[-1]+6)<<endl; //ulfo
	cout<<(*--*++apfin+2)<<endl; //nesto S?bato
	
    system("PAUSE");
    return EXIT_SUCCESS;
}
