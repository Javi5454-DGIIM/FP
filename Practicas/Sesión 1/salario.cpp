//FP 
//Javier Gómez López
/* Programa para comprobar la asignación de una variable a lo
   largo de un programa.
*/

#include <iostream> //Inclusión de los recursos E/S
#include <cmath>    //Inclusión de los recursos matemáticos

using namespace std;

int main()
{
	int salario_bas
int salario_final;
int incremento;
salario_base = 1000;
salario_final = salario_base;
incremento = 200;
salario_final = salario_final + incremento;
salario_base = 3500;
cout << "\nSalario base: " << salario_base;
cout << "\nSalario final: " << salario_final;

return(0);
}

/*
  Como podemos observar, las variables salario_final y salario_base
  no se encuentrna ligadas durante todo el programa
*/
