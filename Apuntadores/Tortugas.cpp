#include <cstdlib>
#include <iostream>

using namespace std;
char *tor={"Rafael", "Leonardo", "Miguel", "Donatello", "Splinter"};
char **bp[5]={tor+3, tor+2, tor+4, tor, tor+1};
char ***ApFin= bp+1;

int main(int argc, char *argv[])
{cout<<*(tor+2 )+4<<endl;
 cout<<*(*ApFin-1)+5<<endl;
 ++*Apfin;
 cout<<**(bp+1)+5<<endl;
 cout<<(*++*--ApFin+3)<<endl;
 cout<<*--Fin[4]+4<<endl;	
 system("PAUSE");
 return EXIT_SUCCESS;
}
