//FP 
//Javier Gómez López
/* Programa para asignar escaños a cada partido en función del número de
   partidos que se presenten y los votos recibidos por cada uno.
   
   Entradas: la cantidad de partidos politicos que se presentan y la cantidad
             de votos que ha recibido cada uno
   Salidas: los escaños que obtiene cada partido en función de la Ley_DHont
*/

#include <iostream>

using namespace std;

int main()
{
	//Declaración de variables
	const int MAX_PRIMO = 5000;
	const int MAX_DATOS = 2000;
	
	bool es_primo[MAX_PRIMO];
	int primos[MAX_DATOS];
	int n;
	
	for(int k = 0; k < MAX_PRIMO; k++)
	{
		es_primo[k] = true;
	}
	
	for(int m = 0; m < MAX_DATOS; m++)
	{
		primos[m] = m;
	}
	
	es_primo[0] = es_primo[1] = false;
	
	//Entradas
	cout << "Introduce un n para que se";
	cout << " muestren los primos menores que ese n: ";
	cin >> n;
	
	for (int i = 2; i<n; i++)
	{
		if (es_primo[i])
		{
			for (int j = 2; j*i <= n; j++)
			{ 
				es_primo[i*j] = false;
			}
		}
	}
	
	cout << "Los números primos menores que " << n << " son: ";
	cout << endl;
	for (int t = 2; t<n; t++)
	{
		if(es_primo[t])
		{
			cout << primos[t] << endl;
		}
	}
		
	return 0;
}
