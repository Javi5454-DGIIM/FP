//FP 
//Javier Gómez López
/* Programa para calcular el precio final de un automóvil.
   
   Para ello utilizaremos un algoritmo que sume el precio y le aplique
   otros costes en base a porcentajes sobre el valor del vehiculo.
   
   Entradas: el costo del vehículo
   Salidas: el precio de venta al público
*/

#include <iostream> //Inclusión de los recursos de entrada y salida

using namespace std;

int main()
{
	//Declaración de variables y constantes 
	double precio_construccion;
	double precio_final;
	
	const double IVA = 0.16;
	const double VENDEDOR = 0.2;
	
	//Entradas
	cout << "Introduzca el coste de producción del vehículo: ";
	cin >> precio_construccion;
	
	//Calculos
	precio_final = precio_construccion + precio_construccion * VENDEDOR;
	precio_final = precio_final + precio_construccion * IVA;
	
	//Salidas
	cout << "El PVP del vehículo es: " << precio_final << " euros";
	
	return (0);
}
