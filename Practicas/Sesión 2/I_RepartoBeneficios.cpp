//FP 
//Javier Gómez López
/* Programa para repartir las ganancias en una empresa de maneras distintas.
   
   Repartiremos el salario entre 3 y luego lo asignaremos según
   se nos pide en el enunciado
   
   Entradas: unas ganancias generales
   Salidas: el salario de cada uno de los participantes
*/

#include <iostream> //Inclusión de los recursos E/S
#include <cmath>    //Inclusión de los recursos matemáticos

using namespace std;

int main()
{
	double ganancias;  //Declaramos las variables
	
	double reparto_igual;
	
	double disenador;
	double fabricante;
	
//Entradas

cout << "Las ganancias de la empresa han sido en euros: ";
cin >> ganancias;

//Calculos

reparto_igual = ganancias/3;
disenador = reparto_igual * 2;
reparto_igual = ganancias - disenador;
fabricante = reparto_igual / 2;

//Salidas

cout << "El diseñador gana: " << disenador << " euros" << endl;
cout << "Cada uno de los fabricantes gana: " << fabricante << " euros";

return (0);
}
