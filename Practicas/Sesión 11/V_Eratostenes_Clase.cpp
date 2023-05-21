//FP 
//Javier Gómez López
/* Programa para calcular los números primos menores que n usando una clase
   
   Entradas: numero n para calcular los primos menores que ese n
   
   Salidas: todos los primos menores que ese n
*/

#include <iostream>  //Inclusión de los recursos de entrada y salida

using namespace std;

class Erastostenes
{

private:
	
	//Todos los primos calculados serán menores que TAMANIO
	static const int TAMANIO = 500;
	int primos[TAMANIO];
	bool es_primo [TAMANIO];
	
	//PRE: 0 <= total_utlizados <= TAMANIO
	int total_utilizados;  //Número de casillas ocupadas
	
public:
	
	Erastostenes ()
	{
		total_utilizados = 0;
		
		for (int i = 0; i < TAMANIO; i++)
		{
			primos[i] = 0;
			es_primo[i] = true;
		}
	}
	
	void CalculaHasta (int n)  //Método de la criba
	{
		for(int num = 2; num*num < n; num++) //Empezamos en 2 y terminamos
		{                                  //si num^2 es < n
			if (es_primo[num]) 
			{
				for (int k = 2; k*num <= n; k++)  //Tachamos los multiplos
				{                                 //del primo
					es_primo[k*num] = false;
				}
			}
		}
		
		for (int i = 1; i <= n; i++)
		{
			if(es_primo[i])
			{
				primos[total_utilizados] = i;
				total_utilizados++;
			}
		}
	}
	
	int TotalCalculados()
	{	
		return total_utilizados;
	}
	
	int Elemento (int k)
	{
		return primos[k];
	}
	
	int GetMaximo()
	{
		return primos[total_utilizados - 1];
	}
	
};

//Funciones
int LeeEnteroEnRango (string mensaje, int uno, int otro)
{
	int numero;
	
	do {
		cout << mensaje;
		cin >> numero;
	} while ((numero<uno) || (numero> otro));
	
	return (numero);
}

int main()     //Función principal
{
	//Declaramos el objeto
	Erastostenes criba;
	
	cout << "Se calcularan un máximo de 500 primos" << endl;
	cout << "Se consideraran los primos menores que el valor límite" << endl;
	
	string msg = "Valor límite (entre 1 y 500): ";
	int limite = LeeEnteroEnRango(msg, 1, 500); //Pedimos el valor máximo 
	
	cout << endl;
	cout << "Generando primos entre 1 y " << limite << endl;
	cout << endl;
	
	criba.CalculaHasta(limite);  //Calculamos los primos con la criba
	
	cout << "Se han encontrado un total de " << criba.TotalCalculados();
	cout << " numeros primos" << endl;
	
	cout << endl;
	cout << "El máximo primo es : " << criba.GetMaximo() << endl;
	cout << endl;
	
	cout << "-------------------------------------" << endl;
	
	//mostramos los elementos primos
	for (int i  = 0; i < criba.TotalCalculados(); i++)
	{
		cout << i + 1 << "." << "\t" << criba.Elemento(i) << endl;
	}
	
	return 0;
}
