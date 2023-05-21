//FP 
//Javier Gómez López
/* Programa para calcular el total ganado a partir de un interés
   en un banco.
   
   Implementamos la fórmula que dice el problema para
   el cálculo del capital final.
   
   Entradas: capital inicial e interés
   Salidas: total del capital
                  
           total = capital + capital * (interes / 100);
*/

#include <iostream> //Inclusión de los recursos E/S
#include <cmath>    //Inclusión de los recursos matemáticos

using namespace std;

int main()
{
	double capital;  //Declaración de variables
	double interes;
	double total;
	
//Entradas

cout << "El capital que usted desea depositar en el banco es: ";
cin >> capital;
cout << endl;
cout << "Y el interés al que desea depositarlo es: ";
cin >> interes;
cout << endl;

//Calculos
total = capital + capital * (interes / 100);

//Salidas

cout << "Su capital tras un año será: " << total << endl;

return (0);

}

/*Si quisieramos cambiar el valor del capital 
  (para un interés compuesto por ejemplo) deberíamos
  usar otra expresión tal que capital = total tras los cálculos
  actuales, no es posible directamente en la misma expresión
*/
