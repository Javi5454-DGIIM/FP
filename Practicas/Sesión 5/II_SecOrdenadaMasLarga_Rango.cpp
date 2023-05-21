//FP 
//Javier Gómez López
/* Programa para calcular la mayor secuencia ordenada de datos en un 
   rango establecido de temperaturas.
   
   Para ello realizaremos distintas comprobaciones entre los datos introducidos
   por el usuario, que deben de haber pasado un filtro previamente.
   
   Entradas: distinas temperaturas comrpendidas en un rango.
   
   Salidas: la mayor racha ascendente así como los días que dura
   
*/

#include <iostream> //Inclusión de los recursos E/S

using namespace std;

int main ()
{
	//Declaración de variables
	
	const int MIN_RANGO = -15;
	const int MAX_RANGO = 50;
	
	int inicio_secuencia, final_secuencia, inicio_secuencia_max,
	    final_secuencia_max;
	int duracion_secuencia;
	int dia = 1;
	double temperatura, temperatura_anterior = MIN_RANGO;
	
	//Entradas

	inicio_secuencia_max = final_secuencia_max = 1;
	inicio_secuencia = 1;
	final_secuencia = 1;
	temperatura_anterior = MIN_RANGO;
	
	cout << "Las temperaturas a introducir tienen que estar comprendidas " <<
	     "entre -15 y 50 grados" << endl;
	cout << "Introduzca la temperatura el primer dia: ";
	cin >> temperatura;
	
	//Iniciamos el filtro
	while (temperatura <= MAX_RANGO && temperatura >= MIN_RANGO)
	{
		if (temperatura > temperatura_anterior)
		{
			if (final_secuencia != dia)
			{
				final_secuencia = dia;
				final_secuencia_max = final_secuencia;
			}
			else
			{
				inicio_secuencia = dia;
				inicio_secuencia_max = inicio_secuencia;
			}
	    }
	    else
	    {
	    	if (final_secuencia - inicio_secuencia >= final_secuencia_max 
	    	    - inicio_secuencia_max)
	    	    {
	    	    	final_secuencia_max = final_secuencia;
	    	    	inicio_secuencia_max = inicio_secuencia;
	    	    }
	    	    else
	    	    {
	    	    	inicio_secuencia = final_secuencia = dia;
	    	    }
		}
			dia++;
			temperatura_anterior = temperatura;
			
			cout << "Introduzca la temperatura del día siguiente: ";
			cin >> temperatura;
		
	}
		
		//Calculos
		
		duracion_secuencia = final_secuencia_max - inicio_secuencia_max;
		
		//Salidas
		
		cout << "La mayor secuencia comenzo el dia " << inicio_secuencia_max;
		cout << " y termino el dia " << final_secuencia_max << endl;
		cout << "La secuencia duró " << duracion_secuencia << " dias" << endl;
		
		return (0);
	}
