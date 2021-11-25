#include <iostream>
#include <ctime>
#include <string>
/*
Siguiendo la misma lógica anterior, diseñar e implementar una clase para manipular arreglos bidimensionales 
(matrices), considerando las siguientes características: 

 - La clase TMatriz debe gestionar los elementos en una matriz dinámica.
 - Usar templates para dar soporte a elementos de cualquier tipo de dato.
 - Implementar al menos tres constructores: constructor vacío, 
 	constructor para crear e inicializar una matriz dinámicamente, y un constructor que copie los datos de otro objeto.
 - Se debe también implementar los métodos básicos para insertar elementos a la matriz y para obtener sus valores.
 - Y por último,  implementar en el destructor la liberación de memoria de la matriz dinámica.  
*/

//Usar templates para dar soporte a elementos de cualquier tipo de dato.
template <class T>
class TMatriz
{
private:
	T **matriz;
	int capacity_x;
	int capacity_y;
	//La clase TMatriz debe gestionar los elementos en una matriz dinámica.
	void initialize()
	{
		matriz = new T *[capacity_x];
		for (int i = 0; i < capacity_x; i++)
		{
			matriz[i] = new T[capacity_y];
		}
	}
	void copy(TMatriz *temp)
	{
		capacity_x = temp->get_capacitiy_x(), capacity_y = temp->get_capacitiy_y();
		initialize();
		for (int i = 0; i < capacity_x; i++)
			for (int j = 0; j < capacity_y; j++)
				matriz[i][j] = temp->at(i, j);
	}

public:
	//constructor vacío
	TMatriz() : capacity_x(10), capacity_y(10) { initialize(); }
	//constructor para crear e inicializar una matriz dinámicamente
	TMatriz(int _size_x, int _size_y) : capacity_x(_size_x), capacity_y(_size_y) { initialize(); }
	//constructor que copie los datos de otro objeto
	TMatriz(TMatriz<T> *temp) { copy(temp); }
	//para obtener sus valores.
	T *at(int index)
	{
		if (0 < index && index < capacity_x)
			return matriz[index];
		throw;
	}
	T at(int x_index, int y_index)
	{
		if (0 <= x_index && x_index < capacity_x && 0 <= y_index && y_index < capacity_y)
			return matriz[x_index][y_index];
		throw;
	}
	//insertar elementos a la matriz
	void add(T *value, int index)
	{
		if (0 < index && index < capacity_x)
			matriz[index] = value;
		else
			throw;
	}
	void add(T value, int x_index, int y_index)
	{
		if (0 <= x_index && x_index < capacity_x && 0 <= y_index && y_index < capacity_y)
			matriz[x_index][y_index] = value;
		else
			throw;
	}
	int get_capacitiy_x() { return capacity_x; }
	int get_capacitiy_y() { return capacity_y; }
	//Implementar en el destructor la liberación de memoria de la matriz dinámica.
	~TMatriz() { delete[] matriz; }
};

int main(int argc, char *argv[])
{
	srand(time(nullptr));
	const int size_x = 15;
	const int size_y = 17;
	TMatriz<std::string> *a = new TMatriz<std::string>(size_x, size_y);
	for (int i = 0; i < size_x; i++)
		for (int j = 0; j < size_y; j++)
		{
			a->add("a", i, j);
		}
	int x = rand() % size_x, y = rand() % size_y;
	TMatriz<std::string> *b = new TMatriz<std::string>(a);
	std::cout << a->at(x, 16) << std::endl;
	std::cout << b->at(x, 16) << std::endl;
	a->add("b", x, 16);
	std::cout << a->at(x, 16) << std::endl;
	std::cout << b->at(x, 16) << std::endl;
	delete a;
	delete b;
}