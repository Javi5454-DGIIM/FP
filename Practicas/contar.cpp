/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <ctype.h>
#include <cstdio>
#include <conio.h>
using namespace std;

	
/***************************************************************************/
/***************************************************************************/
bool EsLetra (char c) 
{
	bool es_letra;
	
	if ((c>='A' && c<='Z') || (c>='a' && c<='z'))
		es_letra = true;
		
	return (es_letra);	
}

/***************************************************************************/
/***************************************************************************/
bool EsVocal (char c) 
{
	const string vocales = "AEIOU";
	bool es_vocal = false;
	
	if(EsLetra(c))
	{
		for (int i = 0; i < vocales.length() && !es_vocal; i++)
		{
			es_vocal = toupper(c) == vocales[i];
		}
	}
	
	return es_vocal;
}

/***************************************************************************/
/***************************************************************************/

bool EsConsonante (char c) 
{
	bool es_consonante;
	
	es_consonante = (!EsVocal(c) && EsLetra(c));
	
	return es_consonante;
}

/***************************************************************************/
/***************************************************************************/

bool EsDigito (char c) 
{
	bool es_digito; 
		
	es_digito = (c >= '0' && c <= '9');
	
	return (es_digito);
}

/***************************************************************************/
/***************************************************************************/

bool EsOtro (char c) 
{
	bool es_otro;
	
	es_otro = (!EsDigito(c) && !EsLetra(c) && c != ' ');
	
	return es_otro;
}

/***************************************************************************/
/***************************************************************************/

enum class Tipo
		{vocal, consonante, digito, otro};
		
/***************************************************************************/
/***************************************************************************/


Tipo Clasifica (char letra)
{
	
	Tipo clasificacion;
	
	if (EsVocal(letra))
	{
		clasificacion = Tipo::vocal;
	}
	else if (EsConsonante(letra))
	{
		clasificacion = Tipo::consonante;
	}
	else if (EsDigito(letra))
	{
		clasificacion = Tipo::digito;
	}
	else if (EsOtro(letra))
	{
		clasificacion = Tipo::otro;
	}
	
	return clasificacion;
}
	
struct Contadores
{
	int vocales = 0, consonantes = 0, digitos = 0, otros= 0, total = 0;
};

/***************************************************************************/
/***************************************************************************/

int main()
{
	char caracter;
	Contadores contadores;
	
	while (caracter != '#')
	{
		caracter = _getch();
		if(caracter!='#')
		{
			cout << caracter << ", ";
			
			if(caracter != ' ')
			{
				if (Clasifica(caracter) == Tipo::vocal)
				{
					contadores.vocales++;
					contadores.total++;
				}
				else if(Clasifica(caracter) == Tipo::consonante)
				{
					contadores.consonantes++;
					contadores.total++;
				}
				else if (Clasifica(caracter) == Tipo::digito)
				{
					contadores.digitos++;
					contadores.total++;
				}
				else if (Clasifica(caracter) == Tipo::otro)
				{
					contadores.otros++;
					contadores.total++;
				}
			}
		}
		else
		{
			cout << caracter;
		}
	}	

	
	
	
	// Salida
	cout << endl;
	cout << "Hay un total de " << contadores.total << " caracteres." << endl;	
	cout << endl;
	cout << "Hay " <<setw(2) << contadores.vocales << " vocales." << endl;	
	cout << "Hay " <<setw(2) << contadores.consonantes << " consonantes.";
	cout << endl;
	cout << "Hay " <<setw(2) << contadores.digitos << " digitos." << endl;
	cout << "Hay " <<setw(2) << contadores.otros << " otros." << endl;	
	cout << endl;

	return 0;	
}

/***************************************************************************/
/***************************************************************************/
