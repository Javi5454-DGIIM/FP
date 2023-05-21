/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 2
// 
/*	
   Programa que calcula el dinero que se obtiene al realizar una 
   inversión un número dado de años.

   Entradas: capital a invertir (capital_inicial)
			 interés a aplicar (interes)
			 número de años de la inversión (numero_anios)
   Salidas:  dinero total obtenido por la inversión 
			 (capital + ganancia obtenida) calculado -anualmente- por: 
				total = capital + (capital * interes/100)
			  reinvirtiendo cada año el nuevo total.
			  
	Se comprueba la validez de los valores leídos usando filtros	  
*/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	const int MIN_CAPITAL = 1000;
	const int MIN_INTERES =  0;
	const int MAX_INTERES = 10;
	
	// Entradas: 
	double interes, capital_inicial;
	int numero_anios;
	   
	// Salidas
	double capital_objetivo;
	
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 

	// Lectura y filtrado de datos

	const string mensaje_capital =  "Introduzca capital inicial (capital >= "
	      + to_string(MIN_CAPITAL) + "): ";
	const string mensaje_interes =  "Introduzca % interes (" 
	      + to_string(MIN_INTERES) + "-" +  to_string(MAX_INTERES) + "): ";
	      	      
	do {	
		cout << mensaje_capital;
		cin >> capital_inicial;
	} while (capital_inicial < MIN_CAPITAL);
		
	do {	
		cout << mensaje_interes;
		cin >> interes;   
   	} while ((interes<= MIN_INTERES) || (interes>MAX_INTERES));

	cout << endl;
	
	// Cálculos y presentación de resultados
	
	capital_objetivo = capital_inicial; // Capital inicial
	
	numero_anios  = 0; // contador de años 
   
	while (capital_objetivo <= capital_inicial * 2) {  //Para comprobar si se
                                                       //se ha doblado
		capital_objetivo = capital_objetivo  +  
		                   (capital_objetivo * (interes / 100.0));   

		numero_anios++; // actualizar el año de inversión 
   }

	cout << endl;
	cout << "Para doblar el capital necesitará como mínimo: " <<  numero_anios
	     << " años";
   
   return 0;
}
