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

#include <iostream> //Inclusión de los recursos de E/S
using namespace std;

//Declaración de structs
struct Instante {
	double horas, minutos, segundos;
};

//Funciones
int filtro_horas () 
{
	int tiempo;
	
	do {
		cout << "Introduce la hora (formato 24 horas): ";
		cin >> tiempo;
	} while (tiempo < 0 || tiempo >= 24);
	
	return tiempo;
}

int filtro_minutos () 
{
	int tiempo;
	
	do {
		cout << "Introduce los minutos: ";
		cin >> tiempo;
	} while (tiempo < 0 || tiempo >= 60);
	
	return tiempo;
}

int filtro_segundos () 
{
	int tiempo;
	
	do {
		cout << "Introduce los segundos: ";
		cin >> tiempo;
	} while (tiempo < 0 || tiempo >= 60);
	
	return tiempo;
}

int main () //Programa Principal
{                       
	//Declaración de variables
	const int CONV_SEXAGESIMAL = 60;
	
	Instante inicio, final, total;
	double distancia, dorsal, km_h, min_km;
	
	//Entrada de datos iniciales
	cout << "Introduce los datos de inicio: " << endl;
	inicio.horas = filtro_horas(); 
	inicio.minutos = filtro_minutos();
	inicio.segundos = filtro_segundos();
	
	do {
		cout << "Introduce la distancia de la carrera en km: ";
		cin >> distancia;
	} while (distancia <= 0);
	

	//Cálculos, entrada de datos personales y salida de estos
	do {
		cout << "\nIntroduce el número de dorsal (debe ser positivo): ";
		cin >> dorsal;
		
		if (dorsal > 0) {
			
			cout << "Introduce los datos de llegada: " << endl;
			final.horas = filtro_horas(); 
			final.minutos = filtro_minutos();
			final.segundos = filtro_segundos();
			
			total.horas = final.horas - inicio.horas;
			total.minutos = final.minutos - inicio.minutos;
			total.segundos = final.segundos - inicio.segundos;
			
			km_h = distancia / (total.horas + (total.minutos / 60));
			min_km = (total.minutos + total.horas*CONV_SEXAGESIMAL) / distancia;
			
			cout << "El dorsal número " << dorsal << " ha completado la carrera"
				 << " en " << total.horas << ":" << total.minutos << ":" 
				 << total.segundos << "." << endl;
			cout << "Su ritmo ha sido " << km_h << " km/h y " << min_km 
				 << " min/km." << endl;
		}	 
	} while (dorsal > 0);

	cout << "No has introducido un dorsal positivo." << "\nFin del programa.";
	
	return 0;
}
