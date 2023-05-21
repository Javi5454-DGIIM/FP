/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// Javier Gómez López
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// PRUEBA 03
//
/*	
	Programa que lee las coordenadas que definen un rectángulo y calcula una 
	serie de circunferencias centradas en el punto de corte de sus diagonales.
	Solo nos interesan aquellas que estén inscritas en el rectángulo.  	
	Guarda estas circunferencias en una colección.
*/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <cctype>
#include <cmath>
#include <cstdlib>

using namespace std;

/***************************************************************************/
/***************************************************************************/

const double PRECISION_SON_IGUALES = 1e-6; // 0.000001
const double PI = 3.141592653589793;

/***************************************************************************/
/***************************************************************************/
// Función global (asociada a la constante PRECISION_SON_IGUALES) que
// permite que dos números reales muy próximos sean considerados iguales.

bool SonIguales(double uno, double otro) 
{
	return (fabs(uno-otro) <= PRECISION_SON_IGUALES);
}

/***************************************************************************/

////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// La clase "Punto2D" representa un punto en R^2  

class Punto2D
{
private:
	
	// La pareja (x,y) son las coordenadas de un punto en un espacio 2D
	double x;
	double y;

public:
	
	/***********************************************************************/
	// Constructor con argumentos.
	//
	// Recibe: abscisaPunto y ordenadaPunto, la abscisa y ordenada, 
	// respectivamente del punto que se está creando.
	
	Punto2D (double abscisaPunto, double ordenadaPunto)
	{
		SetCoordenadas (abscisaPunto, ordenadaPunto);
	}
	
	//Constructor sin argumentos
	//
	//Inicializa un punto con las coordenadas (0,0)
	Punto2D (void)
	{
		SetCoordenadas(0,0);
	}

	/***********************************************************************/
	// Método Set para fijar simultaneamente las coordenadas. 
	//
	// Recibe: abscisaPunto y ordenadaPunto, la abscisa y ordenada, 
	// respectivamente del punto que se está modificando.
	
	void SetCoordenadas (double abscisaPunto, double ordenadaPunto)
	{
		x = abscisaPunto;
		y = ordenadaPunto;
	}

	/***********************************************************************/
	// Métodos Get para leer las coordenadas

	double GetX (void) { return (x); }
	double GetY (void) { return (y); }

	/***********************************************************************/
	// Calcula si dos puntos son iguales 
	//
	// Recibe: otro, el punto que se quiere comparar con el objeto implícito. 
	// Devuelve: true, si se consideran iguales los dos objetos. 

	bool EsIgual (Punto2D otro)
	{
		return (SonIguales(x,otro.x) && SonIguales(y,otro.y));
	}

	/***********************************************************************/
	// Calcula la distancia Euclídea del punto (objeto implícito) a otro que 
	// se recibe como argumento. 
	//
	// Recibe: otro, el punto respecto al cual que se quiere calcular la 
	// distancia euclídea.
	// Devuelve: la distancia entre los dos puntos. 

	double DistanciaEuclidea (Punto2D otro)
	{
		double dif_x = pow (x - otro.x, 2);
		double dif_y = pow (y - otro.y, 2);

		return (sqrt(dif_x + dif_y));
	}

	/***********************************************************************/
	// Devuelve la representación en una cadena de un punto
	string ToString (void)
	{
		string cad;
		cad = "[ " + to_string (x) + ", " + to_string (y) + "]";	
		return (cad);
	}

	/***********************************************************************/
};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// La clase "Circunferencia" representa circunferencias, objetos geométricos 
// que verifican la propiedad de que los puntos (x,y) que la forman están a 
// la misma distancia de otro punto (el centro).

class Circunferencia
{
private:

	// La constante "PI" es común a todos los objetos de la clase.
	static const double PI;		
	
	// Centro de la circunferencia
	Punto2D centro;	
	
	// Longitud del radio
	// PRE: radio >= 0
	double  radio;	

public:

	/***********************************************************************/
	// Constructor con argumentos
	// Recibe:
	//		el_centro, el punto central de la circunferencia. 
	//		radio, el valor del radio.
	// PRE: radio >= 0
	// Observad cómo se ha iniciado "centro": como es de clase "Punto2D"
	// se ha empleado la lista de iniciación para que actúe el constructor
	// de la clase "Punto2D" 
	
	Circunferencia (Punto2D el_centro, double el_radio) 
	    : centro (el_centro), radio(el_radio) 
	{ }
	
	//Añadimos un constructor sin argumentos
	//
	//Inicializa una circunferencia con centro el origen de coordenas
	//y con radio 0
	
	Circunferencia (void)
	{
		Punto2D el_centro(0,0);
		int el_radio = 0;
		
		centro = el_centro;
		radio = el_radio;
	}

	/***********************************************************************/
	// Métodos Get
	
	// Devuelve el punto central de la circunferencia
	Punto2D GetCentro (void) { return (centro); }

	// Devuelve el radio de la circunferencia
	double GetRadio (void) { return (radio); }

	// Devuelve el diámetro de la circunferencia
	double GetDiametro (void) { return (radio*2); }

	/***********************************************************************/
	// Calcula la longitud de la circunferencia

	double Longitud (void)
	{
		return (2.0 * PI * radio);
	}

	/***********************************************************************/
	// Calcula el área del círculo
	
	double Area (void)
	{
		return (PI * radio * radio);
	}

	/***********************************************************************/
	// Devuelve una cadena que representa a una Circunferencia
	
	string ToString (void)
	{
		
		string cad_final;
		cad_final = "{[ " + to_string(centro.GetX()) + ", ";
		cad_final = cad_final + to_string(centro.GetY()) + "), ";
		cad_final = cad_final + to_string(radio) + "]";
		
		return cad_final;
	}
		
	
	/***********************************************************************/
};

const double Circunferencia :: PI = PI;

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// La clase "Rectangulo" representa rectángulos, paralelogramos que 
// verifican la propiedad de que los ángulos interiores son todos rectos. 
// Esta implementación considera únicamente rectángulos cuyos lados sean 
// paralelos a los ejes de coordenadas. 

class Rectangulo
{
private:

	// Esquina superior izquierda 
	Punto2D esquina_si;	
	
	// Longitud de los lados
	// PRE: long_ladoX, long_ladoY >= 0
	double long_ladoX; // Longitud de los lados paralelos al eje X
	double long_ladoY; // Longitud de los lados paralelos al eje Y	

public:

	/***********************************************************************/
	// Constructor con argumentos
	// Recibe:
	//		"la_esquina_si", el punto que determina la esquina superior izda.
	//		"la_long_ladoX", la longitud de los lados paralelos al eje X  
	//		"la_long_ladoY", la longitud de los lados paralelos al eje Y  
	// PRE: la_long_ladoX, la_long_ladoY >= 0

	Rectangulo (Punto2D la_esquina_si, double la_long_ladoX, 
	            double la_long_ladoY) : esquina_si (la_esquina_si) 
	{
		// Observad cómo se ha iniciado "esquina_si": como es de clase 
		// "Punto2D" se ha empleado la lista de iniciación para que actúe el 
		// constructor de la clase "Punto2D" 
		 
		long_ladoX  = la_long_ladoX; 
		long_ladoY  = la_long_ladoY; 
	}

	/***********************************************************************/
	// Métodos Get
	
	// Devuelve la esquina superior izquierda del rectángulo
	Punto2D GetEsquinaSI (void) { return (esquina_si); }
	
	// Devuelve la esquina superior derecha del rectángulo
	Punto2D GetEsquinaSD (void) 
	{
		return (Punto2D(esquina_si.GetX()+long_ladoX, esquina_si.GetY()));
	}
	// Devuelve la esquina inferior izquierda del rectángulo
	Punto2D GetEsquinaII (void) 
	{
		return (Punto2D(esquina_si.GetX(), esquina_si.GetY()-long_ladoY));
	}
	// Devuelve la esquina inferior derecha del rectángulo
	Punto2D GetEsquinaID (void)
	{
		return (Punto2D(esquina_si.GetX()+long_ladoX, 
		                esquina_si.GetY()-long_ladoY));
	}	
	
	// Devuelve la longitud del lado paralelo al eje X
	double GetLongitudLadoX (void) { return (long_ladoX); }
	
	// Devuelve la longitud del lado paralelo al eje Y
	double GetLongitudLadoY (void) { return (long_ladoY); }
	
	/***********************************************************************/
	// Calcula el área del rectángulo
	double Area (void)
	{
		return (long_ladoX*long_ladoY);
	}

	/***********************************************************************/
	// Calcula el perímetro del rectángulo	
	double Perimetro (void)
	{
		return (2*long_ladoX + 2*long_ladoY);
	}
	
	/***********************************************************************/
	// Devuelve una cadena que representa a un rectángulo
	string ToString (void)
	{
	
		string cad_final;
		Punto2D esquinaSI = GetEsquinaSI();
		Punto2D esquinaSD = GetEsquinaSD();
		Punto2D esquinaII = GetEsquinaII();
		Punto2D esquinaID = GetEsquinaID();
		
		cad_final = "Rectangulo: \n" + esquinaSI.ToString() + " - " +
		esquinaSD.ToString() + " Long = "+ to_string(GetLongitudLadoX()) + "\n"
		+ esquinaSD.ToString() + " - " + esquinaID.ToString() + " Long = "
		+ to_string(GetLongitudLadoY()) + "\n" + esquinaID.ToString() + " - " +
		esquinaII.ToString() + " Long = " + to_string(GetLongitudLadoX()) + 
		"\n" + esquinaII.ToString() + " - " + esquinaSI.ToString() + 
		" Long = " + to_string(GetLongitudLadoY());
		
		return cad_final;
		
	}
	
	/***********************************************************************/
};

/////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// La clase "ColeccionCircunferencias" representa una secuencia de 
// datos "Circunferencia" 

class ColeccionCircunferencias 
{
private:

	// Datos asociados a la estructura de datos empleada para guardar 
	// los valores de la coleccion.

	static const int TAMANIO = 200; // Número de casillas disponibles

	Circunferencia vector_privado[TAMANIO];
	
	//PRE: 0 <= total_utilizados <= TAMANIO
	int total_utilizados;	// Número de casillas ocupadas
	
public:
	
	ColeccionCircunferencias (void)
	{
		total_utilizados = 0;
	}
	
	//Devuelve el numero total de circunferencias
	int NumCircunferencias (void)
	{
		return total_utilizados;
	}
	
	//Añade circunferencias al array
	void Aniade (Circunferencia nuevo)
	{
		if (total_utilizados < TAMANIO)
		{
			vector_privado[total_utilizados] = nuevo;
			total_utilizados++;
		}
	}
	
	//Devuelve el elemento del array que se desee
	Circunferencia Elemento (int indice)
	{
		return (vector_privado[indice]);
	}
	
	//Metodo ToString
	string ToString (void)
	{
		string cad_final;
		
		for (int i = 0; i < total_utilizados; i++)
		{
			cad_final = cad_final + vector_privado[i].ToString() + "\n";
		}
		
		return cad_final;
	}
	
};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

/***************************************************************************/
/***************************************************************************/

int main (void)
{
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 
		
	const double RADIO_INIC = 0.5;  // Valor del radio inicial
	const double INCR_RADIO = 0.25;	// Incremento del valor del radio

	// Leer los valores que definen el rectángulo
	
	double x, y, ancho, alto; 

	cout << "Esquina sup. izda." << endl;
	cout << "\tx: ";
	cin >> x; 
	cout << "\ty: ";
	cin >> y;
		 	
	Punto2D esquina_si (x, y);

	cout << endl;
	do
	{	
		cout << "Ancho: ";
		cin >> ancho;
	}while(ancho < 0);

	do
	{
		cout << "Alto: ";
		cin >> alto;
	}while(alto < 0);

	// Crear el rectángulo
	
 	Rectangulo r (esquina_si, ancho, alto); 
 
	cout << endl;		
	cout << "Rectangulo = " << endl;	
	cout << endl; 
	cout << r.ToString() << endl;
	cout << endl; 
	
	// Calcular el centro del rectángulo

	double centroX = ancho/2 + r.GetEsquinaSI().GetX();
	double centroY = r.GetEsquinaSI().GetY() - alto/2;
	
	Punto2D centro_r(centroX, centroY);
	
	//Mostramos el centro del rectangulo
	
	cout << "Punto central del rectángulo: " << centro_r.ToString() << endl;
	cout << endl;
	

	// Todas las circunferencias inscritas tendrán un radio menor o igual que 
	// la mitad de la longitud de la dimensión menor entre el alto y el ancho 
	// del rectángulo.

	double ancho_r = r.GetLongitudLadoX();
	double alto_r  = r.GetLongitudLadoY();
	double min_dimension = ((ancho_r < alto_r) ? ancho_r : alto_r);
	double max_radio = min_dimension / 2;	

	// Creamos una serie de circunferencias centradas en "centro", el centro 
	// del rectángulo. La primera tiene de radio RADIO_INIC. Para las sucesivas 
	// circunferencias sus radios se incrementan en INCR_RADIO. 

	ColeccionCircunferencias circ_inscritas;
	int contador = 1;

	for(double radio = RADIO_INIC; radio <= max_radio; radio += INCR_RADIO)
	{
		Circunferencia c(centro_r, radio);
		
		circ_inscritas.Aniade(c);
		
		cout << "Guardando circunferencia " + to_string(contador) + ": ";
		cout << c.ToString();
		cout << endl;
		contador++;
	}
	
	


	// Mostrar datos de las circunferencias inscritas  

	cout << endl;
	cout << "Se han encontrado " <<circ_inscritas.NumCircunferencias() 
	     << " circunferencias inscritas:" << endl; 
	cout << endl;
	
	cout << circ_inscritas.ToString() << endl; 
	
	return 0;
}

/***************************************************************************/
/***************************************************************************/
