//FP 
//Javier Gómez López
/* Programa para leer una serie de datos que formaran parte de una matriz 
   dentada y en la salida mostrara la suma de los componentes de cada fila
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <cmath>
#include <cstdlib>

using namespace std;

//Definimos la clase SecuenciaReales

class SecuenciaReales
{

private:
	
	static const int TAMANIO = 50; //Numeros de casillas disponibles
	double vector_privado[TAMANIO];
	
	//PRE: 0 <= total_utilizados < TAMANIO
	int total_utilizados;  //Numero de casillas ocupadas
	
public:
	
	//Constructor sin argumentos
	SecuenciaReales (void): total_utilizados(0) {}
	
	
	//Metodos Get 
	
	//Devuelve el numero total de casillas utilizadas
	int TotalUtilizados (void)
	{
		return total_utilizados;
	}
	
	//Devuelve el numero de casillas disponibles
	int Capacidad (void)
	{
		return TAMANIO;
	}
	
	
	// Añade un elemento al vector.
	// Recibe: nuevo, el elemento que se va a añadir.
	//
	// PRE: total_utilizados < TAMANIO
	// 		La adición se realiza si hay espacio para el nuevo elemento.
	// 		El nuevo elemento se coloca al final del vector.
	// 		Si no hay espacio, no se hace nada.

	void Aniade (double nuevo)
	{
		if (total_utilizados < TAMANIO) {
			vector_privado[total_utilizados] = nuevo;
			total_utilizados++;
		}
	}
	
	/***********************************************************************/
	// Eliminar el dato de la posición dada por "indice".
	// Realiza un borrado físico (con desplazamiento y sustitución).
	//
	// PRE: 0 <= indice < total_utilizados

	void Elimina (int indice)
	{
		// Recorremos de izquierda a derecha toda las componentes
		// que hay a la derecha de la posición a eliminar
		//		Le asignamos a cada componente la que hay a su derecha

		if ((indice >= 0) && (indice < total_utilizados)) {

			int tope = total_utilizados-1; // posición del último

			for (int i = indice ; i < tope ; i++)
				vector_privado[i] = vector_privado[i+1];

			total_utilizados--;
		}
	}
	
	/***********************************************************************/
	// Devuelve el elemento de la casilla "indice"
	//
	// PRE: 0 <= indice < total_utilizados

	double Elemento (int indice)
	{
		return vector_privado[indice];
	}
	
	/***********************************************************************/
	// Devuelve true si la secuencia está vacía

	bool EstaVacia (void)
	{
		return (total_utilizados == 0);
	}
	
	/***********************************************************************/
	// "Vacía" una secuencia

	void EliminaTodos (void)
	{
		total_utilizados = 0;
	}
		
	/***********************************************************************/
	// Devuelve la posición del mínimo valor de la secuencia
	//
	// PRE: 0 <= izda <= dcha < total_utilizados

	int PosicionMinimo (int izda, int dcha)
	{
		int posicion_minimo;
		double minimo;

		minimo = vector_privado[izda];
		posicion_minimo = izda;

		for (int i = izda; i <= dcha ; i++) {

			if (vector_privado[i] < minimo){
				minimo = vector_privado[i];
				posicion_minimo = i;
			}
		}

		return (posicion_minimo);
	}
	
	/***********************************************************************/
	// Devuelve la posición del máximo valor de la secuencia
	//
	// PRE: 0 <= izda <= dcha < total_utilizados

	int PosicionMaximo (int izda, int dcha)
	{
		int posicion_maximo;
		double maximo;

		maximo = vector_privado[izda];
		posicion_maximo = izda;

		for (int i = izda; i <= dcha ; i++) {

			if (vector_privado[i] > maximo){
				maximo = vector_privado[i];
				posicion_maximo = i;
			}
		}

		return (posicion_maximo);
	}
	
	/***********************************************************************/
	// Devuelve el mínimo de la secuencia.
	//
	// PRE: 0 <= izda <= dcha < total_utilizados

	double Minimo (int izda, int dcha)
	{
		return (vector_privado[PosicionMinimo(izda, dcha)]);
	}
	
	/***********************************************************************/
	// Devuelve el máximo de la secuencia.
	//
	// PRE: 0 <= izda <= dcha < total_utilizados

	double Maximo (int izda, int dcha)
	{
		return (vector_privado[PosicionMaximo(izda, dcha)]);
	}
	
	//Metodo ToString
	string ToString (void)
	{
		string cadena;

		cadena = "|";
		for (int i=0; i<total_utilizados; i++)
			cadena = cadena + to_string(vector_privado[i]) + "|";

		return (cadena);
	}
};


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
                while(vector_privado[i+1] == ' ')
                {
                    Elimina(i);
                }
			}
		}
	}
	
	/********************************/
	//Método para eliminar los blancos del inicio
	
	void EliminaBlancoInicio()
	{	
	
	   while(vector_privado[0] == ' ')
	   {
	       Elimina(0);
	   }
	}  
	
	
	//Metodo para quitar blancos del final
	void EliminaBlancoFinal()
	{	
	
	   while(vector_privado[total_utilizados - 1] == ' ')
	   {
	       Elimina(total_utilizados - 1);
	   }
	}  
			
	/********************************/
	//Método para eliminar todos los excesos de blanco
    
    void EliminaBlancoTotal()
    {
        EliminaBlancoInicio();
        EliminaBlancoFinal();
        EliminaExcesoBlanco();
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




//Definimos la clase Tabla Dentada Reales

class TablaDentadaReales {
	
private:
	

private:

	static const int TAMANIO = 100; // Número de casillas disponibles
	SecuenciaReales vector_privado[TAMANIO];
	
	//PRE: 0 <= total_utilizados <= TAMANIO
	int total_utilizados;	// Número de casillas ocupadas
	
public:
	
	/***********************************************************************/
	// Constructor sin argumentos

	TablaDentadaCaracteres (void) 	
	{
		total_utilizados = 0;
	}

	/***********************************************************************/
	// Constructor con un argumento "SecuenciaReales"

	TablaDentadaCaracteres (SecuenciaReales la_secuencia) 	
	{
		vector_privado[0] = la_secuencia;
		total_utilizados = 1;
	}

	/***********************************************************************/
	// Devuelve el número de casillas disponibles
	
	int CapacidadFilas (void)
	{
		return (TAMANIO);
	}
	
	/***********************************************************************/
	// Devuelve el número de casillas disponibles
	
	int CapacidadColumnas (void)
	{
		return (SecuenciaCaracteres().Capacidad());
	}
	
	/*****************************************************************/
	// Devuelve cuántas filas hay en la tabla.

	int FilasUtilizadas (void)
	{
		return (total_utilizados);
	}
				
	/*****************************************************************/
	// Método de lectura: número real de columnas usadas en la fila "fila"
	// PRE: 0 <= fila < filas_utilizadas
	
	int ColumnasUtilizadas (int fila)
	{
		return (vector_privado[fila].TotalUtilizados());
	}
		
	/***********************************************************************/
	// Devuelve una fila completa, como un objeto de la clase 
	// "SecuenciaReales"
	//
	// PRE: 0 <= indice_fila < filas_utilizadas

	SecuenciaReales Fila (int indice_fila)
	{
		return (vector_privado[indice_fila]);
	}
	
	
	/***********************************************************************/
	// Añade una secuencia a la tabla (al final)
	// Recibe: una_secuencia, la secuencia que se va a añadir
	//
	// PRE: total_utilizados < TAMANIO
	// 		La adición se realiza si hay espacio para el nuevo elemento. 
	// 		El nuevo elemento se coloca al final del vector. 
	// 		Si no hay espacio, no se hace nada.	

	void Aniade (SecuenciaReales una_secuencia)
	{
		if (total_utilizados < TAMANIO) {

			vector_privado[total_utilizados]=una_secuencia;			
			total_utilizados++;
		}
	}
	
	/*****************************************************************/
	// Inserta una fila completa en una posición dada. 
	// La fila se porporciona en un objeto "SecuenciaCaracteres".
	// 
	// Recibe: num_fila, la posición que ocupará "fila_nueva" cuando se 
	//		 		inserte en la tabla.
	//		   fila_nueva, la secuencia que se va a insertar. Se trata 
	//				de un objeto de la clase SecuenciaCaracteres. 
	//
	// PRE:  filas_utilizadas < TAMANIO
	// PRE:  0 <= num_fila <= TotalUtilizados()
	//		 Si num_fila = 0, "nueva_fila" será la nueva primera fila. 
	//		 Si num_fila = TotalUtilizados(), "nueva_fila" será la nueva 
	//		 última fila (el resultado será equivalente al de "Aniade()" 
	
	void Inserta (int num_fila, SecuenciaReales fila_nueva)
	{
		// Comprobar precondiciones
		
		if ((total_utilizados < TAMANIO) && 
			(0<=num_fila) && (num_fila <=total_utilizados)) {

			// "Desplazar" las filas hacia posiciones altas. 
			// La última fila se copia en una NUEVA FILA que ocupa la 
			// posición "filas_utilizadas", la penúltima se copia en 
			// "filas_utilizadas"-1, ... y se queda un "hueco" en 
			// la fila "num_fila ".
			// NOTA: no se modifica (todavía) "filas_utilizadas" 
			
			for (int fil=total_utilizados; fil>num_fila; fil--) 
			
				vector_privado[fil] = vector_privado[fil-1]; 
				
					
			// Copiar en el "hueco" (fila "num_fila") el contenido de 
			// la secuencia "fila_nueva"
			
			vector_privado[num_fila]= fila_nueva;
						
			total_utilizados++; // Actualización del tamaño de la tabla.
					
		}
	}
	
	/***********************************************************************/
	// Eliminar la secuencia que se encuentra en la posición dada por "indice".
	// Realiza un borrado físico (con desplazamiento y sustitución).
	//
	// PRE: 0 <= indice < total_utilizados 
	
	void Elimina (int indice) 
	{
		// Recorremos de izquierda a derecha toda las componentes 
		// que hay a la derecha de la posición a eliminar
		//		Le asignamos a cada componente la que hay a su derecha

		if ((indice >= 0) && (indice < total_utilizados)) {

			int tope = total_utilizados-1; // posición del último 
    
			for (int i = indice ; i < tope ; i++) {
				vector_privado[i] = vector_privado[i+1];
 	    	}
			total_utilizados--;    
		}
	}
		
	/*****************************************************************/
	// Método de lectura: devuelve el dato que ocupa la casilla 
	// de coordenadas (fila, columna)
	// PRE: 0 <= fila < filas_utilizadas
	// PRE: 0 <= columna < num_cols_utilizadas[fila]	
	
	double Elemento (int fila, int columna)
	{
		return (vector_privado[fila].Elemento(columna));
	}
		
	/***********************************************************************/
	// "Vacía" una secuencia
	
	void EliminaTodos (void)
	{
		total_utilizados = 0;
	}

	/***********************************************************************/
	// Devuelve TRUE si la secuencia está vacía
	
	bool EstaVacia (void)
	{
		return (total_utilizados==0);
	}
	
	/*****************************************************************/
	// Calcula si dos matrices dentadas son iguales

	bool EsIgual (TablaDentadaReales otra)
	{
		bool son_iguales = true; 
		
		if (FilasUtilizadas()!= otra.FilasUtilizadas())
			
			son_iguales = false;
		
		else {
			
			int f=0; 
			
			while (f<FilasUtilizadas() && son_iguales) {
				
				if (ColumnasUtilizadas(f)!= otra.ColumnasUtilizadas(f)) 
				
					son_iguales = false;	
				
				else {
					
					int c=0; 
					
					while (c<ColumnasUtilizadas(f) && son_iguales) {
				
						if (Elemento(f,c) != otra.Elemento(f,c)) 
							son_iguales = false;
							
						c++;
						
					} // while c
		
					f++;
					
				} // else 
					
			} // while f
					
		} // else 
	
		return (son_iguales);
	}
	
	
	SecuenciaReales SumaFilas (void)
	{
	    SecuenciaReales resultado;
	    
	    for(int i = 0; i < total_utilizados; i++)
	    {
	        double suma = 0;
	        SecuenciaReales la_fila = Fila(i);
	        
	        for(int k = 0; k < la_fila.TotalUtilizados(); k++)
	        {
	            
	            suma = suma + la_fila.Elemento(k);
	        }
	        
	        resultado.Aniade(suma);
	    }
	    
	    return resultado;
	}
	
	/*********************************************************************/
	// Forma un string con el contenido de la tabla.  
	// La primera línea es el encabezamiento indicado en "titulo".
	
	string ToString (string titulo)
	{
		string cad; 
		
		cad = "\n" + titulo + "\n"; 	
		cad = cad + "\n--------------------------------------\n"; 
		
		for (int fila=0; fila<total_utilizados; fila++) {
	
			SecuenciaReales la_secuencia = Fila(fila);
			
			int num_datos = la_secuencia.TotalUtilizados();
	
			cad = cad + "Fila " + to_string(fila); 
			cad = cad + " (" + to_string(num_datos) + " datos): "; 
			cad = cad + la_secuencia.ToString() + "\n";
		}
		
		cad = cad + "--------------------------------------\n"; 
		cad = cad + "\n\n";
		
		return (cad); 
	}
	
	/*****************************************************************/
		
};

//Funcion principal

int main()
{
    
    SecuenciaCaracteres secuencia;
	char c;
	const char TERMINADOR = 's';
	
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
	}while(c != TERMINADOR);
	
	//Aniadimos un espacio al final del string para que el algoritmo siguiente
	//no de problemas
	
	secuencia.Aniade(' ');
    
    
   //Ahora convertimos esta secuencia de caracteres en secuencia de reales
   
   SecuenciaReales entrada;
   string elemento;
   
   for(int i = 0; i < secuencia.TotaUtilizados(); i++)
   {
       
       if (secuencia.Elemento(i) != ' ')
       {
           elemento = elemento + secuencia.Elemento(i);
       }
       else
       {
           if (elemento != "")
           {
               entrada.Aniade(stod(elemento));
           }
           
           elemento = "";
       }
           
   }
    
    //Establecemos el numero de filas y creamos la tabla
    int num_filas = entrada.Elemento(0);
    int pos = 1;
    int pos2 = 0;
    
    TablaDentadaReales tabla;
    
    //Ahora creamos secuencias de reales por el numero de filas
    
    for(int k = 0; k < num_filas; k++)
    {
        SecuenciaReales fila;
        
        
        for(int m = 1; m <= entrada.Elemento(pos); m++)
        {
            
            fila.Aniade(entrada.Elemento(pos+m));
            pos2 = m;
        }
        tabla.Aniade(fila);
        pos = pos + pos2 + 1;   //Siempre se avanza una mas
    }

    SecuenciaReales resultados;
    
    resultados = tabla.SumaFilas();
    
    string matriz = tabla.ToString("Tabla generada");
    
    
    //Muestra de resultados
    cout << matriz;
    
    cout << endl << endl;
    cout << "---------------------------------------" << endl;
    cout << "La suma de cada fila es: " << endl << endl;;
    
    for (int t = 0; t < resultados.TotalUtilizados(); t++)
    {
        cout << "\t Fila " << t << " ----> " << resultados.Elemento(t);
        cout << endl;
    }
    
    cout << "---------------------------------------" << endl;
    
    return 0;
}
