//FP 
//Javier Gómez López
/* Programa para calcular el precio de un billete
   de avión en función de los kilómetros a realizar.
   
   Implementamos la fórmula que dice el problema para
   el cálculo del precio del billete.
   
   Entradas: kilómetros que se van a realizar en el viaje
   Salidas: precio del billete final
                  
            Billete final = tarifa base + km * 0.1 (10 céntimos)
*/

#include <iostream> //Inclusión de los recursos E/S
#include <cmath>    //Inclusión de los recursos matemáticos

using namespace std;

int main()
{
	int tarifa_base = 150;  //Declaración de las varibales
	double kilometros;
	double precio_final;     //que definirán el precio del billete
	
//Entradas

cout << "Los kilómetros que usted va a realizar en su viaje son: ";
cin >> kilometros;

//Calculos

precio_final = tarifa_base + kilometros * 0.1;

//Salidas

cout << "El precio de su billete es: " << precio_final << endl;

return (0);

}
