//FP 
//Javier Gómez López
/* Programa para trabajar con una clase triangulo y otra clase
   rectángulo en función de otra clase que defina un punto en R2 llamada 
   Punto2D
*/

#include <iostream>
#include <cmath>

using namespace std;

//Definmos la clase Punto2D
class Punto2D
{

private:
	
	double abscisa;
	double ordenada;
	
public:
	
	//Definimos el constructor
	Punto2D (double abscisaPunto, double ordenadaPunto):
		abscisa(abscisaPunto),
		ordenada(ordenadaPunto)
	{}
	
	//Set coordenadas
	void SetCoordenadas (double abscisaPunto, double ordenadaPunto)
	{
		abscisa = abscisaPunto;
		ordenada = ordenadaPunto;
	}
	
	//Métodos Get
	double Abscisa()
	{
		return abscisa;
	}
	
	double Ordenada()
	{
		return ordenada;
	}
	
	string ToString ()
	{
		return ("("+to_string(abscisa)+", "+to_string(ordenada)+")");
	}
};

//Definamos la clase triangulo

class Triangulo
{
	
private:
	Punto2D vertice1;
	Punto2D vertice2;
	Punto2D vertice3;
	
public:
	
	//Constructor del triangulo
	Triangulo (Punto2D el_vertice1, Punto2D el_vertice2, Punto2D el_vertice3):
		vertice1(el_vertice1),
		vertice2(el_vertice2),
		vertice3(el_vertice3)
	{}
		
	//Metodos Get
	
	Punto2D GetVertice1 (void)
	{
		return vertice1;
	}
	
	Punto2D GetVertice2 (void)
	{
		return vertice2;
	}
	
	Punto2D GetVertice3 (void)
	{
		return vertice3;
	}
	
	double GetLadoA()
	{
		double ladoA;
		
		ladoA = sqrt((pow(vertice3.Abscisa()-vertice2.Abscisa(),2)) + 
				(pow(vertice3.Ordenada()-vertice2.Ordenada(), 2)));
				
		return ladoA;
	}
	
	double GetLadoB()
	{
		double ladoB;
		
		ladoB = sqrt((pow(vertice1.Abscisa()-vertice3.Abscisa(),2)) + 
				(pow(vertice1.Ordenada()-vertice3.Ordenada(), 2)));
				
		return ladoB;
	}
	
	double GetLadoC()
	{
		double ladoC;
		
		ladoC = sqrt((pow(vertice1.Abscisa()-vertice2.Abscisa(),2)) + 
				(pow(vertice1.Ordenada()-vertice2.Ordenada(), 2)));
				
		return ladoC;
	}
		
	
	//Metodo para obtener el perimetro del rectangulo
	
	double Perimetro()
	{
		double perimetro;
		double ladoA, ladoB, ladoC;
		
		ladoA = GetLadoA();
		ladoB = GetLadoB();
		ladoC = GetLadoC();
				
		perimetro = ladoA + ladoB + ladoC;
		
		return perimetro;
	}
				
	//Metodo para calcular si el triángulo es rectángulo
	
	bool EsRectangulo ()
	{
		bool rectangulo;
		double ladoA, ladoB, ladoC;
		double hipo, cat1, cat2;
		
		ladoA = GetLadoA();
		ladoB = GetLadoB();
		ladoC = GetLadoC();
		
		if(ladoA > ladoB && ladoA > ladoC)
		{
			hipo = ladoA;
			cat1 = ladoB;
			cat2 = ladoC;
		}
		else if (ladoB > ladoA && ladoB > ladoC)
		{
			hipo = ladoB;
			cat1 = ladoA;
			cat2 = ladoC;
		}
		else if(ladoC > ladoA && ladoC > ladoB)
		{
			hipo = ladoC;
			cat1 = ladoA;
			cat2 = ladoB;
		}
		
		rectangulo = (((pow(cat1, 2)) + (pow(cat2, 2))) == (pow(hipo, 2)));
		
		return rectangulo;
	}
};

//Definamos la clase del rectángulo
class Rectangulo
{
	
private:
	
	Punto2D esquina_sup_idza;
	double base;   //PRE: 0 < base
	double altura; //PRE: 0 < altura
	
public:
	
	//Constructor
	Rectangulo (Punto2D punto_esq_sup_idza, double la_base, double la_altura):
		esquina_sup_idza(punto_esq_sup_idza),
		base(la_base),
		altura(la_altura)
	{}
	
	//Metodos Get
	double GetBase()
	{
		return base;
	}
	
	double GetAltura()
	{
		return altura;
	}
	
	Punto2D GetEsquina()
	{
		return esquina_sup_idza;
	}
	
	double Area()
	{
		return base*altura;
	}
	
	double Perimetro()
	{
		return (2*base + 2*altura);
	}
	
	bool EstaDentro (Punto2D el_punto)
	{
		bool esta;
		
		if (el_punto.Abscisa() >= esquina_sup_idza.Abscisa() && 
			el_punto.Abscisa() <= esquina_sup_idza.Abscisa() + base)
		{
			if(el_punto.Ordenada() <= esquina_sup_idza.Ordenada() && 
				el_punto.Ordenada() >= esquina_sup_idza.Ordenada() - altura)
				{
					esta = true;
				}
				else
				{
					esta = false;
				}
		}
		else
		{
			esta = false;
		}
		
		return esta;
	}
	
	Triangulo TrianguloInferior()
	{
		double inf_izda_abs, inf_izda_ordenada;
		double inf_dcha_abs, inf_dcha_ordenada;
		
		inf_izda_abs = esquina_sup_idza.Abscisa();
		inf_izda_ordenada = esquina_sup_idza.Ordenada() - altura;
		
		inf_dcha_abs = esquina_sup_idza.Abscisa() + base;
		inf_dcha_ordenada = esquina_sup_idza.Ordenada() - altura;
		
		Punto2D inf_izda(inf_izda_abs, inf_izda_ordenada);
		Punto2D inf_dcha(inf_dcha_abs, inf_dcha_ordenada);
		
		Triangulo trianguloInferior(esquina_sup_idza, inf_izda, inf_dcha);
		
		return trianguloInferior;
	}
	
	Triangulo TrianguloSuperior()
	{
		double sup_dcha_abs, sup_dcha_ordenada;
		double inf_dcha_abs, inf_dcha_ordenada;
		
		inf_dcha_abs = esquina_sup_idza.Abscisa() + base;
		inf_dcha_ordenada = esquina_sup_idza.Ordenada() - altura;
		
		sup_dcha_abs = esquina_sup_idza.Abscisa() + base;
		sup_dcha_ordenada = esquina_sup_idza.Ordenada();
		
		Punto2D sup_dcha(sup_dcha_abs, sup_dcha_ordenada);
		Punto2D inf_dcha(inf_dcha_abs, inf_dcha_ordenada);
		
		Triangulo trianguloSuperior(esquina_sup_idza, sup_dcha, inf_dcha);
		
		return trianguloSuperior;
	}
		
		
};	

int main() //Definamos la funcion principal
{

	//Declaramos las variables que no pertenecen a la clase Punto2D
	double base, altura, esi_abs, esi_ordenada;
	
	//Entradas
	
	//Confiaremos en el usuario para introducir valores con sentido
	cout << "Primero definamos un rectangulo" << endl;
	cout << "Escriba las coordenadas de su esquina superior izquierda";
	cout << endl;
	cout << "\t x: ";
	cin >> esi_abs;
	cout << "\t y: ";
	cin >> esi_ordenada;
	
	//Definimos el punto 2D formado por esas coordenas
	Punto2D esi_rectangulo (esi_abs, esi_ordenada);
	
	//Pedimos los valores de la base y la altura
	
	do
	{
		cout << "Introduzca la base del rectangulo (>0): ";
		cin >> base;
	}while (base <= 0);
	
	do
	{
		cout << "Introduzca la altura del rectangulo (>0): ";
		cin >> altura;
	}while (altura <= 0);
	
	Rectangulo rectangulo(esi_rectangulo, base, altura);
	
	//Ahora probamos los métodos perimetro y area de la clase rectangulo
	double area_rectangulo, perimetro_rectangulo;
	
	area_rectangulo = rectangulo.Area();
	perimetro_rectangulo = rectangulo.Perimetro();
	
	cout << endl << "\t Area del rectangulo -----> " << area_rectangulo << endl;
	cout << "\t Perimetro del rectangulo -----> " << perimetro_rectangulo;
	cout << endl << endl;
	
	//Comprobamos si un punto esta en el rectangulo
	double punto_check_abs, punto_check_ordenada;
	cout << "Introduzca ahora un punto para comprobar si está en el rectangulo:";
	cout << endl;
	cout << "\t x: ";
	cin >> punto_check_abs;
	cout << "\t y: ";
	cin >> punto_check_ordenada;
	
	Punto2D punto_check(punto_check_abs, punto_check_ordenada);
	
	bool esta = rectangulo.EstaDentro(punto_check);
	
	if(esta)
	{
		cout << endl << "-----> Está en el rectangulo";
	}
	else
	{
		cout << endl << "-----> No está en el rectangulo";
	}
	
	//Ahora obtendremos los triangulos superiores e inferiores del rectangulo
	cout << endl << endl;
	
	Triangulo trianguloInferior = rectangulo.TrianguloInferior();
	
	Punto2D v1inf = trianguloInferior.GetVertice1();
	Punto2D v2inf = trianguloInferior.GetVertice2();
	Punto2D v3inf = trianguloInferior.GetVertice3();
	
	cout << "El triangulo inferior del rectangulo está formado por los";
	cout << " vertices: " << endl;
	cout << v1inf.ToString();
	cout << endl;
	cout << "\t V2: (" << v2inf.Abscisa() << "," << v2inf.Ordenada() << ")";
	cout << endl;
	cout << "\t V3: (" << v3inf.Abscisa() << "," << v3inf.Ordenada() << ")";
	cout << endl;
	
	cout << endl << endl;
	
	Triangulo trianguloSuperior = rectangulo.TrianguloSuperior();
	
	Punto2D v1sup = trianguloSuperior.GetVertice1();
	Punto2D v2sup = trianguloSuperior.GetVertice2();
	Punto2D v3sup = trianguloSuperior.GetVertice3();
	
	cout << "El triangulo superior del rectangulo está formado por los";
	cout << " vertices: " << endl;
	cout << "\t V1: (" << v1sup.Abscisa() << "," << v1sup.Ordenada() << ")";
	cout << endl;
	cout << "\t V2: (" << v2sup.Abscisa() << "," << v2sup.Ordenada() << ")";
	cout << endl;
	cout << "\t V3: (" << v3sup.Abscisa() << "," << v3sup.Ordenada() << ")";
	cout << endl;
	
	//Pedimos los vértices de un nuevo triangulo
	
	cout << endl;
	cout << "Ahora definirá un triangulo a partir de sus 3 vértices" << endl;
	
	double v1_abs, v1_ordenada, v2_abs, v2_ordenada, v3_abs, v3_ordenada;
	
	cout << endl << "Vértice 1: " << endl <<  "\t x: ";
	cin >> v1_abs;
	cout << "\t y: ";
	cin >> v1_ordenada;
	cout << endl;
	
	Punto2D v1 (v1_abs, v1_ordenada);
	
	cout << endl << "Vértice 2: " << endl <<  "\t x: ";
	cin >> v2_abs;
	cout << "\t y: ";
	cin >> v2_ordenada;
	cout << endl;
	
	Punto2D v2 (v2_abs, v2_ordenada);
	
	cout << endl << "Vértice 3: " << endl <<  "\t x: ";
	cin >> v3_abs;
	cout << "\t y: ";
	cin >> v3_ordenada;
	cout << endl;
	
	Punto2D v3 (v3_abs, v3_ordenada);
	
	//Creamos el objeto de la clase triangulo con esos vertices
	Triangulo triangulo(v1, v2, v3);
	cout << endl;
	
	//Perímetro del rectangulo
	cout << "El perimétro del rectángulo es -----> ";
	cout << triangulo.Perimetro();
	
	//Comprobamos si es rectangulo
	cout << endl;
	if(triangulo.EsRectangulo())
	{
		cout << "El triangulo es rectangulo";
	}
	else
	{
		cout << "El triangulo no es rectangulo";
	}
	
	return 0;
}
