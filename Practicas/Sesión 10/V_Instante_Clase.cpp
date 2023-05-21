//FP 
//Javier Gómez López
/* Programa para calcular el precio final de un producto a partir de su precio
   inicial, un incremento mensual y un número de meses..
   
   Entradas: precio inical del producto, el incremento mensual, y el nº de 
   meses.
   Salidas: el precio final de dicho producto
*/

#include <iostream>  //Inclusión de los recursos de entrada y salida
#include <string>   //Inclusión de los recursos string

using namespace std;	

const int H_MIN = 60;
const int MIN_SEG = 60;
const int H_SEG = 3600;

class Instante
{
	private:
		int horas;
		int minutos;
		int segundos;
		
	public:
		
		Instante (int las_horas, int los_minutos, int los_segundos)
		{
			horas = las_horas;
			minutos = los_minutos;
			segundos = los_segundos;
		}
		
		//Metodos Get
		
		int GetHoras (void)
		{
			return horas;
		}
		
		int GetMinutos (void)
		{
			return minutos;
		}
		
		int GetSegundos (void)
		{
			return segundos;
		}
		
		//Metodos Set
		
		void SetHoras (int las_horas)
		{
			horas = las_horas;
		}
		
		void SetMinutos (int los_minutos)
		{
			minutos = los_minutos;
		}
		
		void SetSegundos (int los_segundos)
		{
			segundos = los_segundos;
		}
		
		//Otros métodos
		
		void TotalMinutos (int las_horas)
		{
			minutos += las_horas * H_MIN;
		}
		
		void TotalSegundos (int las_horas, int los_minutos)
		{
			segundos = las_horas * H_MIN * MIN_SEG + los_minutos * MIN_SEG;
		}
		
		void AgruparTiempo (int los_segundos)
		{
			SegundosMinutos(los_segundos);
			MinutosHoras(minutos);
		}
			
		string To_String_Instante ()
		{
			return (to_string(horas) + " h: " + to_string(minutos) + " m: " 
					+ to_string(segundos) + " s");
		}
		
	private:
		
		int HorasMinuto (int las_horas)
		{
			minutos += las_horas * H_MIN;
			
			return minutos;
		}
		
		int MinutosSegundos (int los_minutos)
		{
			segundos += los_minutos * MIN_SEG;
			
			return segundos;
		}
		
		void SegundosMinutos (int los_segundos)
		{
			segundos = los_segundos % MIN_SEG;
			minutos = los_segundos / MIN_SEG;
		}
		
		void MinutosHoras (int los_minutos)
		{
			minutos = los_minutos % H_MIN;
			horas = los_minutos / H_MIN;
		}
		
		
};

//Funcion lectura de un numero filtro

int LeeHora(string titulo)
{
	int numero;
	
	do
	{
		cout << titulo;
		cin >> numero;
	} while ((numero < 0 || numero >= 24));
	
	return numero;
}

int LeeMinSeg(string titulo)
{
	int numero;
	
	do
	{
		cout << titulo;
		cin >> numero;
	} while ((numero < 0 || numero >= 60) && !isdigit(numero));
	
	return numero;
}
		
int main()
{
	//Declaracion de variables
	int hora_inicio, hora_fin, min_inicio, min_fin, seg_inicio, seg_fin;
	
	cout << "Introduzca el instante inicial: " << endl;
	hora_inicio = LeeHora("\tHora inicial (<24): ");
	min_inicio = LeeMinSeg("\tMins inicial (<60): ");
	seg_inicio = LeeHora("\tSegs inicial (<60): ");
	cout << endl;
	
	cout << "Introduzca el instante final: " << endl;
	hora_fin = LeeHora("\tHora final (<24): ");
	min_fin = LeeMinSeg("\tMin final (<60): ");
	seg_fin = LeeMinSeg("\tSeg final (<60): ");
	cout << endl;
	
	//Creamos los dos instantes inicial y final
	Instante instante_inicial (hora_inicio, min_inicio, seg_inicio);
	Instante instante_final (hora_fin, min_fin, seg_fin);
	
	
	
	int segundos_totales_inicio = instante_inicial.TotalMinutos()
	
	
	return 0;
}
