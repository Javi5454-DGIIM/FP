//FP 
//Javier Gómez López
/* Programa para leer un número indeterminador de caracteres hasta que el 
   usuario escriba "*". Tras esto, nos mostrará el número total de aparaciones
   de cada letra.
   
   Entradas: una serie de caracteres que lea el usuario
   Salidas: el número total de caractares que se han leido, el número total 
            de aparaciones de cada letra y cuantos espacios hay.
*/

#include <iostream>  //Inclusión de los recursos de entrada y salida
#include <string>    //Inclusión de los recursos string
#include <cstdio>

using namespace std;

struct Contadores
{
	int letras = 0;
	int separadores = 0;
	int caracteres = 0;
};

int main()
{
	//Declaracion de variables 
	const int ABECEDARIO = 'Z' - 'A' + 1;
	const char TERMINADOR = '*';
	Contadores contador;	
	
	int letras [ABECEDARIO] = {0};
	char c, letra;
	int num_min, num_max;
	
	//Entradas
	cout << "Introduzca una serie de caracteres a su gusto" << endl;
	cout << "Puede usar espacios y separadores libremente" << endl;
	cout << "La entrada se efectuará al pulsar ENTER y la lectura";
	cout << " sera hasta que haya introducido un *" << endl;

	c = cin.get();
	
	while (c!= TERMINADOR)
	{
		contador.caracteres++;
		
		if (c == '\t' || c == ' ' || c == '\n')
		{
			contador.separadores++;
		}
		
		if (isalpha(c))
		{
			c = toupper(c);
		}
		
		if (c >= 'A' && c<= 'Z')
		{
			letras[c - 'A']++;
			contador.letras++;
		}
		
		c = cin.get();
	}
	
	//Calculos
	int menos_frecuente = 0, max_frecuente = 0;
	
	for (int i = 0; i < ABECEDARIO; i++)
	{
		if(letras[menos_frecuente] >= letras[i] && letras[i] != 0)
		{
			menos_frecuente = i;
			num_min = letras[i];
		}
		
		if(letras[max_frecuente] <= letras[i])
		{
			max_frecuente = i;
			num_max = letras[i];
		}
	}
		
	//Salida
	
	cout << endl;
	cout << "Se han leido un total de: " << contador.caracteres << endl;
	cout << contador.letras << " letras y " << contador.separadores;
	cout << " separadores" << endl;
	
	cout << "Las letras que no se han usado son: ";
	for (int j = 0; j < ABECEDARIO; j++)
	{
		if(letras[j] == 0)
		{
			letra = j + 'A';
			cout << letra << " ";
		}
	}
	
	cout << endl;
	
	cout << "Las letras que se han usado son: ";
	cout << endl;
	
	for (int k = 0; k < ABECEDARIO; k++)
	{
		if (letras[k] != 0)
		{
			letra = k + 'A';
			cout << letra << ": " << letras[k] << endl;
		}
	}
	
	cout << endl;
	
	char letra_min_frecuente = menos_frecuente + 'A';
	char letra_max_frecuente = max_frecuente + 'A';
	
	cout << "La letra más frecuente: " << letra_max_frecuente << "(";
	cout << num_max << " veces)" << endl;
	
	cout << "La letra menos frecuente: " << letra_min_frecuente << "(";
	cout << num_min << " veces)" << endl;
	
	return 0;
}
