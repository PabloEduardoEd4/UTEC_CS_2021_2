#include <iostream>
using namespace std;

const char MENOR_EDAD = 'M', ADULTO = 'A', ADULTO_MAYOR = 'D';

const char evaluaGrupoEdades(unsigned int edad)
{
	if (edad <= 17)
		return MENOR_EDAD;
	else if (edad <= 60)
		return ADULTO;
	else
		return ADULTO_MAYOR;
}

int main()
{

	// Declaracion de variables de entrada.
	char tipo_Tren, continua;
	unsigned int edad_Usuario = 0;
	// Variable de salida
	unsigned int costo;

	do
	{
		cout << "Venta de pasajes PERU RAIL\n"
			 << endl;
		// Pedimos al usuario el tipo de tren.
		cout << "[H] Hiran Binghan\n[V] Vistadome\n[E] Expedition\n[A] Andian Explorar" << endl;
		cout << "Ingrese el tipo de tren: ";
		cin >> tipo_Tren;
		tipo_Tren = tolower(tipo_Tren);
		cout << endl;

		// Pedimos al usuario ingresar su edad.
		cout << "[0-17] Menor de edad\n[18-60] Mayor de edad\n[+60] Adulto mayor" << endl;
		cout << "Ingrese su edad: ";
		cin >> edad_Usuario;
		cout << endl;

		// Clasificamos el tipo de tren con la edad para ofrecer el monto.
		switch (tipo_Tren)
		{
		case 'h':
		case 'e':
			switch (evaluaGrupoEdades(edad_Usuario))
			{
			case MENOR_EDAD:
				costo = 800;
				break;
			case ADULTO:
				costo = 990;
				break;
			case ADULTO_MAYOR:
				costo = 700;
			}
			break;
		case 'v':
		case 'a':
			switch (evaluaGrupoEdades(edad_Usuario))
			{
			case MENOR_EDAD:
				costo = 350;
				break;
			case ADULTO:
				costo = 500;
				break;
			case ADULTO_MAYOR:
				costo = 700;
				break;
			}
			break;
		}
		cout << "Precio del pasaje " << costo << endl;

		cout << "Continua vendiendo s/n?" << endl;
		cin >> continua;
	} while (continua != 'n');
}