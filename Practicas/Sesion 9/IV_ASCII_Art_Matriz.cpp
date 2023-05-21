//FP 
//Javier Gómez López
/* Programa para crear usando la tecnica ASCII art diferentes figuras (circulo 
   y rectángulo) a partir de una matriz.
   
   Entradas: el centro de la circunferencia y el radio y las coordenadas del 
   			rectángulo.
   Salidas: el dibujo de dichas figuras
*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//Declaracion de estructuras
struct Punto2D
{
	int x,y;
};
	
struct Rectangulo
{
	Punto2D sup_izq, inf_der;
};
	
struct Circunferencia 
{
	Punto2D centro;
	double radio;
};
	
	

//Funciones

string EliminaPrimerosSeparadores (string cadena)
{
	int posicion = 0;
	int tamanio = cadena.length();
	
	while (isspace(cadena.at(posicion) && posicion < tamanio)) {
		posicion++;
	}
	
	string local;
	while (posicion < tamanio) {
		local.push_back(cadena.at(posicion));
		posicion++;
	}
		
	return local;
}

string EliminaUltimosSeparadores (string cadena)
{
	int longitud = cadena.length();
	
   	while (longitud > 0 && isspace(cadena.back())) {
		cadena.pop_back();
		longitud = cadena.length();
	}
        
	return cadena;
}

string EliminaSeparadoresTotales (string cadena)
{	
	return EliminaUltimosSeparadores(EliminaPrimerosSeparadores(cadena)); 
}

bool EsEntero (string entrada)
{
	entrada = EliminaSeparadoresTotales(entrada);
	
	int pos;
	bool es_entero = true;
	int tamanio = entrada.length();
	bool tiene_signo = (entrada.at(0) == '-' || entrada.at(0) == '+');
	
	if (tiene_signo) {
		
		pos = 1;
		
		if (pos == tamanio) {
			
			es_entero = false;
		}
	}
	else {
		
		pos = 0;
	}
		
	while (pos < tamanio&& es_entero) {
		char char_actual = entrada.at(pos);
		es_entero = isdigit(char_actual);
		pos++;
	}
	
	if (entrada.length() == 0) {
		
		es_entero = false;
	}
	
	return es_entero;
}

int LeeEntero (string titulo)
{
	string entrada;
	
	do {
		cout << titulo;
		getline(cin, entrada);
	} while (!EsEntero(entrada));

	int entero = stoi(entrada);
	
	return entero;
}

int LeeEnteroEnRango (string titulo, int menor, int mayor)
{
	int entero;
	bool en_rango = false;
	
	do {
		entero = LeeEntero(titulo);
		en_rango = (entero >= menor && entero <= mayor);
	} while (!en_rango);
	
	return entero;
}

int LeeEnteroMayor (string titulo, int referencia)
{
	int entero;
	bool es_mayor;
	
	do {
		entero = LeeEntero (titulo);
		es_mayor = (entero > referencia);
	} while (!es_mayor);
	
	return entero;
}

bool EstaEnRectangulo (Rectangulo rec, Punto2D punto)
{
	bool x = (punto.x>=rec.sup_izq.x && punto.x<=rec.inf_der.x);
	bool y = (punto.y<=rec.sup_izq.y && punto.y>=rec.inf_der.y);
	
	return (x && y);
}

bool EstaEnCirculo (Circunferencia circulo, Punto2D punto)
{
	int dist_centro_punto_x = pow(punto.x - circulo.centro.x, 2);
	int dist_centro_punto_y = pow(punto.y - circulo.centro.y, 2);
	int dist_centro_punto = dist_centro_punto_x + dist_centro_punto_y;
	
	return (pow(circulo.radio, 2) >= dist_centro_punto);
}


int main()
{

	//Declaracion de variables y constantes
	const int NUM_FILAS = 51;
	const int NUM_COLS = 51;
	const char FONDO = '.';
	const char DIBUJO = '*';
	const char INTERSECCION = 'x';
	
	char matriz_dibujo[NUM_FILAS][NUM_COLS];
	
	Rectangulo rectangulo;
	Circunferencia circulo;
	
	//Entrada circulo
	cout << "Introduce las coordenadas del centro del circulo: " << endl;
	string entrada = "\tx: ";
	circulo.centro.x = LeeEnteroEnRango(entrada, 0, NUM_COLS - 1);
	entrada = "\ty: ";
	circulo.centro.y = LeeEnteroEnRango(entrada, 0, NUM_FILAS - 1);
	
	entrada = "\nIntroduce el radio del círculo (>0): ";
	circulo.radio = LeeEnteroMayor(entrada, 0);
	cout << endl;
	
	//Operaciones circulo
	Punto2D punto_dibujar;
	
	for(punto_dibujar.y = 0; punto_dibujar.y < NUM_FILAS; punto_dibujar.y++)
	{
		for(punto_dibujar.x = 0; punto_dibujar.x < NUM_COLS; punto_dibujar.x++)
		{
			if(EstaEnCirculo(circulo, punto_dibujar))
			{
				matriz_dibujo[punto_dibujar.y][punto_dibujar.x] = DIBUJO;
			}
			else
			{
				matriz_dibujo[punto_dibujar.y][punto_dibujar.x] = FONDO;
			}
		}
	}
	
	//Salida circulo
	
	for(int i = 0; i < NUM_FILAS; i++)
	{
		for(int j = 0; j < NUM_COLS; j++)
		{
			cout << matriz_dibujo[i][j];
		}
		
		cout << endl;
	}
	
	//Entrada rectangulo
	
	cout << "Introduce los puntos que definen al rectángulo: " << endl;
	
	cout << "\tEsquina superior izquierda:" << endl;
	entrada = "\tx: ";
	rectangulo.sup_izq.x = LeeEnteroEnRango(entrada, 0, NUM_COLS-1);
	entrada = "\ty: ";
	rectangulo.sup_izq.y = LeeEnteroEnRango(entrada, 0, NUM_FILAS-1);
	
	cout << "Esquina inferior derecha:" << endl;
	entrada = "\tx: ";
	rectangulo.inf_der.x = LeeEnteroEnRango(entrada, 0, NUM_COLS-1);
	entrada = "\ty: ";
	rectangulo.inf_der.y = LeeEnteroEnRango(entrada, 0, NUM_FILAS-1);
	
	//Calculos rectangulo
	
	for(punto_dibujar.y = 0; punto_dibujar.y < NUM_FILAS; punto_dibujar.y++)
	{
		for(punto_dibujar.x = 0; punto_dibujar.x < NUM_COLS; punto_dibujar.x++)
		{
			if(EstaEnRectangulo(rectangulo, punto_dibujar))
			{
				matriz_dibujo[punto_dibujar.y][punto_dibujar.x] = DIBUJO;
				
				if(EstaEnCirculo(circulo, punto_dibujar))
				{
					matriz_dibujo[punto_dibujar.y][punto_dibujar.x] = 
					INTERSECCION;
				}	
			}
		}
	}
	
	//Salida rectangulo
	
	for(int m = 0; m < NUM_FILAS; m++)
	{
		for(int k = 0; k < NUM_COLS; k++)
		{
			cout << matriz_dibujo[m][k];
		}
		
		cout << endl;
	}
	
	return 0;
}
