//FP 
//Javier Gómez López
/* Programa para comprobar si tres números enteros son introducidos
   de manera ordenada, ascendente o descendente.
   
   Para ello utilizaremos una doble condición que nos verifique la 
   ordenación tanto en un sentido como en otro.
   
   Si no se da ninguno de los dos casos, concluiremos que no están
   ordenados.
   
   Entradas: tres números enteros.
   Salidas: si estos están o no ordenados
*/

#include <iostream>  //Inclusión de los recursos de entrada y salida

using namespace std;

int main()
{
	//Declaración de variables
	int numero_1;
	int numero_2;
	int numero_3;
	
	//Entradas
	cout << "Introduzca el primer numero: ";
	cin >> numero_1;
	cout << "Introduzca el segundo número: ";
	cin >> numero_2;
	cout << "Introduzca el tercer número: ";
	cin >> numero_3;
	
if (numero_1 < numero_2 < numero_3 || numero_1 > numero_2 > numero_3)
{
	cout << "Los valores están ordenados";
}
else 
{
	cout << "Los valores no están ordenados";
}

	return (0);
}
