//FP 
//Javier Gómez López
/* Programa para realizar un cambio de unidad entre horas minutos
   y segundos.
   
   Implementamos las conversiones que se muestran en el enunciado del
   ejercio.
   
   Entradas: una cantidad de horas minutos y segundos
   Salidas: las unidades transformadas al sistema de h, min y segundos.
*/

#include <iostream> //Inclusión de los recursos E/S
#include <cmath>    //Inclusión de los recursos matemáticos

using namespace std;

int main()
{
	int dias_salida;  //Declaración de variables
	int horas_entrada;
	int minutos_entrada;
	int segundos_entrada;
	
	int horas_salida;
	int minutos_salida;
	int segundos_salida;
	
//Entradas

cout << "El número de segundos es: ";
cin >> segundos_entrada;
cout << "El número de minutos es: ";
cin >> minutos_entrada;
cout << "El número de horas es: ";
cin >> horas_entrada;

//Cálculos

segundos_salida = segundos_entrada%60;
minutos_salida = minutos_entrada + (segundos_entrada/60);
horas_salida = horas_entrada + (minutos_salida/60);
dias_salida = horas_salida/24;
minutos_salida = minutos_salida%60;
horas_salida = horas_salida%24;


//Salidas

cout << "Eso son: " << segundos_salida << " segundos" << endl;
cout << "Eso son: " << minutos_salida << " minutos" << endl;
cout << "Eso son: " << horas_salida << " horas" << endl;
cout << "Eso son: " << dias_salida << " dias" << endl;




return (0);
}
