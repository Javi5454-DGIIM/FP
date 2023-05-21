//FP 
//Javier Gómez López
/* Programa para eliminar los excesos de espacios en una cadena de caracteres
   
   Entradas: la cadena de caracteres
   
   Salidas: la cadena sin mas de un espacio en blanco de seguido
*/

#include <iostream>  //Inclusión de los recursos de entrada y salida
#include <string>    //Inclusión de los recursos string
#include <random>  // para la generaci?n de n?meros pseudoaleatorios
#include <chrono>  // para la semilla


using namespace std;

//Definimos la clase generadora de numeros aleatrorios 
class GeneradorAleatorioEnteros
{  
private:
	
	mt19937 generador_mersenne;    // Mersenne twister
	uniform_int_distribution<int>  distribucion_uniforme;
	
	/************************************************************************/
	
	long long Nanosec(){
		return (chrono::high_resolution_clock::now().time_since_epoch().count());
	}
	
	/************************************************************************/ 
	
public:
	
	/************************************************************************/
		
	GeneradorAleatorioEnteros() : GeneradorAleatorioEnteros(0, 1) 
	{ }
	
	/************************************************************************/  
	GeneradorAleatorioEnteros(int min, int max) {
	
		const int A_DESCARTAR = 70000;
		// ACM TOMS Volume 32 Issue 1, March 2006
		
		auto semilla = Nanosec();
		generador_mersenne.seed(semilla);
		generador_mersenne.discard(A_DESCARTAR);
		distribucion_uniforme = uniform_int_distribution<int> (min, max);
	}
	
	/************************************************************************/
	
	int Siguiente(){
	  return (distribucion_uniforme(generador_mersenne));
	}
	
	/************************************************************************/

};

//Definimos la clase para cronometrar los procesos
class Cronometro
{
	
private:
	
   typedef std::chrono::time_point<std::chrono::steady_clock>
           Punto_en_el_Tiempo;
   typedef chrono::duration <double, nano> IntervaloTiempo;

   Punto_en_el_Tiempo inicio;
   Punto_en_el_Tiempo final;

public:
	
	/***********************************************************************/
	void Reset() { 
		inicio = chrono::steady_clock::now();
	}
	
	/************************************************************************/
	double NanoSegundosTranscurridos() {
		final = chrono::steady_clock::now();		
		IntervaloTiempo diferencia = final - inicio;
		return (diferencia.count());
	}
	
	/************************************************************************/
	double MiliSegundosTranscurridos() {
		final = chrono::steady_clock::now();		
		IntervaloTiempo diferencia = final - inicio;
		return (diferencia.count()/1e6);
	}
	/************************************************************************/  
};

//Definamos la clase de secuencia de caracteres

class SecuenciaCaracteres
{

private:
	static const int TAMANIO = 50; //Num casillas disponibles
	char vector_privado[TAMANIO];
	
	//PRE: 0 <= total_utilizados <= TAMANIO
	int total_utilizados;  //Num casiilas ocupadas
	
	void IntercambiaComponentes_en_Posiciones (int pos_izda, int pos_dcha)
	{
		char intercambia;
		
		intercambia = vector_privado[pos_izda];
		vector_privado[pos_izda] = vector_privado[pos_dcha];
		vector_privado[pos_dcha] = intercambia;
	}
	
public:
	/********************************/
	//Constructor sin argumentos
	SecuenciaCaracteres (void) : total_utilizados (0) {}
	
	/********************************/
	//Devuelve el número de casillas ocupadas
	
	int TotaUtilizados (void)
	{
		return total_utilizados;
	}
	
	/********************************/
	//Devuelve el número de casillas disponibles
	
	int Capacidad (void)
	{
		return TAMANIO;
	}
	
	/********************************/
	//"Vacía" completamente la secuencia
	
	void EliminaTodos (void)
	{
		total_utilizados = 0;
	}
	
	/********************************/
	//Añade un elemento "nuevo" al vector
	//PRE: total_utilizados < TAMANIO
	//	La adición se realiza si hay alguna casilla disponible
	//	El nuevo elemento se coloca al final del vector
	//	Si no hay espacio, no se hace nada
	
	void Aniade (char nuevo)
	{
		if (total_utilizados < TAMANIO)
		{
			vector_privado[total_utilizados] = nuevo;
			total_utilizados++;
		}
	}
	
	/********************************/
	//Devuelve el elemento de la casilla "indice"
	//PRE: 0 <= indice < total_utilizados
	
	char Elemento (int indice)
	{
		return (vector_privado[indice]);
	}
	
	/********************************/
	//Cambia el contenido de la casilla "indice" por el valor
	//dado en "nuevo". El tamanio de la secuencia no cambia.
	//PRE: 0 <= indice < total_utilizados
	
	void Modifica (int indice, char nuevo)
	{
		if ((indice >= 0) && (indice < total_utilizados))
		{
			vector_privado[indice] = nuevo;
		}
	}
	
	/********************************/
	//Eliminar el caracter de la posicion dada por "indice".
	//Realiza un borrado físico (desplazamiento y sustitución).
	//PRE: 0 <= indice < total_utilizados
	
	void Elimina (int indice)
	{
		if ((indice >= 0) && (indice < total_utilizados))
		{
			int tope = total_utilizados - 1; //pos del ultimo
			
			for (int i = indice; i < tope; i++)
			{
				vector_privado[i] = vector_privado[i+1];
			}
			
			total_utilizados--;
		}
	}
	
	/********************************/
	//Inserta el carácter "nuevo" en la posición dada por "indice".
	//Desplaza todos los caracteres una posición a la derecha
	//antes de copiar en "indice" el valor "nuevo"
	
	void Inserta (int indice, char valor_nuevo)
	{
		if ((total_utilizados < TAMANIO) && (indice >= 0))
		{
			for (int i = total_utilizados; i > indice; i--)
			{
				vector_privado[i] = vector_privado[i-1];
			}
			
			vector_privado[indice] = valor_nuevo;
			total_utilizados++;
		}
	}
	
	/********************************/
	//Ordenacion por selccion
	
	void Ordena_por_Seleccion()
	{
		int pos_min;
		
		for (int izda = 0; izda < total_utilizados; izda++)
		{
			pos_min = PosicionMinimoEntre (izda, total_utilizados - 1);
			IntercambiaComponentes_en_Posiciones (izda, pos_min);
		}
	}
	
	/********************************/
	//Ordenacion por inserción
	
	void Ordena_por_Insercion()
	{
		int izda, i;
		char a_desplazar;
		
		for(izda = 1; izda < total_utilizados; izda++)
		{
			a_desplazar = vector_privado[izda];
			
			for(i = izda; i > 0 && a_desplazar < vector_privado[i-1]; i--)
			{
				vector_privado[i] = vector_privado[i-1];
			}
			
			vector_privado[i] = a_desplazar;
		}
	}
	
	/********************************/
	//Ordenacion por Burbuja
	
	void Ordena_por_Burbuja()
	{
		int izda, i;
		
		for(izda = 0; izda < total_utilizados; izda++)
		{
			for(i = total_utilizados - 1; i > izda; i--)
			{
				if(vector_privado[i] < vector_privado[i-1])
				{
					IntercambiaComponentes_en_Posiciones(i, i-1);
				}
			}
		}
	}
	
	/********************************/
	//Ordenacion por Burbuja Mejorado
	
	void Ordena_por_BurbujaMejorado()
	{
		int izda, i;
		bool cambio;
		
		cambio = true;
		
		for(izda = 0; izda < total_utilizados - 1 && cambio; izda++)
		{
			cambio = false;
			
			for(i = total_utilizados - 1; i > izda; i--)
			{
				if(vector_privado[i] < vector_privado[i-1])
				{
					IntercambiaComponentes_en_Posiciones(i, i-1);
					cambio = true;
				}
			}
		}
	}
	
	/********************************/
	//Método para elinar todas las apariciones que hubiese
	//de un determinado caracter "a_borrar" en la secuencia.
	
	void EliminaOcurrencias (char a_borrar)
	{
		int posicion_lectura = 0;
		int posicion_escritura = 0;
		bool borrar;
		
		while (posicion_lectura < total_utilizados)
		{
			borrar = false;
			
				if (vector_privado[posicion_lectura] == a_borrar)
				{
					borrar = true;
				}
			
			
			if(borrar)
			{
				Elimina(posicion_escritura);
			}
			else
			{
				posicion_lectura++;
				posicion_escritura++;
			}
		}
		
		total_utilizados = posicion_escritura;
	}
	
	/********************************/
	//Método para elinar todas las apariciones que hubiese
	//de un determinado caracter "a_borrar" en la secuencia.
	
	void EliminaExcesoBlanco()
	{	
		for (int i = 0; i < total_utilizados; i++)
		{
			if (vector_privado[i] == ' ')
			{	
				for (int k = i; vector_privado[k+1] == ' '; k++)
				{
					Elimina(k);
				}
			}
		}
	}
	
	/********************************/
	//Busca un elemento hasta que lo encuentra en su posicion mas baja
	int PrimeraOcurrencia (char buscado)
	{
		return PrimeraOcurrenciaEntre (0, total_utilizados - 1, buscado);
	}
	
	/********************************/
	//Busca un elemento entre dos posiciones 
	int PrimeraOcurrenciaEntre (int pos_izda, int pos_dcha, char buscado)
	{
		int i = pos_izda;
		bool encontrado = false;
		
		while (i <= pos_dcha && !encontrado)
		{
			if (vector_privado[i] == buscado)
			{
				encontrado = true;
			}
			else
			{
				i++;
			}
		}
			
			if (encontrado)
			{
				return i;
			}
			else
			{
				return -1;
			}
	}
		
	/********************************/
	//Busqueda binaria
	
	int BusquedaBinaria (char buscado)
	{
		//PRE: el vector tiene que estar ordenado
		
		int izda, dcha, centro;
		bool encontrado = false;
		
		izda = 0;
		dcha = total_utilizados - 1;
		centro = (izda + dcha) / 2;
		
		while (izda <= dcha && !encontrado)
		{
			if (vector_privado[centro] == buscado)
			{
				encontrado = true;
			}
			else if (buscado < vector_privado[centro])
			{
				dcha = centro - 1;
			}
			else
			{
				izda = centro + 1;
			}
			
			centro = (izda + dcha) / 2;
		}
		
		if (encontrado)
		{
			return centro;
		}
		else
		{
			return -1;
		}
	}
	
	/********************************/
	//Devuelve la posicion del minimo elemento de la secuencia
	
	int PosicionMinimo ()
	{
		return PosicionMinimoEntre(0, total_utilizados - 1);
	}
	
	/********************************/
	//Devuelve la posicion minima entre dos posiciones
	
	int PosicionMinimoEntre (int izda, int dcha)
	{
		int posicion_minimo = -1;
		char minimo;
		
		minimo = vector_privado[izda];
		posicion_minimo = izda;
		
		for (int i = izda+1; i <=dcha; i++)
		{
			if(vector_privado[i] < minimo)
			{
				minimo = vector_privado[i];
				posicion_minimo = i;
			}
		}
		
		return posicion_minimo;
	}
	
	/********************************/
	//Compone un string con todos los caracteres que están 
	//almacenados en la secuenica y lo devuelve
	
	
	
	string ToString()
	{
		string cadena;
		
		for (int i=0; i<total_utilizados; i++)
		{
			cadena = cadena + vector_privado[i];
		}
		
		return cadena;
	}
	/********************************/
	
	
};


int main()   //Funcion principal
{
	//Declaracion de variables
	Cronometro crono;
	GeneradorAleatorioEnteros random(0,10000);
	SecuenciaCaracteres secuencia, copia1, copia2, copia3, copia4;
	
	//Rellenamos la secuencia de manera aleatoria
	for (int i = 0; i <= 10000; i++)
	{
		secuencia.Aniade(char(random.Siguiente()));
	}
	
	//Realizamos 4 copias de la secuencia original para que sean
	//los mismos elementos a ordenadar
	copia1 = secuencia;
	copia2 = secuencia;
	copia3 = secuencia;
	copia4 = secuencia;
	
	crono.Reset();
	copia1.Ordena_por_Seleccion();
	double tiempo_seleccion = crono.MiliSegundosTranscurridos();
	cout << "La ordenacion por seleccion ha tardado: ";
	cout << tiempo_seleccion << " milisegundos" << endl;
	
	crono.Reset();
	copia2.Ordena_por_Insercion();
	double tiempo_insercion = crono.MiliSegundosTranscurridos();
	cout << endl << "La ordenacion por insercion ha tardado: ";
	cout << tiempo_insercion << " milisegundos" << endl;
	
	crono.Reset();
	copia3.Ordena_por_Burbuja();
	double tiempo_burbuja = crono.MiliSegundosTranscurridos();
	cout << endl << "La ordenacion por burbuja ha tardado: ";
	cout << tiempo_burbuja << " milisegundos" << endl;
	
	crono.Reset();
	copia4.Ordena_por_BurbujaMejorado();
	double tiempo_burbuja_mejorado = crono.MiliSegundosTranscurridos();
	cout << endl << "La ordenacion por burbuja mejorada ha tardado: ";
	cout << tiempo_burbuja_mejorado << " milisegundos" << endl;
	
	
	return 0;
}
