//FP 
//Javier Gómez López
/* Programa para calcular la función gaussiana en un rango de valores  
   dados por el usuario, así como el CDF en ese rango.
   
   Para ello usaremos distintas funciones de ejercicios anteriores
   
   Entradas: la desviación típica, la media
   Salidas: valor de la gaussiana para cada valor en ese intervalo y el CDF
            de cada valor
*/

#include <iostream> //Inclusión de los recursos de entrada y salida
#include <cmath>   //Inclusión de los recursos matemáticos

using namespace std;

const double PI = 3.1415926535;

double Gaussiana (double valor_x, double media, double desviacion)
{
    double resultado;
    
    resultado = 1/(desviacion * sqrt(2 * PI));
    resultado = resultado * exp(-0.5 * pow(((valor_x - media) /
                desviacion),2));
                
    return resultado;
}

double GaussianaCDF (double valor_x, double media, double desviacion)
{
    const double dx = 0.00005;
    
    double inicio = media - (3 * desviacion);
    double resultado;
    double integral = 0;
    double gaussiana;
    
    for (double i = inicio; i <= valor_x; i = i + dx)
    {
        gaussiana = Gaussiana (i, media, desviacion);
        resultado = gaussiana * dx;
        integral = integral + resultado;
    }
    
    return integral;
}

double AproxCDF (double valor_x, double media, double desviacion)
{
    const double b0 = 0.2316419;
    const double b1 = 0.31938153;
    const double b2 = -0.356563782;
    const double b3 = 1.781477937;
    const double b4 = -1.821255978;
    const double b5 = 1.330274429;
    
    double resultado;
    double t = 1 / (1 + b0 * fabs(valor_x));
    double g_x = Gaussiana (fabs(valor_x), media, desviacion);
    
    resultado = 1 - g_x * (b1 * t + b2 * pow(t,2) + b3 * pow(t,3) +
                b4 * pow(t,4) + b5 * pow(t,5));
                
    if (resultado < 0)
    {
        resultado = 1 - resultado;
    }
    
    return resultado;
}

int main ()
{
    
    //Declaración de variables
    const float SALTO = 0.25;
    
    double desviacion;
    double media;
    double resultado_gaussiana;
    double resultado_CDF;
    double resultado_aprox_CDF;
    double inicio;
    double fin;
    
    //Entradas
    cout << "Introduzca la media: ";
    cin >> media;
    
    do
    {
        cout << "Introduzca la desviacion tipica (>0): ";
        cin >> desviacion;
    } while (desviacion <= 0);
    
    //Calculos y muestra de resultados
    inicio = media - (3 * desviacion);
    fin = media + (3 * desviacion);
    
    while (inicio <= fin)
    {
        resultado_gaussiana = Gaussiana(inicio, media, desviacion);
        resultado_CDF = GaussianaCDF(inicio, media, desviacion);
        resultado_aprox_CDF = AproxCDF(inicio, media, desviacion);
        cout << "g(" << inicio << ") = " << resultado_gaussiana << endl;
        cout << "CDF(" << inicio << ") = " << resultado_CDF << endl;
        cout << "AproxCDF(" << inicio << ") = " << resultado_aprox_CDF << endl;
        cout << endl;
        inicio = inicio + SALTO;
    } 
    
    return (0);
}
