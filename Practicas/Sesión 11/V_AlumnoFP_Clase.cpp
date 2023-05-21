//FP 
//Javier Gómez López
/* Programa para calcular la nota final de un alumno  y en caso de haber 
   obtenido menos de 5 en alguna parte de la evaluación, mostrar la nota 
   obtenida en dicha parte
   
   Entradas: los datos del alumno
   
   Salidas: la nota final y la nota de un apartado en específico si esta es
   			menor que 5
*/

#include <iostream>  //Inclusión de los recursos de entrada y salida
#include <string>    //Inclusión de los recursos string

using namespace std;

class AlumnoFP
{
	
private:
	static const double PCR_TEORIA;  //Porcentaje de cada parte de la 
	static const double PCR_EX_1;    //asignatura, constante de la clase
	static const double PCR_EX_2;
	static const double PCR_CONTINUA;
	
	string nombre, apellido, dni;  //Datos del alumno
	
	double nota_teoria;
	double nota_ex_1;
	double nota_ex_2;
	double nota_ev_continua;
	double nota_final;
	
	string cad_final;
	
public:
	
	AlumnoFP(string el_nombre, string el_apellido, string el_dni, double teoria,
			 double ex_1, double ex_2, double continua): 
	nombre(el_nombre),
	apellido(el_apellido),
	dni(el_dni),
	nota_teoria(teoria),
	nota_ex_1(ex_1),
	nota_ex_2(ex_2),
	nota_ev_continua(continua)
	{}
	
	//Metodos Get
	
	string GetNombre(void)
	{
		return nombre;
	}
	
	string GetApellido(void)
	{
		return apellido;
	}
	
	string GetDNI (void)
	{
		return dni;
	}
	
	double GetTeoria(void)
	{
		return (nota_teoria);
	}
	
	double GetEx1(void)
	{
		return (nota_ex_1);
	}
	
	double GetEx2(void)
	{
		return (nota_ex_2);
	}
	
	double GetContinua (void)
	{
		return (nota_ev_continua);
	}
	
	string MostrarNotas()
	{
		NotaFinal();
		cad_final ="La nota final ha sido: " +  to_string(nota_final);
		
		if (nota_teoria < 5)
		{
				cad_final =cad_final +  "\n" + "La nota de la teoria ha sido: "
				+ to_string(nota_teoria);
		}
			
		if (nota_ex_1 < 5)
		{
			cad_final =cad_final + "\n" + "La nota del examen práctico 1 ha "
			"sido: " + to_string(nota_ex_1);
		}
			
		if (nota_ex_2 < 5)			
		{
			cad_final =cad_final + "\n" + "La nota del examen practico 2 ha "
			"sido: "+ to_string(nota_ex_2);
		}
			
		if (nota_ev_continua < 5)
		{
			cad_final =cad_final +  "\n" + "La nota de la evaluacion continua "
			"ha sido: " + to_string(nota_ev_continua);
		}
		
		return cad_final;
	}
	
private:
		
	void NotaFinal()
	{
		if(nota_teoria > 4)
		{
			nota_final = PCR_TEORIA * nota_teoria + PCR_EX_1 * nota_ex_1 +
						 PCR_EX_2 * nota_ex_2 + PCR_CONTINUA * nota_ev_continua;
		}
		else
		{
			nota_final = nota_teoria;
		}
		
	}
	
}; //Ahora declaramos las constantes de la clase
const double AlumnoFP::PCR_TEORIA = 0.6;
const double AlumnoFP::PCR_EX_1 = 0.1;
const double AlumnoFP::PCR_EX_2 = 0.2;
const double AlumnoFP::PCR_CONTINUA = 0.1;

//Funciones

string EliminaPrimerosSeparadores (string cadena)
{
	int posicion = 0;
	int tamanio = cadena.length();
	
	while (cadena.at(posicion) == ' ' && posicion < tamanio) {
		posicion++;
	}
	
	string local;
	while (posicion < tamanio) {
		local.push_back(cadena.at(posicion));
		posicion++;
	}
		
	return local;
}

string EliminaUltimosSeparadores (string cadena)
{
	int longitud = cadena.length();
	
   	while (longitud > 0 && cadena.back() == ' ') {
		cadena.pop_back();
		longitud = cadena.length();
	}
        
	return cadena;
}

string EliminaSeparadoresTotales (string cadena)
{	
	return EliminaUltimosSeparadores(EliminaPrimerosSeparadores(cadena)); 
}

double LeerNumRango(int min, int max, string titulo)
{
	double num;
	
	do
	{
		cout << titulo;
		cin >> num;
	} while (num < min || num > max);
	
	return num;
}

int main()  //Funcion principal
{
	//Declaracion de constantes
	const int MIN = 0;
	const int MAX = 10;
	
	//Declaracion de variables
	
	string nombre;
	string apellido;
	string dni;
	
	double teoria, ex_1, ex_2, continua;
	
	//Entradas
	cout << "Introduzca el nombre del alumno: ";
	cin >> nombre;
	nombre = EliminaSeparadoresTotales(nombre);
	
	cout << "Introduzca el apellido del alumno: ";
	cin >> apellido;
	
	cout << "Introduzca el DNI del alumno: ";
	cin >> dni;
	
	cout << endl;
	
	teoria = LeerNumRango(MIN, MAX, "Introduzca la nota de la teoria: ");
	ex_1 = LeerNumRango(MIN, MAX, "Introduzca la nota del examen practico 1: ");
	ex_2 = LeerNumRango(MIN, MAX, "Introduzca la nota del examen practico 2: ");
	continua = LeerNumRango(MIN, MAX, "Introduzca la nota de la evaluación continua: ");
	
	AlumnoFP alumno (nombre, apellido, dni, teoria, ex_1, ex_2, continua);
	
	//Salidas
	
	cout << endl << "Los datos del alumno son: " << endl;
	cout << "\n ---------> Nombre: " << alumno.GetNombre() << endl;
	cout << "\n ---------> Apellido: " << alumno.GetApellido() << endl;
	cout << "\n ---------> DNI: " << alumno.GetDNI() << endl;
	cout << endl;
	cout << alumno.MostrarNotas();
	
	
	return 0;
}
