//FP 
//Javier Gómez López
/* Programa para posicionar un número tras desplazarlo un número de posiciones
   dentro de un intervalo.
   
   Para ello usaremos un algoritmo que nos permita determinar la posicion 
   nueva del numero en el intervalo y situarlo en este.
   
   Primero calcularemos el espacio del intervalo, luego el numero tras el 
   desplazamiento y finalmente la posición de este en el intervalo
   
   Entradas: un mínimo, un máximo, un número y un desplazamiento
   Salidas: la posición de dicho número en el intervalo tras el 
            desplazamiento
   
*/

#include <iostream> //Inclusión de los recursos E/S
#include <cmath>    //Inclusión de los recursos matemáticos

using namespace std;

int main()
{
	/nt minimo;  //Declaración de variables
	int maximo;
	int a_desplazar;
	int desplazamiento;
	
	int intervalo;
	int movimiento;
	int numero_movido;
	
//Entradas

cout << "El mínimo de su intervalo es: ";
cin >> minimo;
cout << "El máximo de su intervalo es: ";
cin >> maximo;
cout << "El desplazamiento que desea realizar es: ";
cin >> desplazamiento;
cout << "Y el número a desplazar es: ";
cin >> a_desplazar;

//Calculos

intervalo = maximo - minimo + 1; //Sumamos el 1 para tomar todos los 
movimiento = a_desplazar + desplazamiento;  //valores del intervalo
numero_movido = minimo + ((movimiento - minimo) % intervalo);

//Salidas
cout << "El número desplazado es: " << numero_movido;

return (0);
}
