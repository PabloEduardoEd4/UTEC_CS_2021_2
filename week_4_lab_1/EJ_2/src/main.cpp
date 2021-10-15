#include <iostream>
using namespace std;

char Menu()
{
	char opcion = ' ';
	cout << "Elija una opcion:" << endl;
	cout << "S. Sumar" << endl;
	cout << "R. Restar" << endl;
	cout << "M. Media Aritmetica" << endl;
	cout << "X. Salir" << endl;
	do
	{
		cout << "Opcion : ";
		cin >> opcion;
		opcion = toupper(opcion);
	} while (opcion != 'S' && opcion != 'R' && opcion != 'M' && opcion != 'X');
	return opcion;
}

void IngresarNumeros(int &n1, int &n2)
{
	cout << "Ingresar Primer Numero: ";
	cin >> n1;
	cout << "Ingresar Segundo Numero: ";
	cin >> n2;
}

float RealizarOperacion(char operacion, int n1, int n2)
{
	switch (operacion)
	{
	case 'S':
		return n1 + n2;
		break;
	case 'R':
		return n1 - n2;
		break;
	case 'M':
		return (n1 + n2) / 2.0;
	}
}

void MostrarResultado(float resultado)
{
	cout << "Resultado: " << resultado << endl;
}

int main()
{
	char opcion = ' ';
	int numero1, numero2;
	float resultado;
	do
	{
		opcion = Menu();
		if (opcion != 'X')
		{
			IngresarNumeros(numero1, numero2);
			resultado = RealizarOperacion(opcion, numero1, numero2);
			MostrarResultado(resultado);
		}
	} while (opcion != 'X');
	return 0;
}
