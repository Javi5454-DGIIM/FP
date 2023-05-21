//FP 
//Javier Gómez López
/* Programa para incrementar de manera porcentual un salario base.
   
   Implementamos las conversiones que se muestran en el enunciado del
   ejercio.
   
   Entradas: un salario base
   Salidas: el salario base incrementdo en un dos por ciento
*/

#include <iostream> //Inclusión de los recursos E/S
#include <cmath>    //Inclusión de los recursos matemáticos

using namespace std;

int main()
{
	double salario_base;  //Declaramos las variables del programa
	
//Entradas

cout << "Su salario es: ";
cin >> salario_base;

//Calculos

salario_base = salario_base * 1.02;

//Salidas

cout << "Su salario incrementado un 2% es de: " << salario_base << " euros";

return (0);
}
