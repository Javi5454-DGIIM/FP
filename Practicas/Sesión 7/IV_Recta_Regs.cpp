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

struct Punto2D 
{
	double x, y;
};

struct Recta
{
	double A, B, C;
};

double Eje_X (double x, Recta recta)
{
	double y;
	
	y = (-recta.C + (x * -recta.A)) / recta.B;
	
	return y;
}

double Eje_Y (double y, Recta recta)
{
	double x;
	
	x = ((-recta.B * y) - recta.C) / recta.A;
	
	return x;
}

void IntervaloX (Recta recta, int inicio, int fin, double salto)
{
	for (double x = inicio; x<= fin; x = x + salto)
	{
		double y;
		y = Eje_X(x, recta);
		cout << endl << "x: " << x << " y: " << y;
	}
}

void IntervaloY (Recta recta, int inicio, int fin, double salto)
{
	for (double y = inicio; y<=fin; y = y + salto)
	{
		double x;
		x = Eje_Y (y, recta);
		cout << endl << "y: " << y << " x: " << x;
	}
}

void EcuacionRecta1 (Recta recta)
{
	double m = -recta.A / recta.B;
	double n = -recta.C / recta.B;
	
	cout << endl; 
	cout << "La ecuación es: y = " << m << "x + " << n;
}

string EcuacionRecta2 (Recta recta)
{
	double m = -recta.A / recta.B;
	double n = -recta.C / recta.B;
	
	string ecuacion;
	
	ecuacion = "Y = " + to_string(m) + "x + " + to_string(n);
	
	return ecuacion;
}

string PosicionRecta (Recta recta1, Recta recta2)
{
	double m1 = -recta1.A / recta1.B;
	double n1 = -recta1.C / recta1.B;
	double m2 = -recta2.A / recta2.B;
	double n2 = -recta2.C / recta2.B;
	string posicion;
	
	if (m1 == m2)
	{ 
		if (n1 == n2)
		{
			posicion == "Coincidentes";
		}
		else
		{
			posicion == "Paralelas";
		}
	}
	else
	{
		posicion == "Secantes";
	}
	
	return posicion;
}

Punto2D PuntoCorte (Recta recta1, Recta recta2)
{
	double m1 = -recta1.A / recta1.B;
	double n1 = -recta1.C / recta1.B;
	double m2 = -recta2.A / recta2.B;
	double n2 = -recta2.C / recta2.B;
	Punto2D punto_corte;
	
	punto_corte.x = (-n1 + n2) / (m1 - m2);
	punto_corte.y = Eje_Y (punto_corte.x, recta1);
	
	return punto_corte;
}

bool EstaEnRecta (Punto2D punto, Recta recta)
{
	bool pertenece;
	pertenece = recta.A * punto.x + recta.B * punto.y + recta.C == 0;
	
	return pertenece;
}


int main()
{
	//Declaracion de variables
	Punto2D punto_corte;
	Recta recta1, recta2;
	string ecuacion_explicita;
	
	//Entrada
	cout << "Introduzca los coeficientes de la recta r (A, B, C)";
	cout << endl;
	cout << "\t Valor A: ";
	cin >> recta1.A;
	
	cout << "\t Valor B: ";
	cin >> recta1.B;
	
	cout << "\t Valor C: ";
	cin >> recta1.C;
	
	cout << "Introduzca los coeficientes de la recta s (A, B, C)";
	cout << endl;
	cout << "\t Valor A: ";
	cin >> recta2.A;
	
	cout << "\t Valor B: ";
	cin >> recta2.B;
	
	cout << "\t Valor C: ";
	cin >> recta2.C;
	
	cout << "Muestreo de puntos en funcion de x de la recta r: ";
	cout << endl;
	IntervaloX(recta1, -10, 10, 1);
	cout << endl;
	cout << endl;
	
	cout << "Muestreo de puntos en funcion de y de la recta r: ";
	cout << endl;
	IntervaloY(recta1, -5, 5, 0.5);
	cout << endl;
	cout << endl;
	
	cout << "Muestreo de puntos en funcion de x de la recta s: ";
	cout << endl;
	IntervaloX(recta2, -10, 10, 1);
	cout << endl;
	cout << endl;
	
	cout << "Muestreo de puntos en funcion de y de la recta s: ";
	cout << endl;
	IntervaloY(recta2, -5, 5, 0.5);
	cout << endl;
	cout << endl;
	
	cout << "Ecuacion explicita de la recta r: ";
	cout << endl;
	EcuacionRecta1(recta1);
	cout << endl;
	cout << "Usando string: " << EcuacionRecta2(recta1);
	cout << endl;
	
	cout << "Ecuacion explicita de la recta s: ";
	cout << endl;
	EcuacionRecta1(recta2);
	cout << endl;
	cout << "Usando string: " << EcuacionRecta2(recta2);
	cout << endl;
	
	if (PosicionRecta(recta1, recta2) == "secantes")
	{
		cout << endl;
		cout << "Se cortan en (" << punto_corte.x << "," << punto_corte.y 
		     << ")" << " [" << PosicionRecta(recta1, recta2) << "]";
	}
	else
	{
		cout << endl;
		cout << "La posicion de estas rectas es: " << PosicionRecta(recta1,
		         recta2);
	}
	
	string punto_x, punto_y;
	Punto2D punto_comprobacion;
	const string TERMINADOR = "FIN";
	
	
	cout << "Ahora introducirá puntos (x,y) para comprobar si se encuentran";
	cout << " en la recta r. Para terminar escriba FIN";
	cout << endl;
	
	while (punto_x != TERMINADOR && punto_y != TERMINADOR)
	{
		cout << "Introduzca el punto X: ";
		cin >> punto_x;
		cout << "Introduzca el punto Y: ";
		cin >> punto_y;
		
		punto_comprobacion.x = stoi (punto_x);
		punto_comprobacion.y = stoi (punto_y);
		
		if (EstaEnRecta(punto_comprobacion, recta1))
		{
			cout << "Si esta en la recta";
			cout << endl;
		}
		else
		{
			cout << "No está en la recta";
			cout << endl;
		}
	}
	
	return 0;
}
