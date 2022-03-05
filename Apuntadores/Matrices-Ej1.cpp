#include <cstdlib>
#include <iostream>

using namespace std;

void LlenadoMatriz(int Q[][5])
{int i, j;
  for(i=0; i<4; i++)
    for(j=0; j<5; j++)
       {Q[i][j]= 0;
             }
}

int main(int argc, char *argv[])
{int M[4][5], *Pm, i, j;
    Pm= M[0];
    LlenadoMatriz(M);
    for(i=0; i<4; i++)
      {for(j=0; j<5; j++)
        {cout<< *Pm << " ";
         Pm=Pm+1;
         }
       cout<<endl;}
       
       cout<<endl;
       
    for(i=0; i<4; i++)
      for(j=0; j<5; j++)
        M[i][j]= i*j;
        
       
    for(i=0; i<4; i++)
      {for(j=0; j<5; j++)
        {cout<< *(*(M+i)+j) << " ";
         }
       cout<<endl;}
            
    system("PAUSE");
    return EXIT_SUCCESS;
}
