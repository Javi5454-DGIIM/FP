//FP
//Javier Gómez López

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int vector[5] = {4,1,3,9,2};
	
	const int T = 12;
	int indice;
	bool general = true;
	
	for (int i = 0; i < 5 && general; i++)
	{
		int suma = 0;
		bool seguir = true;
		
		for (int k = i; k < 5 && seguir; k++)
		{
			suma += vector[k];
			if (suma < T)
			{
				seguir = true;
			}
			else if (suma > T)
			{
				indice = -1;
				seguir = false;
			}
			else
			{
				indice = i;
				seguir = false;
				general = false;
			}
		}
	};
	
	if (indice != -1)
	{
		cout << "La suma comienza en " << indice;
	}
	else
	{
		cout << "La suma no se realiza";
	}
	
	return 0;
}
