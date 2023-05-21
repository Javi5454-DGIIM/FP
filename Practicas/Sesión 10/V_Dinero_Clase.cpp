//FP 
//Javier Gómez López
/* Programa para calcular el precio final de un producto a partir de su precio
   inicial, un incremento mensual y un número de meses..
   
   Entradas: precio inical del producto, el incremento mensual, y el nº de 
   meses.
   Salidas: el precio final de dicho producto
*/

#include <iostream>  //Inclusión de los recursos de entrada y salida
#include <string>   //Inclusión de los recursos string

using namespace std;			

bool EsEntero(string cadena) //Funcion para saber si un numero es entero
{
	bool es_entero = true;
	int longitud = cadena.size() - 1;
	
	for (int i = 1; i <= longitud; i++)
	{
		bool es_numero = isdigit(cadena.at(i));
		
		if (!es_numero)
		{
			es_entero = false;
		}
	}
	
	if(!isdigit(cadena.at(0)) && cadena.at(0) != '-' && cadena.at(0) != '+')
	{
		es_entero = false;
	}
	
	return (es_entero);
}

int LeeEntero (string titulo)
{
	string respuesta;
	bool es_entero;
	
	do
	{
		cout << titulo;
		cin >> respuesta;
		es_entero = EsEntero(respuesta);
	} while(!es_entero);
	
	return (stoi(respuesta));
}

int LeeEnteroMinimo (string titulo, int min)
{
	
	int num;
	
	do
	{
		num = LeeEntero(titulo);
	} while(num < min);
	
	return num;
}

class Dinero
{
private:
	//Los campos de la clase serán los euros y los centimos
	int euros;  //PRE: 0 <= euros
	int centimos;  //PRE: 0 <= centimos <100
	
public:
	
	//Constructor vacio
	Dinero (void) {
		euros = 0;
		centimos = 0;
	}
	
	//Constructor con una cantidad general
	Dinero (double cantidad)
	{
		euros = int(cantidad);
		centimos = 100 * (cantidad - int(cantidad));
	}
		
	//Metodos Get
	int GetEuros(void)
	{
		return euros;
	}
	
	int GetCentimos(void)
	{
		return centimos;
	}
	
	//Metodos Set
	
	void SetEuros(int los_euros)
	{
		euros = los_euros;
	}
	
	void SetCentimos(int los_centimos)
	{
		centimos = los_centimos;
	}
	
	
	void AgruparDinero (int los_centimos)
	{
		SetCentimos(los_centimos % 100);
		SetEuros(los_centimos / 100);
	}
	
	//Metodo To_String
	
	string To_String_Dinero ()
	{
		return (to_string(euros) + " euros y " + to_string(centimos) +	
				" centimos");
	}
	
};

int main ()
{
	//Declaracion de variables
	Dinero dinero(8.79);
	int centimos_totales;
	double interes;
	int meses;
	const int MIN = 0;
	
	cout << dinero.GetCentimos() << endl;
	cout << dinero.GetEuros();
					
	return 0;
}
