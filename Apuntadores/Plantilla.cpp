#include <iostream>
using namespace std;

// definición de la plantilla de función imprimirArreglo
template< class T >
void imprimirArreglo( const T *arreglo, const int contador )
{ for ( int i = 0; i < contador; i++ )
      cout << arreglo[ i ] << " ";
   cout << endl;
}


int main(){
 const int aContador = 5;    const int bContador = 7;    
 const int cContador = 6;    int a[ aContador ] = { 1, 2, 3, 4, 5 };
 double b[ bContador ] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7 };
 char c[ cContador ] = "HOLA";  // 5a. posición para el carácter nulo

  cout << "El arreglo a contiene:" << endl;
  imprimirArreglo( a, aContador );  

   cout << "El arreglo b contiene:" << endl;
  imprimirArreglo( b, bContador );  

   cout << "El arreglo c contiene:" << endl;
  imprimirArreglo( c, cContador );  

   return 0;} 

