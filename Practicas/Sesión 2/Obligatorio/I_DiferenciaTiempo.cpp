//FP 
//Javier Gómez López
/* Programa para calcular el espacio de tiempo entre dos instantes distintos
   manteniendo las unidades.
   
   Implementamos algoritmos de conversion de unidades en sistema sexagesimal.
   
   Entradas: una cantidad de horas minutos y segundos
   Salidas: la diferencia transformada al sistema de h, min y segundos.
*/

#include <iostream> //Inclusión de los recursos E/S
#include <cmath>    //Inclusión de los recursos matemáticos

using namespace std;

int main()
{
	int hora_inicio;  //Declaración de variables
	int minuto_inicio;
	int segundo_inicio;
	
	int hora_final;
	int minuto_final;
	int segundo_final;
	
	int hora_salida;
	int minuto_salida;
	int segundo_salida;
	
//Entradas

cout << "El número de segundos de inicio es: ";
cin >> segundo_inicio;
cout << "El número de minutos de inicio es: ";
cin >> minuto_inicio;
cout << "El número de horas de inicio es: ";
cin >> hora_inicio;

cout << "El número de segundos final es: ";
cin >> segundo_final;
cout << "El número de minutos final es: ";
cin >> minuto_final;
cout << "El número de horas final es: ";
cin >> hora_final;

//Cálculos

segundo_salida = (segundo_final - segundo_inicio)%60;
minuto_inicio = minuto_inicio + (segundo_final - segundo_inicio)/60;
minuto_salida = (minuto_final - minuto_inicio)%60;
hora_inicio = hora_inicio + (minuto_final - minuto_inicio)/60;
hora_salida = hora_final - hora_inicio;


//Salidas

cout << "La diferencia son: " << segundo_salida << " segundos" << endl;
cout << "La diferencia son: " << minuto_salida << " minutos" << endl;
cout << "La diferencia son: " << hora_salida << " horas" << endl;

return (0);
}
