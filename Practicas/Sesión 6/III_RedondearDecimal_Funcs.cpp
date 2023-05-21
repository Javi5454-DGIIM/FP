//FP 
//Javier Gómez López
/* Programa que permitirá al usuario redondear un número decimal según
   la precisión que él elija
   
   Para ello crearemos una función que llamaremos potencia y otra que será
   redondeo
   
   Entradas: un número decimal y el número de decimales que deseamos redondear
   Salidas: el número decimal redondeado
   
*//

#include <iostream> // Inclusión de los recursos de E/S
#include <cmath> // Inclusión de los recursos matemáticos
#include <iomanip>

using namespace std;


double Potencia (double base, int exponente){

	
	double potencia = 1.0;
	
	// Si el exponente es positivo
	
	if (exponente >= 0){
		
		for (int i = 1; i <= exponente; i = i + 1){
			potencia = potencia * base;
		}
	}
	
	// Si el exponente es negativo
	
	else{
		
		for (int i = 1; i <= (exponente - 2*exponente); i = i + 1){
			potencia = (potencia / base);
		}
	}
	
	return (potencia);
}

// 2. Función Redondear

double Redondear (double numero, double cifra_red){
	
	double num_aumentado;
	double num_redondeado;
	
	num_aumentado = numero * Potencia (10, cifra_red);
	
	if ((num_aumentado - floor(num_aumentado)) >= 0.5){
		
		num_redondeado = (floor(num_aumentado) + 1) * Potencia (10, -cifra_red);
	}
	
	else{
		
		num_redondeado = floor(num_aumentado) * Potencia (10, -cifra_red);
	}
	
	return (num_redondeado);
}

int main () // Programa principal
{
	// Declaración de datos
	
	double numero; // Número a redondear;
	int cifra_redondeo; // Cifra hasta la que se quiere redondear
	double numero_redondeado; // Es el resultado del programa
	
	// Entrada de datos
	
	cout << "Introduzca el número que desea redondear: ";
	cin >> numero;
	
	// Filtro para la cifra hasta la que se quiere redondear
	
	do{
		cout << "Introduzca la cifra decimal hasta la que desea redondear: ";
		cin >> cifra_redondeo;
	}
	while (cifra_redondeo < 0);
	
	// Cálculos
	
	numero_redondeado = Redondear (numero, cifra_redondeo);
	
	// Salida de datos
	
	cout << "El número redondeado es " << setw(15) << setprecision(15) 
	<< numero_redondeado;
	
	return 0;
}


		
		
	
	

	
