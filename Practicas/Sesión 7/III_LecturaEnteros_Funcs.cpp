//FP 
//Javier Gómez López
/* Programa para mostrar los distintos puntos por los que pasa una recta,
   así como sus ecuaciones explicitas y si las dos rectas son paralelas,
   secantes o coindicentes.
   
   Entradas: los coeficientes de dos rectas
   Salidas: los puntos que siguen las rectas, la ecuacion explicita de cada 
            una y sus posiciones relativas
*/

#include <iostream>  //Inclusión de los recursos de entrada y salida
#include <string>    //Inclusión de los recursos string

using namespace std;

int LeeEntero (string titulo)
{
	int num;
	string cad_entrada;
	bool es_entero = true;
	
	do
	{	
		cout << titulo;
		getline (cin, cad_entrada);
		
		es_entero = (((cad_entrada[0] >= '0') && cad_entrada[0]
			<= '9') || ((cad_entrada[0] == '-') || (cad_entrada[0] == '+')));
	
		for (int i = 1; i < cad_entrada.length(); i++)
		{
			bool caracter_ok = (((cad_entrada[i] >= '0') && cad_entrada[i]
			<= '9') && ((cad_entrada[0] == '-') || (cad_entrada[0] == '+')
			|| ((cad_entrada[0] >= '0') && (cad_entrada [0] <= '9'))));
			
			if (caracter_ok == false)
			{
				es_entero = false;
				
				i = cad_entrada.length();
			}
			else
			{
				es_entero = true;
			}
		}
	}while (es_entero == false);
	
		
	num = stoi(cad_entrada);
	
	return num;
}


int LeeEnteroRango (string titulo, int menor, int mayor)
{
	int num_rango;
	
	do
	{
		num_rango = LeeEntero (titulo);
	} while (num_rango < menor || num_rango > mayor);
	
	return num_rango;
}

int LeeEnteroMayorOIgual (string titulo, int referencia)
{
	int num_comparacion;
	
	do
	{
		num_comparacion = LeeEntero (titulo);
	}while (num_comparacion < referencia);
	
	return num_comparacion;
}

int main()
{
	//Declaracion de variables
	int minimo, maximo, referencia;
	
	prueba = LeeEntero ("Prueba de leer entero: ");
	cout << endl;
	
	
	minimo = LeeEntero ("Introduzca un minimo: ");
	do
	{
		maximo = LeeEntero ("Introduzca un maximo (mayor que min): ");
	} while(maximo <= minimo);
	
	string cad_rango = "Prueba de leer entero en rango [";
	cad_rango = cad_rango + to_string (minimo) + "," + to_string (maximo);
	cad_rango = cad_rango + "]: ";
	LeeEnteroRango (cad_rango , minimo, maximo);
	cout << endl;
	
	referencia = LeeEntero ("Introduzca una referencia: ");
	string cad_mayorigual = "Prueba de leer entero mayor o igual a ";
	cad_mayorigual = cad_mayorigual + to_string(referencia) + ": ";
	LeeEnteroMayorOIgual (cad_mayorigual, referencia);
	return 0;
}
