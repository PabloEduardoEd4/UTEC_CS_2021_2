#include <iostream>
#include <string>

int char_to_int(const char *a)
{
	int out = 0;
	for (int x = 0; x < sizeof(a); x++)
	{
		std::cout << a[x] << std::endl;
		out = (out * 10) + (a[x] - '0');
	}
	return out;
}

int main(int argc, char *argv[])
{
	//original value
	double A = 1.0f;

	//pointer
	double *p = &A;

	//object copy
	double &C = A;

	double *N = new double;

	A = 2.0f;

	std::cout << char_to_int("1101") << std::endl;
	std::cout << std::stoi("1101") << std::endl;

	std::cout
		<< A << ' ' << *p << ' ' << C << std::endl;

	int L[2];
}