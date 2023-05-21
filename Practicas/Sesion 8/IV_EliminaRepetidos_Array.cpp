/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS 4
//
/*	
	Programa que lee un número indeterminado de números positivos
	(termina la lectura cuando se introduce un negativo) aunque nunca leerá 
	más de 50. Conforme los lee, los va almacenando en un vector.

	A continuación elimina del vector los valores repetidos, dejando 
	una sola copia. No se dejan huecos en el vector y todos los números 
	quedan agrupados en las posiciones más bajas del vector.

	Se implementan tres versiones del borrado (ver enunciado)
*/
/***************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/***************************************************************************/

int main (void)
{
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 
	
	// Vector de datos
	
	const int MAX_DATOS = 50; 
	int datos[MAX_DATOS];
	
	int total_utilizados = 0;	

	// Lectura de los datos 
	
	bool sigo = true; 
	int dato; 
	
	cin >> dato;
	
	while ((dato>=0) && (sigo)) {

		datos[total_utilizados]	= dato;
		total_utilizados++;

		if (total_utilizados==MAX_DATOS) 
			sigo = false;
		else 
			cin >> dato;
	}

	// Se muestran los datos originales
	
	cout << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << endl;	
 	cout << "Datos originales: " << "(" << setw(3) 
	 	 << total_utilizados << " datos): " << endl;	
	 	 
	for (int i=0; i<total_utilizados; i++) 
		cout << setw(3) << datos[i] << "  "; 
	cout << endl;
			
	cout << "--------------------------------------------------------" << endl;
	cout << endl;

	// Copia de los datos originales en dos vectores para trabajar sobre 
	// los nuevos vectores y no perder los datos originales
	// Sobre el array "copia1_datos" se empleará un algoritmo ineficiente
	// mientras que sobre "copia2_datos" se usará otro más eficiente.
	
	int copia1_datos[MAX_DATOS];
	int total_utilizados_copia1 = 0;	

	int copia2_datos[MAX_DATOS];
	int total_utilizados_copia2 = 0;
	
	int copia3_datos[MAX_DATOS];
	int total_utilizados_copia3 = 0;	

	for (int i=0; i<total_utilizados; i++) 
		copia1_datos[i] = copia2_datos[i] = copia3_datos[i] = datos[i];
		
	total_utilizados_copia1 = total_utilizados;
	total_utilizados_copia2 = total_utilizados;
	total_utilizados_copia3 = total_utilizados;

 	/***********************************************************************/
 	// VERSION 1: USANDO UN VECTOR AUXILIAR
 	
	// Se muestran los datos del vector copia (1) antes de procesarlos 
	
	cout << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << endl;
 	cout << "Copia 1 antes de eliminar repetidos usando vector auxiliar"
	     << " (" << setw(3) << total_utilizados_copia1 << " datos):" << endl;	

	for (int i=0; i<total_utilizados_copia1; i++) 
		cout << setw(3) << copia1_datos[i] << "  "; 
	cout << endl;


	int sin_repetidos[MAX_DATOS];
	int total_utilizados_sin_repetidos = 0;

	sin_repetidos[0] = copia1_datos[0];
	total_utilizados_sin_repetidos = 1;
	
	for (int i=1; i<total_utilizados_copia1; i++) {
		
		// Buscar copia1_datos[i] en sin_repetidos
		
		int pos = 0; 
		bool encontrado = false;
		
		while ((pos<total_utilizados_sin_repetidos) && (!encontrado)) {
			if (sin_repetidos[pos]==copia1_datos[i])
				encontrado = true;
			else 
				pos++;
		}
		if (!encontrado) {
			sin_repetidos[total_utilizados_sin_repetidos] = copia1_datos[i];
			total_utilizados_sin_repetidos++;
		}
	
	} // for 
	 
	// Copia desde sin_repetidos a copia1
	 
	for (int i=0; i<total_utilizados_sin_repetidos; i++) 
		 copia1_datos[i] = sin_repetidos[i];
	total_utilizados_copia1 = total_utilizados_sin_repetidos;
	 
	// Se muestran los datos del vector copia (1) después de procesarlos 
	
	cout << endl;	
 	cout << "Copia 1 despues de eliminar repetidos con vector auxiliar"
	     << " (" << setw(3) << total_utilizados_copia1 << " datos):" << endl;

	for (int i=0; i<total_utilizados_copia1; i++) 
		cout << setw(3) << copia1_datos[i] << "  "; 
	cout << endl;
	
	cout << "--------------------------------------------------------" << endl;
	cout << endl;



 	/***********************************************************************/
  	// VERSION 2: BORRAR (DESPLAZAR) REPETIDAMENTE
	
	// Se muestran los datos del vector copia (1) antes de procesarlos 
	
	cout << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << endl;
 	cout << "Copia 2 antes de eliminar repetidos con algoritmo ineficiente"
	     << " (" << setw(3) << total_utilizados_copia2 << " datos):" << endl;	

	for (int i=0; i<total_utilizados_copia2; i++) 
		cout << setw(3) << copia2_datos[i] << "  "; 
	cout << endl;
 
 	// Borrado con desplazamiento
 	
 	// Empezamos a buscar repetidos desde la posición "pos_del_buscado" 
	// hacia arriba. Damos por hecho que los que están por debajo no están 
	// repetidos. Cuando "pos_del_buscado"=1 solo hay uno por debajo, 
	// el de la posición 0 y evidentemente no está repetido (solo hay 
	// uno por debajo del que ocupa la posición "pos_del_buscado"). 
 	
 	int pos_del_buscado = 1;
		
	while (pos_del_buscado < total_utilizados_copia2) {

		int valor_buscado = copia2_datos[pos_del_buscado];

		// Busco "valor_buscado" (el de "pos_del_buscado") en el 
		// subvector izquierdo (posiciones: 0 hasta "pos_del_buscado"-1)
		
  		int pos = 0;
		bool encontrado = false;
    
		while ((pos < pos_del_buscado) && (!encontrado))

			if (copia2_datos[pos] == valor_buscado) 
				encontrado = true; //Éxito: terminar
			else
				pos++; // Siguiente posición

		if (encontrado) {
		
			int tope = total_utilizados_copia2-1; // posición del último 
    
    		// Desplazar hacia la izquierda los valores que están a 
    		// la derecha del que ocupa la posición "pos_del_buscado"
    		
			for (int i=pos_del_buscado ; i < tope ; i++)
				copia2_datos[i] = copia2_datos[i+1];  
    
			total_utilizados_copia2--;  // Ya hay uno menos
		}
		else
			pos_del_buscado++; // Procesar el suguiente

	} // while (pos_del_buscado < total_utilizados_copia1)
		
			
	// Se muestran los datos del vector copia (1) después de procesarlos 
	
	cout << endl;	
 	cout << "Copia 2 despues de eliminar repetidos con algoritmo ineficiente"
	     << " (" << setw(3) << total_utilizados_copia2 << " datos):" << endl;

	for (int i=0; i<total_utilizados_copia2; i++) 
		cout << setw(3) << copia2_datos[i] << "  "; 
	cout << endl;
		
	cout << "--------------------------------------------------------" << endl;
	cout << endl;
	
	/***********************************************************************/
  	// VERSION 3: USANDO DOS APUNTADORES
	
	// Se muestran los datos del vector copia (3) antes de procesarlos 
	
	cout << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << endl;
 	cout << "Copia 3 antes de eliminar repetidos con algoritmo ineficiente"
	     << " (" << setw(3) << total_utilizados_copia3 << " datos):" << endl;	

	for (int i=0; i<total_utilizados_copia3; i++) 
		cout << setw(3) << copia3_datos[i] << "  "; 
	cout << endl;
 	
 	int posicion_lectura = 1, posicion_escritura = 1;
 	bool repetido;
 	
 	while (posicion_lectura < total_utilizados_copia3)
 	{
 		repetido = false;
 		
 		for(int i = 0; i< posicion_escritura; i++)
 		{
 			if(copia3_datos[i] == datos[posicion_lectura])
 			{
 				repetido = true;
 			}
 		}
 		
 		copia3_datos[posicion_escritura] = copia3_datos[posicion_lectura];
 		
 		if(repetido)
 		{
 			posicion_lectura++;
 		}
 		else
 		{
 			posicion_lectura++;
 			posicion_escritura++;
 		}
 				
	}
	
	total_utilizados_copia3 = posicion_escritura ;
	
		
			
	// Se muestran los datos del vector copia (1) después de procesarlos 
	
	cout << endl;	
 	cout << "Copia 3 despues de eliminar repetidos con algoritmo eficiente"
	     << " (" << setw(3) << total_utilizados_copia3 << " datos):" << endl;

	for (int i=0; i<total_utilizados_copia3; i++) 
		cout << setw(3) << copia3_datos[i] << "  "; 
	cout << endl;
		
	cout << "--------------------------------------------------------" << endl;
	cout << endl;
	
	return (0);
}
