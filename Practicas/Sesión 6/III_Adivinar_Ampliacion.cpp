//FP 
//Javier Gómez López
/* Programa para jugar con el usuario a adivinar un número aleatorio 
   
   Para ello usaremos las estructuras que nos proporciona el enunciado.
   
   Entradas: un número cualquiera.
   Salidas: si dicho numero coincide con el generado automaticamente
   
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

bool LeeOpcion2Alternativas ()
{
    const char SI = 's';
	const char NO = 'n';
	
	char volver_a_jugar;
	
	do
    {  
    	cout << "¿Desea seguir jugando? [s/n]: ";
    	cin >> volver_a_jugar;
    	volver_a_jugar = tolower (volver_a_jugar);
    } while (volver_a_jugar != SI && volver_a_jugar != NO);
    
    if (volver_a_jugar == SI)
    {
        return true;
    } 
    else
    {
        return false;
    }
}
    
    
int main()
{
	//Declaración de variables y constantes
	
	const int MIN = 1;
	const int MAX = 100;
	const int NUM_VALORES = MAX - MIN + 1;
	const int TERMINADOR = -1;
	
	time_t t;
	srand(time(&t));
	
	int incognita = (rand() % NUM_VALORES + MIN);
	
	int num = 0;
	bool volver_a_jugar = true;
	
    //Explicacion del juego
    cout << "Adivina el número entre 0 y 100. Si quieres terminar escribe -1";
    cout << endl;
    
    //Calculos
    
    while (volver_a_jugar && num != TERMINADOR)
    {
    	cout << "Introduce un numero: " << endl;
    	cin >> num;
    	
        if (num == TERMINADOR)
    	{
    	   	num = TERMINADOR;
        }
        else if (num < incognita)
        {
        	cout << "El valor introducido es menor que el buscado" << endl;
        }
        else if(num > incognita)
    	{
        	cout << "El valor introducido es mayor que el buscado" << endl;
    	}
        else 
        {
        	cout << "Enhorabuena ha acertado el valor" << endl;
        	volver_a_jugar = LeeOpcion2Alternativas();
        	incognita = (rand() % NUM_VALORES + MIN);
        } 
    }
     
    
    cout << "El juego ha terminado" << endl;
    
    return (0);
	
	
}
