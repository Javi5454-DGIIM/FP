//FP 
//Javier Gómez López
/* Programa para calcular la mayor secuencia ordenada de datos en un 
   rango establecido de temperaturas.
   
   Para ello realizaremos distintas comprobaciones entre los datos introducidos
   por el usuario, que deben de haber pasado un filtro previamente.
   
   Entradas: distinas temperaturas comrpendidas en un rango.
   
   Salidas: la mayor racha ascendente así como los días que dura
   
*/

#include <iostream>

using namespace std;

int main()
{
	//Declaración de variables
	const int MAX_TEMPERATURAS = 100;
	const int TERMINADOR = -1;
	
	
	double temperaturas[MAX_TEMPERATURAS] = {0};
	int inicio, fin, longitud, inicio_max, fin_max, longitud_max = 0;
	double entrada;
	
	//Entradas
	
	cout << "Introduce una serie de temperaturas hasta que quieras (max 100)";
	cout << ". Si quieres terminar, escribe -1" << endl;
	
	bool seguir;
	int posicion = 0;
	
	do
	{
		cin >> entrada;
		seguir = (entrada != TERMINADOR && posicion < MAX_TEMPERATURAS);
		
		if(seguir)
		{
			temperaturas[posicion] = entrada;
			posicion++;
		}
	} while(seguir);
	
	//Calculos
	inicio = fin = 0;
	
	for(int i = 0; i < MAX_TEMPERATURAS; i++)
	{
		bool mayor = temperaturas[i] < temperaturas[i+1];
		
		if (mayor)
		{
			fin = i + 1;
		}
		else
		{
			longitud = fin - inicio;
			
			if (longitud > longitud_max)
			{
				inicio_max = inicio;
				fin_max = fin;
				longitud_max = longitud;
			}
			
			inicio = i+1;
		}
	}
	
	//Salidas
	
	cout << "La subsecuencia más larga es: ";
	for (int t = inicio_max; t <= fin_max; t++)
	{
		cout << temperaturas[t] << " ";
	}
	
	cout << endl << "Esta se inicio en: " << inicio_max << endl;
	cout << "Y termina en: " << fin_max;
	
	
	return 0;
}
