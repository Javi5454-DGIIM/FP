//FP 
//Javier Gómez López
/* Programa diseñar un mapa de ciudades almacenado en una matriz
   
   Entradas: los datos de la matriz
   
   Salidas: el mínimo elemento de la matriz
   
*/

#include <iostream>

using namespace std;


int main()
{
	//Declaracion de variables
	
	int num_ciudades;
	
	//Entrada
	
	do
	{
		cout << "Introduzca el número de ciudades (<50): ";
		cin >> num_ciudades;
	} while (num_ciudades > 50 || num_ciudades < 2);
	
	double matriz_ciudades[num_ciudades][num_ciudades];
	
	cout << "Introduzca la distancia entre cada ciudad: " << endl;
	cout << "No se pedirá la distancia de una ciudad consigo misma" << endl;
	
	for (int i = 0; i < num_ciudades; i++)
	{
		for (int j = 0; j < num_ciudades; j++)
		{
			if (i != j)
			{
				cout << "Distancia [" << i << "][" << j << "]: ";
				cin >> matriz_ciudades[i][j];
			}
			else
			{
				matriz_ciudades[i][j] = 0;
			}
		}
	}
	
	//Calculos
	
	//Obtenemos la ciudad con mayor número de conexiones directas
	int contador[num_ciudades] = {0};
	int mas_conexiones;
	int num_maximo;
	
	for (int t = 0; t < num_ciudades; t++)
	{
		for (int m = 0; m < num_ciudades; m++)
		{
			if (matriz_ciudades[t][m] != 0)
			{
				contador[t]++;
			}
		}
	}
	
	for (int maximo = 0; maximo < num_ciudades - 1; maximo++)
	{
		if (contador[maximo] > contador[maximo+1])
		{
			mas_conexiones = maximo;
			num_maximo = contador[maximo];
		}
	}
	
	
	cout << endl << "La ciudad con más conexiones es la " << mas_conexiones;
	cout << " con " << num_maximo << " conexiones" << endl << endl;
	
	
	//Obtener las ciudades conectadas directamente con una ciudad j
	
	int ciudad_conexiones;
	bool conexiones[num_ciudades] = {false};
	
	do
	{
		
		cout << "Introduzca una ciudad para ver cuantas conexiones directas tiene";
		cout << "(0 - " << num_ciudades - 1 << "): ";
		cin >> ciudad_conexiones;
	} while(ciudad_conexiones < 0 || ciudad_conexiones >= num_ciudades);
	
	for (int puntero = 0; puntero < num_ciudades; puntero++)
	{
		if (matriz_ciudades[ciudad_conexiones][puntero] != 0)
		{
			conexiones[puntero] = true;
		}
	}
	
	cout << endl << "La ciudad " << ciudad_conexiones << " esta conectada con ";
	
	for (int mostrar = 0; mostrar < num_ciudades; mostrar++)
	{
		if(conexiones[mostrar])
		{
			if (mostrar != num_ciudades - 1)
			{
				cout << mostrar << ", ";
			}
			else
			{
				cout << mostrar << endl;
			}
		}
	}
	
	//Obtener el camino más corto entre dos ciudades no conectadas
	
	int ciudad_1, ciudad_2, distancia_min;
	double distancia[num_ciudades] = {0};
	bool puntero_comun [num_ciudades] = {false};
	
	cout << endl << "Introduzca dos ciudades para las cuales no existe camino";
	cout << " directo: " << endl;
	
	do
	{
		cout << "Ciudad 1: ";
		cin >> ciudad_1;
	} while(ciudad_1 < 0 || ciudad_1 >= num_ciudades);
	
	do 
	{
		cout << "Ciudad 2: ";
		cin >> ciudad_2;
	}while((ciudad_2 < 0 || ciudad_2 >= num_ciudades) && ciudad_2 == ciudad_1);
	
	for (int comun = 0; comun < num_ciudades; comun++)
	{
		if (matriz_ciudades[ciudad_1][comun] != 0 
			&& matriz_ciudades[ciudad_2][comun] !=0)
			{
				puntero_comun[comun] = true;
			}
	}
	
	int util_distancia = 0;
	
	for (int suma = 0; suma < num_ciudades; suma++)
	{
		if(puntero_comun[suma])
		{
			distancia[util_distancia] = matriz_ciudades[ciudad_1][suma] + 
						matriz_ciudades[ciudad_2][suma];
			util_distancia++;
		}
	}
	
	int pos;
	
	for (int min = 0; min < util_distancia - 1; min++)
	{
		if (distancia[min] < distancia[min+1])
		{
			distancia_min = distancia[min];
			pos = min;
		}
	}
	
	cout << "La ciudad intermedia es " << pos << " y la distancia a recorrer";
	cout << " es" << distancia_min;
	
	//Apartado d
	const int TERMINADOR = -1;
	int ciudades_conectadas[num_ciudades];
	int util_conectadas = 0;
	bool seguir = true;
	
	cout << endl;
	cout << "Ahora introducirá los índices de una serie de ciudades (0 - ";
	cout << num_ciudades - 1 << "para ver si están conectadas entre si" << endl;
	cout << "Para terminar introduce " << TERMINADOR;
	cout << endl;
	
	do
	{
		cin >> ciudades_conectadas[util_conectadas];
		util_conectadas++;
		
		seguir = ((ciudades_conectadas[util_conectadas-1] != TERMINADOR)
				  && (util_conectadas << num_ciudades) && 
				  (ciudades_conectadas[util_conectadas-1] >= 0));
	}while(seguir);
	
	bool todas_conectadas = true;
	bool estan_conectadas;
	
	for (int l = 0; l < util_conectadas; l++)
	{
		for(int n = l +1; l < util_conectadas; l++)
		{
			estan_conectadas = (ciudades_conectadas[l] == ciudades_conectadas[n]
			|| matriz_ciudades[l][n] > 0);
			
			if(!estan_conectadas)
			{
				todas_conectadas = false;
			}
		}
	}
	
	cout << endl;
	
	if(todas_conectadas)
	{
		cout << "Todas estan conectadas";
	}
	else
	{
		cout << "No todas están conectadas";
	}
	
	

	
	return 0;
}
