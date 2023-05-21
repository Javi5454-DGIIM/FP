//FP 
//Javier Gómez López
/* Programa que permitirá al usuario calcular el número aureo en funcion de 
   una sucesión de Fibonacci
   
   Para ello crearemos una serie de distintas funciones
   
   Entradas: el valor máximo de la diferencia
   Salidas: el número n de Fibonnacci que más se aproxima al número aureo
   
*/


#include <iostream>  //Inclusión de los recursos de entrada y salida
#include <cmath>     //Inclusión de los recursos matemáticos

using namespace std;

int calculo_fibonacci(int n);
int menor_valor_aproximacion_numero_aureo(double diferencia_maxima);
double aproximacion_numero_aureo(int n);

double const NUMERO_AUREO=(1+sqrt(5.0))/2.0;

int main(){
	
	double indice_diferencia;	
	
	//Entrada
	
	do{
		cout<<"Introduzca el valor maximo de diferencia: ";
		cin>>indice_diferencia;
	}while(indice_diferencia>=1);
	
	//Calculos
	
	int menor_valor_fibonacci=
					menor_valor_aproximacion_numero_aureo(indice_diferencia);
	
	//Salidas
	
	cout<<endl;
	cout<<"El minimo valor para que la aproximacion del numero aureo difiera ";
	cout<<indice_diferencia<<" es de: "<<menor_valor_fibonacci;
	
	
	return 0;
}

int calculo_fibonacci(int n){
	
	int total_fibonacci=1;
	int ant1 = 1; // fib(2)
	int ant2 = 1; // fib(1) 
	
		for (int i=2 ; i<n; i++) {
			
			total_fibonacci = ant1 + ant2; // fib (i)
	
			// Preparamos la siguiente iteracion
			ant2 = ant1; 		// fib(n-1)		
			ant1 = total_fibonacci;	// fib(n)	
		}
		
	return total_fibonacci;

}

int menor_valor_aproximacion_numero_aureo(double diferencia_maxima){
	
	int n=1;
	bool sigo=true;
	double diferencia;
	
	
	while(sigo){
		
		diferencia=fabs(aproximacion_numero_aureo(n)-NUMERO_AUREO);
		
		if(diferencia<=	diferencia_maxima)
			sigo=false;
			
		else
			n++;	
	}
	
	return n;
}

double aproximacion_numero_aureo(int n){
	double a_n;
	
	a_n=((double)calculo_fibonacci(n+1))/calculo_fibonacci(n);
	
	return a_n;	
}
