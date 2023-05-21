//FP 
//Javier Gómez López
/* Programa para leer una serie de puntos y comprobar si están en una
   circunferencia definida también por el propio usuario
   
   Se leeran puntos hasta que se escriba FIN cuando se pregunte por el valor
   de la abscisa de un punto
   
   A continuación se pedirán los datos de una circunferencia y se dirá que 
   puntos están en esta y cuales no
*/

#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//Definimos la clase Punto2Dç
class Punto2D
{

private:
	
	double x;
	double y;
	
public:
	
	//Definimos el constructor con argumentos
	Punto2D (double la_x, double la_y):
		x(la_x),
		y(la_y)
	{}
	
	//Definimos el constructor sin argumentos
	Punto2D ()
	{
		x = 0;
		y = 0;
	}
	
	//Set coordenadas
	void SetCoordenadas (double abscisaPunto, double ordenadaPunto)
	{
		x = abscisaPunto;
		y = ordenadaPunto;
	}
	
	//Métodos Get
	double GetX()
	{
		return x;
	}
	
	double GetY()
	{
		return y;
	}
	
	// Calcula la distancia Euclídea del punto (objeto implícito) a otro que 
	// se recibe como argumento. 
	//
	// Recibe: otro, el punto respecto al cual que se quiere calcular la 
	// distancia euclídea.
	// Devuelve: la distancia entre los dos puntos. 

	double DistanciaEuclidea (Punto2D otro)
	{
		double dif_x = pow (x - otro.x, 2);
		double dif_y = pow (y - otro.y, 2);

		return (sqrt(dif_x + dif_y));
	}
};

//Definamos la clase circunferencia

class Circunferencia
{
	
private:
	
	static const double PI;  //La constante PI
	Punto2D centro;
	double radio; //PRE: 0 < radio
	
public:
	
	//Constructor con argumentos
	Circunferencia (Punto2D el_centro, double el_radio):
		centro(el_centro),
		radio(el_radio)
	{}
	
	//Metodos Get
	Punto2D GetCentro (void)
	{
		return centro;
	}
	
	double GetRadio(void)
	{
		return radio;
	}
	
	double GetDiametro (void)
	{
		return (radio*2);
	}
	
	double Longitud (void)
	{
		return (2 * PI * radio);
	}
	
	double Area (void)
	{
		return (PI * radio * radio);
	}
	
	//Método para comprobar si un punto se encuentra en 
	//en una circunferencia usando la distancia euclidea
	bool Contiene (Punto2D un_punto)
	{
		Punto2D el_centro = centro;
		double distancia = el_centro.DistanciaEuclidea(un_punto);
		
		return (distancia <= radio);
	}
}; 
//Definimos las constantes
const double Circunferencia::PI = 3.1415926;

//Definamos la clase ColeecionPuntos2D

class ColeccionPuntos2D
{
	
private:
	
	static const int TAMANIO = 50; //Tamaño máximo del vector
	Punto2D vector_puntos[TAMANIO];
	int total_puntos;
	
public:
	
	//Constructor sin argumentos
	ColeccionPuntos2D (void)
	{
		total_puntos = 0;
	}
	
	//Devuelve el numero total de puntos
	int TotalPuntos (void)
	{
		return total_puntos;
	}
	
	//Devuelve la capacidad
	int Capacidad (void)
	{
		return TAMANIO;
	}
	
	//Vacia la secuencia
	
	void EliminaTotal (void)
	{
		total_puntos = 0;
	}
	
	//Añade un punto nuevo al vector
	//PRE: total_puntos < TAMANIO
	//El nuevo elemento se coloca al final del vector
	//Si no hay espacio no se hace nada
	
	void Aniade (Punto2D el_punto)
	{
		if (total_puntos < TAMANIO)
		{
			vector_puntos[total_puntos] = el_punto;
			total_puntos++;
		}
	}
	
	//Devuelve el punto de la casilla indicada
	//PRE: 0 <= indice < total_alumnos
	
	Punto2D Elemento (int indice)
	{
		if(indice >= 0 && indice < total_puntos)
		{
			return vector_puntos[indice];
		}
	}
};

int main()  //Funcion principal
{
	//Declaramos la constante terminador y la coleccion de puntos
	ColeccionPuntos2D coleccion;
	const string TERMINADOR = "FIN";
	
	//Pedimos datos de puntos hasta que se escriba FIN en la abscisa
	cout << "Introduzca un máximo de " << coleccion.Capacidad() << "puntos";
	cout << endl << "Para terminar escrbia " << TERMINADOR << " cuando se le";
	cout << " pregunte por la abscisa de un punto" << endl;
	

	bool seguir = true;
	
	while (coleccion.TotalPuntos() < coleccion.Capacidad() && seguir)
	{
		string cad_abs;
		int abs = 0, ordenada;
		
		cout << "\t x: ";
		cin >> cad_abs;
			
		if(cad_abs != TERMINADOR)
		{
			abs = stoi(cad_abs);
		}
		else
		{
			seguir = false;
		}
		
		if(seguir)
		{
			cout << "\t y: ";
			cin >> ordenada;
			cout << endl;
		
		
			Punto2D punto(abs, ordenada);
			
			coleccion.Aniade(punto);
		}
	}
	
	cout << "-----------------------------------------" << endl;
	
	cout << "Se han registrado " << coleccion.TotalPuntos() << " puntos";
	cout << endl << endl;
	
	//Ahora definamos una circunferencia
	double centro_x, centro_y, radio;
	
	cout << "Ahora introduzca los datos que definen una circunferencia" << endl;
	cout << "Centro: " << endl << endl << "------------> x:";
	cin >> centro_x;
	cout << "------------> y:";
	cin >> centro_y;
	cout << endl << "Radio: ";
	cin >> radio;
	
	Punto2D centro (centro_x, centro_y);
	Circunferencia circunferencia (centro, radio);
	
	cout << endl << "-----------------------------------------" << endl;

	//Y ahora comprobamos cada punto si esta en la circunferencia
	
	for (int i = 0; i < coleccion.TotalPuntos(); i++)
	{
		if(circunferencia.Contiene(coleccion.Elemento(i)))
		{
			cout << "----->(" << coleccion.Elemento(i).GetX() << ",";
			cout << coleccion.Elemento(i).GetY() << ") está en la circunferencia";
			cout << endl;
		}
		else
		{
			cout << "----->(" << coleccion.Elemento(i).GetX() << ",";
			cout << coleccion.Elemento(i).GetY() << ") no está en la circunferencia";
			cout << endl;
		}
	}
	
	return 0;
	
}
