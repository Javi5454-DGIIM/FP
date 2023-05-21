//FP 
//Javier Gómez López
/* Programa para calcular el mínimo elemento de una matriz comparando los datos
   por filas.
   
   Entradas: los datos de la matriz
   
   Salidas: el mínimo elemento de la matriz
   
*/

#include <iostream>  //Inclusión de los recursos de entrada y salida

using namespace std;

int main()
{
	
	//Declaración de variables y constantes
	
	const int FILAS = 3;
	const int COLUMNAS = 4;
	double datos_menores[FILAS] = {0};
	double dato_mayor;
	
	double matriz [FILAS][COLUMNAS];
	
	//Entradas
	
	cout << "Introduzca los elementos de la matriz";
	cout << endl;
	
	for (int i = 0; i < FILAS; i++)
	{
		
		for (int j = 0; j < COLUMNAS; j++)
		{
			cout << "Dato [" << i << "][" << j << "]: ";
			cin >> matriz[i][j];
		}
	}
	
	//Calculos 
	
	for (int k = 0; k < FILAS; k++)
	{
		for (int t = 0; t < COLUMNAS - 1; t++)
		{
			if (matriz[k][t] < matriz[k][t+1])
			{
				datos_menores[k] = matriz[k][t];
			}
		}
	}
	
	for (int m = 0; m < FILAS - 1; m++)
	{
		if (datos_menores[m] > datos_menores[m+1])
		{
			dato_mayor = datos_menores[m];
		}
	}
		
	//Salidas
	
	cout << "El menor mayor elemento es: " << dato_mayor;
	
	return 0;
}
