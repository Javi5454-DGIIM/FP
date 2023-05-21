//FP 
//Javier Gómez López
/* Programa para mostrar distintas aproximaciones de pi
   
   Implementamos las fórmulas de la longitud y el área de una 
   circunferencia.
   
   Salidas: las distintas aproximaciones de pi

*/

#include <iostream>  //Inclusión de los recursos E/S
#include <cmath>     //Inclusuión de los recursos matemáticos

using namespace std;

int main()
{
	double pi_1800;         //Declaramos las distintas 
	double pi_mesopotamia;  //aproximaciones de pi
	double pi_sigloII;
	
//Calculos
pi_1800 = 256.1/81.0;
pi_mesopotamia = 3.0 + (1.0/8.0);
pi_sigloII = 377.0/120.0;
	
//Salida

cout << "La primera aproximación de pi consta del 1800 y es: " << pi_1800 << endl;
cout << "La segunda aproximación de pi es mesopotámica: " << pi_mesopotamia << endl;
cout << "La tercera aproximación de pi es del siglo II: " << pi_sigloII << endl;

return (0);
}
