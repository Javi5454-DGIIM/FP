//FP 
//Javier Gómez López
/* Programa para calcular el numero de veces que aparece cada letra mayúscula
   tras leer un numero indefinido de datos (hasta encontrar un '.')
   
   Entradas: caracteres a gusto del usuario
   
   Salidas: la cantidad de veces que aparece cada mayúsucla
*/

#include <iostream>  //Inclusión de los recursos de entrada y salida
#include <string>    //Inclusión de los recursos string

using namespace std;

//Declaramos constante global
const int MAYUSCULAS = 'Z' - 'A';

class ContadorMayusculas
{
private:
	
	int contadores[MAYUSCULAS];
	string cad_salida;
	
public: 

	ContadorMayusculas(){
		
		for (int i; i < MAYUSCULAS; i++)
		{
			contadores[i] = 0;
		}
	}
	
	//Metodo Get
	
	int CuantasHay(char letra)
	{
		int pos = letra - 'A';
		return contadores[pos];
	}
	
	
	void IncrementrarCuenta (char letra)
	{
		int pos = letra - 'A';
		contadores[pos] ++;
	}
	
	string MostrarResultados (char letra)
	{
		
		cad_salida = " -------> " + to_string(CuantasHay(letra));
		
		return cad_salida;
	}
};


int main()  //Funcion Principal
{
	//Declaracion de variables
	char c;
	ContadorMayusculas cuenta;
	
	//Entrada de datos
	cin >> c;
	
	while (c != '.')
	{
		if (isupper(c))
		{
			cuenta.IncrementrarCuenta(c);
		}
		
		cin >> c;
	}
	
	//Calculos y salidas
	for (int i = 0; i < MAYUSCULAS; i++)
	{
		char letra = i + 'A';
		if (cuenta.CuantasHay(letra) != 0)
		{
			cout << "\t";
			cout << letra << cuenta.MostrarResultados(letra) << endl;
		}
	}
	
	return 0;
}
