//FP 
//Javier Gómez López
/* Programa para calcular el mínimo numero de bits necesarios
   para representar un numero entero positivo.
   
   Para ello usaremos un algoritmo que nos permita conocer este mínimo
   número de bits a partir de logaritmos en base 2 y truncamientos.
   
   Declararemos una variable booleana en función de si el número es 0
   (puesto que ningun logaritmo puede tener un argumento 0) y para el 
   resto de casos sumaremos uno y truncaremos el resultado.
   
   Entradas: un entero positivo teniendo en cuenta el 0
   Salidas: el mínimo número de bits para representar dicho entero
*/

#include <iostream> //Inclusión de los recursos E/S
#include <cmath>    //Inclusión de los recursos matemáticos

using namespace std;

int main()
{
	//Declaración de variables
	int entero;
	int bits;
	
	//Entradas
	cout << "Introduzca un entero positivo (el 0 también se permite): ";
	cin >> entero;
	
	//Calculos
	bool aux = entero > 0;
	bits = log2(entero);
	bits = aux * bits + 1;
	
	//Salidas
	cout << "El número mínimo de bits necesarios para representar ";
	cout << entero << " es " << bits;
	
	return (0);
}
