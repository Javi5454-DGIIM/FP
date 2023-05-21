//FP 
//Javier Gómez López
/* Programa para convertir dos unidades en funcion de unos valores que 
   que introduzca el usuario.
   
   Para ello trabajaremos con condicionales y conversion entre tipos
   de caracteres
   
   Entradas: 4 tokens que evaluaran lo que pide el usuario
   
   Salidas: las unidades convertidas
   
*/

#include <iostream> //Inclusión de los recursos E/S
#include <string>   //Inclusión de los recursos string
#include <cmath>    //Inclsuión de los recursos matemáticos

using namespace std;

int main()
{
	
	//Declaracion de variables
	string unidad_1, unidad_2;
	char limite;
	int exponente_1, exponente_2;
	int valor;
	double resultado;
	
	//Entradas
	cout << "> ";
	cin >> valor >> unidad_1 >> limite >> unidad_2;
	
	//Calculos
	bool datos_correctos = (valor >= 0 && limite == 'a' &&
	     (unidad_1 == "mm" || unidad_1 == "cm" || unidad_1 == "m"
	     || unidad_1 == "km") && (unidad_2 == "mm" || unidad_2 == "cm"
	     || unidad_2 == "m" || unidad_2 == "km"));
	     
		if (datos_correctos) {

			if (unidad_1 == "mm") {
				exponente_1 = -3;
			} else if (unidad_1 == "cm") {
				exponente_1 = -2;
			} else if (unidad_1 == "m") {
			exponente_1 = 0;
			} else {
				exponente_1 = 3;
			}
		
			if (unidad_2 == "mm") {
				exponente_2 = -3;
			} else if (unidad_2 == "cm") {
				exponente_2 = -2;
			} else if (unidad_2 == "m") {
				exponente_2 = 0;
			} else {
				exponente_2 = 3;
			}
		
		// Calculamos el resultado
		
		resultado = valor * pow(10, exponente_1 - exponente_2);
		cout << valor << " " << unidad_1 <<  " = " << resultado << " " 
		<< unidad_2;
		
	} else {
		cout << "Los datos introducidos son incorrectos";
	}

	return 0;
}
	
