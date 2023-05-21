//FP 
//Javier Gómez López
/* Programa para calcular la circunferencia centrada de mínima
   área de un rectángulo definido por el usuario tras dar la esquina superior 
   izquierda e inferior derecha de este.
   
   Entradas: los dos puntos que definen un rectángulo
   Salidas: el radio de la circunferencia mínima
*/

#include <iostream>   //Inclusión de los recursos de entrada y salida
#include <cmath>      //Inclusión de los recursos matemáticos

using namespace std;

struct Punto2D
{
	double x,y;
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

Punto2D CorteDiagonales (Rectangulo rectangulo)
{
	Punto2D corte;
	corte.x = fabs((rectangulo.sup_izq.x - rectangulo.inf_der.x)) / 2;
	
	corte.y = (rectangulo.sup_izq.y - rectangulo.inf_der.y) / 2;
	
	return corte;
}

double AreaRectangulo (Rectangulo rectangulo)
{
	double area = fabs(rectangulo.sup_izq.x - rectangulo.inf_der.x);
	area = area * fabs(rectangulo.sup_izq.y - rectangulo.inf_der.y);
	
	return area;
}

double AreaCircunferencia (Circunferencia circulo)
{
	const double PI = 6 * asin(0.5);
	double area = PI * pow(circulo.radio, 2);
	
	return area;
}

int main()
{
	//Declaración de variables y constantes
	const double RADIO_MIN = 0.5;
	const double SALTO = 0.25;
	
	Rectangulo rectangulo;
	Circunferencia circulo;
	double radio = RADIO_MIN;
	double area_rectangulo;
	double area_circulo = 0;
	
	//Entradas
	cout << "Introduzca el punto superior izquierdo del rectángulo: " << endl;
	cout << "\t X: ";
	cin >> rectangulo.sup_izq.x;
	cout << "\t Y: ";
	cin >> rectangulo.sup_izq.y;
	cout << endl;
	
	cout << "Introduzca el punto inferior derecho del rectángulo: " << endl;
	cout << "\t X: ";
	cin >> rectangulo.inf_der.x;
	cout << "\t Y: ";
	cin >> rectangulo.inf_der.y;
	cout << endl;
	
	//Calculos
	circulo.centro = CorteDiagonales(rectangulo);
	area_rectangulo = AreaRectangulo(rectangulo);
	
	while(area_circulo <= area_rectangulo)
	{
		circulo.radio = radio;
		area_circulo = AreaCircunferencia(circulo);
		radio = radio + SALTO;
	}
	
	//Salidas
	
	cout << "El area del rectangulo es: " << area_rectangulo << endl;
	cout << "El circulo que buscamos tiene su centro en (" << circulo.centro.x;
	cout << "," << circulo.centro.y << ") y su radio es " << circulo.radio;
	cout << endl;
	cout << "El area del circulo es " << area_circulo;
	
	return 0;
}
