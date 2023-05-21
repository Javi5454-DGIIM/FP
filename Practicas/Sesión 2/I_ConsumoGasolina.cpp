//FP 
//Javier Gómez López
/* Programa para calcular el consumo en km/litro, los litros/100km
   y los kilómetros de autonomía restantes de un coche.
   
   Para ello utilizaremos distintos algoritmos de cálculo
   
   Entradas: distancia recorrida en kms, litros de gasolina consumidos
   y litros de gasolina restantes
   
   Salidas: km/litro, litros/100km y kilómetros de autonomía restantes
   
*/

#include <iostream> //Inclusión de los recursos E/S

using namespace std;

int main()
{
	double distancia_recorrida;   //Declaración de variables
	double litros_consumidos;
	double litros_restantes;
	
	double km_litro;
	double litros_100_km;
	double autonomia_restante;
	
	//Entradas
	
	cout << "Distancia recorrida (en kms): ";
	cin >> distancia_recorrida;
	cout << "Litros de gasolina consumidos: ";
	cin >> litros_consumidos,
	cout << "Litros que quedan en el deposito: ";
	cin >> litros_restantes;
	
	//Cálculos
	km_litro = distancia_recorrida / litros_consumidos;
	litros_100_km = (100 * litros_consumidos) / distancia_recorrida;
	autonomia_restante = km_litro * litros_restantes;
	
	//Salidas
	
	cout << "KM/Litro: " << km_litro << endl;
	cout << "Litros/100KM: " << litros_100_km << endl;
	cout << "Autonomía restante: " << autonomia_restante << " km" << endl;
	
	return (0);
}
