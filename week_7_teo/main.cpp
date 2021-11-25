#include <iostream>
#include <vector>

std::vector<int> empaqutar(int &colores, std::vector<int> &tamCajas)
{
	std::vector<int> respuesta(4);
	for (int i = 0; i < tamCajas.size(); i++)
	{
		respuesta.at(i) = colores / tamCajas.at(i);
		colores %= tamCajas.at(i);
	}
	return respuesta;
}

void imprimir(std::vector<int> &cajas, std::vector<int> &tamCajas)
{
	for (int i = 0; i < tamCajas.size(); i++)
	{
		std::cout << cajas.at(i) << "de" << tamCajas.at(i) << std::endl;
	}
}

int main(int argc, char *argv[])
{
	int colors;
	std::vector<int> tamCajas = {24, 12, 6};
	std::cout << "Ingrese Cantidad de Colores : " << std::endl;
	std::cin >> colors;
	std::vector<int> cajas = empaqutar(colors, tamCajas);
}