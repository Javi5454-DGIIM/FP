//FP 
//Javier Gómez López
/* Programa para pasar de mayusuclas a minusculas sin utilizar toupper y 
   tolower.
   
   Para ello utilizaremos la equivalencia entre tipos enteros 
   y de carácter
   
   Entradas: una cadena de texto en mayusculas
   
   Salidas: la cadena transformada a minusuculas
   
*/

#include <iostream> //Inclusión de los recursos E/S
#include <string>  //Inclusión de los recursos string

using namespace std;

int main()
{
	//Declaracion de variables
	
	char letra_mayus;
	char letra_minus;
	
	//Entradas
	cout << "Introduzca una letra en mayúscula: ";
	cin >> letra_mayus;
	
	//Calculos
	letra_minus = char(letra_mayus + 32);
	
	//Salidas
	cout << "La letra en minúscula es: " << letra_minus;
	
	return (0);
}
