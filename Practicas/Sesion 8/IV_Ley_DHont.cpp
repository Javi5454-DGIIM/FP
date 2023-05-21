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


struct Partido
{
	char sigla; //"Nombre" del partido
	long votos; //Votos recibidos;
	int escanios = 0;  //Escaños obtenidos;
};

int main ()
{
	//Declaracion de variables
	int numero_partidos;
	int num_escanios;
	double maximo_iteracion;
	
	//Entradas
	
	do
	{
		cout << "Introduzca el numero de partidos que se presentan: ";
		cin >> numero_partidos;
	} while(numero_partidos <= 0);
	
	Partido partidos[numero_partidos];
	int contador_escanio[numero_partidos];
	
	for (int i = 0; i < numero_partidos; i++)
	{
		cout << "Partido " << i+1 << endl;
		cout << "\t Sigla: ";
		cin >> partidos[i].sigla;
		partidos[i].sigla = toupper (partidos[i].sigla);
		
		cout << "\t Votos: ";
		cin >> partidos[i].votos;
	}
	
	do
	{
		cout << "Introduzca el numero de escaños a repartir: ";
		cin >> num_escanios;
	} while(num_escanios <= 0);
	
	//Calculos
	
	while (num_escanios > 0)
	{
		
		maximo_iteracion = 0;
		int k;
		int posicion_maximo;
		
		for (k = 0; k < numero_partidos; k++)
		{
			if (partidos[k].votos > maximo_iteracion)
			{
				maximo_iteracion = partidos[k].votos;
				posicion_maximo = k;
			}
		}
		
		partidos[posicion_maximo].escanios++;
		partidos[posicion_maximo].votos /= (partidos[posicion_maximo].escanios + 1);
		
		num_escanios--;
	}
	
	//Salidas
	for (int t = 0; t < numero_partidos; t++)
	{
		cout << "Escanios del partido " << partidos[t]. sigla << ": ";
		cout << partidos[t].escanios;
		cout << endl;
	}
		
	
	return 0;
}
