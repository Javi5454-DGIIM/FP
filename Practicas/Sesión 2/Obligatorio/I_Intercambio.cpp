//FP 
//Javier Gómez López
/* Programa para realizar un cambio de variables simulando el juego del
   trilero.
   
   Entradas: el valor del dinero de la caja izquierda y el valor del dinero
   de la caja derecha-
   
   Salidas: las cantidades de dinero de cada caja cambiadas
*/

#include <iostream> //Inclusión de los recursos E/S
#include <cmath>    //Inclusión de los recursos matemáticos

using namespace std;

int main()
{
	double caja_izda;  //Declaramos las variables que guardarán
	double caja_dcha;  //el valor de cada caja, así como su contenedor
	double valor_dcha;
	double valor_izda;
	
//Entradas

cout << "El valor de la caja derecha es: ";
cin >> valor_dcha;
cout << "El valor de la caja izquierda es: ";
cin >> valor_izda;

//Cálculos

caja_dcha = valor_izda;  
caja_izda = valor_dcha;

//Salidas
cout << "El valor de la caja derecha es: " << caja_dcha << "\n";
cout << "El valor de la caja izquierda es: " << caja_izda;

return (0);

}

/*La solución planteada en el enunciado es la siguiente: 

caja_izda = caja_dcha;
caja_dcha = caja_izda;


El problema de usar este codigo es que primero se está asignando a la 
caja izqueida el valor de la derecha es decir, por ejemplo 1, entonces ahora
la caja izquierda tomará el valor 1. Si después asignamos a caja derecha el
valor de caja izquierda (1), caja derecha volverá a tomar su valor inicial
y ambas cajas tendrán el mismo valor
*/
