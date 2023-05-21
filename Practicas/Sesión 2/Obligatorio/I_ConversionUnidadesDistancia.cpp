//FP 
//Javier Gómez López
/* Programa para realizar un cambio de unidad de una medida dada
   en metros a pulgadas, pies, yardas y millas.
   
   Implementamos las conversiones que se muestran en el enunciado del
   ejercio.
   
   Entradas: la cantidad real de metros que desee convertir el usuario
   Salidas: los metros convertidos a las distintas unidades
*/

#include <iostream> //Inclusión de los recursos E/S
#include <cmath>    //Inclusión de los recursos matemáticos

using namespace std;

int main()
{
    double metros_entrada;  //Declaramos las variables de entrada y salida	
    double pulgadas_salida;
    double pie_salida;
    double yarda_salida;
    double milla_salida;
    
    const double PULGADA_MILIMETRO = 25.4;  //Declaramos las constantes de 
    const double PIE_CENTIMETRO = 30.48;  //conversión
    const double YARDA_METROS = 0.9144;
    const double MILLA_KILOMETRO = 1.609344;
    const double MILIMETRO_METRO = 0.001;
    const double CENTIMETRO_METRO = 0.01;
    const double KILOMETRO_METRO = 1000 ;
    
//Entradas
cout << "La cantidad en metros que desea convertir es: ";
cin >> metros_entrada;

//Cálculos
pulgadas_salida = metros_entrada / (PULGADA_MILIMETRO * MILIMETRO_METRO);
pie_salida = metros_entrada / (PIE_CENTIMETRO * CENTIMETRO_METRO);
yarda_salida = metros_entrada / (YARDA_METROS);
milla_salida = metros_entrada / (MILLA_KILOMETRO * KILOMETRO_METRO);


//Salidas
cout << metros_entrada << " metros son " << pulgadas_salida << " pulgadas"; 
cout << endl;
cout << metros_entrada << " metros son " << pie_salida << " pies"; 
cout << endl;
cout << metros_entrada << " metros son " << yarda_salida << " yardas"; 
cout << endl;
cout << metros_entrada << " metros son " << milla_salida << " millas"; 
cout << endl;

return (0);
}
