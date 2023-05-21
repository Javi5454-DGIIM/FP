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
	const int TARIFA_BASE = 150;   //Declaración de las varibales
	const int KM_BASE = 300;      
	const int DESCUENTO_KM = 700;
	const int PUNTOS_3 = 100;
	const int PUNTOS_4 = 200;

	double descuento_km = 0;
	double descuento_puntos;
	double kilometros;
	int puntos;
	double precio_final;     //que definirán el precio del billete

//Entradas

cout << "Introduzca los km que va a realizar: ";
cin >> kilometros;
cout << "Introduza su número de puntos de fidelización: ";
cin >> puntos;

if (kilometros < KM_BASE)	
{
//Calculos

precio_final = TARIFA_BASE;

}
else 
{
	precio_final = TARIFA_BASE + (kilometros - KM_BASE) * 0.1;
}

if (kilometros > 700)
{
	descuento_km = precio_final * 0.02;
}

if (puntos >= 100 && puntos < 200)
{
	descuento_puntos = precio_final * 0.03;
}
else if (puntos >= 200)
{
	descuento_puntos = precio_final * 0.04;
}

precio_final = precio_final - descuento_puntos - descuento_km;

//Salidas

cout << "El precio de su billete es: " << precio_final << endl;

return (0);

}
