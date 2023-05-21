//FP 
//Javier Gómez López
/* Programa para calcular el precio de un billete
   de avión en función de los kilómetros a realizar
   y con descuento aplicado.
   
   Implementamos la fórmula que dice el problema para
   el cálculo del precio del billete.
   
   Entradas: kilómetros que se van a realizar en el viaje y el descuento
   Salidas: precio del billete final
                  
            Billete final = tarifa base + km * 0.1 (10 céntimos)
                            - (billete final * (descuento / 100)
*/

#include <iostream> //Inclusión de los recursos E/S
#include <cmath>    //Inclusión de los recursos matemáticos

using namespace std;

int main()
{
	int tarifa_base = 150;  //Declaración de las varibales
	double kilometros;
	double precio_sin_descuento;
	double descuento;
	double precio_final;   //que definirán el precio del billete
	
//Entradas

cout << "Los kilómetros que usted va a realizar en su viaje son: ";
cin >> kilometros;
cout << "Y el porcentaje de descuento del que usted dispone es: ";
cin >> descuento;
cout << endl;

//Calculos

precio_sin_descuento = tarifa_base + kilometros * 0.1;
precio_final = precio_sin_descuento - (precio_sin_descuento * (descuento / 100));

//Salidas

cout << "El precio de su billete es: " << precio_final << endl;

return (0);

}


