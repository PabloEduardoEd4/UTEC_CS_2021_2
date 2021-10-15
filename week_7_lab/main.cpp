#include <iostream>

int main(int argc, char *argv[])
{

	//Declaration + Reserving
	double *p1 = new double();
	double *p2 = new double();

	// use space
	std::cout << "First nuumber: ";
	std::cin >> *p1;
	std::cout << "Second nuumber: ";
	std::cin >> *p2;
	std::cout << *p1 + *p2 << std::endl;
	std::cout << *p1 - *p2 << std::endl;
	std::cout << *p1 * *p2 << std::endl;
	delete p1, p2;

	return 0;
}