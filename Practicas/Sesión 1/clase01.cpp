//*******************************************************************

//Primer programa con C++

//*******************************************************************

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string nombre;
	
	cout << "Dame tu nombre: ";
	getline (cin,nombre); 
	cout << "Hola: " << nombre << endl;
	cout << "¡ADIOS, MUNDO CRUEL!" << endl;
	
	return 0;
}
