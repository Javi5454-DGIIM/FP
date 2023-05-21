//FP 
//Javier Gómez López
/* Programa para mostrar el número pi 
   usando el arcoseno.
   
   Salidas: una aproximación bastante fiel de pi.
   
   p/6= arco-seno(0,5)

   
*/

#include <iostream>  //Inclusión de los recursos de E/S
#include <cmath>     //Inlcusión de los recursos matemáticos

using namespace std;

int main()
{
	double pi = asin(0.5) * 6;  //Declaración de la variable de pi
	
//Salidas
	
	cout << "El valor aproximado de pi es: " << pi << endl;
	
return (0);

}
