#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

bool checkrep(int n, int num[])
{
    for(int i=0; i<10; i++)
        if(n == num[i])
            return true;
    return false;
}

int main()
{
    srand(time(NULL));
    int n, num[10];
    for(int i=0; i<10; i++)
    {
        do
        	//variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
            n = 11 + rand() % (20 + 1 - 11);
        while(checkrep(n, num));
        num[i] = n;
        cout << num[i] << "  ";
    }
}
