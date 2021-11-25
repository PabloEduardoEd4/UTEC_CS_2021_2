#include <iostream>

void intercambiar(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}

void mostrar_dato(int a, int b)
{
	std::cout << a << ' ' << b << std::endl;
}

int main(int argc, char *argv[])
{
	int a = 1;
	int b = 2;
	mostrar_dato(a, b);
	intercambiar(a, b);
	mostrar_dato(a, b);
}