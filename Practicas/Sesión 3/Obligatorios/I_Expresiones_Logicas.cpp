//FP 
//Javier Gómez López
/* Programa para trabajar con distintas expresiones lógicas según
   lo que se nos pide en el enunciado del ejercicio.
   
   Para ello usaremos los distintos operadores lógicos y variables
   de tipo booleano que nos devolveran un valor true (1) or false (0).
   
   Primero pediremos las variables al usuario y después imprimiremos 
   el resultado (true or false) tras las operaciones
   
   Entradas: una letra, una edad, un año, una distancia y dos valores enteros.
   Salidas: el resultado de las distintas operaciones lógicas  
*/

#include <iostream> //Inclusión de los recursos de entrada y salida

using namespace std;

int main()
{
	//Declaración de variables
	char letra;
	int edad;
	int fecha;
	double distancia;
	int valor_1;
	int valor_2;
	
	const double LIMITE = 54.5;
	
	//Entradas
	cout << "Introduzca una letra: ";
	cin >> letra;
	cout << "Introduzca una edad: ";
	cin >> edad;
	cout << "Introduzca un año: ";
	cin >> fecha;
	cout << "Introduzca una distancia: ";
	cin >> distancia;
	cout << "Introduzca un valor a comparar: ";
	cin >> valor_1;
	cout << "Introduzca otro valor a comparar con el anterior: ";
	cin >> valor_2;
	
	//Calculos
	bool mayus_minus = int(letra) >= 65 && int(letra) <=90;
	bool adulto = edad >= 18 && edad < 67;
	bool bisiesto = fecha%4 == 0 && fecha%100 != 0;
	bool distancia_comparacion = distancia < LIMITE;
	bool valor_menor = valor_1 < valor_2;
	bool valor_igual = valor_1 == valor_2;
	bool valor_mayor = valor_1 > valor_2;
	
	//Salidas
	cout << "¿La letra introducida es mayúscula? " << mayus_minus << endl;
	cout << "¿Es la edad mayor que 18 y menor que 67? " << adulto << endl;
	cout << "¿Es el año bisiesto? " << bisiesto << endl;
	cout << "¿Es la distancia menor que el límite? " << distancia_comparacion;
	cout << endl;
	cout << "¿Es el valor_1 menor que el valor_2? " << valor_menor << endl;
	cout << "¿Es el valor_1 igual al valor_2? " << valor_igual << endl;
	cout << "¿Es el valor_1 mayor que el valor_2? " << valor_mayor;
	
	
	return (0);
}
