#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

void generarDatos(vector<int> &vec)
{
	srand(time(0));
	for (int i = 0; i < 10; ++i)
	{
		int dato = rand() % 20;
		vec.push_back(dato);
	}
}
void mostrarVector(vector<int> vec)
{
	cout << "# Elementos: " << vec.size() << endl;
	// Recorrer el vector usando un "for each" de solo lectura
	for (const auto dato : vec)
		cout << dato << " ";
	cout << endl;
}

void insertarEnVector(vector<int> &vec, int dato, int posicion)
{
	if (posicion > 0)
		vec.insert(begin(vec) + (posicion - 1), dato);
}

void iterarSumando10(vector<int> &vec)
{
	// Usando el operador [] como dereferenciador
	for (int i = 0; i < vec.size(); ++i)
		vec[i] += 10;
}

void iterarMultiplicando10(vector<int> &vec)
{
	// For each de escritura
	for (auto &dato : vec)
		dato *= 10;
}

void iterarRestando50(vector<int> &vec)
{
	for (auto iter = begin(vec); iter != end(vec); iter++)
		*iter -= 50;
}
void iterarDividiendo2(vector<int> &vec)
{
	for (int i = 0; i < vec.size(); ++i)
		vec.at(i) = vec.at(i) / 2;
}

bool esImpar(int dato)
{
	return dato % 2 == 1;
}

int main()
{
	vector<int> vec;
	generarDatos(vec);
	mostrarVector(vec);
	insertarEnVector(vec, -100, 2);
	mostrarVector(vec);
	vec.resize(15, 1000);
	mostrarVector(vec);
	iterarSumando10(vec);
	mostrarVector(vec);
	iterarMultiplicando10(vec);
	mostrarVector(vec);
	iterarRestando50(vec);
	mostrarVector(vec);
	iterarDividiendo2(vec);
	mostrarVector(vec);
	vec.pop_back();
	mostrarVector(vec);
	vec.erase(vec.begin() + 1);
	mostrarVector(vec);
	// Sintaxis de remove_if
	// iterable = remove_if(iteradorInicial, iteradorFinal, condicionSeleccion)
	// que es la condicionSeleccion:
	//  1. Funcion anonima (predicates)
	//  2. Expresion Lambda
	//  3. Puntero a una función
	// OJO PESTAÑA CEJA Y OREJA: El nombre una funcion representa
	// // la direccion de memoria de su implementacion (Puntero a la funcion)
	//auto toRemove = std::remove_if(vec.begin(), vec.end(), [](int dato){ return dato%2==0; });
	auto toRemove = std::remove_if(vec.begin(), vec.end(), esImpar);
	vec.erase(toRemove, end(vec));
	mostrarVector(vec);

	int datoReferencia = 0;
	cout << "Ingrese el numero que desea remover del vector: " << endl;
	cin >> datoReferencia;
	auto toRemove2 = std::remove_if(vec.begin(), vec.end(), [datoReferencia](int dato)
									{ return dato == datoReferencia; });
	vec.erase(toRemove2, end(vec));
	mostrarVector(vec);

	vec.clear();
	mostrarVector(vec);
	return 0;
}
