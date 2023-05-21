//FP 
//Javier Gómez López
/* Programa para calcular el área de un círculo 
   y la longitud de la circunferencia correspondiente.
   
   Implementamos las fórmulas de la longitud y el área de una 
   circunferencia.
   
   Entradas: el radio de dicha circunferencia
   Salidas: el área y la longitud de la circunferencia
                  
            Longitud = 2 x pi x r
            Área: pi x r^2
*/

#include <iostream> //Inclusión de los recursos E/S
#include <cmath>    //Inclusión de los recursos matemáticos

using namespace std;

int main() //Programa principal
{
	double radio;       //Declara las variables para 
	double longitud;    //guardar tanto el radio como
	double area;        //como los resultados de las operaciones
	
//Entrada de datos

cout << "Introduzca el valor del radio del círculo: ";
cin >> radio;

//Cálculos 

longitud = 2 *3.1415927 * radio;
area = 3.1415927 * radio * radio;

//Salida de datos

cout << endl;
cout << "El valor de la longitud del círculo es: " << longitud << endl;
cout << "El valor del área del círuclo es: " << area << endl;


return (0);
}
