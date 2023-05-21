//FP 
//Javier Gómez López
/* Programa para leer un número de tres dígitos y separar
   sus números con barras.
   
   Para ello trabajaremos con filtros en forma de ciclos do-while y 
   los posteriores cálculos.
   
   Entradas: una cadena string de 3 dígitos.
   
   Salidas: otra cadena string que con los números de la original 
            separados
   
*/

#include <iostream> //Inclusión de los recursos E/S
#include <string>   //Inclusión de los recursos string

using namespace std;

int main()
{

    //Declaración de variables
    string cad_entrada;
    int entero_entrada, numero;

    int cuenta_digitos = 0;
    string SEPARADOR = " | ";
    
    string resultado = " | ";
    int resto;

	//Entradas
	do 
	{
		cout << "Introduzca un entero positivo: ";
		cin >> cad_entrada;
		entero_entrada = stoi(cad_entrada);
		numero = entero_entrada;
	} while (entero_entrada <= 0);
	
	
    //Cáclulos

    while (numero >= 10)
    {
    	resto = numero % 10;
    	
    	resultado = SEPARADOR + to_string(resto) + resultado;
    	
    	cuenta_digitos = cuenta_digitos + 1;
    	
    	numero = numero / 10;
    	
    }
    
    //Falta añadir aún el último dígito
    resultado = SEPARADOR + to_string(numero) + resultado;
    
    cuenta_digitos = cuenta_digitos + 1;
		                       
	//Salida
	
	cout << endl;
	cout << "El número tiene " << cuenta_digitos << " digitos" << endl;
	cout << "El número es: " << resultado << endl;
    
	return (0);
}
