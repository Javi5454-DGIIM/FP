//FP 
//Javier Gómez López
/* Programa para calcular la media aritmética y la desviación típica.
   
   Para ello utilizaremos distintos algoritmos de cálculo que se muestran
   en el enunciado del ejercico
   
   Entradas: la altura de tres diferentes personas
   
   Salidas: la media y la desviación típica de dichas alturas
   
*/

#include <iostream> //Inclusión de los recursos E/S
#include <cmath>    //Inclusión de los recursos de matemáticas

using namespace std;

int main()
{
	double altura_1;  //Declaración de variables
	double altura_2;
	double altura_3;
	
	double media;
	double desviacion_tipica;
	
	//Entradas
	cout << "Altura 1: ";
	cin >> altura_1;
	cout << "Altura 2: ";
	cin >> altura_2;
	cout << "Altura 3: ";
	cin >> altura_3;
	
	//Calculos
	media = (altura_1 + altura_2 + altura_3) / 3;
	double aux = pow(altura_1 - media, 2) + pow(altura_2 - media, 2);
	aux = aux + pow(altura_3 - media, 2);
	desviacion_tipica = sqrt(aux / 3);
	
	//Salidas
	cout << "La media es: " << media << endl;
	cout << "La desviación típica es: " << desviacion_tipica;
	
	return (0);
	
}
