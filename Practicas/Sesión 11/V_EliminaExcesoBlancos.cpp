//FP 
//Javier Gómez López
/* Programa para eliminar los excesos de espacios en una cadena de caracteres
   
   Entradas: la cadena de caracteres
   
   Salidas: la cadena sin mas de un espacio en blanco de seguido
*/

#include <iostream>  //Inclusión de los recursos de entrada y salida
#include <string>    //Inclusión de los recursos string

using namespace std;

//Definamos la clase de secuencia de caracteres

class SecuenciaCaracteres
{

private:
	static const int TAMANIO = 50; //Num casillas disponibles
	char vector_privado[TAMANIO];
	
	//PRE: 0 <= total_utilizados <= TAMANIO
	int total_utilizados;  //Num casiilas ocupadas
	
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
	SecuenciaCaracteres secuencia;
	char c;
	const char TERMINADOR = '.';
	
	cout << "Introduzca una serie de caracteres. EL programa leerá";
	cout << " hasta que introduzca '" << TERMINADOR << "'" << endl;
	
	//Lectura de datos
	do 
	{
		cin.get(c);
		
		if(c != TERMINADOR)
		{
			secuencia.Aniade(c);
		}
	}while(c != '.');
	
	//Mostramos la secuencia como se ha introducido
	cout << "La cadena introducida ha sido: " << endl;
	cout << "-----------------------------------" << endl;
	cout << secuencia.ToString() << endl;
	
	cout << endl << "La cadena sin exceso de espacios es: " << endl;
	cout << "-----------------------------------" << endl;
	secuencia.EliminaExcesoBlanco();
	cout << secuencia.ToString();
	
	
	return 0;
}
