//FP 
//Javier Gómez López
/* Programa para calcular la función gaussiana en base a unos parámetros
   variables (media y desviación típica). Además comprobaremos si los datos
   introducidos son correctos (si la desviación típica es distinta de 0)
   
   Para ello usaremos la fórmula que nos proporciona el enunciado.
   
   Entradas: la desviación típica, la media y un valor x.
   Salidas: un valor de la función gaussiana según esos valores
   
*/

#include <iostream> //Inclusión de los recursos E/S
#include <cmath>    //Inclusión de los recursos matemáticos

using namespace std;

int main ()
{
	const double PI = 3.14159265;
	
	double media;
	double desviacion_tipica;

//Entradas

cout << "Introduzca el valor de la media: ";
cin >> media;
cout << "Introduzca el valor de la desviación típica: ";
cin >> desviacion_tipica;

if (desviacion_tipica >= 0)
{
    double resultado, valor_x;
    cout << "Introduzca el valor de la x: ";
    cin >> valor_x;
	resultado = 1/(desviacion_tipica * sqrt(2 * PI));
	resultado = resultado * exp(-0.5 * pow(((valor_x - media)
	            /desviacion_tipica),2));
	
	cout << "El valor de la y para los valores introducidos es: " << resultado;
	
} 
else
{
	cout << "El valor de la desviación típica debe de ser mayor o igual que 0";
}
	


return (0);

}
