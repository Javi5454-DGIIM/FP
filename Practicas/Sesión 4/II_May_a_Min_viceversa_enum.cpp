//FP 
//Javier Gómez López
/* Programa para reconocer el tipo de letra introducida por el usuario.
   
   Para ello utilizaremos un tipo enumerado para clasificar las letras
   
   Entradas: un caracter
   
   Salidas: el tipo de caracter (mayus, minus u otros) que es
   
*/

#include <iostream> //Inclusión de los recursos E/S

using namespace std;

enum class TipoCaracter 
               {mayuscula, minuscula, otro};

int main()
{
	//Declaración de variables
	char letra_original;
	char letra_convertida;
	
	const int DIFERENCIA_ABECEDARIO = 'a' - 'A';
	
	//Entradas
	cout << "Introduzca una letra o bien mayuscula o bien minuscula: ";
	cin >> letra_original;
	
	//Calculos
	TipoCaracter tipo_letra;
	
	if (letra_original >= 'A' && letra_original <= 'Z')
	{
		letra_convertida = letra_original + DIFERENCIA_ABECEDARIO;
		tipo_letra = TipoCaracter::mayuscula;
	}
	else if (letra_original >= 'a' && letra_original <= 'z')
	{
		letra_convertida = letra_original - DIFERENCIA_ABECEDARIO;
		tipo_letra = TipoCaracter::minuscula;
	}
	else
	{
		tipo_letra = TipoCaracter::otro;
	}
	
	//Salidas
	
	if (tipo_letra == TipoCaracter::mayuscula)
	{
		cout << "La letra era una mayuscula. Una vez convertida es: ";
		cout << letra_convertida;
	}
	else if (tipo_letra == TipoCaracter::minuscula)
	{
		cout << "La letra era una minuscula. Una vez convertida es: ";
		cout << letra_convertida;
	}
	else
	{
		cout << "El caracter no era una letra";
	}
	
	return(0);
}
