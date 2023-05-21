//FP 
//Javier Gómez López
/* Programa para convertir una velocidad (km/h) a ritmo (min seg /km).
   
   Implementamos algoritmos de conversion de unidades de ritmo a velocidad.
   
   Entradas: una velocidad de km/h
   Salidas: dicha velocidad transformada a ritmo
   
                       1min          1km
                    ---------- = -----------
                        1km          60min
                        
                        
   
*/

#include <iostream> //Inclusión de los recursos E/S
#include <cmath>    //Inclusión de los recursos matemáticos

using namespace std;

int main()
{
     double velocidad_entrada;  //Declaracion de variables
     int minutos_salida;
     int segundos_salida;
     
     const int VELOCIDAD_A_SEGUNDOS_KM = 3600;
     double ritmo_sin_convertir;
	
//Entrada

cout << "La velocidad (km/h) a la que usted corre es: ";
cin >> velocidad_entrada;

//Cálculos

ritmo_sin_convertir = VELOCIDAD_A_SEGUNDOS_KM / velocidad_entrada;
segundos_salida = int(ritmo_sin_convertir)%60;
minutos_salida = ritmo_sin_convertir/60;

//Salidas
cout << "Su velocidad es de: " << minutos_salida << " minutos ";
cout << "y " << segundos_salida << " segundos";

return (0);

}
