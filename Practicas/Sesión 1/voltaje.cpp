//FP 
//Javier Gómez López
/* Programa para calcular el valor del voltaje dado intensidad y resistencia
   
   Entradas: el valor de la intensidad de la resistencia
   Salidas: el voltaje
                  
                       V = I x R
*/

#include <iostream> //Inclusión de los recursos E/S
#include <cmath>    //Inclusión de los recursos matemáticos

using namespace std;

int main()  //Programa principal
{

double resistencia;  //Declara variables para guardar
double intensidad;   //la resistencia y la intensidad y el voltaje
double voltaje;

//Entrada de datos

cout << "Introduzca la resistencia: "  ;
cin >> resistencia;
cout << "Introduzca la intensidad: ";
cin >> intensidad;

//Cálculos

voltaje = intensidad * resistencia;    

//Salida

cout << endl;
cout << "El voltaje vale: " << voltaje << endl;

return (0);
}
