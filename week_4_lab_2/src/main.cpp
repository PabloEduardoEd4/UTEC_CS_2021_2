#include <iostream>
#include "funciones.h"

int main(int argc, char *argv[])
{
	int num = 6;
	std::cout << construir(num) << std::endl;
	std::cout << fast_factorial(num);
	return 1;
}