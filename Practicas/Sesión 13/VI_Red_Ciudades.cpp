//FP 
//Javier Gómez López
/* Programa para leer una serei de datos que representaran las distancias entre
   un numero finito de ciudades (max 50)
   
   A continuación se implementaran una serie de metodos con los que se obtendran
   distintos datos de dichas ciudades
*/

#include <iostream>
#include <string>

using namespace std;

//Definimos la clase SecuenciaEnteros

class SecuenciaEnteros
{

private:
	
	static const int TAMANIO = 50; //Numeros de casillas disponibles
	int vector_privado[TAMANIO];
	
	//PRE: 0 <= total_utilizados < TAMANIO
	int total_utilizados;  //Numero de casillas ocupadas
	
public:
	
	//Constructor sin argumentos
	SecuenciaEnteros (void): total_utilizados(0) {}
	
	
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

	void Aniade (int nuevo)
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

	int Elemento (int indice)
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
		int minimo;

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
		int maximo;

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

	int Minimo (int izda, int dcha)
	{
		return (vector_privado[PosicionMinimo(izda, dcha)]);
	}
	
	/***********************************************************************/
	// Devuelve el máximo de la secuencia.
	//
	// PRE: 0 <= izda <= dcha < total_utilizados

	int Maximo (int izda, int dcha)
	{
		return (vector_privado[PosicionMaximo(izda, dcha)]);
	}
};

// El tipo de dato PosicionEnMatriz se emplea para guardar posiciones 	
// dentro de una matriz: se registra la pareja (fila, columna)
	
struct PosicionEnMatriz {
	int fila;
	int columna;
};




// La clase "SecuenciaPosicionEnMatriz" es útil para representar una secuencia
// de  posiciones (coordenadas) en una tabla bidimensional.	
	
class SecuenciaPosicionEnMatriz
{
private:

	static const int TAMANIO = 50; // Número de casillas disponibles
	PosicionEnMatriz vector_privado[TAMANIO];
	
	//PRE: 0 <= total_utilizados <= TAMANIO
	int total_utilizados;	// Número de casillas ocupadas

public: 
	
	/***********************************************************************/
	// Constructor sin argumentos

	SecuenciaPosicionEnMatriz (void) 
	{
		total_utilizados = 0;
	}

	/***********************************************************************/
	// Métodos de lectura (Get) de los datos individuales 

	// Devuelve el número de casillas ocupadas
	int TotalUtilizados (void)
	{
		return (total_utilizados);
	}

	// Devuelve el número de casillas disponibles
	int Capacidad (void)
	{
		return (TAMANIO);
	}

	/***********************************************************************/
	// Añade un elemento al vector.
	// Recibe: nuevo, el elemento que se va a añadir.
	//
	// PRE: total_utilizados < TAMANIO
	// 		La adición se realiza si hay espacio para el nuevo elemento. 
	// 		El nuevo elemento se coloca al final del vector. 
	// 		Si no hay espacio, no se hace nada.	

	void Aniade (PosicionEnMatriz nuevo)
	{
		if (total_utilizados < TAMANIO) {
			vector_privado[total_utilizados] = nuevo;
			total_utilizados++;
		}
	}

	/***********************************************************************/
	// Devuelve el elemento de la casilla "indice" 
	//
	// PRE: 0 <= indice < total_utilizados 

	PosicionEnMatriz Elemento (int indice)
	{
		return vector_privado[indice];
	}
	
	/***********************************************************************/
};
	

//Definamos la clase MapaCiudades

class MapaCiudades
{

private:

    static const int NUM_FILS = 50; // Filas disponibles
    static const int NUM_COLS = 50; // Columnas disponibles
    
    int  matriz_privada[NUM_FILS][NUM_COLS];

    // PRE: 0 <= filas_utilizadas <= NUM_FILS
    // PRE: 0 <= col_utilizadas < NUM_COLS
    
    int filas_utilizadas;
    int cols_utilizadas;

public:

	/***********************************************************************/
	// Constructor sin argumentos--> Crea matriz nula

	MapaCiudades(void): filas_utilizadas(0), cols_utilizadas(0) {}
	
	/***********************************************************************/
	// Constructor--> Recibe "numero_de_columnas" que indica el número de 
	// columnas que deben tener TODAS las filas. 
	// PRE: numero_de_columnas <= MAX_COL

	MapaCiudades (int numero_de_columnas) : filas_utilizadas(0), 
		  cols_utilizadas(numero_de_columnas)
	{ }

	/***********************************************************************/
	// Constructor--> Recibe una secuencia de enteros.  El número de 
	// elementos de la secuencia es el valor que se usa como "col_utilizadas"
	// PRE: primera_fila.TotalUtilizados() <= MAX_COL

	MapaCiudades (SecuenciaEnteros primera_fila)
		: filas_utilizadas(0), cols_utilizadas (primera_fila.TotalUtilizados())
	{
		Aniade(primera_fila); // Actualiza "filas_utilizadas"
	}

	/***********************************************************************/
	// Método de lectura: número máximo de filas

	int CapacidadFilas (void)
	{
		return (NUM_FILS);
	}

	/***********************************************************************/
	// Método de lectura: número máximo de columnas

	int CapacidadColumnas (void)
	{
		return (NUM_COLS);
	}

	/***********************************************************************/
	// Método de lectura: número real de filas usadas

	int FilasUtilizadas (void)
	{
		return (filas_utilizadas);
	}

	/***********************************************************************/
	// Método de lectura: número real de columnas usadas

	int ColumnasUtilizadas (void)
	{
		return (cols_utilizadas);
	}

	/***********************************************************************/
	// Método de lectura: devuelve el dato que ocupa la casilla 
	// de coordenadas (fila, columna)
	// PRE: 0 <= fila < filas_utilizadas
	// PRE: 0 <= columna < cols_utilizadas	
	
	int Elemento (int fila, int columna)
	{
		return (matriz_privada[fila][columna]);
	}

	/***********************************************************************/
	// Devuelve true si la tabla está vacía

	bool EstaVacia (void)
	{
		return (filas_utilizadas == 0);
	}
	
	/*****************************************************************/
	// Devuelve una fila completa (un objeto "SecuenciaEnteros")
	// PRE: 0 <= indice_fila < filas_utilizadas
	
	SecuenciaEnteros Fila (int indice_fila)
	{
		SecuenciaEnteros fila;

		for (int col=0; col<cols_utilizadas; col++)
			fila.Aniade(matriz_privada[indice_fila][col]);

		return (fila);
	}

	/***********************************************************************/
	// Devuelve una columna completa (un objeto "SecuenciaEnteros")
	// PRE: 0 <= indice_columna < cols_utilizadas
	
	SecuenciaEnteros Columna (int indice_columna)
	{
		SecuenciaEnteros columna;

		for (int fil=0; fil<filas_utilizadas; fil++)
			columna.Aniade (matriz_privada[fil][indice_columna]);

		return (columna);
	}

	/***********************************************************************/
	// Añade una fila completa (un objeto "SecuenciaEnteros")
	// PRE:  fila_nueva.TotalUtilizados() = cols_utilizadas
	// PRE:  filas_utilizadas < MAX_FIL
	
	void Aniade (SecuenciaEnteros fila_nueva)
	{
		int numero_columnas_fila_nueva = fila_nueva.TotalUtilizados();
					
		if ((filas_utilizadas < NUM_FILS) &&
			(cols_utilizadas < NUM_COLS)) {

			for (int col = 0; col < numero_columnas_fila_nueva; col++)
				matriz_privada[filas_utilizadas][col]=fila_nueva.Elemento(col);

			cols_utilizadas++;
		}
		
		filas_utilizadas++;
	}

	/***********************************************************************/
	// "Vacía" una tabla

	void EliminaTodos (void)
	{
		filas_utilizadas = 0;
	}
	
	/***********************************************************************/
	// Calcula si dos matrices rectangulares son iguales
	// Compara la tabla implícita con "otra" (tabla explícita) 

	bool EsIgual (MapaCiudades otra_tabla)
	{
		bool son_iguales = true; 
		
		if ((filas_utilizadas != otra_tabla.FilasUtilizadas()) ||  
			 (cols_utilizadas != otra_tabla.ColumnasUtilizadas()))		
			
			son_iguales = false;
		
		else {
			
			int f=0; 
			
			while (f<filas_utilizadas && son_iguales) {
				
				int c=0; 
				
				while (c<cols_utilizadas && son_iguales) {
			
					if (matriz_privada[f][c] != otra_tabla.Elemento(f,c)) 
						son_iguales = false;
						
					c++;
					
				} // while c
	
				f++;
					
			} // while f
					
		} // else 
	
		return (son_iguales);
	}
	
	

	/***********************************************************************/
	// Calcula si una matriz es simétrica.
	// CONDICIÓN NECESARIA: debe ser cuadrada. 
	// Este método comprueba directamente si cada componente es igual a
	// su simétrica, parando el recorrido cuando encuentre una componente
	// que no lo verifique.
	//
	// Evita el cálculo de la traspuesta, y el problema que puede surgir
	// si no se puede calcular la traspuesta de la matriz por problemas de
	// capacidad.

	bool EsSimetrica (void)
	{
		bool es_simetrica = true;

		// Si el número de filas y columnas no coinciden, no hay que seguir
		// porque la matriz no es simétrica.

		es_simetrica = (filas_utilizadas == cols_utilizadas);

		if (es_simetrica) {

			int f=0;

			while (f<filas_utilizadas && es_simetrica) {

				int c=0;

				while (c<cols_utilizadas && es_simetrica) {

					if (matriz_privada[f][c] != matriz_privada[c][f])
						es_simetrica = false;

					c++;

				} // while c

				f++;

			} // while f

		} // if (es_simetrica)

		return (es_simetrica);
	}
					
	/***********************************************************************/
	// Inserta una fila completa en una posición dada. 
	// La fila se porporciona en un objeto "SecuenciaEnteros".
	// 
	// Recibe: num_fila, la posición que ocupará "fila_nueva" cuando se 
	//		 		inserte en la tabla.
	//		   fila_nueva, la secuencia que se va a insertar. Se trata 
	//				de un objeto de la clase "SecuenciaEnteros". 
	//
	// PRE:  fila_nueva.TotalUtilizados() = cols_utilizadas
	// PRE:  filas_utilizadas < MAX_FIL
	// PRE:  0 <= num_fila <= TotalUtilizados()
	//		 Si num_fila = 0, "nueva_fila" será la nueva primera fila. 
	//		 Si num_fila = TotalUtilizados(), "nueva_fila" será la nueva 
	//		 última fila (el resultado será equivalente al de "Aniade()" 
	
	void Inserta (int num_fila, SecuenciaEnteros fila_nueva)
	{
		int numero_columnas_fila_nueva = fila_nueva.TotalUtilizados();
					
		// Comprobar precondiciones
		
		if ((filas_utilizadas < NUM_FILS) &&
			(numero_columnas_fila_nueva == cols_utilizadas) && 
			(0<=num_fila) && (num_fila <=filas_utilizadas)) {

			// "Desplazar" las filas hacia posiciones altas. 
			// La última fila se copia en una NUEVA FILA que ocupa la 
			// posición "filas_utilizadas", la penúltima se copia en 
			// "filas_utilizadas"-1, ... y se queda un "hueco" en 
			// la fila "num_fila ".
			// NOTA: no se modifica (todavía) "filas_utilizadas" 
			
			for (int fil=filas_utilizadas; fil>num_fila; fil--) {
				
				for (int col = 0; col < numero_columnas_fila_nueva; col++)
					matriz_privada[fil][col]=matriz_privada[fil-1][col];
			}
			
			// Copiar en el "hueco" (fila "num_fila") el contenido de 
			// la secuencia "fila_nueva"
			
			for (int col = 0; col < numero_columnas_fila_nueva; col++)
				matriz_privada[num_fila][col]=fila_nueva.Elemento(col);	
			
			filas_utilizadas++; // Actualización del tamaño de la tabla.
		}
	}

	/***********************************************************************/
	// Elimina una fila completa, dada una posición. 
	// 
	// Recibe: num_fila, la posición de la fila a eliminar.
	// PRE:  0 <= num_fila < TotalUtilizados()
	
	void Elimina (int num_fila)
	{		
		// Comprobar precondiciones
		
		if ((0<=num_fila) && (num_fila <=filas_utilizadas)) {

			// "Desplazar" las filas hacia posiciones bajas. 
			// En la posición "num_fila" se copia la que está en la posición
			// siguiente ("num_fila"+1), en su lugar se copia que está en 
			// "num_fila"+2, ... y en la posición "total_utilizados"-2 se 
			// copia la de "total_utilizados"-1. 
			
			for (int fil=num_fila; fil<filas_utilizadas-1; fil++) {
			
				int num_columnas = cols_utilizadas;
					
				for (int c=0; c<num_columnas; c++) 
					matriz_privada[fil][c]=matriz_privada[fil+1][c];
			}
			
			filas_utilizadas--; // Actualización del tamaño de la tabla.
		}
	}	
	
	/***********************************************************************/
	// Devuelve TRUE si la matriz contiene el valor "buscado"
	
	bool Contiene (int buscado)
	{
		bool encontrado = false;

		// Recorrido por columnas 

		int col = 0;

		while (col < cols_utilizadas && !encontrado) {

			int fil=0;

			while (fil < filas_utilizadas && !encontrado) {

				if (matriz_privada[fil][col] == buscado)
					encontrado = true;
				
				fil++;

			} // while fil

			col++; 

		} // while col

		return (encontrado);
	}
		
	/***********************************************************************/
	// Encontrar un dato en la matriz y devolver su posición.
	// El valor devuelto contiene información acerca de la posición 
	// (fila y columna) de "buscado".  
	// 		En el caso de que no esté contendrá {-1,-1}. 
	// La consulta de la fila y la columna se delega en los métodos de 
	// la clase "PosicionEnMatriz" 

	PosicionEnMatriz PrimeraOcurrencia (int buscado)
	{
		PosicionEnMatriz posicion_dato_buscado = {-1,-1};
      
		bool encontrado = false;

		// Recorrido por filas 

		for (int i=0; i < filas_utilizadas && !encontrado ; i++){

			for (int j=0; j < cols_utilizadas && !encontrado; j++){

				if (matriz_privada[i][j] == buscado){
					encontrado = true;
					posicion_dato_buscado.fila = i;
					posicion_dato_buscado.columna = j;
				}

			} // for j

		} // for i
      
		return (posicion_dato_buscado);
	} 
	
	//Conocer si dos ciudades estan conectadas
	
	bool EstanConectadas (int ciudad_1, int ciudad_2)
	{
	    bool estan;
	    
	    if (matriz_privada[ciudad_1][ciudad_2] != 0)
	    {
	        estan = true;
	    }
	    else
	    {
	        estan = false;
	    }
	    
	    return estan;
	}
	
	
	//Encontrar en la matriz la ciudad con más conexiones
	
	string CiudadMasConexiones (void)
	{
		int contador[filas_utilizadas] = {0};
		int mas_conexiones;
		int num_maximo;
		string cad_final;
		
		for (int t = 0; t < filas_utilizadas; t++)
		{
			for (int m = 0; m < cols_utilizadas; m++)
			{
				if (EstanConectadas(t, m))
				{
					contador[t]++;
				}
			}
		}
		
		for (int maximo = 0; maximo < filas_utilizadas - 1; maximo++)
		{
			if (contador[maximo] > contador[maximo+1])
			{
				mas_conexiones = maximo;
				num_maximo = contador[maximo];
			}
		}
		
		cad_final = "La ciudad con mas conexiones es " + to_string(mas_conexiones)
		+ " con " + to_string(num_maximo) + " conexiones";
		
		return cad_final;
	}
	
	//Obtener las ciuades conectadas directamente con una ciudad j
	
	SecuenciaEnteros Conexiones (int num_ciudad)
	{
		
		SecuenciaEnteros conex;
		bool conexiones[cols_utilizadas] = {false};
		
		for (int puntero = 0; puntero < cols_utilizadas; puntero++)
		{
			if (EstanConectadas(num_ciudad, puntero))
			{
				conexiones[puntero] = true;
			}
		}
		
		for (int mostrar = 0; mostrar < cols_utilizadas; mostrar++)
		{
			if(conexiones[mostrar])
			{
				conex.Aniade(mostrar);
			}
		}
		
		return conex; 
	}
	
	//Metodo para obtener las ciudades intermedias entre dos ciudades
	
	SecuenciaEnteros CiudadesIntermedias (int ciudad_1, int ciudad_2)
	{
	    SecuenciaEnteros ciudades;
	    
	    for (int i = 0; i < filas_utilizadas; i++)
	    {
	        if (matriz_privada[ciudad_1][i] != 0 &&
	           matriz_privada[ciudad_2][i] != 0)
	        {
	           ciudades.Aniade(i);
            }
        }
            
        return ciudades;
    }
	
	//Metodo para obtener el camino mas corto entre dos ciudades no conectadas
	//PRE: las ciudades no deben estar conectadas
	
	string CaminoMasCorto(int ciudad_1, int ciudad_2)
	{
	    SecuenciaEnteros ciudades_intermedias = CiudadesIntermedias (ciudad_1,
	    ciudad_2);
	    int distancia;
    	int puntero = ciudades_intermedias.Elemento(0);
	    string resultado;
	    
	    //Inicializamos la distancia minima como la primera
	    int distancia_min = 
        matriz_privada[ciudad_1][ciudades_intermedias.Elemento(0)]
	        + matriz_privada[ciudad_2][ciudades_intermedias.Elemento(0)];
	    
	    
	    for (int i = 1; i < ciudades_intermedias.TotalUtilizados(); i++)
	    {
	        distancia = matriz_privada[ciudad_1][ciudades_intermedias.Elemento(i)]
	        + matriz_privada[ciudad_2][ciudades_intermedias.Elemento(i)];
	        
	        if (distancia < distancia_min)
	        {
	            distancia_min = distancia;
	            puntero = ciudades_intermedias.Elemento(i);
	        }
	    }
	    
	    resultado = "El camino más corto entre " + to_string(ciudad_1) + " y "
	    + to_string(ciudad_2) + " pasa por " + to_string(puntero) + " y " +
	    "la distancia es de " + to_string(distancia_min);
	    
	    return resultado;
	}
		
		

	/***********************************************************************/
};



//Funcion principal
int main()
{
	SecuenciaEnteros distancias;
	MapaCiudades mapa;
	int num_ciudades;
	
	//Entrada de datos
	cout << "Numero minimo de ciudades 2 y máximo 50" << endl;
	
	do
	{
		cout << "Introduzca el numero de ciudades: ";
		cin >> num_ciudades;
	}while(num_ciudades < 2 || num_ciudades > 50);
	
	//Leemos las distancias con cada ciudad
	cout << endl;
	
	for (int i = 0; i < num_ciudades; i++)
	{
		cout << "Introduzca las distancias de la ciudad " << i << endl;
		
		for (int k = 0; k < num_ciudades; k++)
		{
			int distancia;
			
			if (k != i)
			{
				do
				{
					cout << "\t -----> Ciudad " << k << ": ";
					cin >> distancia;
				}while(distancia < 0);
				
				distancias.Aniade(distancia);
			}
			else
			{
			    distancias.Aniade(0);
			}
		}
		
		mapa.Aniade(distancias);
		distancias.EliminaTodos();
		cout << endl;
	}
	
	//Mostramos la ciudad con más conexiones
	
	cout << endl;
	cout << "--------------------------" << endl;
	cout << mapa.CiudadMasConexiones() << endl;
	cout << "--------------------------";
	
	
	//Pedimos los datos de un ciudad para comprobar cuantas conexiones tiene
	
	int check_conexiones;

	cout << endl << endl << endl;
	cout << "--------------------------" << endl;
	do
	{
		
		cout << "Introduzca una ciudad para ver cuantas conexiones directas ";
		cout << "tiene (0 - " << num_ciudades - 1 << "): ";
		cin >> check_conexiones;
	} while(check_conexiones < 0 || check_conexiones >= num_ciudades);
	
	SecuenciaEnteros conexiones_ciudad;
	
	conexiones_ciudad = mapa.Conexiones(check_conexiones);
	
	//mostramos los resultados
	
	cout << endl;
	cout << "La ciudad " << check_conexiones << " esta conectada con: " << endl;
	
	for (int m = 0; m < conexiones_ciudad.TotalUtilizados(); m++)
	{
	    cout << "\t -----> " << conexiones_ciudad.Elemento(m);
	    cout << endl;
	}
	
	cout << "--------------------------";
	
	//Ahora pediremos dos ciudades que no tienen conexion para calcular el 
	//camino mas corto
	
	if(num_ciudades > 2)  //Debe de haber mas de dos ciudades
	{
    	int ciudad_1, ciudad_2;
    	
    	cout << endl;
    	cout << "--------------------------" << endl;
        cout << "Introduzca dos ciudades para las cuales no existe camino directo: ";
        cout << endl << endl;
    	
    	bool volver_a_pedir = true;  //Variable para saber si la entrada es correcta
    	
    	while(volver_a_pedir)
    	{
    	    do
    	    {
    	        cout << "Ciudad 1: ";
    	        cin >> ciudad_1;
    	    }while (ciudad_1 < 0 || ciudad_1 >= num_ciudades);
    	    
    	    do
    	    {
    	        cout << "Ciudad 2: ";
    	        cin >> ciudad_2;
    	    }while ((ciudad_2 < 0 || ciudad_2 >= num_ciudades) || ciudad_1 == 
    	               ciudad_2);
    	    
    	    if (mapa.EstanConectadas(ciudad_1, ciudad_2) == false)
    	    {
    	       volver_a_pedir = false;
    	    }
    	    else
    	    {
    	        cout << endl << endl;
    	    }
    	}
    	
    	cout << endl;
    	cout << mapa.CaminoMasCorto(ciudad_1, ciudad_2);
    }
	
	
	//Ahora pedimos ciudades hasta que se introduzca el -1 y despues indicamos
	//si estan todas conectadas entre si
	SecuenciaEnteros conectadas;
	int n;
	
	const int TERMINADOR = -1;
	
	cout << endl;
	cout << endl << "--------------------------" << endl;
	cout << "Ahora introducirá los indices de una serie de ciudad (0 - ";
	cout << num_ciudades - 1 << ") para ver si estan conectadas entre si" << endl;
	cout << "Para terminar, introduce: " << TERMINADOR << endl;
	
	cin >> n;
	do
	{
	    if (n != TERMINADOR)
	    {
	        conectadas.Aniade(n);
	        cin >> n;
	    }
	} while (n != TERMINADOR); //Suponemos que el usuario introducira
	//un numero adecuado de elementos >1 y <num_ciudades
    
    //Comprobamos si estan todas conectadas
    bool todas_conectadas = true;
    
    for (int t = 0; t < conectadas.TotalUtilizados() && todas_conectadas; t++)
    {
        for (int h = t+1; h < conectadas.TotalUtilizados() && todas_conectadas; h++)
        {
            if (mapa.EstanConectadas(conectadas.Elemento(t), 
            conectadas.Elemento(h)))
            {
                todas_conectadas = true;
            }
            else
            {
                todas_conectadas = false;
            }
        }
    }
    
    
    //Mostramos los resultados
    
    cout << endl;
    
    if(todas_conectadas)
    {
        cout << "Todas estan conectadas";
    }
    else
    {
        cout << "No estan todas conectadas";
    }
			
	
	return 0;
}
