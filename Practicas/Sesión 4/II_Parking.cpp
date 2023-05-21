//FP 
//Javier Gómez López
/* Programa para calcular el precio final de estancia en un parking
   en función de los minutos que ha estado el coche aparcado.
   
   Para ello utilizaremos condicionales simples
   
   Entradas: la cantidad de tiempo que ha estado el coche en el parking
   
   Salidas: el precio final del parking en función de las 
            distintas tarifas
   
*/

#include <iostream> //Inclusión de los recursos E/S
#include <cmath>    //Inclusión de los recursos de matemáticas

using namespace std;

int main()
{
	//Declaracion de variables
	const float PRIMER_TRAMO = 0.0412;
	const float SEGUNDO_TRAMO = 0.0370;
	const float TERCER_TRAMO = 0.0311;
	const float CUARTO_TRAMO = 0.0305;
	const int QUINTO_TRAMO = 24;
	const int MINUTOS_DIAS = 1440;
	
	int minutos_entrada;
	double precio_final;
	
	//Entradas
	cout << "Introduzca los minutos que ha usado el parking: ";
	cin >> minutos_entrada;
	
	//Calculos y salida
	if (minutos_entrada <= 30)
    {
		precio_final = minutos_entrada * PRIMER_TRAMO;
		cout << "El precio final es: " << precio_final << " euros";
	}
	else if (minutos_entrada > 30 && minutos_entrada <=90)
	{
		precio_final = 30 * PRIMER_TRAMO + ((minutos_entrada - 30) * 
		                    SEGUNDO_TRAMO);
		cout << "El precio final es: " << precio_final << " euros";
    }
	else if (minutos_entrada > 90 && minutos_entrada <= 120)
	{
		precio_final = 30 * PRIMER_TRAMO + 60 * SEGUNDO_TRAMO + 
		               ((minutos_entrada - 90) * TERCER_TRAMO);
		cout << "El precio final es: " << precio_final << " euros";
    }    
	else if (minutos_entrada > 120 && minutos_entrada <= 660)
	{
		precio_final = 30 * PRIMER_TRAMO + 60 * SEGUNDO_TRAMO + 30 * 
		               TERCER_TRAMO + ((minutos_entrada - 120) * CUARTO_TRAMO);
		cout << "El precio final es: " << precio_final << " euros";
    }  
	else if (minutos_entrada > 660 && minutos_entrada <= MINUTOS_DIAS)
	{
		precio_final = 30 * PRIMER_TRAMO + 60 * SEGUNDO_TRAMO + 30 * 
		               TERCER_TRAMO + 540 * CUARTO_TRAMO + QUINTO_TRAMO;
		cout << "El precio final es: " << precio_final << " euros";
    }
	else 
	{
	    cout << "Ha introducido una cantidad incorrecta de minutos";
    }
	
	return (0);
}

