#include <iostream>
#include <math.h>

double diffrence(int x1, int x2, int y1, int y2)
{
	int delta_x = x2 - x1;
	int delta_y = y2 - y1;
	double square_sum = (delta_x * delta_x) + (delta_y * delta_y);
	return sqrt(square_sum);
}

int main(int argc, char *argv[])
{
	//Entrada
	int vertexes, x, y, x_first, y_first, x_stack, y_stack;

	//Salida
	double sum = 0;
	do
	{
		std::cout << "Numero de vertices:" << std::endl;
		std::cin >> vertexes;
	} while (vertexes < 3 || vertexes > 10);
	for (int i = 0; i < vertexes; i++)
	{
		std::cout << "Coordenanda x:" << std::endl;
		std::cin >> x;
		std::cout << "Coordenanda y:" << std::endl;
		std::cin >> y;
		if (i == 0)
			x_first = x, y_first = y;
		else
			sum = sum + diffrence(x, x_stack, y, y_stack);
		x_stack = x, y_stack = y;
	}
	sum = sum + diffrence(x, x_first, y, y_first);
	std::cout << "El perimetro es:" << sum << std::endl;
}