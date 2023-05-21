//FP 
//Javier Gómez López
/* Programa para calcular el tiempo que podemos estar en un parking en 
   función de nuestro dinero.
   
   Para ello utilizaremos unos filtros previos y comprobaremos que 
   los datos introducidos son correctos.
   
   Entradas: hora de inicio y dinero
   
   Salidas: hora hasta la que podemos tener el coche
   
*/

#include <iostream> //Inclusión de los recursos E/S
#include <cmath>    //Inclusión de los recursos de matemáticas

using namespace std;

int main()
{
	
	//Declaracion de variables
	
	const float PRIMER_TRAMO = 0.0412;    // 0 a 30
	const float SEGUNDO_TRAMO = 0.0370;   // 31 a 90
	const float TERCER_TRAMO = 0.0311;    // 91 a 120
	const float CUARTO_TRAMO = 0.0305;    // 121 a 660
	const float QUINTO_TRAMO = 0.0270;    // 661 a 900
	const int SEXTO_TRAMO = 35;           // 900 a 24h
	const int MINUTOS_HORA = 60;
	const int HORAS_DIA = 24;
	
	double dinero_disponible;
	double dinero_gastado = 0;
	int minutos_inicio;
	int hora_inicio;
	int minutos_final;
	int hora_final;
	int minutos_totales_inicio;
	int contador;
	int minutos_disponibles;
	
	//Entradas
	
	cout << "Introduzca la hora actual: " << endl;
	
	do
	{
		cout << "\t Hora: ";
		cin >> hora_inicio;
	} while (hora_inicio >= HORAS_DIA);
	
	do 
	{
		cout << "\t Minutos: ";
		cin >> minutos_inicio;	
	} while (minutos_inicio >= MINUTOS_HORA);
	
	do
	{
		cout << "Introduzca el dinero del que dispone (euros y centimos): ";
		cin >> dinero_disponible;
	} while (dinero_disponible <= 0);
	
	//Calculos
	
	minutos_totales_inicio = minutos_inicio + (hora_inicio * MINUTOS_HORA);
	                         
	while (dinero_gastado <= dinero_disponible)
	{
		if (contador <= 30)
		{
			dinero_gastado = dinero_gastado + PRIMER_TRAMO;
		}
		else if (contador > 30 && contador <=90)
		{
			dinero_gastado = dinero_gastado + SEGUNDO_TRAMO;
		}
		else if (contador > 90 && contador <= 120)
		{
			dinero_gastado = dinero_gastado + TERCER_TRAMO;
		}
		else if (contador > 120 && contador <= 660)
		{
			dinero_gastado = dinero_gastado + CUARTO_TRAMO;
		}
		else if (contador > 660 && contador <= 900)
		{
			dinero_gastado = dinero_gastado + QUINTO_TRAMO;
		}
		else
		{
			dinero_gastado = dinero_gastado + SEXTO_TRAMO;
		}
		contador++;
	}
	
	minutos_disponibles = minutos_totales_inicio + contador;

	hora_final = minutos_disponibles / 60;
	minutos_final = minutos_disponibles % 60;
	
	//Salidas
	
	cout << "El vehículo podrá permancer en el parking hasta: ";
	cout << "\t" << hora_final << " horas";
	cout << " " << minutos_final << " minutos";
	return (0);
}
