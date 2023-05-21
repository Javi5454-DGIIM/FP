//FP 
//Javier Gómez López
/* Programa que calcula e imprime:
	a) el valor de una gaussiana, dados sus parámetros (desviación típica -s-   
	   y esperanza -m-) modularizando con funciones.
	b) el valor aproximado de la CDF(x) modularizando con funciones.
	para distintos valores de x comprendidos entre m-3s y m+3s.

	Entradas: parámetros de la gaussiana (desviacion -s-, y esperanza -m-) 
	Salidas:  Para valores de x entre m-3s y m+3s: 	
*/

#include <iostream>  //Inclusión de los recursos de entrada y salida
#include <string>   //Inclusión de los recursos string
#include <cmath>    //Inclusión de los recursos matemáticos
#include <iomanip>

using namespace std;

const double PI = 3.14159265358979323846;


//Declaracion de la clase gaussiana
class Gaussiana
{
private:
	double esperanza;
	double desviacion;
	
public:
	
	//Constructor
	Gaussiana (double la_esperanza, double la_desviacion)
	{
		esperanza = la_esperanza;
		desviacion = la_desviacion;
	}
	
	double Gauss(double x)
	{
		return (exp (-0.5 * pow ((x - esperanza)/desviacion, 2)) / 
		        (desviacion * sqrt(2*PI)));
	}
	
	double CDF_1 (double x)
	{
		const double SALTO_CDF = 0.001;	
	
		// Cálculos de la CDF (fuerza bruta, no está optimizado)
		
		double abscisa_inic = esperanza-(3*desviacion); 
		double abscisa_fin  = x; 
		
		// Valor común que puede precalcularse   
		double d = desviacion*sqrt(2*PI);
	
		// Acumular g(x)
		
		double suma_g_abs = 0.0; 
		
		for (double abs=abscisa_inic; abs<abscisa_fin; abs+=SALTO_CDF) {
		
			double g_abs = exp (-0.5*pow((abs-esperanza)/desviacion, 2)) / d;
			suma_g_abs += g_abs; 
		}
	
		return (suma_g_abs * SALTO_CDF); 
	}	
	
	double CDF_2 (double x)
	{
		const double B0 =  0.231641900;
		const double B1 =  0.319381530;
		const double B2 = -0.356563782;
		const double B3 =  1.781477937;
		const double B4 = -1.821255978;
		const double B5 =  1.330274429;
	
		// Estandarizar la distribución gaussiana  
		// Si x -> N(m,s) y z = (x-m)/s entonces z -> N(0,1)    
		
		double z = (x-esperanza)/desviacion; // variable aleatoria N(0,1)  
		
		double t = 1.0 / (1 + B0*fabs(z));
		double t2 = t*t;
		double t3 = t2*t; // t*t*t
		double t4 = t3*t; // t*t*t*t
		double t5 = t4*t; // t*t*t*t*t
		
		double g_std_x = exp (-0.5 * pow ((z - 0)/1, 2)) / 
		        (1 * sqrt(2*PI));
		double w = 1.0 - g_std_x * (B1*t + B2*t2 + B3*t3 + B4*t4 + B5*t5);
	
		return (x>=0.0 ? w : 1.0-w);
	}
	
	//Metodos Get
	
	double GetEsperanza (void)
	{
		return esperanza;
	}
	
	double GetDesviacion (void)
	{
		return desviacion;
	}
};


int main()
{
	
	const double NUM_STDV = 3.0;
	const double SALTO_X  = 0.25;

	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales
	
	//Declaracion de variables
	double esperanza;
	double desviacion;
	
	//Entradas
	cout << "Introduzca la esperanza: ";
	cin >> esperanza;
	
	do
	{
		cout << "Introduzca la desviación tipica (>0): ";
		cin >> desviacion;
	}while (desviacion <= 0);
	
	Gaussiana la_gaussiana(esperanza,desviacion); //Declaramos el objeto 
												  //gaussiana
	
	double min_x = esperanza - NUM_STDV*
				   desviacion;
	double max_x = esperanza + NUM_STDV*
				   desviacion;
				   
	for (double x=min_x; x<=max_x; x+=SALTO_X) {
		
		cout << "G(" << setw(11) << setprecision(7) << x << ") = " 
			 << setw(10) << setprecision(7) << la_gaussiana.Gauss(x) 
			 << " ----- ";
		cout << "CDF_1 (" << setw(11) << setprecision(7) << x << ") = " 
				 << setw(10) << setprecision(7) << la_gaussiana.CDF_1(x) 
				 << " ----- ";
		cout << "CDF_2 (" << setw(11) << setprecision(7) << x << ") = " 
				 << setw(10) << setprecision(7) << la_gaussiana.CDF_2(x);			
		cout << endl;
	}
	
	return 0;
}
