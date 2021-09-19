//main.cpp

#include <iostream>
#include "physics.hpp"

using namespace std;

int main()
{
	double test = force_grav(10000, 10000, 1);
	cout << test << endl;
	return 0;
}