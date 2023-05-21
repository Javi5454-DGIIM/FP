//FP 
//Javier Gómez López
/* Programa para calcular la función gaussiana en base a unos parámetros
   variables (media y desviación típica).
   
   Para ello usaremos la fórmula que nos proporciona el enunciado.
   
   Entradas: la desviación típica, la media y un valor x.
   Salidas: un valor de la función gaussiana según esos valores
   
*/

#include <iostream> //Inclusión de los recursos E/S
#include <cmath>    //Inclusión de los recursos matemáticos

using namespace std;

int main ()
{
	double media;
	double desviacion_tipica;
	double valor_x;
	
	double resultado;

//Entradas

cout << "El valor de la media es: ";
cin >> media;
cout << "El valor de la desviación típica es: ";
cin >> desviacion_tipica;
cout << "El valor de la x es: ";
cin >> valor_x;

//Calculos

resultado = 1/(desviacion_tipica * sqrt(2 * 3.141592));
resultado = resultado * exp(-0.5 * pow(((valor_x - media)/desviacion_tipica),2));

//Salidas

cout << "El valor es: " << resultado;

return (0);

}
