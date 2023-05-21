//FP 
//Javier Gómez López
/* Programa para encriptar una letra mauyuscula en función
   de una clave que introduzca un usuario.
   
   Para ello utilizaremos la tabla de caracteres ASCII
   
   Entradas: distancia recorrida en kms, litros de gasolina consumidos
   y litros de gasolina restantes
   
   Salidas: km/litro, litros/100km y kilómetros de autonomía restantes
   
*/

#include <iostream> //Inclusión de los recursos E/S
#include <cmath>    //Inclusión de los recursos de matemáticas

using namespace std;

int main()
{
	//Declaración ed variables
	char letra_entrada;
	int clave_entrada; 
	int clave_acotada;
	
	char letra_salida;
	
	//Entrada
	cout << "La longitud de su clave es: ";
	cin >> clave_entrada;
	cout << "El caracter a cifrar es: ";
	cin >> letra_entrada;
	
	//Calculos
	clave_acotada = clave_entrada%25;
	letra_salida = char(letra_entrada + clave_acotada);
	
	//Salidas
	cout << "El caracter encriptado es: " << letra_salida << endl; 
	
	
	return (0);
}
