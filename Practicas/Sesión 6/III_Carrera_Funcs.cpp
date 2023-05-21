//FP 
//Javier Gómez López
/* Programa para calcular distintos dadtos de interés tras una carrera
   como la velocidad y el ritmo de los corredores y el tiempo empleado en la 
   carrera.
   
   Para ello trabajaremos con bucles de lectura simples
   
   Entradas: hora de inicio de la carrera y la distancia a recorrer
             y hora de llegada del corredor
   
   Salidas: tiempo empleado en la carrera, ritmo y velocidad
   
*/

#include <iostream> //Inclusión de los recursos E/S
#include <cmath>    //Inclsuión de los recursos matemáticos

using namespace std;

const int SEGUNDOS_MINUTOS = 60;
const int MINUTOS_HORA = 60;
const int HORAS_DIA = 24;

int AgruparTiempo (int hora, int minuto, int segundo)
{
    int resultado;
    
    resultado = hora * MINUTOS_HORA * SEGUNDOS_MINUTOS +
	            minuto * SEGUNDOS_MINUTOS + segundo;
	            
	return resultado;
}

double Velocidad (int segundos_totales, double distancia)
{
    double hora_velocidad;
    double velocidad;
    
    hora_velocidad = segundos_totales / (SEGUNDOS_MINUTOS * MINUTOS_HORA);
    velocidad = distancia / hora_velocidad;
    
    return velocidad;
}

double Ritmo (int segundos_totales, double distancia)
{
    double minuto_ritmo;
    double ritmo;
    
    minuto_ritmo = segundos_totales / SEGUNDOS_MINUTOS;
    ritmo = minuto_ritmo / distancia;
    
    return ritmo;
}

int main ()
{
	
	//Declaracion de variables y constantes
	
	int hora_inicio;
	int minuto_inicio;
	int segundo_inicio;
	int dorsal = 0;	
	double distancia;
	
	int hora_final;
	int minuto_final;
	int segundo_final;
	
	int segundos_inicio_totales;
	int segundos_final_totales;
	
	int hora_salida;
	int minuto_salida;
	int segundo_salida;
	
	double velocidad;
	double ritmo;
	
	//Entradas
	
	cout << "Introduzca la hora de inicio: " << endl;
	
	do
	{
		cout << "\t Hora: ";
		cin >> hora_inicio;
	} while (hora_inicio >= HORAS_DIA);
	
	do 
	{
		cout << "\t Minuto: ";
		cin >> minuto_inicio;
	} while (minuto_inicio >= MINUTOS_HORA);
	
	do 
	{
		cout << "\t Segundo: ";
		cin >> segundo_inicio;
	} while (segundo_inicio >= SEGUNDOS_MINUTOS);
	
	do
	{
		cout << "Introduzca la distancia en km: ";
		cin >> distancia;
	} while (distancia <= 0);
	
	segundos_inicio_totales = AgruparTiempo (hora_inicio, minuto_inicio, 
	                                         segundo_inicio);
	
	cout << "Ahora registrará los dorsales de los corredores que llegan";
	cout << endl;
	cout << "Para finalizar el proceso deberá escribir un dorsal negativo";
	cout << endl;
	
	cout << "Introduzca el dorsal del corredor: ";
	cin >> dorsal;
	
	
	while (dorsal >= 0)
	{
		
		cout << "Introduzca ahora la hora de llegada del corredor a meta: ";
		cout << endl;
		
		do
		{
			cout << "\t Hora: ";
			cin >> hora_final;
		} while (hora_final < hora_inicio && hora_final >= HORAS_DIA);
	
		do 
		{
			cout << "\t Minuto: ";
			cin >> minuto_final;
		} while (minuto_final < minuto_inicio && minuto_final >= MINUTOS_HORA);
	
		do 
		{
			cout << "\t Segundo: ";
			cin >> segundo_final;
		} while (segundo_final < segundo_inicio
		        && segundo_final >= SEGUNDOS_MINUTOS);	
		
		//Calculos
		
		segundos_final_totales = AgruparTiempo (hora_final, minuto_final, 
	                                            segundo_final);
		segundos_final_totales = segundos_final_totales - 
		                         segundos_inicio_totales;
		                        
		segundo_salida = segundos_final_totales % 60;
		minuto_salida = segundos_final_totales / 60;
		hora_salida = minuto_salida / 60;
		minuto_salida = minuto_salida % 60;
		
		velocidad = Velocidad (segundos_final_totales, distancia);
		
		ritmo = Ritmo(segundos_final_totales, distancia);
		
		//Salidas
		
		cout << "El tiempo que se ha tomado en terminar la carrea han sido: ";
		cout << endl;
		cout << "\t Hora: " << hora_salida << endl;
		cout << "\t Minuto: " << minuto_salida << endl;
		cout << "\t Segundo: " << segundo_salida << endl;
		
		cout << "El ritmo ha sido: " << ritmo << " min/km" << endl,
		cout << "La velocidad ha sido: " << velocidad << " km/h" << endl;
		
		cout << "Introduzca el dorsal del corredor: ";
		cin >> dorsal;
	}
	
	return (0);
}
