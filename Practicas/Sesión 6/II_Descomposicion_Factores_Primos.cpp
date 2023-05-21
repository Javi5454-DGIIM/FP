//FP 
//Javier Gómez López
/* Programa para calcular la descomposición en factores primos de 
   un número
   
   Para ello usaremos un ciclo while anidado dentro de un ciclo for
   
   Entradas: un número cualquiera.
   Salidas: la descomposición en factores primos de dicho numero
   
*/

#include <iostream>
#include <cmath>
#include <string>

using namespace std;


//PROGRAMA A

int main()
{
    //Declaracion de variables 
    
    int num;
    string resultado;
    
    const string ESTRELLA = " * ";
    
    //Entradas
    
    do
    {
        cout << "Introduzca un entero positivo: ";
        cin >> num;
    } while (num <= 0);
    
    
    //Calculos y salidas
    
    cout << num << " = "; 
    for (int i = 2; num > 1; i++)
    {
        while (num % i == 0)
        {
            resultado = resultado + to_string (i) + ESTRELLA;
            num = num / i;
        }
    }
    
    resultado = resultado.erase(resultado.length() - 2, 2);
    
    cout << resultado;
    
    return (0);
} 

//PROGRAMA B 

int main()
{
    //Declaracion de variables 
    
    int num;
    int contador = 0;
    string resultado;
    
    const string ESTRELLA = " * ";
    const string POTENCIA = "^";
    
    //Entradas
    
    do
    {
        cout << "Introduzca un entero positivo: ";
        cin >> num;
    } while (num <= 0);
    
    
    //Calculos y salidas
    
    cout << num << " = "; 
    for (int i = 2; num > 1; i++)
    {
        while (num % i == 0)
        {
            num = num / i;
            contador = contador + 1;
        }
        
        if (contador == 0)
        {
            resultado = resultado;
            contador = 0;
        }
        else if (contador == 1)
        {
            resultado = resultado + to_string (i) + ESTRELLA;
            contador = 0;
        }
        else
        {
            resultado = resultado + to_string (i) + POTENCIA + 
                        to_string (contador) + ESTRELLA;
            contador = 0;
        }
    }
    
    resultado = resultado.erase(resultado.length() - 2, 2);
    
    cout << resultado;
    
    return (0);
}
