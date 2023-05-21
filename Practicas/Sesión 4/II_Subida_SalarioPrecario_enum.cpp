//FP
//Javier Gómez López
/* Programa para modificar un salario en función de distintas condiciones
   que el usuario especificará en la entrada de datos (edad, salario).
   
   Para ello trabajaremos crearemos distintos tipos enumerados y utilizaremos
   condicionales anidados
   
   Entradas: un salario y una edad
   
   Salidas: el salario en base a distintas condiciones
   
*/

#include <iostream> //Inclusión de los recursos E/S

using namespace std;

enum class CategoriaLaboral
        {trabajador_estandar, trabajadorPrecario};
enum class Salario
        {precario, salario_medio, mayor_SMI};
        
int main()
{
	int edad;
	double salario_entrada;
	double subida_edad = 0;
	double subida_salario = 0;
	double salario_final;
	
	const double PORCENTAJE_EDAD = 0.04;
	const double PORCENTAJE_MENOS_300 = 0.03;
	const double PORCENTAJE_MENOS_900 = 0.015;
	
	CategoriaLaboral tipo_trabajador;
	Salario tipo_salario;
	
	//Entradas
	cout << "Introduzca su edad: ";
	cin >> edad;
	cout << "Introduzca su salario: ";
	cin >> salario_entrada;
	
	//Calculos
	if (edad < 35 || edad > 65)
	{
		tipo_trabajador = CategoriaLaboral::trabajadorPrecario;
	} 
	else
	{
		tipo_trabajador = CategoriaLaboral::trabajador_estandar;
	}
	
	if (salario_entrada < 300)
	{
		tipo_salario = Salario::precario;
	}
	else if (salario_entrada >= 300 && salario_entrada < 900)
	{
		tipo_salario = Salario::salario_medio;
	}
	else
	{
		tipo_salario = Salario::mayor_SMI;
	}
	
	if (tipo_trabajador == CategoriaLaboral::trabajadorPrecario)
	{
		subida_edad = salario_entrada * PORCENTAJE_EDAD;
		
		if (tipo_salario == Salario::precario)
		{
			subida_salario = salario_entrada * PORCENTAJE_MENOS_300;
			salario_final = salario_entrada + subida_salario + subida_edad;
			cout << "Se ha aplicado la subida del 4 por su edad y ";
			cout << "de el 3 por ciento por cobrar menos de 300" << endl;
			cout << "Su salario final es: " << salario_final << endl;
		}
		else if (tipo_salario == Salario::salario_medio)
		{
		    subida_salario = salario_entrada * PORCENTAJE_MENOS_900;
			salario_final = salario_entrada + subida_salario + subida_edad;
			cout << "Se ha aplicado la subida del 4por ciento por su edad y ";
			cout << "de el 1.5 por cobrar más de 300 y menos de 900" << endl;
			cout << "Su salario final es: " << salario_final << endl;
		}
		else if (tipo_salario == Salario::mayor_SMI)
		{
			salario_final = salario_entrada + subida_salario + subida_edad;
			cout << "Se ha aplicado la subida del 4 por ciento por su edad"; 
			cout << endl;
			cout << "Su salario final es: " << salario_final << endl;
		}
	else if (tipo_trabajador == CategoriaLaboral::trabajador_estandar)
	{
		cout << "Su salario no recibe ninguna bonificacion";
    }
		
		return (0);
	}
}
