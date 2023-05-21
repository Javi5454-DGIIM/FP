//FP 
//Javier Gómez López
/* Programa para calcular la variación porcentual 
   a partir de dos valores, inicial y final.
   
   Implementamos la fórmula de  la variación porcentual.
   
   Entradas: valor inicial y final
   Salidas: la variación porcentual entre esos valores
                  
            VP = abs ((100 x (valor final - valor inicial)) / valor inicial)
*/

#include <iostream> //Inclusión de los recursos E/S
#include <cmath>    //Inclusión de los recursos matemáticos

using namespace std;

int main()
{
	double valor_inicial; //Declaración de las variables 
	double valor_final;
	double variacion_porcentual;
	
//Entradas
cout << "El valor inicial es: ";
cin >> valor_inicial;
cout << endl;
cout << "El valor final es: ";
cin >> valor_final;
cout << endl;

//Calculos

variacion_porcentual = abs((100 * (valor_final - valor_inicial)) / valor_inicial);

//Salida

cout << "La variación porcentual es: " << variacion_porcentual << endl;

return (0);

}
