//FP 
//Javier Gómez López
/* Programa para calcular distintos datos de interes de la función gaussiana
   en base a los valores introducidos por el usuario
   
   Para ello usaremos distintas funciones que nos darán distintos resultados
   
   Entradas: la desviación típica, la media y un valor x.
   Salidas: un valor de la función gaussiana según esos valores y el CFD.
   
*/

#include <iostream> //Inclusión de los recursos E/S
#include <cmath>    //Inclusión de los recursos matemáticos

using namespace std;

double ValorGaussiana (double valor_x, double media, double desviacion)
{
	const double PI = 3.1415926535;
	
	double resultado;
	
	resultado = 1/(desviacion_tipica * sqrt(2 * PI));
	resultado = resultado * exp(-0.5 * pow(((valor_x - media) /
	            desviacion_tipica),2));
	            
	return resultado;


int main ()
{
	double media;
	double desviacion_tipica;
	
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
